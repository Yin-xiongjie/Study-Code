<?php
if(trim($_POST['password']) != trim($_POST['repassword'])){
    exit('两次密码不一致，请返回上一一级');
}
$username = trim($_POST['username']);
$password = md5(trim($_POST['password']));
$time = time();
$ip = $_SERVER['REMOTE_ADDR'];
//echo $username.'-'.$password.'-'.time;

$conn = mysqli_connect('localhost', 'root', 'yin52547', 'shuju');
if(mysqli_errno($conn)){
    echo mysqli_error($conn);
    exit;
}
mysqli_select_db($conn, shuju);
mysqli_set_charset($conn, 'utf-8');
$sql = "insert into user(username, password, creattime, createip) values($username, $p, $time, $ip)";
$result = mysqli_query($conn, $sql);
if($result){
    echo '成功';
}else{
    echo '失败';
}

echo '当前用户插入的ID为：'.mysqli_insert_id($conn);
mysqli_close($conn);
?>