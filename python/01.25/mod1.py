def plus(n1,n2):
  return n1+n2

def minus(n1,n2):
  return n1-n2

#
if __name__ == "__main__": #처리해주면 모듈에서만 실행되고 불러올땐 안됨
  print(plus(1,4))##__name__ 에 mod1이 들어가게 됨. 그래서 구분 가능
  print(minus(4,2))
