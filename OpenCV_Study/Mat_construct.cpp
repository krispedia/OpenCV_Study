
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    
    Mat mtx(3,3,CV_32F);               //3x3 matrix with 32bit(floating point)
    Mat cmtx(10,1,CV_64FC2);           //10x1 matrix 2-channel(floating point)
    Mat img(Size(5,3), CV_8UC3);       //3-channel image(color)
    
    Mat mtx2;
    mtx2 = Mat(3,3,CV_32F);
    Mat cmtx2;
    cmtx2 = Mat(10, 1, CV_64FC1);
    
    Mat *mtx3 = new Mat(3,3, CV_32F);
    delete mtx3;
    
    mtx.setTo(10);
    cout<<mtx<<endl;
    
    cmtx2.setTo(11);
    cout<<cmtx2<<endl;
    
    return 0;
}
