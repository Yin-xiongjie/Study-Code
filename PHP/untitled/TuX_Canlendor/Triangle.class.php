<?php

class Triangle extends Shape
{
    private $bian1;
    private $bian2;
    private $bian3;

    function __construct($arr = array())
    {
        if (!empty($arr)) {
            $this->bian1 = $arr['bian1'];
            $this->bian2 = $arr['bian2'];
            $this->bian3 = $arr['bian3'];
        }
        $this->name = "三角形";
        $this->error = '';
    }

    function area()
    {
        $p = ($this->bian1 + $this->bian2 + $this->bian3) / 2;
        //  p(p-a)(p-b)(p-c)
        return sqrt($p * ($p - $this->bian1) * ($p - $this->bian2) * ($p - $this->bian3));
    }

    function zhou()
    {
        return $this->bian1 + $this->bian2 + $this->bian3;
    }

    function view($arr)
    {
        $form = '';
        $form .= "<form action='index.php?action=triangle' method='post'>";
        $form .= "请输入" . $arr['name'] . "的第一条边：<input type='text' name='bian1' value='" . $_POST['bian1'] . "'/><br>";
        $form .= "<br>";
        $form .= "请输入" . $arr['name'] . "的第二条边：<input type='text' name='bian2' value='" . $_POST['bian2'] . "'/><br>";
        $form .= "<br>";
        $form .= "请输入" . $arr['name'] . "的第三条边：<input type='text' name='bian3' value='" . $_POST['bian3'] . "'/><br>";
        $form .= "<br>";
        $form .= "<input type='submit' name='sub' value='提交'/>    ";
        $form .= "<input type='reset' name='ret' value='重置'/>";
        $form .= "</form>";
        echo $form;
    }

    function yan($arr)
    {
        $bz = true;
        if ($arr['bian1'] < 0) {
            $this->error .= "第一条边小于0；";
            $bz = false;
        } else {
            if (!is_numeric($arr['bian1'])) {
                $this->error .= "第一条边不是数字；";
                $bz = false;
            }
        }
        if ($arr['bian2'] < 0) {
            $this->error .= "第二条边小0；";
            $bz = false;
        } else {
            if (!is_numeric($arr['bian2'])) {
                $this->error .= "第二条边不是数字；";
                $bz = false;
            }
        }
        if ($arr['bian2'] < 0) {
            $this->error .= "第三条边小于0；";
            $bz = false;
        } else {
            if (!is_numeric($arr['bian2'])) {
                $this->error .= "第三条边不是数字；";
                $bz = false;
            }
        }
        if (($this->bian1 + $this->bian2) < $this->bian3 || ($this->bian1 + $this->bian3) < $this->bian2 || ($this->bian2 + $this->bian3) < $this->bian1) {
            $this->error .= "三条边不能构成三角形";
            $bz = false;
        }
        return $bz;
    }
}
