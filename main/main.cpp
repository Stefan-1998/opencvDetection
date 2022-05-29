#include <memory>
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include "../lib/videoStream.hpp"
#include "../lib/personDetection.hpp"
#include "../lib/faceDetection.hpp"
#include "../lib/eyeDetection.hpp"
#include "memory"

using namespace cv;

int main()
{
    /*
        For the detection, are .xml Files used, which come with
        the opencv repo undar data haarcascades. To load those file
        a relativ path is needed. Also the results aren't that good
        yet. With those files other detections are possible.
        Just check which .xml files are availible
        
        */

    //Create Videostream
    std::unique_ptr<VideoStream> vid;
    std::unique_ptr<IDetector>personDetector;
    std::unique_ptr<IDetector>faceDetector;
    std::unique_ptr<IDetector>eyeDetector;

    try{
        vid= std::make_unique<VideoStream>();
        personDetector=std::make_unique<personDetection>();
        faceDetector=std::make_unique<faceDetection>();
        eyeDetector=std::make_unique<eyeDetection>();
    }
    catch(std::string e) {
        //if Videostream isn't created quit the application
        //or if one detector is not there
        std::cout <<e<<std::endl; 
        return -1;
    }

    //Display Options
    std::cout<<"Options\n";
    std::cout<<"VideoStream:"<<"\t\t"<<"1"<<'\n';
    std::cout<<"Persondetection:"<<"\t"<<"2"<<'\n';
    std::cout<<"Facedetection:"<<"\t\t"<<"3"<<'\n';
    std::cout<<"Eyedetection:"<<"\t\t"<<"4"<<'\n';
    std::cout<<"Quit:"<<"\t\t\t"<<"q";
    std::cout<<std::endl;
    
	std::vector<cv::Rect> detections;


    char lastPressedKey='1';
    int frameNumber=0;

    bool loop=true;
    while(loop)
    {
        Mat picture=vid->getImage();
        
        if(frameNumber>5)
        {
            //delete detections after being drawn
            detections.clear();

            //Switch between the detections
            switch(lastPressedKey)
            {
                case '2': personDetector->detect(&picture,&detections);break; 
                case '3': faceDetector->detect(&picture,&detections);break; 
                case '4': eyeDetector->detect(&picture,&detections);break; 
                defauld: break;
            }
             


            frameNumber=0;
        }
        else
        {
            frameNumber++;
        }

        //goes through all Rectangles
        for(cv::Rect box : detections)
        {
            //draw squares in picture
            cv::rectangle(picture, box.tl(), box.br(), cv::Scalar(255, 0, 0), 2);
        }
        
        // Display picture
        cv::namedWindow("Picture");
        cv::imshow("Picture", picture);
        
        //so q should quit the application
        int pressedKey=cv::pollKey();
        if(pressedKey!=-1)
        {
            lastPressedKey=(char)pressedKey;
        }
        if(lastPressedKey=='q')
        { 
            //quit loop
            loop=false;
        }
        
        
    }

    //destroy all objects
    destroyAllWindows();
    return 0;
}
