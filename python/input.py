#input的接收类型都是字符串类型，若要转换可以使用强制转换
name = input("请输入名字：")
age = input("请输入入职年龄：")
year = input("工作年限：")
print(name)
print("年龄为：")
print(int(age) + int(year))