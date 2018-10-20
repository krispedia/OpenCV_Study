// Mat img copyTo(copy)

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
    //cimg copyTo(copy)
    Mat cimg;
    img.copyTo(cimg);
    
    //cimg2 copyTo_r(copy)
    Rect r(img.cols/4, img.rows/4, img.cols/4*2, img.rows/4*2);
    Mat cimg2;
    img.copyTo(cimg2);
    
    //cimg3 copyTo_size
    Mat cimg3(Size(img.cols*2, img.rows), img.type());
    cimg3.setTo(255);   //set white
    img.copyTo(cimg3(Range::all(), Range(0,img.cols)));
    cimg.copyTo(cimg3(Range::all(), Range(cimg.cols, cimg.cols*2)));
    
    //before change compare img, cimg, cimg2
    imshow("img_original", img);
    imshow("cimg_original", cimg);
    imshow("cimg2_origianl", cimg2);
    
    //bitwise only img
    bitwise_not(img, img);
    
    //after change compare img, cimg, cimg2
    imshow("img",img);
    imshow("cimg", cimg);
    imshow("cimg2", cimg2);
    imshow("cimg3", cimg3);
    waitKey(0);
    
    return 0;
}
