#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include "../lib/videoStream.hpp"
#include "../lib/personDetection.hpp"

using namespace cv;

int main()
{
    //Create Videostream
    VideoStream *vid;
    try{
     vid= new VideoStream();
    }
    catch(std::string e) {
        //if Videostream isn't created quit the application
        std::cout <<e<<std::endl; 
        return -1;
    }
    
    
	std::vector<cv::Rect> detections;

    personDetection *detector= new personDetection();

    bool loop=true;
    while(loop)
    {
        Mat picture=vid->getImage();
        
        detector->detect(&picture,&detections);
         
        //goes through all Rectangles
        for(cv::Rect box : detections)
        {
            //draw squares in picture
            cv::rectangle(picture, box.tl(), box.br(), cv::Scalar(255, 0, 0), 2);
        }

        //delete detections after being drawn
        detections.clear();

        // Display picture
        cv::namedWindow("Picture");
        cv::imshow("Picture", picture);
        
        //apperently 1048689 is equal to q 
        //so q should quit the application
        char pressedKey=cv::pollKey();
        if(pressedKey=='q')
        { 
            //quit loop
            loop=false;
        }
        
    }

    //destroy all objects
    destroyAllWindows();
    delete detector;
    delete vid;


    return 0;
}
