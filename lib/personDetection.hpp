#pragma once

#include "IDetector.hpp"
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <vector>


class personDetection:public IDetector
{
    public:
        personDetection();

        ~personDetection();
        void detect(cv::Mat *picture,std::vector<cv::Rect>*detections) 
             override{detectPerson(picture,detections);};
    private:
        void detectPerson(cv::Mat *picture,std::vector<cv::Rect>*detections);
        
        cv::HOGDescriptor hog;

};

