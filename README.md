# opencvDetection

This repo is testet on a linux machine.

## Requirements
To build this repo opencv and cmake are needed.

To install opencv [this tutorial ](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html)is usefull.
It also shows how to install cmake.

## Building 
To build this project, you have to clone it, go into it, make a build folder and start the build process. 
The following commands represent those steps.

>git clone https://github.com/Stefan-1998/opencvDetection.git
>
>cd opencvDetection
>
>mkdir build
>
>cd build
>
>cmake ..
>
>make

Now you should have an executable, which can be started

## Usage

This application can be controlled via the numbers 1,2,3,4 und q to Quit. With the numbers a detection can be selected.

## Future

Other detectors can be added. Opencv provides here more xml-File, which can be found under "data/haarcascades" in the opencv repo. 
To add these, you need a relative path. To include those, the same logic as in the project can be used.

Furthermore the performance needs a lot of optimisation.
