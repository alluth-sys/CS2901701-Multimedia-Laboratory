#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void bilinear(const Mat& src, Mat& dst, double dy, double dx)
{	
	int original_width = src.rows;
	int original_height = src.cols;

	dst = Mat::zeros(original_width*dx,original_height*dy, CV_8UC3);

	for (int i = 0; i < dst.rows; ++i)
	{

		for (int j = 0; j < dst.cols; ++j)
		{
			double x = i / dx, y = j / dy;
			int x1 = floor(x), y1 = floor(y);
			int x2 = x1 + 1, y2 = y1 + 1;

			double d1 = x - x1, d2 = x2 - x;
			double d3 = y - y1, d4 = y2 - y;
			Vec3b result;
			
			if (x2 >= src.rows || y2 >= src.cols) {
				result = src.at<Vec3b>(x1, y1);
			}
			else {
				result = src.at<Vec3b>(x1, y1) * d2 * d4 + src.at<Vec3b>(x2, y1) * d1 * d4 + src.at<Vec3b>(x1, y2) * d2 * d3 + src.at<Vec3b>(x2, y2) * d1 * d3;
			}

			
			dst.at<Vec3b>(i, j) = result;
		}
	}
}

int main()
{
	Mat src = imread("lenna.jpg");
	Mat dst;
	bilinear(src, dst, 2.5, 2.5);

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
}
