<?php
class Demo1
{
    public  $name = 'php'; //pulic公有属性，外部可访问
    private $age = 20;     //private私有属性，只允许在类中调用
    protected  $sex = 'male'; //protected,仅允许在本类或者子类访问

    public function  getName()
    {
        return $this->name;
    }
    public function  getAge()
    {
        return $this->age;
    }
    public function  getSex()
    {
        return $this->sex;
    }
}
?>