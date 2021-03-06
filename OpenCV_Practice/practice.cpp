#include "practice.h"

void practice_1()
{
	std::cout << "Hello OpenCV" << CV_VERSION << "\n";
	cv::Mat img;
	img = cv::imread("lenna.tif");

	if (img.empty())
		std::cerr << "Image Load failed! \n";


	cv::namedWindow("image");
	cv::imshow("image", img);

	cv::waitKey();
}

void practice_2()
{
	/* Point, Size, Rect Class */
	cv::Point pt1;
	pt1.x = 5; pt1.y = 10;
	cv::Point pt2(10, 30);

	cv::Point pt3 = pt1 + pt2;
	cv::Point pt4 = pt1 * 2;

	int d1 = pt1.dot(pt2);
	bool b1 = (pt1 == pt2);

	std::cout << "pt1: " << pt1 << "\n";
	std::cout << "pt2: " << pt2 << "\n";
	std::cout << "pt3: " << pt3 << "\n";
	std::cout << "pt4: " << pt4 << "\n";
	std::cout << "pt1, pt2 inner product: " << d1 << "\n";
	std::cout << "pt1 == pt2: " << b1 << "\n";

	cv::Size sz1, sz2(10, 20);
	sz1.width = 5;
	sz1.height = 5;

	cv::Size sz3 = sz1 + sz2;
	cv::Size sz4 = sz2;

	int area = sz3.area();

	std::cout << "Size1: " << sz1 << "\n";
	std::cout << "Size2: " << sz2 << "\n";
	std::cout << "Size3: " << sz3 << "\n";
	std::cout << "Size4: " << sz4 << "\n";
	std::cout << "Area of Size3: " << area << "\n";

	cv::Rect rc1; // 0 x 0 from 0, 0
	cv::Rect rc2(10, 10, 60, 40); // 60 x 40 from 10, 10
	cv::Rect rc3 = rc1 + cv::Size(50, 40); // 50 x 40 from 0, 0
	cv::Rect rc4 = rc2 + cv::Point(10, 10); // 60 x 40 from 20, 20
	cv::Rect rc5 = rc3 & rc4; // intersection
	cv::Rect rc6 = rc3 | rc4; // union

	std::cout << "Rect1: " << rc1 << "\n";
	std::cout << "Rect2: " << rc2 << "\n";
	std::cout << "Rect3: " << rc3 << "\n";
	std::cout << "Rect4: " << rc4 << "\n";
	std::cout << "Rect5: " << rc5 << "\n";
	std::cout << "Rect6: " << rc6 << "\n";

	cv::RotatedRect rr1(cv::Point2f(40, 30), cv::Size2f(40, 20), 30.f);
	cv::Point2f pts[4];

	rr1.points(pts);
	cv::Rect br = rr1.boundingRect();

	for (int i = 0; i < 4; ++i)
		std::cout << "Point" << (i + 1) << ": " << pts[i] << "\n";

	std::cout << "Bounding Rect: " << br << "\n";
}

void practice_3()
{
	Mat img1;
	Mat img2(480, 640, CV_8UC1);
	Mat img3(480, 640, CV_8UC3);
	Mat img4(Size(480, 640), CV_8UC1);
	Mat img5(480, 640, CV_8UC1, Scalar(128));
	Mat img6(Size(480, 640), CV_8UC3, Scalar(0, 0, 255));

	float data[] = { 1,2,3,4,5,6 };
	Mat mat1(2, 3, CV_32FC1, data);

	std::cout << mat1 << "\n";
	data[3] = 7;
	std::cout << mat1 << "\n";

	Mat mat2 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);

	std::cout << mat2 << "\n";

	mat1.create(2, 2, CV_8UC3);
	mat2.create(4, 4, CV_32FC1);

	std::cout << mat1 << "\n";
	std::cout << mat2 << "\n";

	mat1 = Scalar(255, 0, 0);
	mat2.setTo(1.f);
	std::cout << mat1 << "\n";
	std::cout << mat2 << "\n";
}


void practice_4()
{
	Mat img = imread("lenna.tif");

	Mat img2 = img; // ???? ????

	Mat img3 = img.clone(); // ???? ????
	Mat img4;
	img.copyTo(img4); // ???? ????

	img.setTo(Scalar(0, 255, 255));

	imshow("img1", img);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);

	waitKey();
	destroyAllWindows();
}

void practice_5()
{
	Mat img = imread("lenna.tif");
	Mat img2 = img(Rect(0, 0, 340, 240));
	Mat img3 = img(Range(0, 240), Range(0, 340)).clone();

	img2 = ~img2;

	imshow("img1", img);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();
	destroyAllWindows();
}

void practice_6()
{
	Mat mat = Mat::zeros(3, 4, CV_8UC1);

	for (int i = 0; i < mat.rows; ++i)
		for (int j = 0; j < mat.cols; ++j)
			mat.at<uchar>(i, j)++;

	std::cout << "Mat1: \n" << mat << "\n";

	Mat mat2 = Mat::zeros(3, 4, CV_8UC1);

	for (int i = 0; i < mat2.rows; ++i)
	{
		uchar* p = mat2.ptr<uchar>(i);
		for (int j = 0; j < mat2.cols; ++j)
			p[j]++;
	}

	std::cout << "Mat2: \n" << mat2 << "\n";

	Mat mat3 = Mat::zeros(3, 4, CV_8UC1);

	MatIterator_<uchar> iter;

	for (iter = mat3.begin<uchar>(); iter != mat3.end<uchar>(); iter++)
	{
		(*iter)++;
	}

	std::cout << "Mat3: \n" << mat3 << "\n";
}

void practice_7()
{
	Mat img = imread("lenna.tif");

	std::cout << "Width: " << img.cols << "\n";
	std::cout << "Height: " << img.rows << "\n";

	if (img.type() == CV_8UC1)
		std::cout << "img1 is a grayscale image\n";
	else if (img.type() == CV_8UC3)
		std::cout << "img1 is a truecolor image\n";

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);

	std::cout << "Mat1: \n" << mat1 << "\n";
}

void practice_8()
{
	float data[] = { 1,2,3,4 };
	Mat mat(2, 2, CV_32FC1, data);
	std::cout << "Mat1: \n" << mat << "\n";

	Mat mat2 = mat.inv();
	std::cout << "Mat2: \n" << mat2 << "\n";

	std::cout << "Mat1 Transpose: \n" << mat.t() << "\n";
	std::cout << "Mat1 + 3: \n" << mat + 3 << "\n";
	std::cout << "Mat1 + Mat2: \n" << mat + mat2 << "\n";
	std::cout << "Mat1 * Mat2: \n" << mat * mat2 << "\n";
}

void practice_9()
{
	Mat img = imread("lenna.tif", IMREAD_GRAYSCALE);

	Mat img1f;
	img.convertTo(img1f, CV_32FC1);

	// std::cout << img1f << "\n";

	uchar data[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Mat mat1(3, 4, CV_8UC1, data);
	Mat mat2 = mat1.reshape(0, 1);

	std::cout << mat1 << "\n";
	std::cout << mat2 << "\n";

	Mat mat3 = Mat::ones(2, 4, CV_8UC1) * 255;

	mat1.push_back(mat3);
	std::cout << mat1 << "\n";

	mat1.resize(10, 100);
	std::cout << mat1 << "\n";
}

void practice_10()
{
	Vec3b v1, v2(0, 255, 255);
	std::cout << "Vector1: " << v1 << "\n";
	std::cout << "Vector2: " << v2 << "\n";

	Scalar gray = 128;
	std::cout << "Scalar1: " << gray << "\n";

	Scalar yellow(0, 255, 255);
	std::cout << "Scalar2: " << yellow << "\n";

	Mat img1(256, 256, CV_8UC3, yellow);

	for (int i = 0; i < yellow.rows; ++i)
		std::cout << yellow[i] << " ";
	std::cout << "\n";

	imshow("img", img1);
	waitKey();

	destroyAllWindows();
}

void printMat(InputArray _mat)
{
	Mat mat = _mat.getMat();
	std::cout << mat << "\n";
}

void practice_11()
{
	uchar data[] = { 1,2,3,4,5,6 };
	Mat mat1(2, 3, CV_8U, data);
	printMat(mat1);

	std::vector<float> v1 = { 1.2f, 3.4f, -2.1f };
	printMat(v1);
}

void practice_12()
{
	VideoCapture cap("video.mp4");

	if (!cap.isOpened())
	{
		std::cerr << "Camera open failed\n";
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

void practice_13()
{
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0));

	line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);
	line(img, Point(250, 70), Point(350, 120), Scalar(255, 0, 255), 1, LINE_8);
	line(img, Point(250, 90), Point(350, 140), Scalar(0, 0, 255), 1, LINE_AA);

	arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);
	arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(255, 0, 255), 1);
	arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255, 0, 0), 1, LINE_AA, 0, 0.05);

	drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
	drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
	drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
	drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
	drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
	drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
	drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);

	imshow("img", img);
	waitKey(0);

	destroyAllWindows();
}

