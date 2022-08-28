# Stereo Camera

## Calibration
Based on:
- [OpenCV Tutorial](https://docs.opencv.org/4.x/d4/d94/tutorial_camera_calibration.html)
- [Stereo Vision Camera Calibration ](https://www.youtube.com/watch?v=yKypaVl6qQo) youtube tutorial 
- [Intrinsic and Extrinsic Matrices | Camera Calibration](https://www.youtube.com/watch?v=2XM2Rb2pfyQ&list=PL2zRqk16wsdoCCLpou-dGo7QQNks1Ppzo&index=5) youtube lecture.

## Depth estimation
Based on:
- [Depth Estimation Using Stereo Vision](https://www.youtube.com/watch?v=snJVyfl9ZMg) youtube tutorial.
- [Stereo Vision and Depth Estimation](https://www.youtube.com/watch?v=KOSS24P3_fY) youtube tutorial.



# Setup
**Visual Studio 2019**
Set build to `x64`
- Project -> Properties -> C/C++ -> Language -> C++ Language Standard
  * ISO C++ 17 Standard (`/std:c++17`)
- Project -> Properties -> C/C++ -> General -> Additional Include Directories
  * `C:\Libraries\opencv\build\include`
- Project -> Properties -> Linker -> General -> Additional Library Directories
  * `C:\Libraries\opencv\build\x64\vc15\lib`
- Project -> Properties -> Linker -> Input -> Additional Dependencies
  * `opencv_world460d.lib`
- Project -> Properties -> Debugging -> Environment
  * `PATH=C:\Libraries\opencv\build\x64\vc15\bin;%PATH%`