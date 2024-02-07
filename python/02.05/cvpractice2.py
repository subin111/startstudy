import cv2
import sys
import numpy as np # hstack()

cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)

if not cap.isOpened():
    sys.exit("카메라 연결 실패")
    
frames = []
while True:
    ret, frame = cap.read()
    
    #비디오를 구성하는 프레임 획득
    
    if not ret:
        print("프레임 획득에 실패하여 루프를 나갑니다.")
        break
    
    cv2.imshow("Video Display", frame)
    
    key = cv2.waitKey(1)
    
    #c키가 입력되면 프레임을 리스트에 추가한다.
    if key == ord("c"):
        frames.append(frame)
    elif key == ord("q") or key == 27:
        break
        
cap.release()
cv2.destroyAllWindows()

#수집된 영상이 있을 때에만
if len(frames) > 0:
    imgs = frames[0]
    for i in range(1,min(3, len(frames))):
        imgs = np.hstack((imgs, frames[i]))
        #(480, 1920, 3)
        
    cv2.imshow("collected images", imgs)
    
    cv2.waitKey()
    cv2.destroyAllWindows()
        