void drawPolys()
{
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);
	rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 255), -1);

	circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);
	circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);

	ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(255, 255, 0), -1, LINE_AA);
	ellipse(img, Point(120, 300), Size(100, 50), 20, 0, 360, Scalar(0, 255, 0), 2, LINE_AA);

	std::vector<Point> pts;
	pts.push_back(Point(250, 250));
	pts.push_back(Point(300, 250));
	pts.push_back(Point(300, 300));
	pts.push_back(Point(350, 300));
	pts.push_back(Point(350, 350));
	pts.push_back(Point(250, 350));
	polylines(img, pts, true, Scalar(255, 0, 255), 2);

	imshow("img", img);
	waitKey();
	destroyAllWindows();
}

void drawText1()
{
	Mat img(500, 800, CV_8UC3, Scalar(255, 255, 255));
	putText(img, "FONT_HERSHEY_SIMPLEX", Point(20, 50),
		FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1, 8);
	putText(img, "FONT_HERSHEY_PLAIN", Point(20, 100),
		FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_DUPLEX", Point(20, 150),
		FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_COMPLEX", Point(20, 200),
		FONT_HERSHEY_COMPLEX, 1, Scalar(255, 0, 0));
	putText(img, "FONT_HERSHEY_TRIPLEX", Point(20, 250),
		FONT_HERSHEY_TRIPLEX, 1, Scalar(255, 0, 0));
	putText(img, "FONT_HERSHEY_COMPLEX_SMALL", Point(20, 300),
		FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255, 0, 0));
	putText(img, "FONT_HERSHEY_SCRIPT_SIMPLEX", Point(20, 350),
		FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(255, 0, 255));
	putText(img, "FONT_HERSHEY_SCRIPT_COMPLEX", Point(20, 400),
		FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(255, 0, 255));
	putText(img, "FONT_HERSHEY_COMPLEX | FONT_ITALIC", Point(20, 450),
		FONT_HERSHEY_COMPLEX | FONT_ITALIC, 1, Scalar(255, 0, 0));

	imshow("img", img);
	waitKey();
	destroyAllWindows();
}

void drawText2()
{
	Mat img(240, 640, CV_8UC3, Scalar(255, 255, 255));

	const String text = "Hello, OpenCV";
	const int fontFace = FONT_HERSHEY_TRIPLEX;
	const double font_scale = 2.0;
	const int thickness = 1;

	Size textSize = getTextSize(text, fontFace, font_scale, thickness, 0);
	Size sizeImage = img.size();

	Point org(((sizeImage.width - textSize.width) / 2), (sizeImage.height + textSize.height) / 2);
	putText(img, text, org, fontFace, font_scale, Scalar(255, 0, 0), thickness, false); // ???? ?????? ???????? ????

	rectangle(img, org, org + Point(textSize.width, -textSize.height),
		Scalar(255, 0, 0), 1);

	imshow("img", img);
	waitKey();
	destroyAllWindows();
}

void keyboard()
{

	Mat img = imread("lenna.tif", IMREAD_GRAYSCALE);

	if (img.empty())
	{
		std::cerr << "Image load failed!\n";
	}

	namedWindow("img");
	imshow("img", img);

	while (1)
	{
		int key = waitKey();

		if (key == 'i' || key == 'I')
		{
			img = ~img;
			imshow("img", img);
		}
		else if (key == 27)
			break;
	}

	destroyAllWindows();
}

bool isEmpty(Mat& img)
{
	if (img.empty())
	{
		std::cerr << "Image load failed!\n";
		return true;
	}
	else
		return false;

}

Mat mouse_img, mouse_org;
Point ptOld;

void onMouse(int evt, int x, int y, int flags, void* userdata)
{
	switch (evt)
	{
	case EVENT_LBUTTONDOWN:
		ptOld = Point(x, y);
		std::cout << "Event_LBUTTONDOWN: " << x << ", " << y << "\n";
		break;
	case EVENT_LBUTTONUP:
		std::cout << "Event_LBUTTONUP: " << x << ", " << y << "\n";
		break;
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON)
		{
			line(mouse_img, ptOld, Point(x, y), Scalar(0, 255, 255), 2);
			imshow("img", mouse_img);
			ptOld = Point(x, y);
		}
		break;
	case EVENT_RBUTTONDOWN:
		mouse_org.copyTo(mouse_img);
		std::cout << "Event_RBUTTONDOWN: " << x << ", " << y << "\n";
		imshow("img", mouse_img);
		break;
	case EVENT_RBUTTONUP:
		std::cout << "Event_RBUTTONUP: " << x << ", " << y << "\n";
		break;
	default:
		break;
	}
}

void mouse()
{
	mouse_img = imread("lenna.tif");
	mouse_img.copyTo(mouse_org);

	namedWindow("img");
	setMouseCallback("img", onMouse);

	imshow("img", mouse_img);
	waitKey();
}

void on_level_change(int pos, void* userdata)
{
	Mat img = *(Mat*)userdata;
	img.setTo(pos);
	imshow("img", img);
}

void trackbar_practice()
{
	Mat img = Mat::zeros(400, 400, CV_8UC1);

	namedWindow("img");
	createTrackbar("Level", "img", 0, 255, on_level_change, (void*)&img);

	imshow("img", img);
	waitKey();
}

void writeData(String filename)
{
	String name = "Jane";
	int age = 10;
	Point pt(100, 200);
	std::vector<int> score = { 80, 90, 50 };
	Mat mat = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

	FileStorage fs(filename, FileStorage::WRITE);

	if (!fs.isOpened())
	{
		std::cerr << "File open failed!\n";
		return;
	}

	fs << "name" << name;
	fs << "age" << age;
	fs << "point" << pt;
	fs << "score" << score;
	fs << "data" << mat;

	fs.release();
}

void readData(String filename)
{
	String name;
	int age;
	Point pt;
	std::vector<int> scores;
	Mat mat;
	
	FileStorage fs(filename, FileStorage::READ);

	if (!fs.isOpened())
	{
		std::cerr << "File open failed\n";
		return;
	}

	fs["name"] >> name;
	fs["age"] >> age;
	fs["point"] >> pt;
	fs["score"] >> scores;
	fs["data"] >> mat;

	fs.release();

	std::cout << "name: " << name << "\n";
	std::cout << "age: " << age << "\n";
	std::cout << "point: " << pt << "\n";
	std::cout << "scores: " << Mat(scores).t() << "\n";
	std::cout << "data:\n " << mat << "\n";
}

void mask_setTo()
{
	Mat src = imread("lenna.tif");
	Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src) || isEmpty(mask))
		return;

	src.setTo(Scalar(0, 0, 0), mask);

	imshow("src", src);
	imshow("mask", mask);

	waitKey();
	destroyAllWindows();
}

