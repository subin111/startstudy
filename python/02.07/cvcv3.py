# FLANN 라이브러리를 이용한 SIFT 매칭
import cv2
import numpy as np
import time

img1=cv2.imread('02.07/mot_color70.jpg')[190:350,440:560] # 버스를 크롭하여 모델 영상으로 사용
gray1=cv2.cvtColor(img1,cv2.COLOR_BGR2GRAY)
img2=cv2.imread('02.07/mot_color83.jpg')  # 장면 영상
gray2=cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)

sift=cv2.SIFT_create()
kp1,des1=sift.detectAndCompute(gray1,None)
kp2,des2=sift.detectAndCompute(gray2,None)
print('특징점 개수:', len(kp1), len(kp2))

start=time.time()
flann_matcher=cv2.DescriptorMatcher_create(cv2.DescriptorMatcher_FLANNBASED)
knn_match=flann_matcher.knnMatch(des1,des2,2)

T=0.7
good_match=[]
for nearest1,nearest2 in knn_match:# 식 5.14의 최근접 이웃 거리 비율 적용
    if (nearest1.distance/nearest2.distance)<T:
        good_match.append(nearest1)
print('매칭에 걸린 시간:',time.time()-start) 

img_match=np.empty((max(img1.shape[0],img2.shape[0]),img1.shape[1]+img2.shape[1],3),dtype=np.uint8)
cv2.drawMatches(img1,kp1,img2,kp2,good_match,img_match,flags=cv2.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)

cv2.imshow('Good Matches', img_match)

k=cv2.waitKey()
cv2.destroyAllWindows()