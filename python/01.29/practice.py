# 코드 적는 곳

data = """
1 0 4 2
8 3 9 4
2 3 5 7
4 6 7 8
3 1 6 5
1 8 4 10
7 2 9 5
8 8 10 9
1 4 2 6
"""
a = []
b = []
x0 = []
y0 = []
x1 = []
y1 = []
sum1 = 0
sum2 = 0
totalsum = 0

def process_input(data):
    rows = data.strip().split('\n')
    lst = [list(map(int, row.split())) for row in rows]
    return lst

lst = process_input(data)

def area(i):
  return abs(x0[i]-x1[i]) * abs(y0[i]-y1[i])


# row = lst[0]
# print(row)
# print(row[0])

print(lst)

      
for i in range(0,len(lst)):
  
  x0.append(lst[i][0])
  y0.append(lst[i][1])
  x1.append(lst[i][2])
  y1.append(lst[i][3])
  
  large = area(i)
  sum1 += large
  a.append(large)
  
for i in range(len(lst)):
    for j in range(i + 1, len(lst)):
        overlap_x = max(0, min(x1[i], x1[j]) - max(x0[i], x0[j]))
        overlap_y = max(0, min(y1[i], y1[j]) - max(y0[i], y0[j]))
        s = overlap_x * overlap_y
        sum2 += s
        b.append(s)
  
totalsum = sum1 - sum2
print(sum1)
print(sum2)
print(totalsum)
print(len(a))
print(b)