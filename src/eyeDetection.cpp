#include "../lib/eyeDetection.hpp"



eyeDetection::eyeDetection()
{
        
    if(!faceDetector.load(defaultXmlPath))
    {
        std::string message = "Could not load the XML FaceDetector";
        throw message;
    }
    
}
eyeDetection::eyeDetection(std::string xmlPath)
{
    if(!faceDetector.load(xmlPath))
    {
        std::string message = "Could not load the XML FaceDetector";
        throw message;
    }
}
eyeDetection::~eyeDetection()
{

}
void eyeDetection::detectEyes(cv::Mat *picture,std::vector<cv::Rect>*detections)
{
    cv::Mat grayPicture;
    cv::cvtColor(*picture, grayPicture, cv::COLOR_BGR2GRAY );
    cv::equalizeHist(grayPicture, grayPicture );
    faceDetector.detectMultiScale(grayPicture,*detections);
}
