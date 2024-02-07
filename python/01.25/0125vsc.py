import sys
result = 0
args = sys.argv[1:]
for i in args:
  result += int(i)
print(result)