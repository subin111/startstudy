import cv2
import sys
img = cv2.imread("D:/python/02.05/cat.bmp")

if img is None:
    sys.exit("파일을 찾을 수 없습니다.")
    
img = cv2.imread("D:/python/02.05/cat.bmp")
#직사각형 그리는 곳, (좌상단), (우하단), (BGR), 선 두께
cv2.rectangle(img, (830, 30), (1000, 200), (0,0,255), 2) 
#글씨 쓰는 곳, 텍스트, 위치, 폰트, (BGR), 선 두께
cv2.putText(img, "thebest",( 830, 24), cv2.FONT_HERSHEY_SIMPLEX, 1, (255,0,0),2)

cv2.imshow("Draw", img)
cv2.waitKey(5000)
cv2.destroyAllWindows()
        