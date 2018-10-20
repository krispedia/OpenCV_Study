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
    
    //using data
    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){
            unsigned char r,g,b;
            
            b = img.data[i*img.step + j*img.elemSize() + 0];
            g = img.data[i*img.step + j*img.elemSize() + 1];
            r = img.data[i*img.step + j*img.elemSize() + 2];
            
            img.data[i*img.step + j*img.elemSize() + 0] = (unsigned char)(255-b);
            img.data[i*img.step + j*img.elemSize() + 1] = (unsigned char)(255-g);
            img.data[i*img.step + j*img.elemSize() + 2] = (unsigned char)(255-r);
        }
    }
    imshow("img", img);
    waitKey(0);
}
