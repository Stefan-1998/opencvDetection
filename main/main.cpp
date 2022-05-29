#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include "../lib/videoStream.hpp"
#include "../lib/personDetection.hpp"
#include "../lib/faceDetection.hpp"

using namespace cv;

int main()
{
    //Create Videostream
    VideoStream *vid;
    personDetection *personDetector;
    faceDetection *faceDetector;
    try{
        vid= new VideoStream();
        personDetector= new personDetection();
        faceDetector= new faceDetection();
    }
    catch(std::string e) {
        //if Videostream isn't created quit the application
        std::cout <<e<<std::endl; 
        return -1;
    }
    
    std::cout<<"Options\n";
    std::cout<<"VideoStream:"<<"\t\t"<<"1"<<'\n';
    std::cout<<"Persondetection:"<<"\t"<<"2"<<'\n';
    std::cout<<"Facedetection:"<<"\t"<<"3"<<'\n';
    std::cout<<"Quit:"<<"\t\t\t"<<"q";
    std::cout<<std::endl;
    
	std::vector<cv::Rect> detections;


    char lastPressedKey='1';

    bool loop=true;
    while(loop)
    {
        Mat picture=vid->getImage();
        
        switch(lastPressedKey)
        {
            case '2': personDetector->detect(&picture,&detections);break; 
            case '3': faceDetector->detect(&picture,&detections);break; 
        }
         
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
    delete personDetector;
    delete faceDetector;
    delete vid;


    return 0;
}
