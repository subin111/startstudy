class Mul:
  def __init__(self, m):
    self.m = m

  def mul(self, n):
    return self.m * n
    
if __name__ == "__main__":
    mul3 = Mul(3)
    mul5 = Mul(5)

    print(mul3.mul(10))
    print(mul5.mul(10))

# class Mul:
#   def __init__(self, m):
#     self.m = m
  
#   def __call__(self,n):
#     return self.m * n
    
# if __name__ == "__main__":
#     mul3 = Mul(3)
#     mul5 = Mul(5)

#     print(mul3(10))
#     print(mul5(10))