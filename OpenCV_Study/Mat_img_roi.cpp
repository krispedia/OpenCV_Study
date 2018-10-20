// Mat img roi(copy)

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn = "/users/sujinlee/desktop/prac/prac/test.jpg";
    namedWindow("img",0);
    
    Mat img = imread(fn, CV_LOAD_IMAGE_COLOR);
    
    if(!img.data){
        cout<<"File Not Found"<<endl;
        return -1;
    }
    
    Rect r(img.cols/4, img.rows/4, img.cols/4*2, img.rows/4*2);
    
    //roi ref img.. so connected
    Mat roi(img, r);
    bitwise_not(roi, roi);
    imshow("rio", roi);
    imshow("img", img);
    
    waitKey(0);
    
    return 0;
}
