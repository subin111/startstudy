import cv2
import matplotlib.pyplot as plt
import numpy as np

img = cv2.imread("D:/python/02.06/dog.bmp")
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

plt.subplot(2,2,1)
plt.imshow(gray, cmap = "gray")
plt.xticks([])
plt.yticks([])
#plt.show()

plt.subplot(2,2,2)
h = cv2.calcHist([gray],[0],None,[256],[0,256])
plt.plot(h,color = "b", linewidth = 1)
#plt.show()

plt.subplot(2,2,3)
equal = cv2.equalizeHist(gray)
plt.imshow(equal, cmap = "gray")
plt.xticks([])
plt.yticks([])
#plt.show()

plt.subplot(2,2,4)
h = cv2.calcHist([equal],[0],None,[256],[0,256])
plt.plot(h, color = "b", linewidth = 1)
plt.show()

#퀴즈:동시에 보고 싶으면?

