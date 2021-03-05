////Mat ªºÀ³¥Î
//#include<iostream>
//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat img = imread("lenna.jpg");
//	img.row(250).setTo(Scalar(0, 0, 0));
//	img.col(250).setTo(Scalar(0, 0, 0));
//	
//	img.rowRange(10, 30).setTo(Scalar(0, 0, 255));
//	img.colRange(10, 30).setTo(Scalar(255, 0, 0));
//	img.rowRange(100, 150).colRange(100, 150).setTo(Scalar(0, 255, 0));
//	
//	imshow("image", img);
//	waitKey();
//	return 0;
//}
