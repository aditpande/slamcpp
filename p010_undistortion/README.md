# p010_undistortion

Image undistortion.

## Dependencies

```bash
sudo apt-get install ninja-build libfmt-dev
sudo apt-get install libeigen3-dev
sudo apt-get install libopencv*     # install opencv
```

## Build and Run

To build and run this project do the following

    ```bash
    # build
    cd slamcpp/p010_undistortion
    mkdir build
    cd build
    cmake -GNinja ..
    ninja

    # running the executable
    ./p010_undistortion ../data/test_image.jpg
    ```

## Data reference:
- Data for distortion experiment from [ChihaoZhang's GitHub repo](https://github.com/ChihaoZhang/camera-calibration-and-image-undistortion)
