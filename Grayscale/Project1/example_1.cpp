//// Mat 的基本應用
//
//#include<iostream>
//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	int a[] = { 1,  2,  0, 9,
//		2,  5, -1, 6,
//		4, 10, -1, 8 };
//
//
//	Mat Ma = Mat(3, 4, CV_32SC1, a);
//	//0:CV_8UC1, 1:CV_8SC1, 2:CV_16UC1, 3:CV_16SC1, 4:CV_32SC1, 5:CV_32FC1, 6:CV_64FC1,
//	//8:CV_8UC2, 9:CV_8SC2, 10:CV_16UC2, 11:CV_16SC2, 12:CV_32SC2, 13:CV_32FC2, 14:CV_64FC2
//
//
//	cout << "Ma = " << endl << " " << Ma << endl << endl;
//
//	cout << "cols = " << Ma.cols << endl;
//	cout << "rows = " << Ma.rows << endl;
//	cout << "size = " << Ma.size() << endl;
//	cout << "total = " << Ma.total() << endl << endl;
//
//	cout << "channel = " << Ma.channels() << endl;
//	cout << "type = " << Ma.type() << ", CV_32SC1 = " << CV_32SC1 << endl;
//	// enum{ CV_8U=0, CV_8S=1, CV_16U=2, CV_16S=3, CV_32S=4, CV_32F=5, CV_64F=6};
//	cout << "depth = " << Ma.depth() << endl;
//	cout << endl;
//
//	cout << "Ma(" << 0 << "," << 0 << ") = " << Ma.at<int>(0, 0) << endl;
//	cout << "Ma(" << 2 << "," << 1 << ") = " << Ma.at<Vec<int, 1>>(2, 1)[0] << endl;
//	//<int>等同於<Vec<int,1>>，代表int格式，一通道。
//
//	Ma.at<int>(0, 0) = 30;
//	cout << "Ma(" << 0 << "," << 0 << ") = " << Ma.at<int>(0, 0) << endl;
//	system("pause");
//	return 0;
//}
