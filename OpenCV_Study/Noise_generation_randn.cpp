// noise generation_randn

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    
    //5x5 unsigned char 1channel
    //    Mat Gaussian_noise = Mat(5,5,CV_8UC1);
    //    double mean = 0;
    //    double std = 10;
    //    randn(Gaussian_noise, mean, std);
    //    cout<< Gaussian_noise << endl;
    
    //5x5 signed char 1channel
    //    Mat Gaussian_noise = Mat(5,5,CV_8SC1);
    //    double mean = 0;
    //    double std = 10;
    //    randn(Gaussian_noise, mean, std);
    //    cout<< Gaussian_noise << endl;
    
    //5x5 32 FLOAT
    Mat Gaussian_noise = Mat(5,5,CV_32F);
    double mean = 0;
    double std = 10;
    randn(Gaussian_noise, mean, std);
    cout<< Gaussian_noise << endl;
    
    return 0;
}
