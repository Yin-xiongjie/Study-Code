# name = input("请输入名字：")
# age = input("请输入年龄：")
# job = input("请输入工作：")
# hobby = input("请输入爱好：")
#
# print("----------info of Sylar"+name+"-----------")
# print("Name:"+name)
# print("Age:"+ age)
# print("工作:"+job)
# print("爱好:"+hobby)
# print("----------end-----------")

#字符串的格式化
#老的格式化方案
# s ="""---------info of Sylar %s-----------
# Name:%s
# Age:%s
# 工作:%s
# 爱好:%s
# ----------end-----------
# """ %(name, name, age, job, hobby)
#print(s)

# 新的格式化方案 python3.5以上支持， f-string
name = "尹雄杰"
addr = "NBA"
hobby = "打篮球"

print(f"我叫{name},我喜欢在{addr}{hobby}")