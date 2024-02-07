import cv2
import sys


img = cv2.imread("D:/python/02.05/cat.bmp")

if img is None:
    sys.exit("파일을 찾을 수 없습니다.")

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
gray_small = cv2.resize(gray, dsize = (0,0), fx = 0.5, fy = 0.5)

cv2.imwrite("cat_gray.jpg", gray)
cv2.imwrite("cat_gray_small.jpg", gray_small)

cv2.imshow("COLOR", img)
cv2.imshow("GRAY", gray)
cv2.imshow("GRAY_SMALL", gray_small)

#print(type(img))
#print(img.shape)

#print(img[0,0,0],img[0,1,1], img[0,0,2])
#print("*"*80)
#cv2.imshow("window", img)

#print(img[0,1,0],img[0,1,1], img[0,1,2])
#print("*"*80)
cv2.waitKey()

cv2.destroyAllWindows()