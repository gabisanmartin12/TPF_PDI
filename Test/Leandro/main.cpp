#include <opencv2/opencv.hpp>
#include "../../Funciones/showmultipleimages.h"
#include <vector>

using namespace cv;

int main (int argc, char **argv) {

	cv::VideoCapture cap ("../../Videos/caminar3.mp4");
	cap.set(CV_CAP_PROP_FORMAT,CV_32F);

	//namedWindow("Original");
	//namedWindow("Test gray");
	vector<Mat> channels;
	for(;;)
	{
		Mat frame, gray, hsv;
		cap>>frame; // get a new frame from camera
		cvtColor(frame, gray, CV_BGR2GRAY);
		cvtColor(frame, hsv, CV_BGR2HSV_FULL);

		split(hsv, channels);

		//imshow("Original", frame);
		//imshow("Test gray", gray);
		//showmultipleimages("HSV Channels",3,channels[0],channels[1],channels[2]);
		//gray = channels[2];


		BackgroundSubtractorMOG mog;
		Mat image_mog;
		mog(gray,image_mog,10);


		showmultipleimages("MOG",3,gray,image_mog,channels[2]);


		if(waitKey(30) >= 0) break;
	}
	cv::waitKey();
	return 0;
}
