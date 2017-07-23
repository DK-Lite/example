#include <opencv\cv.h>
#include <opencv\highgui.h>
#include "constant.h"
using namespace cv;

void imgSharpening(cv::Mat& img, float sigma)

{

	cv::Mat tmp;

	cv::GaussianBlur(img, tmp, cv::Size(0, 0), sigma);

	cv::addWeighted(img, 1.5, tmp, -0.5, 0, img);

}

int main()

{

	Mat img = imread(".\\image\\5.jpg");
	Mat src, gray, edge, binary;


	cv::resize(img, src, cv::Size(WIDTH, HEIGHT), 0, 0, CV_INTER_NN);

	//Mat img = imread("C:\\Users\\Public\\Pictures\\Sample Pictures\\Desert.jpg");


	cvtColor(src, gray, CV_RGB2GRAY);


	//imgSharpening(img, 1);

	cv::Canny(gray, edge, 50, 200, 3);
	threshold(gray, binary, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	





	imshow("origin", src);
	imshow("binary", binary);
	imshow("edge", edge);




	waitKey(0);



	return 0;

}