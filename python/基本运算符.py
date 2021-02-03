#基本运算
a = 10
b = 20
#
# print(a + b)
# print(a - b)
# print(a * b)
# print(a / b)
#
# print(a // b) #计算商
# print(a % b)  #取余
#
# print(3**2) #次幂计算 3的2次方

#比较运算
# print(a > b)
# print(a < b)
# print(a == b)
# print (a != b)

#逻辑运算 与或非 都是布尔值
#优先级 not > and > or
# print(True and False)

#成员运算 in;not in
#让用户输入评论信息，需要过滤敏感词汇
#判断ing按此
content = input("请输入敏感词：")
if "黄赌毒" in content:
    print("含敏感词")
else:
    print("不含敏感词")