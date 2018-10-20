// Mat img ref

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
    Mat img_s = img;
    
    //img_s ref img
    imshow("img_original", img);
    imshow("img_s_original", img_s);
    
    //bitwise only img
    bitwise_not(img, img);
    
    //after change compare img, img_s
    imshow("img",img);
    imshow("img_s", img_s);
    waitKey(0);
    
    return 0;
}