void mask_copyTo()
{
	Mat src = imread("airplane.bmp");
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("field.bmp", IMREAD_COLOR);

	if (isEmpty(src) | isEmpty(mask) | isEmpty(dst))
		return;

	src.copyTo(dst, mask);

	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void time_copyTo()
{
	TickMeter tm;
	tm.start();
	Mat src = imread("airplane.bmp");
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("field.bmp", IMREAD_COLOR);

	if (isEmpty(src) | isEmpty(mask) | isEmpty(dst))
		return;

	src.copyTo(dst, mask);
	tm.stop();
	std::cout << " Image Copy To Dst " << tm.getTimeMilli() << "ms. \n";
	imshow("dst", dst);
	waitKey();
	destroyAllWindows();
}

void util()
{
	Mat img = imread("Lenna.bmp", IMREAD_GRAYSCALE);

	std::cout << "Sum: " << sum(img) << "\n";
	std::cout << "Avg: " << mean(img) << "\n";

	double minVal, maxVal;
	Point minPos, maxPos;
	minMaxLoc(img, &minVal, &maxVal, &minPos, &maxPos);

	std::cout << "minVal: " << minVal << " at " << minPos << "\n";
	std::cout << "maxVal: " << maxVal << " at " << maxPos << "\n";

	Mat src = (Mat_<float>(1, 5) << -1.f, -0.5f, 0.f, 0.5f, 1.f);

	Mat dst;
	normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);

	std::cout << "src: " << src << "\n";
	std::cout << "dst: " << dst << "\n";

	std::cout << "cvRound(2.5): " << cvRound(2.5) << "\n";
	std::cout << "cvRound(2.51): " << cvRound(2.51) << "\n";
	std::cout << "cvRound(3.4999): " << cvRound(3.4999) << "\n";
	std::cout << "cvRound(3.5): " << cvRound(3.5) << "\n";
}

void brightness_1()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (isEmpty(src))
		return;

	Mat dst = src + 100;

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	destroyAllWindows();
}

void brightness_2()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (isEmpty(src))
		return;
	
	Mat dst(src.rows, src.cols, src.type());
	for (int i = 0; i < src.rows; ++i)
	{
		for (int j = 0; j < src.cols; ++j)
		{
			if (src.at<uchar>(i, j) > 155)
				dst.at<uchar>(i, j) = 255;
			else
				dst.at<uchar>(i, j) = src.at<uchar>(i, j) + 100;
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	destroyAllWindows();
}

void brightness_3()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (isEmpty(src))
		return;

	Mat dst(src.rows, src.cols, src.type());
	for (int i = 0; i < src.rows; ++i)
		for (int j = 0; j < src.cols; ++j)
			dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) + 100);
	

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	destroyAllWindows();
}

void on_brightness(int pos, void* userdata)
{
	Mat dst = (* (Mat*)userdata) + pos;
	imshow("dst", dst);
}

void brightness_trackbar()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	namedWindow("dst");
	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
	on_brightness(0, (void*)&src);

	waitKey();
	destroyAllWindows();
}

void contrast_1()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	namedWindow("dst");

	Mat dst = src * 2.f;
	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	destroyAllWindows();
}

void contrast_2()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	namedWindow("dst");

	float a = 1.f;
	Mat dst = src + (src - 128) * a;

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	destroyAllWindows();
}

void GrayHistImage()
{
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	CV_Assert(img.type() == CV_8UC1);

	Mat hist;
	int channel[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float grayLevel[] = { 0, 256 };
	const float* ranges[] = { grayLevel };

	calcHist(&img, 1, channel, noArray(), hist, dims, histSize, ranges);

	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imageHist(100, 256, CV_8UC1, Scalar(255));
	
	for (int i = 0; i < 256; ++i)
		line(imageHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));

	imshow("histogram", imageHist);
	waitKey();

	destroyAllWindows();
}

Mat calcGrayHist(const Mat& img)
{
	CV_Assert(img.type() == CV_8UC1);
	Mat hist;
	int channel[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float grayLevel[] = { 0, 256 };
	const float* ranges[] = { grayLevel };

	calcHist(&img, 1, channel, noArray(), hist, dims, histSize, ranges);

	return hist;
}

Mat calcGrayHistImage(const Mat& hist)
{
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imageHist(100, 256, CV_8UC1, Scalar(255));

	for (int i = 0; i < 256; ++i)
		line(imageHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));

	return imageHist;
}

void compareHist()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	float a = 0.2f;
	Mat dst_1 = src + (src - 128) * a;
	float b = 0.6f;
	Mat dst_2 = src * b + 50;

	imshow("src", calcGrayHistImage(calcGrayHist(src)));
	imshow("dst1", calcGrayHistImage(calcGrayHist(dst_1)));
	imshow("dst2", calcGrayHistImage(calcGrayHist(dst_2)));
	waitKey();
	destroyAllWindows();
}

void histogram_stretching()
{
	Mat src = imread("hawkes.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	double gmin, gmax;
	minMaxLoc(src, &gmin, &gmax);

	Mat dst = (src - gmin) / (gmax - gmin) * 255;

	imshow("src", src);
	Mat hist_src = calcGrayHistImage(calcGrayHist(src));
	imshow("hist_src", hist_src);
	imshow("dst", dst);
	Mat hist_dst = calcGrayHistImage(calcGrayHist(dst));
	imshow("hist_dst", hist_dst);
	waitKey();
	destroyAllWindows();
}

void histogram_equalization()
{
	Mat src = imread("hawkes.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Mat dst;
	equalizeHist(src, dst);

	imshow("src", src);
	Mat hist_src = calcGrayHistImage(calcGrayHist(src));
	imshow("hist_src", hist_src);
	imshow("dst", dst);
	Mat hist_dst = calcGrayHistImage(calcGrayHist(dst));
	imshow("hist_dst", hist_dst);
	
	waitKey();
	destroyAllWindows();
}

void arithmetic()
{
	Mat src1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
	Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src1) || isEmpty(src2))
		return;

	imshow("src1", src1);
	imshow("src2", src2);

	Mat dst1, dst2, dst3, dst4;

	add(src1, src2, dst1);
	addWeighted(src1, 0.5, src2, 0.5, 0, dst2);
	subtract(src1, src2, dst3);
	absdiff(src1, src2, dst4);

	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);
	waitKey();

	destroyAllWindows();
}

void logical()
{
	Mat src1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
	Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src1) || isEmpty(src2))
		return;

	imshow("src1", src1);
	imshow("src2", src2);

	Mat dst1, dst2, dst3, dst4;
	bitwise_and(src1, src2, dst1);
	bitwise_or(src1, src2, dst2);
	bitwise_xor(src1, src2, dst3);
	bitwise_not(src1, dst4);

	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);
	waitKey();

	destroyAllWindows();
}

void filter_embossing()
{
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	float data[] = { -1,-1,0, -1, 0,1,0,1,1 };
	Mat emboss(3, 3, CV_32FC1, data);

	Mat dst;

	filter2D(src, dst, -1, emboss, Point(-1, -1), 128);

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void blurring_mean()
{
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	imshow("src", src);

	Mat dst;

	for (int size = 3; size <= 7; size += 2)
	{
		blur(src, dst, Size(size, size));
		String desc = format("Mean: %dx%d", size, size);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_COMPLEX, 1.0, Scalar(255), 1, LINE_AA);

		imshow("dst", dst);
		waitKey();
	}
	destroyAllWindows();
}

void blurring_gaussian()
{
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	imshow("src", src);

	Mat dst;

	for (int sigma = 1; sigma <= 5; ++sigma)
	{
		GaussianBlur(src, dst, Size(), (double)sigma);
		String desc = format("Sigma: %d", sigma);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_COMPLEX, 1.0, Scalar(255), 1, LINE_AA);

		imshow("dst", dst);
		waitKey();
	}
	destroyAllWindows();
}

void unsharp_mask()
{
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	imshow("src", src);
	
	for (int sigma = 1; sigma <= 5; ++sigma)
	{
		Mat blur;
		GaussianBlur(src, blur, Size(), sigma);
		float alpha = 1.f;

		Mat dst = (1.f + alpha) * src - alpha * blur;

		String desc = format("sigma: %d", sigma);

		putText(dst, desc, Point(10, 30), FONT_HERSHEY_COMPLEX, 1.0, Scalar(255), 1, LINE_AA);

		imshow("dst", dst);
		waitKey();
	}
	destroyAllWindows();
}

