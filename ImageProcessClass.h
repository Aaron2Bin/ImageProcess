#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;
class ImageProcess
{
public:
ImageProcess(string str);
void HisEqual(Mat &src, Mat &dst);
void Skeleton(Mat &src, Mat &dst);
private:
Mat src_img;
}
