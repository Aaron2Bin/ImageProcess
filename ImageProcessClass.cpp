#include "ImageProcessClass.h"
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;
ImageProcess::ImageProcess(string str)
{
src_img = imread(str);
}
void ImageProcess::HisEqual(Mat &src, Mat &dst)
{
int L = 256;
int M = src.rows;
int N = src.cols;
int temp;
long int sum=0;
int n[256] = {0};
  
for (int i = 0; i < M; i++)
{
  for (int j = 0; j < N; j++)
  {
    n[src.at<uchar>(i, j)]++;
  }
}

for (int i = 0; i < M; i++)
{
  for (int j = 0; j < N; j++)
  {
    sum = 0;
    temp = src.at<uchar>(i, j);
    for (int k = 0; k <= temp; k++)
    {
      sum = sum + n[k];
    }
    dst.at<uchar>(i, j) = saturate_cast<uchar>((double)(L - 1)*sum / (M*N));
  }
}

}
void ImageProcess::Skeleton(Mat &src, Mat &dst)
{
	Mat temp;
	bool flag;
	temp = src.clone();
	morphologyEx(temp, temp, MORPH_OPEN, Mat(), Point(-1, -1), 1);
	dst = dst | src - temp;
	while (1)
	{
		flag = false;
		erode(src, src, Mat(), Point(-1, -1), 1);
		temp = src.clone();
		morphologyEx(temp, temp, MORPH_OPEN, Mat(), Point(-1, -1), 1);
		dst = dst | src - temp;

		for (int i = 0; i < src.rows; i++)
		{
			for (int j = 0; j < src.cols; j++)
			{
				flag = flag | src.at<uchar>(i, j);
			}
		}
		if (flag == false)
		{
			break;
		}
	}
}
