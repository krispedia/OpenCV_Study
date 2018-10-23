// noise generation_example

#include <time.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn1 = "/users/sujinlee/desktop/prac/prac/test1.jpeg";
    Mat img = imread(fn1);
    
    if(!img.data){
        cout<<"File Not Found"<<endl;
        return -1;
    }
    resize(img, img, Size(500, 500));
    
    //    //noise adapt
    //    Mat Gaussian_noise = Mat(img.size(), img.type());
    //    double mean = 0;
    //    double std = 10;
    //    randn(Gaussian_noise, mean, std);
    //    Mat colorNoise = img + Gaussian_noise;
    //
    //    namedWindow("img", 0);
    //    imshow("img", img);
    //
    //    namedWindow("Gaussian_noise", 0);
    //    imshow("Gaussian_noise", Gaussian_noise);
    //
    //    namedWindow("noiseGray", 0);
    //    imshow("noiseGray", noiseGray);
    
    
    //method_2
    //    int rsize = 1000;
    //    srand(time(NULL));
    //    Mat imgD = img.clone();
    //    for(int i=0; i<rsize; ++i)
    //    {
    //        int x = rand() % img.cols;
    //        int y = rand() % img.rows;
    //
    //        imgD.at<Vec3b>(y,x)[0] = 255;
    //        imgD.at<Vec3b>(y,x)[1] = 255;
    //        imgD.at<Vec3b>(y,x)[2] = 255;
    //    }
    //    namedWindow("img", 0);
    //    imshow("img", img);
    //
    //    namedWindow("imgD", 0);
    //    imshow("imgD", imgD);
    
    //method_3
    Mat noiseGray = img.clone();
    cvtColor(noiseGray, noiseGray, CV_RGB2GRAY);
    Mat Gaussian_noise = Mat(noiseGray.rows, noiseGray.cols, CV_8UC1);
    double mean = 0;
    double std = 10;
    randn(Gaussian_noise, mean, std);
    double minV, maxV;
    minMaxIdx(Gaussian_noise, &minV, &maxV);
    cout<< "min : "<< minV << "max : "<< maxV <<endl;
    threshold(Gaussian_noise, Gaussian_noise, (minV + maxV)/2, 255, CV_THRESH_BINARY);
    
    noiseGray = noiseGray + Gaussian_noise;
    
    namedWindow("img", 0);
    imshow("img", img);
    
    namedWindow("Gaussian_noise", 0);
    imshow("Gaussian_noise", Gaussian_noise);
    
    namedWindow("noiseGray", 0);
    imshow("noiseGray", noiseGray);
    
    waitKey(0);
    
    
    return 0;
}
