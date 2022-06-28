# p008_sophus_pangolin

Using sophus for transformations and pangolin for visualization

## Dependencies

```bash
sudo apt-get install ninja-build libfmt-dev
sudo apt-get install libeigen3-dev
```

Install [Pangolin](https://github.com/stevenlovegrove/Pangolin) by following the instructions in its repository.
With these instructions, Pangolin will be installed as a ```SHARED``` library. If it is not found in CMake configuration of this project, you may have forgotten to do ```sudo ldconfig``` after doing ``sudo make install`` while installing Pangolin.


## Build and Run

```bash
# build the project
cd slamcpp/p008_sophus_pangolin
chmod +x ./setup.sh
./setup.sh
mkdir build
cd build
cmake -GNinja ..
ninja

# running the executable
./p008_sophus_pangolin

```


## Trajectory Data

Data for the trajectories in [data folder](./data) is generated using the simulation from [PythonRobotics/AerialNavigation/](https://github.com/AtsushiSakai/PythonRobotics/tree/master/AerialNavigation/drone_3d_trajectory_following).
