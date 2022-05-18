#include "../lib/videoStream.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

VideoStream::VideoStream()
{
    //values for selecting the default camera
    int deviceID=0;
    int apiID=CAP_ANY;
    
    //open and configure camera
    captureObject.open(deviceID,apiID);
    captureObject.isOpened();

    if(!captureObject.isOpened())
    {
        std::string message = "Could not open the camera";

        throw message;
    }
}

VideoStream::~VideoStream()
{

}
Mat VideoStream::getImage()
{
    //gets the current immage
    Mat image;
    captureObject >> image;
    return image;

}

void VideoStream::showVideoSteam(std::string windowName)
{
    std::cout<<"To Cancel press q"<<std::endl;
    namedWindow(windowName);

   while (true) {


        Mat image=getImage();
        imshow(windowName, image);

        char key=waitKey(25);
        if(key=='q')
        {
            break;
        }
    }
}


