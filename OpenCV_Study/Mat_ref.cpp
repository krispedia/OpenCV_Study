// m2가 dm 을 참조해서 가져옴.
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat m = Mat::zeros(3,3, CV_64F);
    m = m + 3;
    cout << m << endl;
    
    double dm[3][3] = {{1,2,1},{0,1,1},{1,0,1}};
    Mat m2 = Mat(3,3, CV_64F,dm);
    
    //arithmatic operation
    cout<<m+m2<<endl<<endl;
    cout<<m-m2<<endl<<endl;
    
    cout<<m*m2<<endl<<endl;
    cout<<m.mul(m2)<<endl<<endl;
    
    cout<<m/m2<<endl<<endl;
    //inversion
    cout<<m2.inv()<<endl;
    
    //transpose
    cout<<m2.t()<<endl;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<dm[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
