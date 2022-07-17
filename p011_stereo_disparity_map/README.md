# p011_stereo_disparity_map

Calculate disparity map from stereo images.

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
    cd slamcpp/p011_stereo_disparity_map
    mkdir build
    cd build
    cmake -GNinja ..
    ninja

    # running the executable
    ./p011_stereo_disparity_map ../data/im_left.png ../data/im_right.png
    ```

## Data reference:
- Data for stereo camera experiment: Scharstein, Daniel, et al. "High-resolution stereo datasets with subpixel-accurate ground truth." German conference on pattern recognition. Springer, Cham, 2014. [[link](https://vision.middlebury.edu/stereo/data/scenes2014)]
