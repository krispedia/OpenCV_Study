// bitwise operation

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat circle1 = Mat(500, 1000, CV_8UC1);
    Mat circle2 = Mat(500, 1000, CV_8UC1);
    circle1.setTo(0);
    circle2.setTo(0);
    
    circle(circle1, Point(1000/5*2, 500/2), 250, CV_RGB(255, 255, 255), CV_FILLED);
    circle(circle2, Point(1000/5*3, 500/2), 250, CV_RGB(255, 255, 255), CV_FILLED);
    
    imshow("circle1", circle1);
    imshow("circle2", circle2);
    
    Mat res;
    bitwise_and(circle1, circle2, res); imshow("and", res);
    bitwise_or(circle1, circle2, res); imshow("or", res);
    bitwise_xor(circle1, circle2, res); imshow("xor", res);
    bitwise_not(circle1, res); imshow("not", res);
    
    waitKey(0);
    
    return 0;
}
