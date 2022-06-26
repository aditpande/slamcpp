# p004_sophus

Builds a project with Sophus as thirdparty dependency.

#### Install dependencies

```bash
sudo apt install gcc g++ cmake make git
sudo apt-get install gfortran libc++-dev libgoogle-glog-dev libatlas-base-dev libsuitesparse-dev libceres-dev ccache libeigen3-dev libfmt-dev
```

#### Build and Run

```bash
# build the project
cd slamcpp/p004_sophus
chmod +x setup.sh
./setup.sh
mkdir build
cd build
cmake ..
make

./p004_sophus     # running the executable
```
