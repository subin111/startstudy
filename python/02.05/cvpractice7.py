
import cv2
import matplotlib.pyplot as plt
import sys

img = cv2.imread("D:/python/02.05/cat.bmp")
h = cv2.calcHist([img],[2], None, [256], [0,256])

#영상, 채널 번호bgr로 2면 green, 전체 영상에서 histogram 구함, 
plt.plot(h, color = 'r', linewidth = 1)
plt.show()

if img is None:
    sys.exit("파일을 찾을 수 없습니다.")

while True:
    if cv2.waitKey(1) == ord("q"):
        cv2.destroyAllWindows()
        break