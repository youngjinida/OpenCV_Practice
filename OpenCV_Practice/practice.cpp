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

	Mat img2 = img; // ¾èÀº º¹»ç

	Mat img3 = img.clone(); // ±íÀº º¹»ç
	Mat img4;
	img.copyTo(img4); // ±íÀº º¹»ç

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
