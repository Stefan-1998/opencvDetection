#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

class VideoStream
{
    public:
        VideoStream ();
        ~VideoStream ();
        Mat getImage();

        //to cancel press q
        void showVideoSteam(std::string windowName);

    private:
         VideoCapture captureObject;
         

};