void noise_gaussian()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	imshow("src", src);
	
	for (int std = 0; std <= 30; std += 1)
	{
		Mat noise(src.size(), CV_32SC1);
		randn(noise, 0, std);

		Mat dst;
		add(src, noise, dst, Mat(), CV_8U);

		String desc = format("std: %d", std);

		putText(dst, desc, Point(10, 30), FONT_HERSHEY_COMPLEX, 1.0, Scalar(255), 1, LINE_AA);

		imshow("dst", dst);
		waitKey();
	}
	destroyAllWindows();
}

void filter_bilateral()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Mat noise(src.size(), CV_32SC1);
	randn(noise, 0, 3);
	add(src, noise, src, Mat(), CV_8U);

	Mat dst;
	GaussianBlur(src, dst, Size(), 3);

	Mat dst2;
	bilateralFilter(src, dst2, -1, 10, 3);

	imshow("src", src);
	imshow("dst", dst);
	imshow("dst2", dst2);
	waitKey();

	destroyAllWindows();
}

void filter_median()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	int num = (int)(src.total() * 0.1);
	for (int i = 0; i < num; ++i)
	{
		int x = rand() % src.cols;
		int y = rand() % src.rows;
		src.at<uchar>(x, y) = (i & 1) ? 0 : 255;
	}

	Mat dst;
	GaussianBlur(src, dst, Size(), 1);

	Mat dst2;
	medianBlur(src, dst2, 3);

	imshow("src", src);
	imshow("dst", dst);
	imshow("dst2", dst2);
	waitKey();

	destroyAllWindows();
}

void affine_transform()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Point2f srcPts[3], dstPts[3];
	srcPts[0] = Point2f(0, 0);
	srcPts[1] = Point2f(src.cols-1.0, 0);
	srcPts[2] = Point2f(src.cols - 1.0, src.rows - 1.0);
	
	dstPts[0] = Point2f(10, 10);
	dstPts[1] = Point2f(src.cols - 20, 20);
	dstPts[2] = Point2f(src.cols - 10, src.rows - 10);

	Mat M = getAffineTransform(srcPts, dstPts);

	Mat dst;
	warpAffine(src, dst, M, Size());

	imshow("src", src);
	imshow("dst", dst);

	waitKey();

	destroyAllWindows();
}

void affine_translation()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Mat M = Mat_<double>({ 2, 3 }, { 1, 0, 150, 0, 1, 100 });


	Mat dst;
	warpAffine(src, dst, M, Size());

	imshow("src", src);
	imshow("dst", dst);

	waitKey();

	destroyAllWindows();
}

void affine_shear()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	double mx=0.1, my=0.1;
	Mat M = Mat_<double>({ 2, 3 }, { 1, mx, 0, 0, 1, 0 });


	Mat dst;
	warpAffine(src, dst, M, Size(src.cols + src.rows * mx, src.rows));

	Mat M2 = Mat_<double>({ 2, 3 }, { 1, 0, 0, my, 1, 0 });


	Mat dst2;
	warpAffine(src, dst2, M2, Size(src.cols, src.rows + src.cols * my));

	imshow("src", src);
	imshow("dst", dst);
	imshow("dst2", dst2);

	waitKey();

	destroyAllWindows();
}


void affine_scale()
{
	Mat src = imread("rose.bmp");

	if (isEmpty(src))
		return;
	Mat dst, dst2, dst3, dst4;

	resize(src, dst, Size(), 4, 4, INTER_NEAREST);
	resize(src, dst2, Size(1920, 1280));
	resize(src, dst3, Size(1920, 1280), 0, 0, INTER_CUBIC);
	resize(src, dst4, Size(1920, 1280), 0, 0, INTER_LANCZOS4);

	imshow("src", src);
	imshow("dst1", dst(Rect(400, 500, 400, 400)));
	imshow("dst2", dst2(Rect(400, 500, 400, 400)));
	imshow("dst3", dst3(Rect(400, 500, 400, 400)));
	imshow("dst4", dst4(Rect(400, 500, 400, 400)));

	waitKey();

	destroyAllWindows();
}

void affine_rotation()
{
	Mat src = imread("rose.bmp");

	if (isEmpty(src))
		return;
	Mat dst;
	Point2f cp(src.cols, src.rows);
	Mat M = getRotationMatrix2D(cp, 20, 1);

	warpAffine(src, dst, M, Size());
	imshow("src", src);
	imshow("dst", dst);

	waitKey();

	destroyAllWindows();
}


void affine_flip()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Mat dst, dst2;
	int flipCode[] = { 1 , 0 ,-1 };
	Mat M2[] = {
		Mat_<double>({ 2, 3 }, { -1, 0, (double)src.cols - 1, 0, 1 , 0 }),
		Mat_<double>({ 2, 3 }, { 1, 0, 0, 0, -1, (double)src.rows - 1 }),
		Mat_<double>({ 2, 3 }, { -1, 0, (double)src.cols - 1, 0, -1, (double)src.rows - 1 }) };
	imshow("src", src);
	for (int i = 0; i < 3; ++i)
	{
		flip(src, dst, flipCode[i]);
		warpAffine(src, dst2, M2[i], Size());
		String desc = format("flipcode: %d", flipCode[i]);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_COMPLEX, 1, Scalar(255), 1, LINE_AA);
		putText(dst2, desc, Point(10, 30), FONT_HERSHEY_COMPLEX, 1, Scalar(255), 1, LINE_AA);
		
		imshow("dst", dst);
		imshow("dst2", dst2);
		waitKey();
	}

	destroyAllWindows();
}

Mat perspective_src;
Point2f srcQuad[4], dstQuad[4];
void on_mouse(int evt, int x, int y, int flag, void* userdata)
{
	static int cnt = 0;

	if (evt == EVENT_LBUTTONDOWN)
	{
		if (cnt < 4)
		{
			srcQuad[cnt++] = Point2f(x, y);

			circle(perspective_src, Point(x, y), 5, Scalar(255, 0, 0), -1);
			imshow("src", perspective_src);
			if (cnt == 4)
			{
				int w = 200, h = 300;
				dstQuad[0] = Point2f(0, 0);
				dstQuad[1] = Point2f(w-1, 0);
				dstQuad[2] = Point2f(w-1, h-1);
				dstQuad[3] = Point2f(0, h-1);

				Mat pers = getPerspectiveTransform(srcQuad, dstQuad);

				Mat dst;
				warpPerspective(perspective_src, dst, pers, Size(w, h));

				imshow("dst", dst);
			}
		}
	}
}

void perspective()
{
	perspective_src = imread("card.bmp");

	if (isEmpty(perspective_src))
		return;

	namedWindow("src");
	setMouseCallback("src", on_mouse);

	imshow("src", perspective_src);
	waitKey();
}

void sobel_derivate()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Mat mx = Mat_<float>({ 1, 3 }, { -1, 0 ,1 });
	Mat my = Mat_<float>({ 3, 1 }, { -1, 0 ,1 });

	Mat dx, dy;

	filter2D(src, dx, -1, mx, Point(-1, -1), 128);
	filter2D(src, dy, -1, my, Point(-1, -1), 128);

	imshow("src", src);
	imshow("dx", dx);
	imshow("dy", dy);

	waitKey();
	destroyAllWindows();
}

void sobel_edge()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Mat dx, dy;
	Sobel(src, dx, CV_32FC1, 1, 0);
	Sobel(src, dy, CV_32FC1, 0, 1);

	Mat fmag, mag;

	magnitude(dx, dy, fmag);
	fmag.convertTo(mag, CV_8UC1);

	Mat edge = mag > 120;

	imshow("src", src);
	imshow("mag", mag);
	imshow("edge", edge);

	waitKey();
	destroyAllWindows();
}

void canny_edge()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Mat dst, dst2;

	Canny(src, dst, 50, 100);
	Canny(src, dst2, 50, 150);

	imshow("src", src);
	imshow("dst1", dst);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
}

