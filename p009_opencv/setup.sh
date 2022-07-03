
set -ex

rm -rf thirdparty

mkdir thirdparty
cd thirdparty

echo "Downloading Sophus v22.04 ..."
wget https://github.com/strasdat/Sophus/archive/refs/tags/v22.04.tar.gz
tar -xf v22.04.tar.gz
mv Sophus* Sophus
rm v22.04.tar.gz

echo "Downloading OpenCV v4.6.0 ..."
wget https://github.com/opencv/opencv/archive/refs/tags/4.6.0.tar.gz
tar -xf 4.6.0.tar.gz
mv opencv* opencv
rm 4.6.0.tar.gz

echo "Downloading OpenCV v4.6.0 ..."
wget https://github.com/opencv/opencv_contrib/archive/refs/tags/4.6.0.tar.gz
tar -xf 4.6.0.tar.gz
mv opencv_contrib* opencv_contrib
rm 4.6.0.tar.gz

cd opencv
mkdir build
cd build
cmake -DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
  -DBUILD_SHARED_LIBS=OFF \
  -DBUILD_TESTS=OFF \
  -DBUILD_PERF_TESTS=OFF \
  -DBUILD_EXAMPLES=OFF \
  -DBUILD_opencv_apps=OFF \
  -DBUILD_opencv_python3=OFF \
  -DBUILD_opencv_python2=OFF \
  -DBUILD_JAVA=OFF \
  -GNinja ..
ninja
cd ../..

cd ..
