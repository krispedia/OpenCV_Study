// point processing constant operation

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn = "/users/sujinlee/desktop/prac/prac/test.jpg";
    Mat img = imread(fn);
    Mat img_add, img_sub, img_mul, img_div, img_absdiff;
    
    add(img, Scalar(200, 200, 200), img_add);
    subtract(img, Scalar(200, 200, 200), img_sub);
    multiply(img, 20, img_mul);
    divide(img, 20, img_div);
    absdiff(img, Scalar(255, 255, 255), img_absdiff);
    
    imshow("img",img);
    imshow("img_add", img_add);
    imshow("img_sub", img_sub);
    imshow("img_mul", img_mul);
    imshow("img_div", img_div);
    imshow("img_diff", img_absdiff);
    
    waitKey(0);
    
    return 0;
}
