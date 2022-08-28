# Stereo Camera Calibration
Based on [Stereo Vision Camera Calibration ](https://www.youtube.com/watch?v=yKypaVl6qQo) youtube tutorial and [Intrinsic and Extrinsic Matrices | Camera Calibration](https://www.youtube.com/watch?v=2XM2Rb2pfyQ&list=PL2zRqk16wsdoCCLpou-dGo7QQNks1Ppzo&index=5) lecture.

## Setup

**Visual Studio 2019**
Set build to `x64`
- Project -> Properties -> C/C++ -> Language -> C++ Language Standard
  * ISO C++ 17 Standard (`/std:c++17`)
- Project -> Properties -> C/C++ -> General -> Additional Include Directories
  * `C:\Libraries\opencv\build\include`
- Project -> Properties -> Linker -> General -> Additional Library Directories
  * `C:\Libraries\opencv\build\x64\vc15\lib`
- Project -> Properties -> Linker -> Input -> Additional Dependencies
  * `opencv_world460.lib`