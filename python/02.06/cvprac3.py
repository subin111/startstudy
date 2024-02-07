import cv2
import numpy as np


a = np.array([-3,-2,-1,0,1,254,255,256,257,258], dtype = np.uint8)
print(a)

#np.cilp(a,p,q)
#a <p => p
#a >q => q

b = [-3, -2, -1, 0, 1, 254,255,256,257,258 ]
print(b)
b = np.clip(b,0,255)
print(b)