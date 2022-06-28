#include "commons.hpp"
#include "utils_plot_trajectory.hpp"


using namespace std;
using namespace Eigen;

string traj_true_file = "./../data/trajectory_true.txt";
string traj_noisy_file = "./../data/trajectory_noisy.txt";


int main(int argc, char **argv) {

  TrajectoryType trajtrue = ReadTrajectory(traj_true_file);
  TrajectoryType trajnoisy = ReadTrajectory(traj_noisy_file);

  // draw trajectory in pangolin
  DrawTrajectory(trajtrue, trajnoisy);
  return 0;
}
