#include "opencv2/opencv.hpp"
#include <iostream>
#include "practice.h"

using namespace cv;

int main()
{
	std::cout << getGaussianKernel(9, 1) << "\n";
}