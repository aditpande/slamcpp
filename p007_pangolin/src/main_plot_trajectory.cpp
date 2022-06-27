#include "commons.hpp"
#include "plot_trajectory_utils.hpp"


using namespace std;
using namespace Eigen;

string data_file = "./../data/trajectory.txt";


int main(int argc, char **argv) {

  vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>> poses;
  ifstream fin(data_file);
  if (!fin) {
    cout << "cannot find trajectory file at " << data_file << endl;
    return 1;
  }

  while (!fin.eof()) {
    double time, tx, ty, tz, qx, qy, qz, qw;
    fin >> time >> tx >> ty >> tz >> qx >> qy >> qz >> qw;
    Isometry3d Twr(Quaterniond(qw, qx, qy, qz));
    Twr.pretranslate(Vector3d(tx, ty, tz));
    poses.push_back(Twr);
  }
  cout << "read total " << poses.size() << " pose entries" << endl;

  // draw trajectory in pangolin
  DrawTrajectory(poses);
  return 0;
}
