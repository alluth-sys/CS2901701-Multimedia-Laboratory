////Mat 的應用
//#include<iostream>
//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat Ma = Mat::zeros(3, 4, CV_8UC1);
//	cout << "Ma = " << endl << " " << Ma << endl << endl;
//
//	Mat Mb = Mat::ones(3, 4, CV_8UC1);
//	cout << "Mb = " << endl << " " << Mb << endl << endl;
//
//	Mat Mc = Mat::ones(50, 50, CV_8UC3);
//	Mc.setTo(Scalar(255, 0, 0));
//	// Mc.setTo(Scalar(255));
//	// Mc.setTo(Scalar::all(255));
//	imshow("Mc", Mc);
//	waitKey(0);
//	destroyAllWindows();
//
//	uchar m[] = {
//		0,1,1,1,
//		1,0,1,1,
//		1,1,0,1 };
//	Mat mask = Mat(3, 4, CV_8UC1, m);
//	Mb.setTo(Scalar(3), mask);
//	cout << "Mb change = " << endl << " " << Mb << endl << endl;
//
//
//	Mat Md = Ma.clone();
//	Mat Me = Ma; // pass by reference 記憶體區塊相同
//
//	Md.at<uchar>(0, 0) = 1;
//	Me.at<uchar>(1, 1) = 1;
//	cout << endl << "clone example " << endl << endl;
//	cout << "Md = " << endl << " " << Md << endl << endl;
//	cout << "Me = " << endl << " " << Me << endl << endl;
//	cout << "Ma = " << endl << " " << Ma << endl << endl;
//
//
//	system("pause");
//	return 0;
//}
