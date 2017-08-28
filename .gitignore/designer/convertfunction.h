#ifndef CONVERTFUNCTION
#define CONVERTFUNCTION

#include <QImage>
//#include </home/dima/Desktop/openCV/include/opencv2/opencv.hpp>
#include </home/dima/Desktop/openCV/modules/highgui/include/opencv2/highgui/highgui_c.h>


cv::Mat qImageToMat(const QImage& img);

QImage matToQImage(const cv::Mat& img);

#endif // CONVERTFUNCTION

