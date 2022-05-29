#pragma once

#include "IDetector.hpp"
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <vector>
#include <iostream>


class eyeDetection:public IDetector
{
    public:
        eyeDetection();
        //needs a relative path
        eyeDetection(std::string xmlPath);

        ~eyeDetection();
        void detect(cv::Mat *picture,std::vector<cv::Rect>*detections) 
             override{detectEyes(picture,detections);};
    private:
        void detectEyes(cv::Mat *picture,std::vector<cv::Rect>*detections);
        cv::CascadeClassifier faceDetector;
        std::string defaultXmlPath="../../Library/opencv/data/haarcascades/haarcascade_eye.xml";
        
        

};

