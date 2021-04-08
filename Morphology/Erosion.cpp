#include <opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
#define KSIZE 3

//RECTANGLE Structure element
void initKernel(int kernel[][KSIZE]) {
	for (int i = 0; i < KSIZE; ++i) {
		for (int j = 0; j < KSIZE; ++j) {
			kernel[i][j] = 1;
		}
	}
}

void erodeFunc(Mat& img, Mat& dst,int kernel[][KSIZE]) {
	int offset = KSIZE / 2;

	for (int y = offset; y < img.rows - offset; y++) {
		for (int x = offset; x < img.cols - offset; x++) {
			int product[KSIZE * KSIZE] = { 0 };
			int counter = 0;
			bool flag = 1;
			
			for (int i = -offset; i <= offset; i++) {
				for (int j = -offset; j <= offset; j++) {
					product[counter++] = img.at<uchar>(y - j, x - i) * kernel[j + offset][i + offset];
				}
			}
			for (int c = 0; c < KSIZE * KSIZE; c++) {
				if (product[c] == 0) {
					flag = 0;
					break;
				}
			}

			flag ? dst.at<uchar>(y, x) = 1 : NULL;
		}
	}
}

int main() {
	Mat img = imread("image.jpg", 0);
	double scale = 0.2;
	resize(img, img, Size(0, 0), scale, scale);

	Mat dst = Mat::zeros(img.rows, img.cols, CV_8UC1);
	threshold(img, img, 127, 255, THRESH_BINARY_INV);

	int kernel[KSIZE][KSIZE];
	initKernel(kernel);

	erodeFunc(img, dst,kernel);
	

	imshow("origin_img", img);
	imshow("erode", dst);
	waitKey(0);
}
