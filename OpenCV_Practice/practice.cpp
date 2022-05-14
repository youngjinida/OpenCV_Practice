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

	Mat img2 = img; // 얕은 복사

	Mat img3 = img.clone(); // 깊은 복사
	Mat img4;
	img.copyTo(img4); // 깊은 복사

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
	putText(img, text, org, fontFace, font_scale, Scalar(255, 0, 0), thickness, false); // 좌측 하단을 기준으로 생성

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