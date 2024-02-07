lst = []

for i in range(1,1000):
    lst.append(i)
    
def add_multiple(lst):
    sum = 0
    for j in lst:
        if j % 3 == 0 or j % 5 == 0:
            sum += j
    return sum
    

sum = add_multiple(lst)
print(sum)