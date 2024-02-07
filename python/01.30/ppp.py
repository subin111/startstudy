#IndexError
#list1 = [1,2,3,4,5,6]
#print(list1[6])

try:
    lst = [1,2,3,4,5]
    f = open('abc.txt', 'r')
    print(lst[5])
    print(lst[1]+lst[2])

except FileNotFoundError as e:
    print(e, end = '\n')
    print("해당 파일이 존재하지 않습니다.")
    
except IndexError as er:
    print(er,"인덱스 에러가 발생하였습니다.")  

else:
    print("코드 실행이 완료되었습니다.")
    
finally:
    f.close() #중간에 오류가 발생하여도 무조건 실행