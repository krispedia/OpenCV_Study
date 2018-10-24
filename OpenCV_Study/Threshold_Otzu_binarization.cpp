//otzu_binarization
//when we need to calculate threshold automatically
//threshold(Mat, 0, 255, THRESH_BINARY+THRESH_OTSU)

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
    namedWindow("binary", 0);
    namedWindow("binary_th", 0);
    namedWindow("binary_ad", 0);
    
    Mat gray, binary, binary_th, binary_ad;
    cvtColor(img, gray, CV_RGB2GRAY);
    
    threshold(gray, binary_th, 128, 255, CV_THRESH_BINARY);
    adaptiveThreshold(gray, binary_ad, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, 5);
    GaussianBlur(gray, gray, Size(7,7), 0);
    threshold(gray, binary, 0, 255, CV_THRESH_BINARY+THRESH_OTSU);
    
    imshow("img", img);
    imshow("binary", binary);
    imshow("binary_th", binary_th);
    imshow("binary_ad", binary_ad);
    
    waitKey(0);
    
    return 0;
}
