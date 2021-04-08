#include <opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat img = imread("image.jpg", 0);
	Mat src_binary_inv;
	Mat dst1;
	double scale = 0.2;
	resize(img, img, Size(0, 0), scale, scale);


	Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5)); //create structuring element
	threshold(img, src_binary_inv, 127, 255, THRESH_BINARY_INV); //Thresh the image
	erode(src_binary_inv, dst1, kernel, Point(-1, -1), 12 ); //Point(-1,-1) is the center of image, 12 is number of iteration

	Mat labels;
	int number_labels = connectedComponents(dst1, labels);
	cout << "¦@¦³: " << number_labels - 1;

	imshow("origin_img", img);
	imshow("src_binary_inv", src_binary_inv);
	imshow("erode", dst1);
	waitKey(0);
}
