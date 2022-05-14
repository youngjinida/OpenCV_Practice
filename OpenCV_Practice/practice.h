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
#endif