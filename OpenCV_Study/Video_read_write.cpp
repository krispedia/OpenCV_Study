// video read write

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    char *fn = "/users/sujinlee/desktop/prac/prac/test.jpg";
    
    Mat img = imread(fn, CV_LOAD_IMAGE_COLOR);
    
    //    cout<<"Element Size : "<< img.elemSize()<<endl;
    //    cout<<"Channels     : "<< img.channels()<<endl;       //channels - r?g?b?å
    //    cout<<"Rows         : "<< img.rows<<endl;
    //    cout<<"Steps        : "<< img.step<<endl;
    //
    //    vector<Mat> rgbMat(3);
    //    split(img, rgbMat);
    //
    //    imshow("r", rgbMat[2]);
    //    imshow("g", rgbMat[1]);
    //    imshow("b", rgbMat[0]);
    
    VideoCapture capture("/users/sujinlee/desktop/video.avi");
    Mat frame;
    
    int askFileTypeBox = 0;
    int Color = 1;
    Size S = Size((int)capture.get(CV_CAP_PROP_FRAME_WIDTH), (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));
    
    //make out video file
    //outVideo.open(FILENAME, CODEC BOX?, FRAME PER SECOND, VIDEO SIZE, COLOR?)
    VideoWriter outVideo;
    outVideo.open("/User/sujinlee/desktop/outvideo.avi", askFileTypeBox, capture.get(CV_CAP_PROP_FPS), S, Color);
    
    if(!capture.isOpened()){
        printf("AVI file can not open\n");
        return 0;
    }
    
    //create window
    namedWindow("out");
    
    while(1){
        //read frame
        capture >> frame;
        if(frame.empty())
            break;
        //write frame
        outVideo.write(frame);
        
        imshow("out", frame);
        if(waitKey(10)>0)
            break;
    }
    
    return 0;
}
