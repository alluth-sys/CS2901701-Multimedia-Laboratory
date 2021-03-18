#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat pika = imread("pikachu_qrcode.png", 0);
	int rows = pika.rows, cols = pika.cols;
	Mat qrcode = Mat::zeros(rows, cols, CV_8UC1);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (pika.at<uchar>(i, j) & 0b00000001 == 1) {
				qrcode.at<uchar>(i, j) = 255;
			}
			else {
				qrcode.at<uchar>(i, j) = 0;
			}
		}
	}
	    
	imshow("pika", pika);
	imshow("qrcode_pika", qrcode);

	waitKey();
}
