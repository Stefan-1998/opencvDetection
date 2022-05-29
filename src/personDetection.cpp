#include "../lib/personDetection.hpp"
#include "../lib/IDetector.hpp"
#include <vector>


personDetection::personDetection()
{
    //set up hog Detector
	hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
}

personDetection::~personDetection()
{

}
void personDetection::detectPerson(cv::Mat* picture,std::vector<cv::Rect>*detections)
{

    //detect in picture
	hog.detectMultiScale(*picture, *detections, 0, cv::Size(8, 8), cv::Size(32, 32), 1.2, 2);
    for(cv::Rect box : *detections)
    {
        // resise the boxes
        box.x += cvRound(box.width*0.1);
        box.width = cvRound(box.width*0.8);
        box.y += cvRound(box.height*0.06);
        box.height = cvRound(box.height*0.8);

    }
}

