#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <cstdlib>

int main()
{
	std::cout << "Stereo Camera Depth Estimation (using OpenCV " << CV_VERSION << ")" << std::endl;
	
	// IOmage setup
	const uint32_t
	width = 640,
	height = 480;
	cv::Mat left_image{ cv::Size(width, height), CV_8UC3, cv::Scalar(255, 255, 0) };
	cv::Mat right_image{ cv::Size(width, height), CV_8UC3, cv::Scalar(0, 255, 255) };

	// Window setup
	const char* window_left_image = "Left Image";
	const char* window_right_image = "Right Image";

	cv::namedWindow(window_left_image);
	cv::namedWindow(window_right_image);

	cv::moveWindow(window_left_image, 0, 0);
	cv::moveWindow(window_right_image, width, 0);

	// Camera setup
	cv::VideoCapture left_camera, right_camera;
	
	left_camera.open(1);
	left_camera.set(width, height);
	if (not left_camera.isOpened())
	{
		std::cout << "Left camera could not be opened!" << std::endl;
		return EXIT_FAILURE;
	}

	right_camera.open(2);
	right_camera.set(width, height);
	if (not right_camera.isOpened())
	{
		std::cout << "Right camera could not be opened!" << std::endl;
		return EXIT_FAILURE;
	}

	for (;;)
	{
		if (not left_camera.read(left_image))
		{
			std::cout << "Could not read left camera image!" << std::endl;
		}

		if (not right_camera.read(right_image))
		{
			std::cout << "Could not read right camera image!" << std::endl;
		}

		cv::imshow(window_left_image, left_image);
		cv::imshow(window_right_image, right_image);

		if (cv::waitKey(33) == 27) { break; } // Esc to quit
	}

	return EXIT_SUCCESS;
}