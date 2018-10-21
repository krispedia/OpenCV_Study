// image read by ptr

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
    
    //using ptr
    for (int i=0; i<img.rows;i++){
        cv::Vec3b* ptr = img.ptr<cv::Vec3b>(i);
        
        for(int j=0; j<img.cols; j++){
            
            unsigned char b1 = (ptr[j][0]);
            unsigned char g1 = (ptr[j][1]);
            unsigned char r1 = (ptr[j][2]);
            
            cv::Vec3b bgr = ptr[j];
            unsigned char b2 = (bgr[0]);
            unsigned char g2 = (bgr[1]);
            unsigned char r2 = (bgr[2]);
            
            ptr[j] = cv::Vec3b(255-b1, 255-g1, 255-r2);
        }
    }
    
    imshow("img", img);
    waitKey(0);
}
