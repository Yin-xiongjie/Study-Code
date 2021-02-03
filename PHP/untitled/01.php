<html>
<head
    <title>尹雄杰's超级无敌计算器</title>
</head>
<body>
<?php
$num1 = '';
$num2 = '';
$sigal = '';
$sum = '';
if(!empty($_POST)){
    $num1 = $_POST['num1'];
    $num2 = $_POST['num2'];
    $sigal = $_POST['sigal'];
    switch ($sigal){
        case '+':
            $sum = $num1 + $num2;
            break;
        case '-':
            $sum = $num1 -$num2;
            break;
        case '*':
            $sum = $num1 * $num2;
            break;
        case '/':
            $sum = $num1 / $num2;
            break;
        case '%':
            $sum = $num1 % $num2;
            break;
        default:
            echo '计算出现错误'.'<br>';
    }
}
?>
<form method = "post" action=" ">
    <input type = "text" name = "num1" value = "<?php echo $num1?>">
    <select name = "sigal">
        <option value = "+" <?php echo $sigal == '+'?'selected':''?>>+</option>
        <option value = "-" <?php echo $sigal == '-'?'selected':''?>>-</option>
        <option value = "*" <?php echo $sigal == '*'?'selected':''?>>*</option>
        <option value = "/" <?php echo $sigal == '/'?'selected':''?>>/</option>
        <option value = "%" <?php echo $sigal == '%'?'selected':''?>>%</option>
    </select>
    <input type = "text" name = "num2" value = "<?php echo $num2?>">
    =
    <input type = "text" username = "sum" value = "<?php echo $sum?>"><br><br>
    <input type = "submit" value = "计算">
</form>
</body>
</html>