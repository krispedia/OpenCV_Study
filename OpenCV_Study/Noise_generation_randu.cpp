// noise generation_randu

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    
    //
//    Mat Gaussian_noise = Mat(5,5,CV_8UC1);
//    randu(Gaussian_noise, 5, 10);
//    cout<< Gaussian_noise << endl;
    
    //gaussian noise
//    Mat Gaussian_noise = Mat(5,5,CV_32F);
//    randu(Gaussian_noise, 5, 10);
//    cout<< Gaussian_noise << endl;
    
    //gaussian noise
    Mat Gaussian_noise = Mat(5,5,CV_8SC1);
    randu(Gaussian_noise, 5, 10);
    cout<< Gaussian_noise << endl;
    
    return 0;
}
