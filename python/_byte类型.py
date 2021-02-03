# s = "大中国"
# #编码
# bs = s.encode("utf-8")
# print(bs)  #输出bytes b'\xe5\xa4\xa7\xe4\xb8\xad\xe5\x9b\xbd'
# bs = b'\xe5\xa4\xa7\xe4\xb8\xad\xe5\x9b\xbd'
# print( type(bs))
#
# s = "中国"
# print(s.encode("gbk"))


#babytes转化为字符串
#decode()解码
bs = b'\xd6\xd0\xb9\xfa'
s = bs.decode("gbk")
print(s)