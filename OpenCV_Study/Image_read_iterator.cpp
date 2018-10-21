// image read by iterator

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
    
    //using iteration
    cv::MatIterator_<cv::Vec3b> itd = img.begin<cv::Vec3b>(), itd_end = img.end<cv::Vec3b>();
    
    //i count location
    for(int i=0; itd != itd_end; ++itd, ++i){
        cv::Vec3b bgr = (*itd);
        
        (*itd)[0] = 255-bgr[0];
        (*itd)[1] = 255-bgr[1];
        (*itd)[2] = 255-bgr[2];
    }
    
    imshow("img", img);
    waitKey(0);
}
