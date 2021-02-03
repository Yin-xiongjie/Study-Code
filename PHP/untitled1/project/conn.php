<?php
$conn = mysqli_connect("localhost", "root","yin52547", "bbs")or die("连接数据库失败！");
if($conn)
{
    echo '数据库连接成功！';
}
mysqli_select_db($conn, "bbs");
mysqli_query($conn,"set names 'utf8'"); //使用utf8进行中文编码
mysqli_set_charset($conn,'utf-8');
?>
