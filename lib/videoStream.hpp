#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

class VideoStream
{
    public:
        VideoStream ();
        Mat getImage();
    private:
        VideoCapture capture;

};

