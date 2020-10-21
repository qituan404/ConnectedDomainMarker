#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat binaryMat, labelMat, stateMat, centerMat;
	Mat srcMat = imread("0.jpg", 0);
	threshold(srcMat, binaryMat, 100, 255, THRESH_BINARY);		//二值化算法
	int Number = connectedComponentsWithStats(binaryMat, labelMat, stateMat, centerMat, 8, CV_32S);	//连通域标记函数

	cout << "硬币数= " << Number - 1 << endl;  //硬币数为统计值减去一张背景的连通域

	for (int i = 1; i < Number; i++)
	{
		Rect bbx;
		bbx.x = stateMat.at<int>(i, 0);
		bbx.y = stateMat.at<int>(i, 1);
		bbx.width = stateMat.at<int>(i, 2);
		bbx.height = stateMat.at<int>(i, 3);
		rectangle(binaryMat, bbx, CV_RGB(255, 255, 255), 1, 8, 0);
	}

	imshow("frame", srcMat);
	imshow("binaryMat", binaryMat);
	waitKey(0);
	return 0;
}