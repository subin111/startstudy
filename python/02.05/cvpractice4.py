import cv2
import sys

img = cv2.imread("D:/python/02.05/cat.bmp")

if img is None:
    sys.exit("파일을 찾을 수 없습니다.")
    
def draw(event, x, y, flags, param):
    global ix, iy
    
    if event == cv2.EVENT_LBUTTONDOWN:
        ix, iy = x, y
        #cv2.rectangle(img, (x,y), (x+200, y+200), (0,255,0),2)
    elif event == cv2.EVENT_LBUTTONUP:
        cv2.rectangle(img, (ix,iy), (x, y), (255, 0, 0), 2)
        
    cv2.imshow("draw", img)

cv2.namedWindow("Drawwing")
cv2.imshow("Drawing", img)

cv2.setMouseCallback("Drawing", draw)

while True:
    if cv2.waitKey(1) == ord("q"):
        cv2.destroyAllWindows()
        break