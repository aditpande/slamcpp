# p009_opencv

Example of working with OpenCV: Handling of images with ``cv::Mat`` and image distortion example.
This project can be build either by use of prebuilt binaries or by building opencv from source.

## Dependencies

```bash
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install ninja-build libfmt-dev

sudo apt-get install libeigen3-dev

sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libgstreamer-plugins-base1.0-dev libgstreamer1.0-dev libgtk-3-dev libpng-dev libjpeg-dev libopenexr-dev libtiff-dev libwebp-dev libopenjp2-7-dev libgtk-3-dev

sudo apt-get install -y tesseract-ocr libtesseract-dev libleptonica-dev   # install tesseract support
```

Install [Pangolin](https://github.com/stevenlovegrove/Pangolin) by following the instructions in its repository.
With these instructions, Pangolin will be installed as a ```SHARED``` library. If it is not found in CMake configuration of this project, you may have forgotten to do ```sudo ldconfig``` after doing ``sudo make install`` while installing Pangolin.


## Build and Run

### Option 1: Build opencv from source

Do not forget to update ``CMakeLists.txt`` if building this project from source.
    
    ```bash
    # build the project
    cd slamcpp/p009_opencv
    chmod +x ./setup.sh
    ./setup.sh          # to build opencv from source
    mkdir build
    cd build
    cmake -GNinja ..
    ninja

    # running the executable
    ./p009_opencv ../data/test_image.jpg
    ```

### Option 2: Install prebuild opencv binaries
    ```bash

    # build the project
    sudo apt-get install libopencv*     # install opencv
    cd slamcpp/p009_opencv
    mkdir build
    cd build
    cmake -GNinja ..
    ninja

    # running the executable
    ./p009_opencv ../data/test_image.jpg
    ```

## Data reference:
- Data for distortion experiment from [ChihaoZhang's GitHub repo](https://github.com/ChihaoZhang/camera-calibration-and-image-undistortion)


