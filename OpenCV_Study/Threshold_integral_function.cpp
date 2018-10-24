//integral function
//haar-like feature 계산에 많이 사용 됨
//전체 영역의 값 합을 구하는 함수.(적분연산 사용) for문을 돌려서 구해야 하는 값을 하나의 함수로 구할 수 있음
//C++: void integral(InputArray src, OutputArray sum, int sdept =-1)


#include <time.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int click_x = 0, click_y = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        printf("lLBUTTONDOWN down %d, %d \n", x, y);
        
        click_x = x;
        click_y = y;
    }
    
    
}

int main()
{
    Mat img = Mat(10, 10, CV_8UC1);
    randu(img, 0, 10);
    
    cout<<"origin" <<endl<<img<<endl;
    
    int x=3, y=4, w=4, h=4;
    
    //using for
    int sum=0;
    for(int i=0; i<2; ++i){
        for(int j=0; j<h; ++j){
            sum = sum+img.at<unsigned char>((y+j),(x+i));
        }
    }
    
    cout<<"for loop : sum = "<<sum<<endl;
    
    
    //using integral
    Mat integralimg;
    integral(img, integralimg, CV_64F);
    
    cout<<endl<<"integral"<<endl<<integralimg<<endl;
    
    double p1 = integralimg.at<double>((y),(x));
    double p2 = integralimg.at<double>((y),(x+w));
    double p3 = integralimg.at<double>((y+h),(x));
    double p4 = integralimg.at<double>((y+h),(x+w));
    
    cout<<"p1: "<<p1<<" p2: "<<p2<<" p3: "<<p3<<" p4: "<<p4<<endl;
    cout<<"integral: sum = "<<(p1+p4)-(p2+p3)<<endl;
    
    
    return 0;
}
