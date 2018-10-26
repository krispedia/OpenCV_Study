#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void histogrammer(Mat grim, char *w, int c);
void rgb_histogrammer(Mat src);
void equalize_histogra(char *weq, Mat img, int x, int y);
void hsv_skinner(Mat src, int wx, int wy);

int W=300, H=200;

int main(int argc, char* argv[]) {

    //Names, Labels
    char *w0 = "입력";
    Mat img, grim;
    char *fn = "/Users/Zett/desktop/openCV test/openCV test/pastel.jpg";
    char *fn2 = "/Users/Zett/desktop/openCV test/openCV test/faces_lessenthusia.jpg";

    //Load & display image
    img = imread(fn2, CV_LOAD_IMAGE_COLOR);
    if(img.empty()) {cout<<"File Not Found"<<endl; return -1;}
    H = img.rows; W = img.cols;
    namedWindow(w0, 1); imshow(w0, img);
    moveWindow(w0, 50, 50);

    //Grayscale Histogram
    cvtColor(img, grim, COLOR_BGR2GRAY);
    //histogrammer(grim, "H0", -1);
    //rgb_histogrammer(img);
    waitKey(0);
    hsv_skinner(img, 50+(16+W)*2, 50);waitKey(0);

    return 0;
}
