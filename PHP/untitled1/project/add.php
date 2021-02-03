<?php
include ("conn.php");
$id = $_POST['id'];
$user = $_POST['user'];
$title = $_POST['title'];
$content = $_POST['content'];
if ($_POST['submit']){
    $sql = "insert into message(id,user,title,content,lastdate) values('','$user','$title','$content', now())";
    $result = mysqli_query($conn,$sql);
    if($result){
        echo "插入数据成功"."<br/>";
    }else{
        echo "插入数据失败"."<br/>";
    }
    // "<script>alert('提交成功');location.href = 'add.html'</script>";
}
?>
