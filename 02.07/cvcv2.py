import cv2 as cv

img=cv.imread('02.07/mot_color70.jpg')# 영상 읽기
#gray=cv.cvtColor(img,cv.COLOR_BGR2GRAY)

#sift=cv.SIFT_create()
sift=cv.SIFT_create(nfeatures = 2000) #신뢰도가 높은 500개의 특징점

#매개변수 
#nfeatures: 검출할 특징점 개수
#기본값 0: 검출한 특징점 모두 반환
#nOctavelayers: 옥타브 개수를 지정
#contrastThreshold: 테일러 확장
#edgeThresHold: 에지에서 검출된 특징점을 걸러냄
#sigma: 옥타브 0의 입력 영상에 적용할 가우시안의 표준편차

#cv2.CIFT_create(nfeatures = 0, nOctavaLayers = 3, contrastThreshold = 0.04,
# edgeThresHold = 10, sigma = 1.6)

kp, des = sift.detectAndCompute(img,None)
#특징점 kp, 기술자 des
#kp = sift.detect(gray, None)
#des = sift.compute(gray, kp)

print(len(kp))
gray=cv.drawKeypoints(img,kp,None, flags=cv.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
cv.imshow('sift', gray)

k=cv.waitKey()
cv.destroyAllWindows()

