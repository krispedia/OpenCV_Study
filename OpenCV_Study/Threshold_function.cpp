// threshold
// binary = 2개의 색상(2진화 된 영상)
//histogram = 영상의 밝기 값을 빈도수로 나타낸 것
//ex) 100의 값이 몇개가 있는지 측정(voting이라 불림)
//threashold는 영상에서 값을 색을 두가지로 나눌 임계값
//하나의 threashold 값으로 영상을 2진화 하기는 어려운 경우가 많음.
// c++: double threshold(InputArray src, OutputArray dst, double thresh, double maxcal, int type)

#include <time.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn1 = "/users/sujinlee/desktop/prac/prac/photo.jpeg";
    Mat img = imread(fn1);
    
    if(!img.data){
        cout<<"File Not Found"<<endl;
        return -1;
    }
    //    resize(img, img, Size(500, 500));
    
    Mat gray, binary;
    cvtColor(img, gray, CV_RGB2GRAY);
    threshold(gray, binary, 128, 255, CV_THRESH_BINARY);
    
    imshow("img", img);
    imshow("binary", binary);
    
    waitKey(0);
    
    return 0;
}
