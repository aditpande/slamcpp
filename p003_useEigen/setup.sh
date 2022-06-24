
mkdir thirdparty
cd thirdparty

echo "Downloading Eigen-3.4.0 ..."

wget https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.bz2
tar -xf eigen-3.4.0.tar.bz2
rm eigen-3.4.0.tar.bz2
cd ..
