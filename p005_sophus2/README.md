# p005_sophus2

Builds a project with Eigen and Sophus as thirdparty dependency.

#### Install dependencies

```bash
sudo apt install gcc g++ cmake make git
sudo apt-get install gfortran libc++-dev libgoogle-glog-dev libatlas-base-dev libsuitesparse-dev libceres-dev ccache libfmt-dev
```

#### Build and Run

```bash
# build the project
cd slamcpp/p005_sophus2
chmod +x setup.sh
./setup.sh
mkdir build
cd build
cmake ..
make

./p005_sophus2     # running the executable
```
