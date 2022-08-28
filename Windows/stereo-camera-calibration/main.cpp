#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <condition_variable>

// Frames time in milliseconds
const uint32_t frame_time = 33; // milliseconds

// mutex setup (for threading)
std::mutex left_mutex, right_mutex;
std::condition_variable left_condition, right_condition;

// Image setup
const uint32_t
width = 640,
height = 480;
cv::Mat left_image{ cv::Size(width, height), CV_8UC3, cv::Scalar(255, 255, 0) };
cv::Mat right_image{ cv::Size(width, height), CV_8UC3, cv::Scalar(0, 255, 255) };

// Threading function declarations
void left_camera_read(cv::VideoCapture left_camera, cv::Mat left_image);
void right_camera_read(cv::VideoCapture right_camera, cv::Mat right_image);

int main()
{
	std::cout << "Stereo Camera Depth Estimation (using OpenCV " << CV_VERSION << ")" << std::endl;
	
	// Window setup
	const char* window_left_image = "Left Image";
	const char* window_right_image = "Right Image";

	cv::namedWindow(window_left_image);
	cv::namedWindow(window_right_image);

	cv::moveWindow(window_left_image, 0, 0);
	cv::moveWindow(window_right_image, width, 0);


	// Camera setup
	cv::VideoCapture left_camera, right_camera;

	// Launch threads
	std::thread left_thread(left_camera_read, left_camera, left_image);
	std::thread right_thread(right_camera_read, right_camera, right_image);

	for (;;)
	{
		std::unique_lock<std::mutex> left_lock{ left_mutex };
		left_condition.wait(left_lock);
		cv::imshow(window_left_image, left_image);

		std::unique_lock<std::mutex> right_lock{ right_mutex };
		right_condition.wait(right_lock);
		cv::imshow(window_right_image, right_image);

		if (cv::waitKey(frame_time) == 27) { break; } // Esc to quit
	}

	return EXIT_SUCCESS;
}

// Threading functions
void left_camera_read(cv::VideoCapture left_camera, cv::Mat left_image)
{
	left_camera.open(1);
	left_camera.set(width, height);
	if (not left_camera.isOpened()) { std::cout << "Left camera could not be opened!" << std::endl; }

	for (;;)
	{
		{
			std::lock_guard<std::mutex> left_guard{ left_mutex };
			auto captured = left_camera.read(left_image);
			if (not captured)
			{
				std::cout << "Could not read left camera image!" << std::endl;
			}
		}
		left_condition.notify_all();
		std::this_thread::sleep_for(std::chrono::milliseconds(frame_time));
	}

}

void right_camera_read(cv::VideoCapture right_camera, cv::Mat right_image)
{
	right_camera.open(2);
	right_camera.set(width, height);
	if (not right_camera.isOpened()) { std::cout << "Right camera could not be opened!" << std::endl; }

	for (;;)
	{
		{
			std::lock_guard<std::mutex> right_guard{ right_mutex };
			auto captured = right_camera.read(right_image);
			if (not captured) { std::cout << "Could not read right camera image!" << std::endl; }
		}
		right_condition.notify_all();
		std::this_thread::sleep_for(std::chrono::milliseconds(frame_time));
	}
}