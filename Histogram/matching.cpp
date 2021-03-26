#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
#define PIXEL 256

int totalPixel(Mat src) {
	return src.rows * src.cols;
}

void imgHistogram(Mat& src, int histogram[]) {
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

	Mat src = imread("dark.jpg", 0);
	Mat target = imread("target.jpg", 0);
	Mat dst = Mat::zeros(src.size(), CV_8UC1);

	//create lookup table for source
	int histogramSrc[PIXEL], cumulativHistSrc[PIXEL], lookUpSrc[PIXEL];
	int totalPixSrc = totalPixel(src);
	imgHistogram(src, histogramSrc);
	cumulativeHist(histogramSrc, cumulativHistSrc);

	for (int i = 0; i < PIXEL; i++) {
		lookUpSrc[i] = 0;
	}
	for (int i = 0; i < PIXEL; i++) {
		lookUpSrc[i] = round((cumulativHistSrc[i] / float(totalPixSrc)) * PIXEL);
		if (lookUpSrc[i] > 255) {
			lookUpSrc[i] = 255;
		}
	}

	//create lookup table for target
	int histogramTrgt[PIXEL], cumulativHistTrgt[PIXEL], lookUpTrgt[PIXEL];
	int totalPixTrgt = totalPixel(target);
	imgHistogram(target, histogramTrgt);
	cumulativeHist(histogramTrgt, cumulativHistTrgt);

	for (int i = 0; i < PIXEL; i++) {
		lookUpTrgt[i] = 0;
	}
	for (int i = 0; i < PIXEL; i++) {
		lookUpTrgt[i] = round((cumulativHistSrc[i] / float(totalPixTrgt)) * PIXEL);
		if (lookUpTrgt[i] > 255) {
			lookUpTrgt[i] = 255;
		}
	}

	//create convert table
	int convertTable[PIXEL];
	for (int c = 0; c < PIXEL; c++) {
		convertTable[c] = lookUpTrgt[lookUpSrc[c]];
	}

	for (int i = 0; i < dst.rows; i++) {
		for (int j = 0; j < dst.cols; j++) {
			dst.at<uchar>(i, j) = convertTable[src.at<uchar>(i, j)];
		}
	}
	

	imshow("src", src);
	imshow("target", target);
	imshow("dst", dst);
	//imwrite("homework1-1.jpg", dst);

	waitKey(0);
	return 0;
}
