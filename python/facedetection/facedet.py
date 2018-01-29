#-*- coding:UTF-8 -*-
import sys
import numpy as np
import dlib
import cv2

def rect_to_bb(rect):
    x=rect.left()
    y=rect.top()
    w=rect.right()-x
    h=rect.bottom()-y
    return (x,y,w,h)


def shape_to_np(shape,dtype="int"):
    coords=np.zeros((68,2),dtype=dtype)
    for i in range(0,68):
        coords[i]=(shape.part(i).x,shape.part(i).y)
    return coords

def resize(image,width=1200):
    r =width*1.0/image.shape[1]
    dim=(width,int(image.shape[0]*r))
    resized=cv2.resize(image,dim,interpolation=cv2.INTER_AREA)
    return resized


if __name__=="__main__":
    print(start)
