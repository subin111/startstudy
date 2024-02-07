#빨간색 붓과 파란색 붓으로 페인팅하기
import cv2
import sys

img = cv2.imread("D:/python/02.05/cat.bmp")

if img is None:
    sys.exit("파일을 찾을 수 없습니다.")

#붓의 크기
BRUSH_SIZE  = 5
#파란색, 빨간색
LCOLOR, RCOLOR = (255,0,0), (0,0,255)
   
def painting(event, x, y, flags, param):
    
    
    if event == cv2.EVENT_LBUTTONDOWN:
        cv2.circle(img,(x,y), BRUSH_SIZE, LCOLOR, -1)
        #ix, iy = x, y
        #cv2.rectangle(img, (x,y), (x+200, y+200), (0,255,0),2)
    elif event == cv2.EVENT_RBUTTONDOWN:
        cv2.circle(img,(x,y), BRUSH_SIZE, RCOLOR, -1)
    elif event == cv2.EVENT_MOUSEMOVE and flags == cv2.EVENT_FLAG_LBUTTON:
        cv2.circle(img,(x,y), BRUSH_SIZE, LCOLOR, -1)
    elif event == cv2.EVENT_MOUSEMOVE and flags == cv2.EVENT_FLAG_RBUTTON:
        cv2.circle(img,(x,y), BRUSH_SIZE, RCOLOR, -1)
        
        
        
    cv2.imshow("paint", img)

cv2.namedWindow("Painting")
cv2.imshow("Painting", img)

cv2.setMouseCallback("Painting", painting)

while True:
    if cv2.waitKey(1) == ord("q"):
        cv2.destroyAllWindows()
        break