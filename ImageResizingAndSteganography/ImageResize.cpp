#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;


Mat Bilinear(Mat src, double rx, double ry) {
	int height = src.rows;
	int width = src.cols;
	Mat result = Mat::zeros(height * ry, width * rx, CV_8UC3);

	double original_x, original_y;

	for (int i = 0; i < result.rows; i++) {
		original_y = i / ry;
		for (int j = 0; j < result.cols; j++) {
			original_x = j / rx;
			
			//compute bilinear
			for (int c = 0; src.channels(); c++) {

			}
			
		}
	}


}


int main() {
	Mat src = imread("lenna,jpg");
	Mat result = Bilinear(src, 2.5, 2.5);
	imwrite("result", result);
}
