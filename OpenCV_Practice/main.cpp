#include "opencv2/opencv.hpp"
#include <iostream>
#include "practice.h"

using namespace cv;

int main()
{
	VideoCapture cap("video.mp4");

	if (!cap.isOpened())
	{
		std::cerr << "Camera open failed\n";
		return -1;
	}

	std::cout << "Widht:" << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << "\n";
	std::cout << "Height:" << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << "\n";

	double fps = cap.get(CAP_PROP_FPS);
	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	int delay = cvRound(1000 / fps);
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');

	VideoWriter out("output.avi", fourcc, fps, Size(w, h));

	if (!out.isOpened())
	{
		std::cerr << "file open failed!\n";
		return -1;
	}

	Mat frame, inv_frame;
	while (1)
	{
		cap >> frame;
		if (frame.empty())
			break;

		inv_frame = ~frame;
		out << inv_frame;
	
		imshow("frame", frame);
		imshow("inv", inv_frame);

		if (waitKey(delay) == 27)
			break;
	}

	destroyAllWindows();
}