#pragma once

#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <vector>

class IDetector
{
    public: 
        virtual ~IDetector() =default;
        virtual void detect(cv::Mat *picture,std::vector<cv::Rect>*detections)=0;

};
