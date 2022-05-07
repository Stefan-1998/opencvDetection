#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../lib/videoStream.hpp"

using namespace cv;

int main()
{
    try{
    VideoStream *vid= new VideoStream();
    }
    catch(std::string e) {
        std::cout <<e<<std::endl; 
    }
    VideoCapture cap;
    cap.open(0,0);
    /*Mat image;

    namedWindow("Display window");

    VideoCapture cap(0);

    if (!cap.isOpened()) {

        std::cout << "cannot open camera";

    }

    while (true) {

        cap >> image;

        imshow("Display window", image);

        char key=waitKey(25);
        if(key=='q')
        {
            break;
        }
    }*/

    return 0;
}
