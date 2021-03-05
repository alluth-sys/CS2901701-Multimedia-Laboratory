//// Mat 的應用
//
//#include<iostream>
//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat Ma = imread("lenna.jpg");
//
//	// cout << "Ma = " << endl << " " << Ma << endl << endl;
//
//	cout << "cols = " << Ma.cols << endl;
//	cout << "rows = " << Ma.rows << endl;
//	cout << "size = " << Ma.size() << endl;
//	cout << "total = " << Ma.total() << endl << endl;
//
//	cout << "channel = " << Ma.channels() << endl;
//	cout << "type = " << Ma.type() << ", CV_8UC3 = " << CV_8UC3 << endl;
//	// enum{ CV_8U=0, CV_8S=1, CV_16U=2, CV_16S=3, CV_32S=4, CV_32F=5, CV_64F=6};
//	cout << "depth = " << Ma.depth() << endl;
//	cout << endl;
//
//	// b/s/i/f/d 分別代表uchar, short, int, float, double
//	cout << "Ma(" << 0 << "," << 0 << ")[0] = " << (int)Ma.at<Vec3b>(0, 0)[0] << endl;			// blur color value
//	cout << "Ma(" << 0 << "," << 0 << ")[1] = " << (int)Ma.at<Vec<uchar, 3>>(0, 0)[1] << endl;  // green color value
//	cout << "Ma(" << 0 << "," << 0 << ")[2] = " << (int)Ma.at<Vec<uchar, 3>>(0, 0)[2] << endl;	// red color value
//	system("pause");
//	return 0;
//}
