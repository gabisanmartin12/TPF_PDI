#include <opencv2/opencv.hpp>
#include "../../Funciones/showmultipleimages.h"
#include <vector>

using namespace cv;

int main (int argc, char **argv) {

	cv::VideoCapture cap ("../../Videos/objeto2.mp4");
	cap.set(CV_CAP_PROP_FORMAT,CV_32F);
	BackgroundSubtractorMOG2 mog;
	mog.set("nShadowDetection",0);

	SimpleBlobDetector::Params params;
	//params.filterByArea = true;
	//params.minArea = 200;

	SimpleBlobDetector blob(params);
	std::vector<KeyPoint> keypoints;

	Mat element = getStructuringElement(MORPH_CROSS,Size(3,3));
	//KalmanFilter kalman(4, 2, 0);

	//namedWindow("Original");
	//namedWindow("Test gray");
	vector<Mat> channels;
	for(;;)
	{
		Mat frame, gray, hsv;
		cap>>frame; // get a new frame from camera
		cvtColor(frame, gray, CV_BGR2GRAY);
		//cvtColor(frame, hsv, CV_BGR2HSV_FULL);

		split(hsv, channels);

		//imshow("Original", frame);
		//imshow("Test gray", gray);
		//showmultipleimages("HSV Channels",3,channels[0],channels[1],channels[2]);
		//gray = channels[2];
		medianBlur(gray,gray,5);

		//equalizeHist(gray,gray);

		Mat image_mog;
		mog(gray,image_mog,.00001);
		dilate(image_mog,image_mog, element);
		erode(image_mog,image_mog, element);




		showmultipleimages("MOG",2,gray,image_mog);
		//showmultipleimages("Blob detection",1,im_with_keypoints);


		if(waitKey(30) >= 0) break;
	}
	cv::waitKey();
	return 0;
}
