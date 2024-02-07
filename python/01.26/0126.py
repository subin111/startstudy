# import os
# a = os.listdir('C:\doit')
# print(a)

# import glob
# a = glob.glob(r"C:\doit\*py")
# print(a)

# import time
# a = time.strftime('%y/%m/%d %H:%M:%S', time.localtime(time.time()))
# print(a)

# import os
# os.enviorn['PATH']
#os.chdir("C:\python\")

import zipfile
with zipfile.ZipFile('mytext.txt','w') as myzip:
    # myzip.write('a.txt')
    # myzip.write('b.txt')
    # myzip.write('c.txt')
    myzip.extractall()
    
with zipfile.ZipFile('mytext.zip') as myzip:
    myzip.extractall()