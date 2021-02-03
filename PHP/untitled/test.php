<?php
$sql = "insert into user(name, age, salary) values('张飞', 25, 3000), ('关羽', 30, 4000)";
$con = mysqli_connect("localhost", "root","yin52547",'shuju');
if(!$con)
{
    die('could not connect:'. mysqli_connect_errno($con));
}
echo "连接成功".'<br/>';
mysqli_select_db($con,'shuju');
//mysqli_set_charset("utf8");
$result = mysqli_query($con,$sql);
if($result)
{
    echo "插入数据成功"."<br/>";
    $return_result = mysqli_close($con);
    if($return_result){
        echo '数据库关闭成功'."<br>";
    }else{
        echo '数据库打开失败'.'<br>';
    }
}else{
    echo "数据插入失败"."<br/>";
}

?>