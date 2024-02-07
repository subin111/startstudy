num: int = 1 # num 변수가 int 형이라는 것을 명시함.

def add(a: int, b: int) -> int: #매개변수와 return 값에도 타입 명시.
  return a+b

result = add(3,4)
print(result)