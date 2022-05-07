#include "../lib/videoStream.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;

VideoStream::VideoStream()
{
    int deviceID=0;
    int apiID=CAP_ANY;
    capture.open(deviceID,apiID);

    if(!capture.isOpened())
    {
        std::string message = "Could not open the camera";

        throw message;
    }
}



