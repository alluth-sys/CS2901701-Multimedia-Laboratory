#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;

Mat Bilinear(Mat src, double rx, double ry)
{
    if (rx == 1 && ry == 1)
    {
        return src;
    }
    else
    {
        int height = src.rows;
        int width = src.cols;
        Mat result = Mat::zeros(height * ry, width * rx, CV_8UC3);
        double original_x, original_y;
        int x1, x2, y1, y2;

        //iterates through new matrix
        for (int i = 0; i < result.rows; i++)
        {
            original_y = i / ry;
            //offset_y = original_y - floor(original_y); //2.4 - 2 = 0.4
            y1 = floor(original_y);
            y2 = ceil(original_y);

            for (int j = 0; j < result.cols; j++)
            {
                original_x = j / rx;
                //offset_x = original_x - floor(original_x);
                x1 = floor(original_x);
                x2 = ceil(original_x);

                double d1 = original_x - x1, d2 = x2 - original_x;
                double d3 = original_y - y1, d4 = y2 - original_y;
                //compute bilinear
                Vec2f target = Vec2f(x1, y1) * d2 * d4 +
                               Vec2f(x2, y1) * d1 * d4 +
                               Vec2f(x1, y2) * d2 * d3 +
                               Vec2f(x2, y2) * d1 * d3;

                result.at<Vec3b>(i, j) = src.at<Vec3b>(target.val[0], target.val[1]);
            }
        }
        return result;
    }
}

int main()
{
    Mat src = imread("lenna,jpg");
    Mat result = Bilinear(src, 2.5, 2.5);
    imwrite("result", result);
}
