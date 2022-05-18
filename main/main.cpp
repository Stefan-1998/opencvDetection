#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include "../lib/videoStream.hpp"

using namespace cv;

int main()
{
    VideoStream *vid;
    try{
     vid= new VideoStream();
    //VideoCapture captured;
    }
    catch(std::string e) {
        std::cout <<e<<std::endl; 
    }
    

   vid->showVideoSteam("Videostream");

    /*VideoCapture cap(0);

    if (!cap.isOpened()) {

        std::cout << "cannot open camera";

    }*/


    return 0;
}
