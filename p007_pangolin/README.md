# p007_pangolin

## Dependencies

```bash
sudo apt-get install ninja-build
sudo apt-get install libeigen3-dev
```

Install [Pangolin](https://github.com/stevenlovegrove/Pangolin) by following the instructions in its repository.
With these instructions, Pangolin will be installed as a ```SHARED``` library. If it is not found in CMake configuration of this project, you may have forgotten to do ```sudo ldconfig``` after doing ``sudo make install`` while installing Pangolin.


## Build and Run

```bash
# build the project
cd slamcpp/p007_pangolin
mkdir build
cd build
cmake -GNinja ..
ninja

# running the executable
./p007_pangolin_plot_trajectory
./p007_pangolin_vizualize_geometry

```



## Trajectory Data

Data for the [trajectory](./data/trajectory.txt) is generated using the simulation from [PythonRobotics/AerialNavigation/](https://github.com/AtsushiSakai/PythonRobotics/tree/master/AerialNavigation/drone_3d_trajectory_following).
