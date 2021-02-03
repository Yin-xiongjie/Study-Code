##########重要###########
"""
1.upper() 把字符串中所有的字符变成大写，主要用在忽略大小写的地方
2.strip() 默认去掉左右两端的空白，包括\n和\t，空格
3.replace() 字符串替换
4.split() 字符串切割,得到字符串列表
5.startswith() 判断是否以xxx开头
6.find() 查找xxx
7.count() 数数，查看xxx出现的次数
8.isdigit() 判断该字符是否由数字组成
9.join() 把列表组合成一个字符串
"""

s = "我喜欢你"

for letter in s:
    print(f"当前字符：{letter}")