void hough_lines()
{
	Mat src = imread("building.jpg", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;
	
	Mat edge;
	Canny(src, edge, 50, 150);

	std::vector<Vec2f> lines;
	HoughLines(edge, lines, 1, CV_PI / 180, 250);

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	for (size_t i = 0; i < lines.size(); ++i)
	{
		float r = lines[i][0], t = lines[i][1];
		double cos_t = cos(t), sin_t = sin(t);
		double x0 = r * cos_t, y0 = r * sin_t;
		double alpha = 1000;

		Point pt1(cvRound(x0 + alpha * (-sin_t)), cvRound(y0 + alpha * cos_t));
		Point pt2(cvRound(x0 - alpha * (-sin_t)), cvRound(y0 - alpha * cos_t));

		line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void hough_lines_segment()
{
	Mat src = imread("building.jpg", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Mat edge;
	Canny(src, edge, 50, 150);

	std::vector<Vec4i> lines;
	HoughLinesP(edge, lines, 1, CV_PI / 180, 160, 50, 5);

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	for (Vec4i l : lines)
	{
		line(dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void hough_circle()
{
	Mat src = imread("coins.png", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Mat blurred;
	blur(src, blurred, Size(3, 3));

	std::vector<Vec3f> circles;
	HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, 50, 150, 30);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (Vec3i c : circles)
	{
		Point center(cvRound(c[0]), cvRound(c[1]));
		int radius = cvRound(c[2]);
		circle(dst, center, radius, Scalar(0, 0, 255), 1, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void color_inverse()
{
	Mat src = imread("butterfly.jpg", IMREAD_COLOR);
	if (isEmpty(src))
		return;
	
	Mat dst(src.rows, src.cols, src.type());
	Mat dst2(src.rows, src.cols, src.type());

	for (int i = 0; i < src.rows; ++i)
	{
		for (int j = 0; j < src.cols; ++j)
		{
			Vec3b& p1 = src.at<Vec3b>(i, j);
			Vec3b& p2 = dst.at<Vec3b>(i, j);

			p2[0] = 255 - p1[0];
			p2[1] = 255 - p1[1];
			p2[2] = 255 - p1[2];
		}
	}
	MatIterator_<Vec3b> iter;
	MatIterator_<Vec3b> iter2 = dst2.begin<Vec3b>();
	for (iter = src.begin<Vec3b>(); iter != src.end<Vec3b>(); iter++)
	{
		(*iter2) = Vec3b(255, 255, 255) - (*iter);
		iter2++;
	}

	imshow("src", src);
	imshow("dst", dst);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
}

void color_split()
{
	Mat src = imread("candies.png");

	if (isEmpty(src))
		return;
	
	std::vector<Mat> v;
	split(src, v);
	imshow("src", src);
	imshow("B_plane", v[0]);
	imshow("G_plane", v[1]);
	imshow("R_plane", v[2]);

	waitKey();
	destroyAllWindows();
}

void color_eq()
{
	Mat src = imread("pepper.bmp", IMREAD_COLOR);

	if (isEmpty(src))
		return;

	Mat src_ycbcr;
	cvtColor(src, src_ycbcr, COLOR_BGR2YCrCb);

	std::vector<Mat> ycrcb_plane;
	split(src_ycbcr, ycrcb_plane);

	equalizeHist(ycrcb_plane[0], ycrcb_plane[0]);

	Mat dst, dst2;

	merge(ycrcb_plane, dst);
	cvtColor(dst, dst2, COLOR_YCrCb2BGR);
	
	imshow("src", src);
	imshow("dst", dst2);

	waitKey();
	destroyAllWindows();
}

Mat range_src, range_src_hsv, mask;
int lower_hue = 40, upper_hue = 80;
void on_hue_changed(int, void* userdata)
{
	Scalar lowerb(lower_hue, 100, 0);
	Scalar upperb(upper_hue, 255, 255);
	inRange(range_src_hsv, lowerb, upperb, mask);
	imshow("mask", mask);
}

void range_extraction()
{
	range_src = imread("candies.png", IMREAD_COLOR);

	if (isEmpty(range_src))
		return;

	imshow("src", range_src);
	cvtColor(range_src, range_src_hsv, COLOR_BGR2HSV);

	namedWindow("mask");
	createTrackbar("LowerHue", "mask", &lower_hue, 179, on_hue_changed);
	createTrackbar("UpperHue", "mask", &upper_hue, 179, on_hue_changed);
	on_hue_changed(0, 0);

	waitKey();
}

void backproject()
{
	Mat ref, ref_ycrcb, mask;
	ref = imread("ref.png", IMREAD_COLOR);
	mask = imread("mask.bmp", IMREAD_GRAYSCALE);
	cvtColor(ref, ref_ycrcb, COLOR_BGR2YCrCb);

	Mat hist;
	int channels[] = { 1, 2 };
	int cr_bins = 128; int cb_bins = 128;
	int histSize[] = { cr_bins, cb_bins };
	float cr_range[] = { 0, 256 };
	float cb_range[] = { 0, 256 };
	const float* ranges[] = { cr_range, cb_range };


	calcHist(&ref_ycrcb, 1, channels, mask, hist, 2, histSize, ranges);

	Mat src, src_ycrcb;
	src = imread("kids.png", IMREAD_COLOR);
	cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);

	Mat backproj;
	calcBackProject(&src_ycrcb, 1, channels, hist, backproj, ranges, 1, true);

	imshow("src", src);
	imshow("backproj", backproj);
	imshow("hist", hist);

	waitKey();
	destroyAllWindows();
}

void on_threshold(int pos, void* userdata)
{
	Mat src = *(Mat*)userdata;

	Mat dst;
	threshold(src, dst, pos, 255, THRESH_BINARY);
	imshow("dst", dst);
}

void threshold()
{
	Mat src;
	
	src = imread("neutrophils.png", IMREAD_GRAYSCALE);
	if (isEmpty(src))
		return;

	imshow("src", src);

	namedWindow("dst");
	createTrackbar("Threshold", "dst", 0, 255, on_threshold, (void*)&src);
	setTrackbarPos("Threshold", "dst", 128);
	waitKey();
	destroyAllWindows();
}

void on_ada_threshold(int pos, void* userdata)
{
	Mat src = *(Mat*)userdata;

	Mat dst;
	int bsize = pos;
	if (bsize < 3)
		bsize = 3;
	if (!(bsize & 1))
		--bsize;

	adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bsize, 5);
	imshow("dst", dst);
}

void adaptive_threshold()
{
	Mat src;

	src = imread("sudoku.jpg", IMREAD_GRAYSCALE);
	if (isEmpty(src))
		return;

	imshow("src", src);

	namedWindow("dst");
	createTrackbar("Threshold", "dst", 0, 200, on_ada_threshold, (void*)&src);
	setTrackbarPos("Threshold", "dst", 11);
	waitKey();
	destroyAllWindows();
}

void erode_dilate()
{
	Mat src = imread("milkdrop.bmp", IMREAD_GRAYSCALE);
	
	if (isEmpty(src))
		return;
	Mat bin;
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Mat dst, dst2;
	erode(bin, dst, Mat());
	dilate(bin, dst2, Mat());

	imshow("src", src);
	imshow("bin", bin);
	imshow("dst", dst);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
}

void open_close()
{
	Mat src = imread("milkdrop.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;
	Mat bin;
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Mat dst, dst2;
	morphologyEx(bin, dst, MORPH_OPEN, Mat());
	morphologyEx(bin, dst2, MORPH_CLOSE, Mat());

	imshow("src", src);
	imshow("bin", bin);
	imshow("dst", dst);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
}

void labeling_basic()
{
	uchar data[] = {
		0, 0, 1, 1, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 0, 1, 0,
		1, 1, 1, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 1, 0,
		0, 0, 0, 1, 1, 1, 1, 0,
		0, 0, 0, 1, 0, 0, 1, 0,
		0, 0, 1, 1, 1, 1, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	Mat src = Mat(8, 8, CV_8UC1, data) * 255;

	Mat labels;
	int cnt = connectedComponents(src, labels);

	std::cout << "src: \n" << src << "\n";
	std::cout << "labels: \n" << labels << "\n";
	std::cout << "number of cnt: \n" << cnt << "\n";
}

void labeling_stats()
{
	Mat src = imread("keyboard.bmp", IMREAD_GRAYSCALE);
	if (isEmpty(src))
		return;

	Mat bin;
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Mat labels, stats, centroids;
	int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);

	Mat dst;

	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int i = 1; i < cnt; ++i)
	{
		int* p = stats.ptr<int>(i);
		if (p[4] < 20)
			continue;
		rectangle(dst, Rect(p[0], p[1], p[2], p[3]), Scalar(0, 255, 255), 2);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void contour_basic()
{
	Mat src = imread("contours.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	std::vector<std::vector<Point>> contours;
	findContours(src, contours, RETR_LIST, CHAIN_APPROX_NONE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int i = 0; i < contours.size(); ++i)
	{
		Scalar c(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, i, c, 2);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void contours_hier()
{
	Mat src = imread("contours.bmp", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;
	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	findContours(src, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int idx = 0; idx >= 0; idx = hierarchy[idx][0])
	{
		Scalar c(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, idx, c, -1, LINE_8, hierarchy);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void setLabel(Mat& img, const std::vector<Point>& pts, const String& label)
{
	Rect rc = boundingRect(pts);
	rectangle(img, rc, Scalar(0, 0, 255), 1);
	putText(img, label, rc.tl(), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255));
}

void label_grigi()
{
	Mat img = imread("polygon.bmp", IMREAD_COLOR);

	if (isEmpty(img))
		return;

	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);

	Mat bin;
	threshold(gray, bin, 200, 255, THRESH_BINARY_INV | THRESH_OTSU);

	std::vector<std::vector<Point>> contours;
	findContours(bin, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	for (std::vector<Point>& pts : contours)
	{
		if (contourArea(pts) < 400)
			continue;

		std::vector<Point> approx;
		approxPolyDP(pts, approx, arcLength(pts, true) * 0.02, true);

		int vtc = (int)approx.size();

		if (vtc == 3)
		{
			setLabel(img, pts, "TRI");
		}
		else if (vtc == 4)
		{
			setLabel(img, pts, "RECT");
		}
		else if (vtc > 4)
		{
			double len = arcLength(pts, true);
			double area = contourArea(pts);
			double ratio = 4. * CV_PI * area / (len * len);
			
			if(ratio > 0.8)
				setLabel(img, pts, "CIR");
		}
	}

	imshow("img", img);
	waitKey();
}

void template_matching()
{
	Mat img = imread("circuit.bmp", IMREAD_COLOR);
	Mat templ = imread("crystal.bmp", IMREAD_COLOR);

	if (isEmpty(img) | isEmpty(templ))
		return;

	img += Scalar(50, 50, 50);

	Mat noise(img.size(), CV_32SC3);
	randn(noise, 0, 10);
	add(img, noise, img, Mat(), CV_8UC3);

	Mat res, res_norm;
	matchTemplate(img, templ, res, TM_CCOEFF_NORMED);
	normalize(res, res_norm, 0, 255, NORM_MINMAX, CV_8U);

	double maxv;
	Point maxloc;
	minMaxLoc(res, 0, &maxv, 0, &maxloc);
	std::cout << "max value: " << maxv << "\n";
	rectangle(img, Rect(maxloc.x, maxloc.y, templ.cols, templ.rows), Scalar(0,0,255), 2);

	imshow("templ", templ);
	imshow("res_norm", res_norm);
	imshow("img", img);

	waitKey();
	destroyAllWindows();
}

void detect_face()
{
	Mat src = imread("kids.png");
	
	if (isEmpty(src))
		return;

	CascadeClassifier classifier("haarcascade_frontalface_default.xml");

	if (classifier.empty()) {
		std::cerr << "Xml load fail!\n";
		return;
	}

	std::vector<Rect> faces;
	classifier.detectMultiScale(src, faces);

	for (Rect rc : faces)
	{
		rectangle(src, rc, Scalar(0, 0, 255), 2);
	}

	imshow("src", src);
	waitKey();
	destroyAllWindows();

}

void detect_eye()
{
	Mat src = imread("kids.png");

	if (isEmpty(src))
		return;

	CascadeClassifier classifier("haarcascade_frontalface_default.xml");
	CascadeClassifier eye_classifier("haarcascade_eye.xml");

	if (classifier.empty() | eye_classifier.empty())
	{
		std::cerr << "Xml load failed\n";
		return;
	}

	std::vector<Rect> faces;
	classifier.detectMultiScale(src, faces);
	for (Rect rc : faces)
	{
		rectangle(src, rc, Scalar(0, 0, 255), 2);

		Mat faceROI = src(rc);
		std::vector<Rect> eyes;
		eye_classifier.detectMultiScale(faceROI, eyes);
		for (Rect eye : eyes)
		{
			Point center(eye.x + eye.width / 2, eye.y + eye.height / 2);
			circle(faceROI, center, eye.width / 2, Scalar(0, 255, 0), 2);
		}
	}

	imshow("src", src);
	waitKey();
	destroyAllWindows();
}

void hog()
{
	VideoCapture cap("vtest.avi");

	if (!cap.isOpened())
	{
		std::cerr << "Video open failed!\n";
		return;
	}

	HOGDescriptor hog;
	hog.setSVMDetector(hog.getDefaultPeopleDetector());

	Mat frame;
	while (true)
	{
		cap >> frame;
		if (frame.empty())
			break;

		std::vector<Rect> detected;
		hog.detectMultiScale(frame, detected);

		for (Rect r : detected)
		{
			Scalar c = Scalar(rand() & 255, rand() & 255, rand() & 255);
			rectangle(frame, r, c, 1);
		}

		imshow("frame", frame);
		if (waitKey(10) == 27)
			break;
	}
}
void decode_qrcode()
{

}

void harris_corner()
{
	Mat src = imread("building.jpg", IMREAD_GRAYSCALE);
	if (isEmpty(src))
		return;

	Mat harris;
	cornerHarris(src, harris, 3, 3, 0.04);

	Mat harris_norm;
	normalize(harris, harris_norm, 0, 255, NORM_MINMAX, CV_8U);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int j = 1; j < harris.rows - 1; ++j)
	{
		for (int i = 1; i < harris.cols - 1; ++i)
		{
			if (harris_norm.at<uchar>(j, i) > 120)
			{
				if (harris.at<float>(j, i) > harris.at<float>(j - 1, i) &&
					harris.at<float>(j, i) > harris.at<float>(j + 1, i) &&
					harris.at<float>(j, i) > harris.at<float>(j, i - 1) &&
					harris.at<float>(j, i) > harris.at<float>(j, i + 1))
				{
					circle(dst, Point(i, j), 5, Scalar(0, 0, 255), 2);
				}
			}
		}
	}

	imshow("src", src);
	imshow("harris_norm", harris_norm);
	imshow("dst", dst);
	
	waitKey();
	destroyAllWindows();
}

void fast_corner()
{
	Mat src = imread("building.jpg", IMREAD_GRAYSCALE);
	
	if (isEmpty(src))
		return;

	std::vector<KeyPoint> keypoints;
	FAST(src, keypoints, 90, true);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (const KeyPoint kp : keypoints)
	{
		Point pt(cvRound(kp.pt.x), cvRound(kp.pt.y));
		circle(dst, pt, 5, Scalar(0, 0, 255), 2);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}


void detect_keypoints()
{
	Mat src = imread("box_in_scene.png", IMREAD_GRAYSCALE);

	if (isEmpty(src))
		return;

	Ptr<Feature2D> feature = ORB::create();

	std::vector<KeyPoint> keypoints;
	Mat desc;

	feature->detectAndCompute(src, Mat(), keypoints, desc);

	std::cout << "Keypoint size: " << keypoints.size() << "\n";
	std::cout << "descripter size: " << desc.size() << "\n";

	Mat dst;
	drawKeypoints(src, keypoints, dst, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

	imshow("src", src);
	imshow("dst", dst);
	
	waitKey();
	destroyAllWindows();
}

void keypoint_matching()
{
	Mat src1 = imread("box.png", IMREAD_GRAYSCALE);
	Mat src2 = imread("box_in_scene.png", IMREAD_GRAYSCALE);

	if (isEmpty(src1) || isEmpty(src2))
		return;

	Ptr<Feature2D> feature = ORB::create();

	std::vector<KeyPoint> keypoint1, keypoint2;
	Mat desc1, desc2;

	feature->detectAndCompute(src1, Mat(), keypoint1, desc1);
	feature->detectAndCompute(src2, Mat(), keypoint2, desc2);

	Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);

	std::vector<DMatch> matches;
	matcher->match(desc1, desc2, matches);

	Mat dst;
	drawMatches(src1, keypoint1, src2, keypoint2, matches, dst);

	imshow("dst", dst);
	
	waitKey();
	destroyAllWindows();
}

void good_matching()
{
	Mat src1 = imread("box.png", IMREAD_GRAYSCALE);
	Mat src2 = imread("box_in_scene.png", IMREAD_GRAYSCALE);

	if (isEmpty(src1) || isEmpty(src2))
		return;

	Ptr<Feature2D> feature = ORB::create();

	std::vector<KeyPoint> keypoint1, keypoint2;
	Mat desc1, desc2;

	feature->detectAndCompute(src1, Mat(), keypoint1, desc1);
	feature->detectAndCompute(src2, Mat(), keypoint2, desc2);

	Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);

	std::vector<DMatch> matches;
	matcher->match(desc1, desc2, matches);

	std::sort(matches.begin(), matches.end());
	std::vector<DMatch> good_matches(matches.begin(), matches.begin() + 50);

	Mat dst;
	drawMatches(src1, keypoint1, src2, keypoint2, good_matches, dst, Scalar::all(-1), Scalar::all(-1), std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void find_homography()
{
	Mat src1 = imread("box.png", IMREAD_GRAYSCALE);
	Mat src2 = imread("box_in_scene.png", IMREAD_GRAYSCALE);

	if (isEmpty(src1) || isEmpty(src2))
		return;

	Ptr<Feature2D> orb = ORB::create();

	std::vector<KeyPoint> kp1, kp2;
	Mat desc1, desc2;
	orb->detectAndCompute(src1, Mat(), kp1, desc1);
	orb->detectAndCompute(src2, Mat(), kp2, desc2);

	Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);
	std::vector<DMatch> matches;

	matcher->match(desc1, desc2, matches);

	std::sort(matches.begin(), matches.end());
	std::vector<DMatch> good_matches(matches.begin(), matches.begin() + 50);

	Mat dst;
	drawMatches(src1, kp1, src2, kp2, good_matches, dst, Scalar::all(-1), Scalar::all(-1), std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

	std::vector<Point2f> pts1, pts2;
	for (size_t i = 0; i < good_matches.size(); ++i)
	{
		pts1.push_back(kp1[good_matches[i].queryIdx].pt);
		pts2.push_back(kp2[good_matches[i].trainIdx].pt);
	}

	Mat H = findHomography(pts1, pts2, RANSAC);
	
	std::vector<Point2f> corner1, corner2;
	corner1.push_back(Point2f(0, 0));
	corner1.push_back(Point2f(src1.cols - 1.f, 0));
	corner1.push_back(Point2f(src1.cols - 1.f, src1.rows - 1.f));
	corner1.push_back(Point2f(0, src1.rows - 1.f));
	perspectiveTransform(corner1, corner2, H);

	std::vector<Point> corner_dst;

	for (Point2f pt : corner2)
	{
		corner_dst.push_back(Point(cvRound(pt.x + src1.cols), cvRound(pt.y)));
	}

	polylines(dst, corner_dst, true, Scalar(0, 255, 0), 2, LINE_AA);

	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void stitch_img()
{
	std::vector<Mat> imgs;
	std::string img_name[3] = { "img1.jpg", "img2.jpg" , "img3.jpg" };

	for (int i = 0; i < 3; ++i)
	{
		Mat img = imread(img_name[i]);
		if (isEmpty(img))
			return;
		imgs.push_back(img);
	}

	Ptr<Stitcher> stitcher = Stitcher::create();

	Mat dst;
	Stitcher::Status status = stitcher->stitch(imgs, dst);

	if (status != Stitcher::Status::OK)
	{
		std::cerr << "Error on stitching!\n";
		return;
	}

	imshow("dst", dst);
	waitKey();
	destroyAllWindows();
}

Mat knn_img;
Mat knn_train, knn_label;
Ptr<KNearest> knn;

int k_value = 1;

void on_k_change(int, void*)
{
	if (k_value < 1)
		k_value = 1;

	if (!isEmpty(knn_train))
		trainAndDisplay();
		
}

void addPoint(const Point& pt, int cls)
{
	Mat new_sample = (Mat_<float>(1, 2) << pt.x, pt.y);
	knn_train.push_back(new_sample);

	Mat new_label = (Mat_<int>(1, 1) << cls);
	knn_label.push_back(new_label);
}

void trainAndDisplay()
{
	knn->train(knn_train, ROW_SAMPLE, knn_label);

	for (int i = 0; i < knn_img.rows; ++i) {
		for (int j = 0; j < knn_img.cols; ++j) {
			Mat sample = (Mat_<float>(1, 2) << j, i);

			Mat res;
			knn->findNearest(sample, k_value, res);

			int response = cvRound(res.at<float>(0, 0));
			if (response == 0)
				knn_img.at<Vec3b>(i, j) = Vec3b(128, 128, 255); // R
			else if (response == 1)
				knn_img.at<Vec3b>(i, j) = Vec3b(128, 255, 128); // G
			else if (response == 2)
				knn_img.at<Vec3b>(i, j) = Vec3b(255, 128, 128); // B
		}
	}

	for (int i = 0; i < knn_train.rows; i++)
	{
		int x = cvRound(knn_train.at<float>(i, 0));
		int y = cvRound(knn_train.at<float>(i, 1));
		int l = knn_label.at<int>(i, 0);

		if (l == 0)
			circle(knn_img, Point(x, y), 5, Scalar(0, 0, 128), -1, LINE_AA);
		else if (l == 1)
			circle(knn_img, Point(x, y), 5, Scalar(0, 128, 0), -1, LINE_AA);
		else if (l == 2)
			circle(knn_img, Point(x, y), 5, Scalar(128, 0, 0), -1, LINE_AA);
	}

	imshow("knn", knn_img);
}

void knn_practice()
{
	knn_img = Mat::zeros(Size(500, 500), CV_8UC3);
	knn = KNearest::create();

	namedWindow("knn");
	createTrackbar("k", "knn", &k_value, 5, on_k_change);

	const int num = 30;
	Mat rn(num, 2, CV_32SC1);

	randn(rn, 0, 50);
	for (int i = 0; i < num; ++i)
	{
		addPoint(Point(rn.at<int>(i, 0) + 150, rn.at<int>(i, 1) + 150), 0);
	}

	randn(rn, 0, 50);
	for (int i = 0; i < num; ++i)
	{
		addPoint(Point(rn.at<int>(i, 0) + 350, rn.at<int>(i, 1) + 150), 1);
	}

	randn(rn, 0, 70);
	for (int i = 0; i < num; ++i)
	{
		addPoint(Point(rn.at<int>(i, 0) + 250, rn.at<int>(i, 1) + 400), 2);
	}

	trainAndDisplay();

	waitKey();
	return;
}

Point ptPrev(-1, -1);

Ptr<KNearest> train_knn()
{
	Mat digits = imread("digits.png", IMREAD_GRAYSCALE);

	if (isEmpty(digits))
		return 0;

	Mat train_images, train_labels;

	for (int j = 0; j < 50; ++j)
	{
		for (int i = 0; i < 100; ++i)
		{
			Mat roi, roi_float, roi_flatten;
			roi = digits(Rect(i * 20, j * 20, 20, 20));
			roi.convertTo(roi_float, CV_32F);
			roi_flatten = roi_float.reshape(1, 1);

			train_images.push_back(roi_flatten);
			train_labels.push_back(j / 5);
		}
	}

	Ptr<KNearest> knn = KNearest::create();
	knn->train(train_images, ROW_SAMPLE, train_labels);

	return knn;
}

void knn_on_mouse(int evt, int x, int y, int flags, void* userdata)
{
	Mat img = *(Mat*)userdata;
	if (evt == EVENT_LBUTTONDOWN)
	{
		ptPrev = Point(x, y);
	}
	else if(evt == EVENT_LBUTTONUP)
	{
		ptPrev = Point(-1, -1);
	}
	else if (evt == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON))
	{
		line(img, ptPrev, Point(x, y), Scalar::all(255), 40, LINE_AA, 0);
		ptPrev = Point(x, y);
		imshow("img", img);
	}
}

void knn_pilgichae()
{
	Ptr<KNearest> knn = train_knn();

	if (knn.empty())
	{
		cerr << "Training failed!\n";
		return;
	}

	Mat img = Mat::zeros(400, 400, CV_8U);

	imshow("img", img);
	setMouseCallback("img", knn_on_mouse, (void*)&img);

	while (true)
	{
		int c = waitKey();

		if (c == 27)
			break;
		else
		{
			Mat img_resize, img_float, img_flatten, res;
			resize(img, img_resize, Size(20, 20), 0, 0, INTER_AREA);
			img_resize.convertTo(img_float, CV_32F);
			img_flatten = img_float.reshape(1, 1);

			knn->findNearest(img_flatten, 3, res);
			cout << cvRound(res.at<float>(0, 0)) << "\n";

			img.setTo(0);
			imshow("img", img);
		}
	}
}

void svmplane()
{
	Mat train = Mat_<float>({ 8, 2 },
		{ 150, 200, 200, 250, 100, 250, 150, 300,
		350, 100, 400, 200 ,400 ,300 ,350, 400 });
	Mat label = Mat_<int>({ 8, 1 }, { 0, 0, 0, 0, 1, 1, 1, 1 });

	Ptr<SVM> svm = SVM::create();
	svm->setType(SVM::Types::C_SVC);
	svm->setKernel(SVM::KernelTypes::RBF);
	svm->trainAuto(train, ROW_SAMPLE, label);

	Mat img = Mat::zeros(Size(500, 500), CV_8UC3);
	for (int j = 0; j < img.rows; ++j)
	{
		for (int i = 0; i < img.cols; ++i)
		{
			Mat test = Mat_<float>({ 1, 2 }, { (float)i, (float)j });
			int res = cvRound(svm->predict(test));

			if (res == 0)
				img.at<Vec3b>(j, i) = Vec3b(128, 128, 255);
			else
				img.at<Vec3b>(j, i) = Vec3b(128, 255, 128);
		}
	}

	for (int i = 0; i < train.rows; ++i)
	{
		int x = cvRound(train.at<float>(i, 0));
		int y = cvRound(train.at<float>(i, 1));
		int l = label.at<int>(i, 0);

		if (l == 0)
			circle(img, Point(x, y), 5, Scalar(0, 0, 128), -1, LINE_AA);
		else
			circle(img, Point(x, y), 5, Scalar(0, 128, 0), -1, LINE_AA);
	}

	imshow("svm", img);

	waitKey();
}

Ptr<SVM> train_hog_svm(const HOGDescriptor& hog)
{
	Mat digits = imread("digits.png", IMREAD_GRAYSCALE);

	if (isEmpty(digits))
		return 0;

	Mat train_hog, train_labels;

	for (int j = 0; j < 50; ++j)
	{
		for (int i = 0; i < 100; ++i)
		{
			Mat roi = digits(Rect(i * 20, j * 20, 20, 20));
			vector<float> desc;
			hog.compute(roi, desc);

			Mat desc_mat(desc);

			train_hog.push_back(desc_mat.t());
			train_labels.push_back(j / 5);
		}
	}

	Ptr<SVM> svm = SVM::create();
	svm->setType(SVM::Types::C_SVC);
	svm->setKernel(SVM::KernelTypes::RBF);
	svm->setC(2.5);
	svm->setGamma(0.50625);
	svm->train(train_hog, ROW_SAMPLE, train_labels);

	return svm;
	
}

void hog_pilgichae()
{
	HOGDescriptor hog(Size(20, 20), Size(10, 10), Size(5, 5), Size(5, 5), 9);

	Ptr<SVM> svm = train_hog_svm(hog);

	if (svm.empty())
	{
		cerr << "Training failed!\n";
		return;
	}

	Mat img = Mat::zeros(400, 400, CV_8U);

	imshow("img", img);
	setMouseCallback("img", knn_on_mouse, (void*)&img);

	while (true)
	{
		int c = waitKey();

		if (c == 27)
			break;
		else if (c == ' ')
		{
			Mat img_resize;
			resize(img, img_resize, Size(20, 20), 0, 0, INTER_AREA);

			vector<float> desc;
			hog.compute(img_resize, desc);

			Mat desc_Mat(desc);

			int res = cvRound(svm->predict(desc_Mat.t()));
			cout << res << "\n";

			img.setTo(0);
			imshow("img", img);
		}
	}
}

void dnnmnist()
{
	Net net = readNet("mnist_cnn.pb");
	if (net.empty())
		return;

	Mat img = Mat::zeros(400, 400, CV_8UC1);
	imshow("img", img);

	setMouseCallback("img", knn_on_mouse, (void*)&img);

	while (true)
	{
		int c = waitKey();

		if (c == 27)
			break;
		else if (c == ' ')
		{
			Mat inputBlob = blobFromImage(img, 1 / 255.f, Size(28, 28));
			net.setInput(inputBlob);
			Mat prob = net.forward();

			double maxVal;
			Point maxLoc;
			minMaxLoc(prob, NULL, &maxVal, NULL, &maxLoc);
			int digit = maxLoc.x;

			cout << digit << " (" << maxVal * 100 << "%)\n";

			img.setTo(0);
			imshow("img", img);
		}
	}
}

void googlenet_classify()
{
	Mat img = imread("beagle.jpg");

	Net net = readNet("bvlc_googlenet.caffemodel", "deploy.prototxt");

	if (net.empty())
	{
		cerr << "Network load failed!\n";
		return;
	}

	
	ifstream fp("classification_calsses_ILSVRC2012.txt");
	
	if (!fp.is_open())
	{
		cerr << "Class file load failed\n";
		return;
	}

	vector<String> classNames;
	string name;

	while (!fp.eof())
	{
		getline(fp, name);
		if (name.length())
			classNames.push_back(name);
	}

	fp.close();

	Mat inputBlob = blobFromImage(img, 1, Size(224, 224), Scalar(104, 117, 123));
	net.setInput(inputBlob);
	Mat prob = net.forward();

	double maxVal;
	Point maxLoc;
	minMaxLoc(prob, NULL, &maxVal, NULL, &maxLoc);

	String str = format("%s (%4.21f%%)", classNames[maxLoc.x].c_str(), maxVal * 100);
	putText(img, str, Point(10, 30), FONT_HERSHEY_COMPLEX, 0.8, Scalar(0, 0, 255));
	imshow("img", img);
	waitKey();
}

void face_detect()
{
	const String model = "res10_300x300_ssd_iter_140000_fp16.caffemodel";
	const String config = "deploy.prototxt";

	Mat img = imread("holo.png");

	if (isEmpty(img))
		return;

	Net net = readNet(model, config);

	if (net.empty())
	{
		cerr << "Net open failed!\n";
		return;
	}

	Mat blob = blobFromImage(img, 1, Size(300, 300), Scalar(104, 177, 123));
	net.setInput(blob);
	Mat res = net.forward();

	Mat detect(res.size[2], res.size[3], CV_32FC1, res.ptr<float>());

	for (int i = 0; i < detect.rows; ++i)
	{
		float conf = detect.at<float>(i, 2);
		if (conf < 0.5)
			break;

		int x1 = cvRound(detect.at<float>(i, 3) * img.cols);
		int y1 = cvRound(detect.at<float>(i, 4) * img.rows);
		int x2 = cvRound(detect.at<float>(i, 5) * img.cols);
		int y2 = cvRound(detect.at<float>(i, 6) * img.rows);

		rectangle(img, Rect(Point(x1, y1), Point(x2, y2)), Scalar(0, 255, 0));

		String label = format("Face: %4.3f", conf);
		putText(img, label, Point(x1, y1 - 1), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0));
	}

	imshow("img", img);
	waitKey();
}































