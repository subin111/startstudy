import cv2
import matplotlib.pyplot as plt

img = cv2.imread("D:/python/02.05/cat.bmp")


gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
plt.imshow(gray, cmap = "gray")
plt.xticks([])
plt.yticks([])
plt.show()

h = cv2.calcHist([gray],[0],None,[256],[0,256])
plt.plot(h,color = "r", linewidth = 1)
plt.show()

##

equal = cv2.equalizeHist(gray)
plt.imshow(equal, cmap = "gray")
plt.xticks([])
plt.yticks([])
plt.show()

h = cv2.calcHist([equal],[0],None,[256],[0,256])
plt.plot(h,color = "r", linewidth = 1)
plt.show()