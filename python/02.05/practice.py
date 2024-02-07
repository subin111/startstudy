# import cv2 as cv
# import sys

# img1 = cv.imread("D:/python/02.05/cat.bmp")	# 영상 읽기
# img2 = cv.imread("D:/python/02.05/dog.bmp")
# if img1 is None or img2 is None:
#     sys.exit('파일을 찾을 수 없습니다.')
    
    
# cv.imshow('Image1 Display',img1)
# cv.imshow('Image2 Display',img2)# 윈도우에 영상 표시

# cv.waitKey()
# cv.destroyAllWindows()

# import cv2 as cv
# import sys

# img=cv.imread("D:/python/02.05/cat.bmp") 

# if img is None:
#     sys.exit('파일을 찾을 수 없습니다.')
# scales = list(map(lambda x: x * 0.1, range(1, 11)))
# gray=cv.cvtColor(img,cv.COLOR_BGR2GRAY)	# BGR 컬러 영상을 명암 영상으로 변환
# for scale in scales:
#     resized_img = cv.resize(img,None, fx = scale, fy = scale)
#     windowname = f'Scaled Image - {scale:.1f}'
#     cv.imshow(windowname, resized_img)

# cv.waitKey()
# cv.destroyAllWindows()

# import cv2 as cv
# import sys

# cap=cv.VideoCapture(0,cv.CAP_DSHOW)	# 카메라와 연결 시도

# if not cap.isOpened():
#     sys.exit('카메라 연결 실패')
    
# while True:
#     ret,frame=cap.read()			# 비디오를 구성하는 프레임 획득
    
#     if not ret:
#         print('프레임 획득에 실패하여 루프를 나갑니다.')
#         break
        
#     cv.imshow('Video display',frame)
#     key=cv.waitKey(1)	# 1밀리초 동안 키보드 입력 기다림
    
#     if key==ord('g'):
#         gray_frame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
#         cv.imshow('gray image', gray_frame)
        
#     elif key==ord('c'):
#         cv.imshow('color image', frame)

#     elif key==ord('q'):	# 'q' 키가 들어오면 루프를 빠져나감
#         break 
    
        
            
# cap.release()			# 카메라와 연결을 끊음
# cv.destroyAllWindows()

# import cv2 as cv
# import sys

# img=cv.imread('D:/python/02.05/cat.bmp')
# resized_img = cv.resize(img,None, fx = 2.0, fy = 1.5) 
  
# if img is None:
#     sys.exit('파일을 찾을 수 없습니다.')

# cv.rectangle(resized_img,(830,30),(1000,200),(0,0,255),2)	# 직사각형 그리기
# cv.putText(resized_img,'laugh',(830,300),cv.FONT_HERSHEY_SIMPLEX,1,(255,0,0),2)	# 글씨 쓰기

# cv.arrowedLine(resized_img, (870,275), (870,200), (0, 255, 0), 2, tipLength=0.2)
# cv.imshow('Draw',resized_img)

# cv.waitKey()
# cv.destroyAllWindows()


# import cv2 as cv
# import sys

# img=cv.imread('D:/python/02.05/cat.bmp') 
  
# if img is None:
#     sys.exit('파일을 찾을 수 없습니다.')
    
# def draw(event,x,y,flags,param):		# 콜백 함수
#     if event==cv.EVENT_LBUTTONDOWN:	# 마우스 왼쪽 버튼 클릭했을 때
#         cv.rectangle(img,(x,y),(x+200,y+100),(0,0,255),2)
#     elif event==cv.EVENT_RBUTTONDOWN:	# 마우스 오른쪽 버튼 클릭했을 때
#         cv.circle(img,(x,y), 10, (255,0,0), -1)
#         #cv2.circle(img,(x,y), 
        
#     cv.imshow('Drawing',img)          
    
# cv.namedWindow('Drawing')
# cv.imshow('Drawing',img)

# cv.setMouseCallback('Drawing',draw)	# Drawing 윈도우에 draw 콜백 함수 지정

# while(True):		# 마우스 이벤트가 언제 발생할지 모르므로 무한 반복
#     if cv.waitKey(1)==ord('q'):
#         cv.destroyAllWindows() 
#         break


# import cv2 as cv
# import sys

# img=cv.imread('D:/python/02.05/cat.bmp') 
  
# if img is None:
#     sys.exit('파일을 찾을 수 없습니다.')
    
# def draw(event,x,y,flags,param):
#     global ix,iy
#     global xx, yy
    
#     if event==cv.EVENT_LBUTTONDOWN:	# 마우스 왼쪽 버튼 클릭했을 때 초기 위치 저장
#         ix,iy=x,y
#     elif event==cv.EVENT_LBUTTONUP:	# 마우스 왼쪽 버튼 클릭했을 때 직사각형 그리기
#         cv.rectangle(img,(ix,iy),(x,y),(0,0,255),2)
#     elif event==cv.EVENT_RBUTTONDOWN:	
#         xx, yy = x, y
#     elif event==cv.EVENT_RBUTTONUP:	
#         cv.circle(img,(xx,yy),int(((xx-x)**2+(yy-y)**2)*(1/2)),(0,255,0),2)
    
#     cv.imshow('Drawing',img)
    
# cv.namedWindow('Drawing')
# cv.imshow('Drawing',img)

# cv.setMouseCallback('Drawing',draw)

# while(True):
#     if cv.waitKey(1)==ord('q'):
#         cv.destroyAllWindows()      
#         break


import cv2 as cv 
import sys

img=cv.imread('D:/python/02.05/cat.bmp')
if img is None:
    sys.exit('파일을 찾을 수 없습니다.')

BrushSiz=5					# 붓의 크기
LColor,RColor=(255,0,0),(0,0,255)		# 파란색과 빨간색

def painting(event,x,y,flags,param):
    if event==cv.EVENT_LBUTTONDOWN:   
        cv.circle(img,(x,y),BrushSiz,LColor,-1)# 마우스 왼쪽 버튼 클릭하면 파란색
    elif event==cv.EVENT_RBUTTONDOWN: 
        cv.circle(img,(x,y),BrushSiz,RColor,-1)# 마우스 오른쪽 버튼 클릭하면 빨간색
    elif event==cv.EVENT_MOUSEMOVE and flags==cv.EVENT_FLAG_LBUTTON:
        cv.circle(img,(x,y),BrushSiz,LColor,-1)# 왼쪽 버튼 클릭하고 이동하면 파란색
    elif event==cv.EVENT_MOUSEMOVE and flags==cv.EVENT_FLAG_RBUTTON:
        cv.circle(img,(x,y),BrushSiz,RColor,-1)# 오른쪽 버튼 클릭하고 이동하면 빨간색

    cv.imshow('Painting',img)		# 수정된 영상을 다시 그림

cv.namedWindow('Painting')
cv.imshow('Painting',img)
cv.setMouseCallback('Painting',painting)

while(True):
    if cv.waitKey(1) == ord('+'):
        BrushSiz += 1
    elif cv.waitKey(1) == ord('-'):
        BrushSiz -= 1
    elif cv.waitKey(1)==ord('q'):
        cv.destroyAllWindows()      
        break
    
    