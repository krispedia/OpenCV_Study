// image bitwise operation(Mask)

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn1 = "/users/sujinlee/desktop/prac/prac/test1.jpeg";
    Mat img1 = imread(fn1);
    
    resize(img1, img1, Size(500, 500));
    
    Mat img_mask = Mat(img1.rows, img1.cols, img1.type());
    img_mask.setTo(0);
    circle(img_mask, Point(625/5*2, 500/2), 250, CV_RGB(255, 255, 255), CV_FILLED);
    
    Mat res;
    bitwise_and(img1, img_mask, res); imshow("and", res);
    bitwise_or(img1, img_mask, res); imshow("or", res);
    bitwise_xor(img1, img_mask, res); imshow("xor", res);
    bitwise_not(img1, res); imshow("not", res);
    
    imshow("img_mask", img_mask);
    imshow("img", img1);
    waitKey(0);
    
    
    return 0;
}
