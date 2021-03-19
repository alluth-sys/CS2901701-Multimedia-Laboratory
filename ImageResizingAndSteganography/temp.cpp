#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void bilinearInterpolation(const Mat &src, Mat &dst, double dy, double dx)
{
    Size ssize = src.size();
    Size dsize(ssize.width * dx, ssize.height * dy);

    dst = Mat::zeros(dsize, CV_8UC3);

    int drows = dsize.height, dcols = dsize.width;
    for (int i = 0; i < drows; ++i)
    {

        for (int j = 0; j < dcols; ++j)
        {
            double x = i / dx, y = j / dy;
            int sx1 = floor(x), sy1 = floor(y);
            int sx2 = sx1 + 1, sy2 = sy1 + 1;

            double d1 = x - sx1, d2 = sx2 - x;
            double d3 = y - sy1, d4 = sy2 - y;

            Vec2f target = Vec2f(sx1, sy1) * d2 * d4 +
                           Vec2f(sx2, sy1) * d1 * d4 +
                           Vec2f(sx1, sy2) * d2 * d3 +
                           Vec2f(sx2, sy2) * d1 * d3;

            //cout << src.at<Vec3b>(target.val[0], target.val[1]) << endl;
            dst.at<Vec3b>(i, j) = src.at<Vec3b>(target.val[0], target.val[1]);
        }
    }
}

int main()
{
    Mat src = imread("lenna.jpg");
    Mat dst;
    bilinearInterpolation(src, dst, 1, 10);

    imshow("src", src);
    imshow("dst", dst);
    waitKey();
}
