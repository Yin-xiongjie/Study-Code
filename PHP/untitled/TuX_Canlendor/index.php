<!doctype html>

<html>
<head>
    <meta charset="utf-8">
    <title>图形计算器</title>
    <style>
        * {
            margin: 0px;
            padding: 0px;
        }
        #contains {
            width: 500px;
            margin: 20px auto;
            background: skyblue;
            text-align: center;
        }
        h1 {
            width: 500px;
            height: 60px;
        }
        a {
            font-size: 20px;
            text-decoration: none;
        }
        #footer {
            width: 300px;
            background: #fff;
            margin: 0 auto;
            padding: 5px 10px;
            border-radius: 150px;
        }
    </style>
</head>
<body>
<div id="contains">
    <h1>简易图形计算器</h1>
    <a href='index.php?action=rect'>矩形</a> |
    <a href='index.php?action=triangle'>三角形</a> |
    <a href='index.php?action=cirle'>圆形</a> |
    <a href='index.php?action=sphere'>球体</a>
    <hr>
    <?php
    include 'Cirle.class.php';
    ini_set("display_errors", "On"); //开启错误调试
    //设置错误报告的级别，除了无关紧要的'注意'，其他的报告都输出
    error_reporting(E_ALL & ~E_NOTICE);
    function __autoload($classname) { //魔术方法 自动加载类
        require "./$classname.class.php"; //将类名转化成小写
    }
    if (!empty($_GET['action'])) {
        //  echo "传送成功";
        $classname = ucfirst($_GET['action']);
        $shape = new $classname($_POST);
        $shape->view($_POST);
        if (isset($_POST['sub'])) {
            echo "<div id='footer'>";
            if($shape->name!='球体'){
                if ($shape->yan($_POST)) {
                    echo "<b>".$shape->name."的周长".$shape->zhou()."</b>"."<br>";
                    echo "<br>";
                    echo "<b>".$shape->name."的面积".$shape->area()."</b>"."<br>";
                }else {
                    echo "<b>错误：$shape->error</b>";
                }
                echo "</div>";
            }else{
                if ($shape->yan($_POST)) {
                    echo "<b>".$shape->name."的表面积".$shape->area()."</b>"."<br>";
                    echo "<br>";
                    echo "<b>".$shape->name."的体积".$shape->zhou()."</b>"."<br>";
                }else {
                    echo "<b>错误：$shape->error</b>";
                }
                echo "</div>";
            }
        }
    } else {
        echo "请选择一个图形";
    }
    ?>
</div>
</body>
</html>