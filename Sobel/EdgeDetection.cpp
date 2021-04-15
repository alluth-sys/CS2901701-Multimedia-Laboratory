#include <opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int getGx(Mat image, int x, int y)
{
	return image.at<uchar>(y - 1, x + 1) +
		2 * image.at<uchar>(y, x + 1) +
		image.at <uchar>(y + 1, x + 1) -
		image.at <uchar>(y - 1, x - 1) -
		2 * image.at<uchar>(y, x - 1) -
		image.at<uchar>(y + 1, x - 1);
}

int getGy(Mat image, int x, int y)
{
	return image.at<uchar>(y + 1, x - 1) +
		2 * image.at<uchar>(y + 1, x) +
		image.at <uchar>(y + 1, x + 1) -
		image.at <uchar>(y - 1, x - 1) -
		2 * image.at<uchar>(y - 1, x) -
		image.at<uchar>(y - 1, x + 1);
}

int main()
{
	Mat img = imread("pikachu.png");
	cvtColor(img, img, COLOR_BGR2GRAY);
	Mat edge_img = Mat::zeros(img.rows, img.cols, CV_8UC1);

	int T = 150; 

	for (int y = 1; y < img.rows - 1; y++)
	{
		for (int x = 1; x < img.cols - 1; x++)
		{
			int Gx, Gy, G; 
			Gx = getGx(img, x, y);
			Gy = getGy(img, x, y);
			G = sqrt((Gx * Gx) + (Gy * Gy));

			G >= T ? G = 255 : G = 0;

			edge_img.at<uchar>(y, x) = G;

		}
	}

	imshow("img", img);
	imshow("edge_img", edge_img);
	waitKey(0);
	return 0;
}

