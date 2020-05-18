#include <opencv2/opencv.hpp>
#include <stdlib.h> 
#include <time.h>

void drawLine(cv::Mat* img, int x, int y)
{
	cv::Point p1(img->cols/2, img->rows/2);
	cv::Point p2(x, y);
	cv::Scalar color(255, 255, 255);
	cv::line(*img, p1, p2, color, 1, 8, 0);
}

void callBack(int event, int x, int y, int flags, void* param)
{
	switch (event)
	{
		case cv::EVENT_MOUSEMOVE : break;
		case cv::EVENT_LBUTTONDOWN: drawLine((cv::Mat*)param, x, y); break; 
		case cv::EVENT_LBUTTONUP: break;
	}
}

int main() {
	cv::Mat backgrd(500,1000,CV_8UC3,cv::Scalar(0,0,0));
	cv::namedWindow("Out", cv::WINDOW_AUTOSIZE);

	cv::setMouseCallback("Out", callBack, (void*)&backgrd);

	while (1)
	{
		cv::imshow("Out", backgrd);
		char c = cv::waitKey(33);
		if (c == 27) break;

	}

	cv::destroyWindow("Out");
	return 0;
}