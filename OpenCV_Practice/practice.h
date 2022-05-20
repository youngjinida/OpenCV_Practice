#ifndef PRACTICE_H
#define PRACTICE_H

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

void practice_1();
void practice_2();
void practice_3();
void practice_4();
void practice_5();
void practice_6();
void practice_7();
void practice_8();
void practice_9();
void practice_10();
void practice_11();
void practice_12();
void practice_13();
void printMat(InputArray _mat);
void drawPolys();
void drawText1();
void drawText2();
void keyboard();
void onMouse(int evt, int x, int y, int flags, void* userdata);
bool isEmpty(Mat& img);
void mouse();
void on_level_change(int pos, void* userdata);
void trackbar_practice();
void writeData(String filename);
void readData(String filename);
void mask_setTo();
void mask_copyTo();
void time_copyTo();
void util();
void brightness_1();
void brightness_2();
void brightness_3();
void brightness_trackbar();
void contrast_1();
void contrast_2();
void GrayHistImage();
Mat calcGrayHist(const Mat& img);
Mat calcGrayHistImage(const Mat& hist);
void compareHist();
void histogram_stretching();
void histogram_equalization();
void arithmetic();
void logical();
void filter_embossing();
void blurring_mean();
void blurring_gaussian();
void unsharp_mask();
void noise_gaussian();
void filter_bilateral();
void filter_median();
void affine_transform();
void affine_translation();
void affine_shear();
void affine_scale();
void affine_rotation();
void affine_flip();
void perspective();
void sobel_derivate();
void sobel_edge();
void canny_edge();
void hough_lines();
void hough_lines_segment();
void hough_circle();
void color_inverse();
void color_split();
void color_eq();
void range_extraction();
void backproject();
#endif