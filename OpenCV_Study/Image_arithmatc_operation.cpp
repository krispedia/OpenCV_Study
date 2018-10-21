// image arithmatic operation

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn1 = "/users/sujinlee/desktop/prac/prac/test1.jpeg";
    char *fn2 = "/users/sujinlee/desktop/prac/prac/test2.jpeg";
    Mat img1 = imread(fn1);
    Mat img2 = imread(fn2);
    Mat img_add, img_sub, img_mul, img_div;
    Mat img_wadd;
    
    if(img1.empty()){
        cout<<"File Not Found"<<endl;
        return -1;
    }
    if(img2.empty()){
        cout<<"File Not Found"<<endl;
        return -1;
    }
    
    resize(img1, img1, Size(500, 500));
    resize(img2, img2, Size(img1.size().width, img1.size().height));
    add(img1, img2, img_add);
    subtract(img1, img2, img_sub);
    multiply(img1, img2, img_mul);
    divide(img1, img2, img_div);
    
    imshow("img_add", img_add);
    imshow("img_sub", img_sub);
    imshow("img_mul", img_mul);
    imshow("img_div", img_div);
    
    waitKey(0);
    
    double alpha = 0.5;
    double beta;
    double input;
    
    for(float i=0; i<1; i+= 0.1){
        
        
        alpha = i;
        beta = (1.0-alpha);
        
        addWeighted(img1, alpha, img2, beta, 0.0, img_wadd);
        
        imshow("img_wadd", img_wadd);
        
        waitKey(500);
    }
    
    return 0;
}
