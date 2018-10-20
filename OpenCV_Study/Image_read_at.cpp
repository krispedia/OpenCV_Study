// image read by data

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn = "/users/sujinlee/desktop/prac/prac/test.jpg";
    Mat img = imread(fn, CV_LOAD_IMAGE_COLOR);
    
    cout<<"Element Size : "<< img.elemSize()<<endl;
    cout<<"Channels     : "<< img.channels()<<endl;       //channels - r?g?b?å
    cout<<"Rows         : "<< img.rows<<endl;
    cout<<"Steps        : "<< img.step<<endl;
    
    //using at
    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){
            
            //Vec3b means 'uchar 3channel' ... more options
            unsigned char b = img.at< cv::Vec3b>(i,j)[0];
            unsigned char g = img.at< cv::Vec3b>(i,j)[1];
            unsigned char r = img.at< cv::Vec3b>(i,j)[2];
            
            img.at< cv::Vec3b>(i,j)[0] = (unsigned char)(255-b);
            img.at< cv::Vec3b>(i,j)[1] = (unsigned char)(255-g);
            img.at< cv::Vec3b>(i,j)[2] = (unsigned char)(255-r);
        }
    }
    
    imshow("img", img);
    waitKey(0);
}
