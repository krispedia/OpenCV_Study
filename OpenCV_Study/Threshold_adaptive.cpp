//threshold_adaptive
// c++: void adaptiveTreshold(inputArray src, OutputArray dst, double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double C);

#include <time.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn1 = "/users/sujinlee/desktop/prac/prac/photo.jpeg";
    Mat img = imread(fn1);
    
    if(!img.data){
        cout<<"File Not Found"<<endl;
        return -1;
    }
    //    resize(img, img, Size(500, 500));
    
    namedWindow("img", 0);
    namedWindow("threshold", 0);
    namedWindow("mena_thres", 0);
    namedWindow("gauss_thres", 0);
    
    Mat gray, binary, binary1, binary2;
    cvtColor(img, gray, CV_RGB2GRAY);
    
    threshold(gray, binary, 128, 255, CV_THRESH_BINARY);
    adaptiveThreshold(gray, binary1, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, 5);
    adaptiveThreshold(gray, binary2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 15, 5);
    
    imshow("img", img);
    imshow("threshold", binary);
    imshow("mean_thres", binary1);
    imshow("gauss_thres", binary2);
    
    waitKey(0);
    
    return 0;
}
