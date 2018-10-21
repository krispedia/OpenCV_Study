// Simple Image Read
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn = "/users/sujinlee/desktop/OpenCV_Study/OpenCV_Study/test.jpg";
    namedWindow("img",0);
    
    Mat img = imread(fn, CV_LOAD_IMAGE_COLOR);
    
    if(!img.data){
        cout<<"File Not Found"<<endl;
        return -1;
    }
    
    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", img);
    
    waitKey(0);
    
    destroyAllWindows();
    
    return 0;
}
