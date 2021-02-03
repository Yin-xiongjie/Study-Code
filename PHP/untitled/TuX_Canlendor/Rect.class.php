<?php
class Rect extends Shape {
    private $width;
    private $height;
    function __construct($arr = array()) {
        if (!empty($arr)) {
            $this->width = $arr['width'];
            $this->height = $arr['height'];
        }
        $this->name = "矩形";
        $this->error = '';
    }
    function area() {
        return $this->width * $this->height;
    }
    function zhou() {
        return ($this->width+$this->height) * 2;
    }
    function view($arr) {
        $form='';
        $form .= "<form action='index.php?action=rect' method='post'>";
        $form .= "请输入".$arr['name']."的宽度：<input type='text' name='width' value='".$_POST['width']."'/><br>";
        $form .= "<br>";
        $form .= "请输入".$arr['name']."的长度：<input type='text' name='height' value='".$_POST['height']."'/><br>";
        $form .= "<br>";
        $form .= "<input type='submit' name='sub' value='提交'/>    ";
        $form .= "<input type='reset' name='ret' value='重置'/>";
        $form .= "</form>";
        echo $form;
    }
    function yan($arr) {
        $bz = true;
        if ($arr['width']< 0) {
            $this->error .= "宽度小于0；";
            $bz = false;
        } else {
            if (!is_numeric($arr['width'])) {
                $this->error .= "宽不是数字；";
                $bz = false;
            }
        }
        if ($arr['height']< 0) {
            $this->error .= "宽度小于0；";
            $bz = false;
        } else {
            if (!is_numeric($arr['height'])) {
                $this->error .= "高不是数字；";
                $bz = false;
            }
        }
        return $bz;
    }
}
?>