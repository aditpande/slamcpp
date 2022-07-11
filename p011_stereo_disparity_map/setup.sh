
set -ex

rm -rf thirdparty

mkdir thirdparty
cd thirdparty

echo "Downloading Sophus v22.04 ..."
wget https://github.com/strasdat/Sophus/archive/refs/tags/v22.04.tar.gz
tar -xf v22.04.tar.gz
mv Sophus* Sophus
rm v22.04.tar.gz

cd ..
