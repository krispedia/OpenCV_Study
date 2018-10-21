// image split 3channel

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
    
    vector<Mat> rgbMat(3);
    split(img, rgbMat);
    
    imshow("r", rgbMat[2]);
    imshow("g", rgbMat[1]);
    imshow("b", rgbMat[0]);
    
    imshow("img", img);
    waitKey(0);
    destroyAllWindows();
    
    return 0;
}
