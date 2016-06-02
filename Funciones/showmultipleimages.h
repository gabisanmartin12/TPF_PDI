#include <stdio.h>
#include <vector>
#include <opencv2/opencv.hpp>

#include <stdarg.h>

void showmultipleimages (std::string title, int n_images, ...) {
	va_list ap;
	va_start(ap, n_images);
	cv::Mat img = va_arg(ap,cv::Mat);
	int maxcols = img.cols;
	int maxrows = img.rows;

	for (int i = 1; i < n_images; i++) {
		cv::Mat img = va_arg(ap, cv::Mat);
		if (img.cols>=maxcols) maxcols = img.cols;
		if (img.rows>=maxrows) maxrows = img.rows;
	}

	cv::Mat m = cv::Mat(cv::Size(n_images*maxcols,maxrows), img.type());

	va_start(ap,n_images);
	for (int i=0; i<n_images; i++) {
		cv::Mat img = va_arg(ap, cv::Mat);
		img.copyTo(cv::Mat(m,cv::Rect(i*maxcols,0,img.cols,img.rows)));
	}

	cv::namedWindow(title.c_str(), cv::WINDOW_AUTOSIZE);
	cv::imshow(title.c_str(), m);
}
