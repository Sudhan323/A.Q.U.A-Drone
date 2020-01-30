'''/*
*
* Project Name:   A.Q.U.A Drone
* Author List:    Sudharsanan J, Manikandan A, Prithivirajan K
* Filename:     Fish_Detection.py
* Functions:    None
* Global Variables: fish_cascade, cap, fourcc, result_video, img, fishes
*
*/'''

import numpy as np
import cv2

#this is the cascade we just made using OpenCV in ubuntu.
fish_cascade = cv2.CascadeClassifier('cascade.xml')
#Read video from the sample ROV video
cap = cv2.VideoCapture("E:\_LABELED-FISHES-IN-THE-WILD\Test\Test_ROV_video_h264_decim.mp4")
cap.set(cv2.CAP_PROP_FPS, 10) #Set the FPS to 10
fourcc = cv2.VideoWriter_fourcc(*'mp4v') #Video format of output video
result_video = cv2.VideoWriter('video_Modified.mp4',fourcc,1,(1276,720)) #Video Dimension
while 1:
    ret, img = cap.read()
    # image, reject levels level weights.
    fishes = fish_cascade.detectMultiScale(img, 5, 5)
    
    #Draws Rectagle boxes around the identified fishes
    for (x,y,w,h) in fishes:
        if w>20 and h>20:
            cv2.rectangle(img,(x,y),(x+w,y+h),(255,255,0),2)

    cv2.imshow('img',img) #Display the image
    result_video.write(img) #Writes the image in output format
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

result_video.release()
cap.release()
cv2.destroyAllWindows()
