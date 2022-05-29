#include "../lib/faceDetection.hpp"



faceDetection::faceDetection()
{
    
    if(!faceDetector.load(defaultXmlPath))
    {
        std::string message = "Could not load the XML FaceDetector";
        throw message;
    }
    
}
faceDetection::faceDetection(std::string xmlPath)
{
    if(!faceDetector.load(xmlPath))
    {
        std::string message = "Could not load the XML FaceDetector";
        throw message;
    }
}
faceDetection::~faceDetection()
{

}
void faceDetection::detectFace(cv::Mat *picture,std::vector<cv::Rect>*detections)
{
    cv::Mat grayPicture;
    cv::cvtColor(*picture, grayPicture, cv::COLOR_BGR2GRAY );
    cv::equalizeHist(grayPicture, grayPicture );
    faceDetector.detectMultiScale(grayPicture,*detections);
}
