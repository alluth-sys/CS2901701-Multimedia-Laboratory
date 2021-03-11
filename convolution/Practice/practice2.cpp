#include <opencv2/opencv.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace cv;
using namespace std;

//Blur image
int main()
{
	Mat src = imread("lenna.jpg", 0); // 灰階圖
	//Mat src = imread("lenna_noise.jpg", 0);
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	float sum;
	int ksize = 5; // 5 * 5 遮罩
	float kernel[5][5] =
	{
	   {1 / 25.0, 1 / 25.0, 1 / 25.0, 1 / 25.0, 1 / 25.0},
	   {1 / 25.0, 1 / 25.0, 1 / 25.0, 1 / 25.0, 1 / 25.0},
	   {1 / 25.0, 1 / 25.0, 1 / 25.0, 1 / 25.0, 1 / 25.0},
	   {1 / 25.0, 1 / 25.0, 1 / 25.0, 1 / 25.0, 1 / 25.0},
	   {1 / 25.0, 1 / 25.0, 1 / 25.0, 1 / 25.0, 1 / 25.0}
	};

	for (int y = 2; y < src.rows - 2; y++) {
		for (int x = 2; x < src.cols - 2; x++) {
			sum = 0.0;
			for (int k = -2; k <= 2; k++) {
				for (int j = -2; j <= 2; j++) {
					sum = sum + kernel[j + 2][k + 2] * src.at <uchar>(y - j, x - k);
				}
			}
			dst.at<uchar>(y, x) = sum;
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
}

////Median Method
//int main()
//{
//    Mat src = imread("lenna.jpg", 0);
//    // Mat src = imread("lenna_noise.jpg", 0);
//    Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
//
//
//    for (int y = 2; y < src.rows - 2; y++) {
//        for (int x = 2; x < src.cols - 2; x++) {
//
//            vector<uchar> t;
//            for (int k = -2; k <= 2; k++) {
//                for (int j = -2; j <= 2; j++) {
//                    t.push_back(src.at<uchar>(y - j, x - k));
//                }
//            }
//
//            sort(t.begin(), t.end());
//
//            dst.at<uchar>(y, x) = t[25 / 2];
//        }
//    }
//
//    imshow("src", src);
//    imshow("dst", dst);
//    waitKey();
//}