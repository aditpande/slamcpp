
set -ex

rm -rf thirdparty

mkdir thirdparty
cd thirdparty

echo "Downloading Sophus v22.04 ..."
wget https://github.com/strasdat/Sophus/archive/refs/tags/v22.04.tar.gz
tar -xf v22.04.tar.gz
mv Sophus* Sophus
rm v22.04.tar.gz

echo "Downloading Eigen-3.4.0 ..."
wget https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.bz2
tar -xf eigen-3.4.0.tar.bz2
rm eigen-3.4.0.tar.bz2
mv eigen* eigen3

cd ..
