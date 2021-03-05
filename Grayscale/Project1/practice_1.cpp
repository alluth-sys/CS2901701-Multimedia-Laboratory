#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("lena.jpg");
	Mat img_gray = Mat::zeros(img.rows, img.cols, CV_8UC1);

	for (int i = 0; i < img.rows; i++) {
		for (int k = 0; k < img.cols; k++) {
			int grey = img.at<Vec3b>(i, k)[0] * 0.299 + img.at<Vec3b>(i, k)[1] * 0.587 + img.at<Vec3b>(i, k)[2] * 0.114;
			img_gray.at<uchar>(i, k) = grey;
		}
	}

	imshow("RGB image", img);
	imshow("gray image", img_gray);
	waitKey();
}