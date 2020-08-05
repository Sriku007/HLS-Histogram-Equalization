#include <hls_opencv.h>
#include "image.h"
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
	cv::Mat image_in(MAX_HEIGHT, MAX_WIDTH, CV_8UC3);
	cv::Mat image_in2(MAX_HEIGHT, MAX_WIDTH, CV_8UC3);
	cv::Mat image_out_hls(MAX_HEIGHT, MAX_WIDTH, CV_8UC3);

	image_in = cv::imread("testa.bmp", 1);
	image_in2 = cv::imread("testa.bmp", 0);

	AXI_STREAM24 src_axi, dst_axi;
	cvMat2AXIvideo(image_in, src_axi);
	hist_equalize_hls(src_axi, dst_axi);
	AXIvideo2cvMat(dst_axi, image_out_hls);

	cvMat2AXIvideo(image_in, src_axi);
	hist_equalize_hls(src_axi, dst_axi);
	AXIvideo2cvMat(dst_axi, image_out_hls);

	cv::imwrite("test_original_gray.jpg", image_in2);
	cv::imwrite("test_histequalize_hls.jpg", image_out_hls);

	return 0;


}
