# p009_opencv

Example of work with OpenCV

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
    ```bash
    # build the project
    cd slamcpp/p008_sophus_pangolin
    chmod +x ./setup.sh
    ./setup.sh          # to build opencv from source
    mkdir build
    cd build
    cmake -GNinja ..
    ninja

    # running the executable
    ./p008_sophus_pangolin
    ```

### Option 2: Install prebuild opencv binaries
    ```bash
    # build the project

    sudo apt-get install libopencv*     # install opencv

    cd slamcpp/p008_sophus_pangolin
    mkdir build
    cd build
    cmake -GNinja ..
    ninja

    # running the executable
    ./p008_sophus_pangolin
    ```
