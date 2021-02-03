<?php
class Sphere extends Shape {
    private $r;
    function __construct($arr = array()) {
        if (!empty($arr)) {
            $this->r = $arr['r'];
        }
        $this->name = "球体";
        $this->error = '';
    }
    //4π(R的平方),体积 4/3π*r的立方
    //球的面积
    function area() {
        return 4*pi()* $this->r* $this->r; ;
    }
    //求的体积
    function zhou() {
        return pow((4/3)*$this->r*pi(),3);
    }
    function view($arr) {
        $form='';
        $form .= "<form action='index.php?action=sphere' method='post'>";
        $form .= "请输入".$arr['name']."的半径：<input type='text' name='r' value='".$_POST['r']."'/><br>";
        $form .= "<br>";
        $form .= "<input type='submit' name='sub' value='提交'/>    ";
        $form .= "<input type='reset' name='ret' value='重置'/>";
        $form .= "</form>";
        echo $form;
    }
    function yan($arr) {
        $bz = true;
        if ($arr['r']< 0) {
            $this->error .= "半径小于0；";
            $bz = false;
        } else {
            if (!is_numeric($arr['r'])) {
                $this->error .= "半径不是数字；";
                $bz = false;
            }
        }
        return $bz;
    }
}
?>
