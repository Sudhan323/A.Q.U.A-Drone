import cv2
import numpy as np
#480 640
video = cv2.VideoCapture(0)
pipe_dia = input('Enter the diameter of the pipe (in mm): ')
x=250
ret, concat_img = video.read()
while 1:
    ret, img = video.read()
    dimension = img.shape
    cv2.line(img,(320-x,0),(320-x,480),(255,150,0),2)
    cv2.line(img,(320+x,0),(320+x,480),(255,150,0),2)
    cv2.imshow('img',img)
    k = cv2.waitKey(30)
    if k == 27: 
        break
    if k == 97:
        x = x-5
    if k == 100:
        x = x+5
    if k == 32:
        concat_img = img[0:480,322-x:318+x]
        k = cv2.waitKey(30)
        gray = cv2.cvtColor(concat_img, cv2.COLOR_BGR2GRAY)
        cv2.imshow('img1',gray)
        ret,thresh = cv2.threshold(gray,127,255,0)
        thresh = cv2.bitwise_not(thresh)
        cv2.imshow('Threshold',thresh)
        contours, hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
        img = cv2.drawContours(img, contours, 0, (0,255,0), 3)
        cv2.imshow('contour',img)
        area = cv2.contourArea(contours[0])
        area = area*float(pipe_dia)*float(pipe_dia)/(4*float(x*x))
        print(area,'sq.mm')

cv2.destroyAllWindows()
print('Enter Pressed')

'''while 1:
    cv2.line(img,(320-x,0),(320-x,480),(255,150,0),2)
    cv2.line(img,(320+x,0),(320+x,480),(255,150,0),2)
    concat_img = concat_img[0:480,320-x:320+x]
    cv2.imshow('img',concat_img)
    k = cv2.waitKey(30)
    gray = cv2.cvtColor(concat_img, cv2.COLOR_BGR2GRAY)
    ret,thresh = cv2.threshold(gray,127,255,0)
    contours, hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    img = cv2.drawContours(img, contours, -1, (0,255,0), 3)
    if k == 27: 
        break
'''

video.release()
cv2.destroyAllWindows()