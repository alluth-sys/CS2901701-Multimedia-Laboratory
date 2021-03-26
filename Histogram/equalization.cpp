#include <opencv2/opencv.hpp>
#include <iostream>
#define PIXEL 256
using namespace std;
using namespace cv;

int totalPixel(Mat src) {
	return src.rows * src.cols;
}

void imgHistogram(Mat& src,int histogram[]) {
	//clean value
	for (int i = 0; i < PIXEL; i++) {
		histogram[i] = 0;
	}

	for (int k = 0; k < src.rows; k++) {
		for (int j = 0; j < src.cols; j++) {
			histogram[src.at<uchar>(k, j)]++;
		}
	}
}

void cumulativeHist(int histogram[], int cumulativHist[]) {
	
	cumulativHist[0] = histogram[0];
	for (int i = 1; i < PIXEL; i++) {
		cumulativHist[i] = histogram[i] + cumulativHist[i - 1];
	}
}



int main() {

	//Mat src = imread("dark.jpg", 0);//還要測bright.jpg
	Mat src = imread("bright.jpg", 0);
	Mat dst = Mat::zeros(src.size(), CV_8UC1);

	int srcRow = src.rows;
	int srcCols = src.cols;
	int histogram[PIXEL], cumulativHist[PIXEL], lookUp[PIXEL];
	//find the number of probability
	int totalPix = totalPixel(src);
	imgHistogram(src, histogram);
	cumulativeHist(histogram, cumulativHist);

	for (int i = 0; i < PIXEL; i++) {
		lookUp[i] = 0;
	}
	for (int i = 0; i < PIXEL; i++) {
		lookUp[i] = round((cumulativHist[i] / float(totalPix))*PIXEL);
		if (lookUp[i] > 255) {
			lookUp[i] = 255;
		}
	}

	for (int i = 0; i < dst.rows; i++) {
		for (int j = 0; j < dst.cols; j++) {
			dst.at<uchar>(i, j) = lookUp[src.at<uchar>(i, j)];
		}
	}
	
	imshow("src", src);
	imshow("dst", dst);
	//imwrite("homework1-1.jpg", dst);

	waitKey(0);
	return 0;
}
