#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>


int main()
{
	std::cout << "Stereo Camera Depth Estimation (using OpenCV " << CV_VERSION << ")" << std::endl;
	const uint32_t
	width = 640,
	height = 480;
	cv::Mat left_image{ cv::Size(width, height), CV_8UC3, cv::Scalar(0, 0, 0) };
	cv::Mat right_image{ cv::Size(width, height), CV_8UC3, cv::Scalar(255, 0, 0) };
	cv::Mat left_depth{ cv::Size(width, height), CV_8UC3, cv::Scalar(0, 255, 0) };
	cv::Mat right_depth{ cv::Size(width, height), CV_8UC3, cv::Scalar(0, 0, 255) };

	const char* window_left_image = "Left Image";
	const char* window_left_depth = "Left Depth";
	const char* window_right_image = "Right Image";
	const char* window_right_depth = "Right Depth";

	cv::namedWindow(window_left_image);
	cv::namedWindow(window_right_image);
	cv::namedWindow(window_left_depth);
	cv::namedWindow(window_right_depth);

	cv::moveWindow(window_left_image, 0, 0);
	cv::moveWindow(window_right_image, width, 0);
	cv::moveWindow(window_left_depth, 0, height);
	cv::moveWindow(window_right_depth, width, height);

	cv::imshow(window_left_image, left_image);
	cv::imshow(window_right_image, right_image);
	cv::imshow(window_left_depth, left_depth);
	cv::imshow(window_right_depth, right_depth);

	cv::waitKey();
}