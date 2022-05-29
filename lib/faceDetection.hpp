#pragma once

#include "IDetector.hpp"
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <vector>
#include <iostream>


class faceDetection:public IDetector
{
    public:
        faceDetection();
        //needs a relative path
        faceDetection(std::string xmlPath);

        ~faceDetection();
        void detect(cv::Mat *picture,std::vector<cv::Rect>*detections) 
             override{detectFace(picture,detections);};
    private:
        void detectFace(cv::Mat *picture,std::vector<cv::Rect>*detections);
        cv::CascadeClassifier faceDetector;
        std::string defaultXmlPath="../../Library/opencv/data/haarcascades/haarcascade_frontalface_alt.xml";
        
        

};

