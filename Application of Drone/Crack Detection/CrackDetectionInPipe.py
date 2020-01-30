'''/*
*
* Project Name:   A.Q.U.A Drone
* Author List:    Sudharsanan J, Harish N.
* Filename:     CrackDetectionInPipe.py
* Functions:    None
* Global Variables: video, pipe_dia, x, concat_img, img, dimension, k, gray,
*                   thresh, contour, contour_length, y_text, area. 
*
*/'''
import cv2
import numpy as np
#480 640 is the image size
video = cv2.VideoCapture(0) #Capturing image from the camera in the drone
video.set(cv2.CAP_PROP_FPS, 20) #Setting the frame rate at 20fps
pipe_dia = input('Enter the diameter of the pipe (in mm): ') #Accepting the underwater pipeline's diameter in mm
x=250 #intial position of the size of pipe (Blue Line)
ret, concat_img = video.read() #Reading the image from the video
while 1:
    ret, img = video.read()
    dimension = img.shape
    cv2.line(img,(320-x,0),(320-x,480),(255,150,0),2) #Drawing the lines as border
    cv2.line(img,(320+x,0),(320+x,480),(255,150,0),2)
    cv2.imshow('img',img) #Display the image
    k = cv2.waitKey(30)
    if k == 27: 
        break
    if k == 97: #Change the position of the line according the the input from the user
        x = x-5
    if k == 100:
        x = x+5
    if k == 32: #Start the crack detection in the pipe
        print('Space is pressed')
        break

cv2.destroyAllWindows()

while 1:
    ret, img = video.read()
    cv2.line(img,(320-x,0),(320-x,480),(255,150,0),2)
    cv2.line(img,(320+x,0),(320+x,480),(255,150,0),2)
    k = cv2.waitKey(30)
    if k == 27: #Exit from the program if ESC is pressed
        break
    concat_img = img[0:480,322-x:318+x] #extract the required image from the video
    k = cv2.waitKey(30)
    gray = cv2.cvtColor(concat_img, cv2.COLOR_BGR2GRAY) #Convert into black and white image
    cv2.imshow('img1',gray)
    ret,thresh = cv2.threshold(gray,127,255,0)  #Camera #Set a threshold for the black and white conversion
    #ret,thresh = cv2.threshold(gray,127,255,0)  #Webcamera
    thresh = cv2.bitwise_not(thresh)
    cv2.imshow('Threshold',thresh)
    contours, hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE) #Identify the contours in the image
    contour_length = len(contours) #Find the number of contours
    img = cv2.drawContours(img, contours, -1, (0,255,0), 3) #Draw the contours to show the Crack in Image
    y_text=30 #Print the area of the Contour
    area = 0.0
    for i in range(0,contour_length):
        area = cv2.contourArea(contours[i]) #Calculate the area of the contour in pixels
        area = area*float(pipe_dia)*float(pipe_dia)/(4*float(x*x)) #Convert the area of contours from pixels to milli meter square
        cv2.putText(img,str(area),(400,y_text),cv2.FONT_HERSHEY_SIMPLEX,1,(255,255,0),2) #Display the area
        y_text = y_text +207

    print(area,'sq.mm')
    cv2.imshow('Crack',img) #Show the crack in the image

video.release()
cv2.destroyAllWindows()
