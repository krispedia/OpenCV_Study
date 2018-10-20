// Mat img clone(copy)

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
    //img2 clone(copy)
    Mat img2 = img.clone();
    
    //img3 clone_r(copy)
    Rect r(img.cols/4, img.rows/4, img.cols/4*2, img.rows/4*2);
    Mat img3 = img(r).clone();
    
    imshow("img_original", img);
    imshow("img2_original", img2);
    imshow("img3_origianl", img3);
    
    //bitwise only img
    bitwise_not(img, img);
    
    //after change compare img, img2
    imshow("img",img);
    imshow("img2", img2);
    imshow("img3", img3);
    waitKey(0);
    
    return 0;
}
