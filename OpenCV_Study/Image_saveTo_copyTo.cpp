// image setTo copyTo

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn1 = "/users/sujinlee/desktop/prac/prac/test1.jpeg";
    Mat img1 = imread(fn1);
    
    resize(img1, img1, Size(500, 500));

    Mat img_mask_8 = Mat(img1.rows, img1.cols, CV_8UC1);
    img_mask_8.setTo(0);
    circle(img_mask_8, Point(625/5*2, 500/2), 250, CV_RGB(255, 255, 255), CV_FILLED);
    
    //img1 copy to img2
    Mat img2;
    img1.copyTo(img2, img_mask_8); imshow("img2", img2);
    
    //set Scalar(r,g,b) to mask white part
    img1.setTo(Scalar(0,50,255), img_mask_8); imshow("img1", img1);
    
    waitKey(0);
    
    return 0;
}
