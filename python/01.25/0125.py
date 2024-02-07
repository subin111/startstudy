class Bird:
  def fly(self):
    raise NotImplementedError

class Eagle(Bird):
  def fly(self):
    print("잘 난다~")
eagle = Eagle()
eagle.fly()

# try:
#     age = int(input("나이를 입력하세요: "))
# except:
#     print("입력이 정확하지 않습니다.")
# else: 
#     if age >= 18:
#         print("환영합니다.")
#     else:
#         print("미성년자입니다.")
# try:
#     4/0
#     a = [1,2]
#     print(a[3])
    
# except (ZeroDivisionError, IndexError) as e:
#     print(e)


# try:
#    4/0
# except ZeroDivisionError as e:
#      print(e)
    
    
# try:
#     with open('D:\python\01.25\단문2','w') as f:
#         data = "\n안녕 파이썬"
#         f.write(data)
        
# finally:
#     f.close()
  
#f = open('나없는파일','w')
#4/0
# lst = [1,2,3]
# print(lst[3])