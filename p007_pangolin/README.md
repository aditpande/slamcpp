# p007_pangolin

## Dependencies

```bash
sudo apt-get install ninja-build
sudo apt-get install libeigen3-dev
```

Install [Pangolin](https://github.com/stevenlovegrove/Pangolin) by following the instructions in the repository.

## Build and Run

```bash
# build the project
cd slamcpp/p007_pangolin
mkdir build
cd build
cmake -GNinja ..
ninja

./p007_pangolin     # running the executable

```
