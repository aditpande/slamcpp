#include "utils_plot_trajectory.hpp"

using namespace std;


TrajectoryType ReadTrajectory(const std::string &filepath){
  TrajectoryType traj;

  ifstream fin(filepath);
  if (!fin){
    cout << "Trajectory filepath " << filepath << " not found." << endl;
    return traj;
  }

  while (!fin.eof())
  {
    double time, tx, ty, tz, qx, qy, qz, qw;
    fin >> time >> tx >> ty >> tz >> qx >> qy >> qz >> qw;

    Sophus::SE3d p(
      Eigen::Quaterniond(qx, qy, qz, qw),
      Eigen::Vector3d(tx, ty, tz)
    );
    traj.push_back(p);
  }
  return traj;
}


void PlotLineWithPointsFromTrajectory(
  const TrajectoryType &traj,
  const float &linewidth,
  const float &line_red,
  const float &line_green,
  const float &line_blue
  )
{
    glLineWidth(linewidth);

    for (size_t i = 0; i < traj.size() - 1; i++) {
      glColor3f(line_red, line_green, line_blue);     // color of trajectory

      glBegin(GL_LINES);

      auto p1 = traj[i], p2 = traj[i + 1];

      glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);

      glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);

      glEnd();
    }

}

void DrawTrajectory(const TrajectoryType &traj)
{
  pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);    // create pangolin window and plot the trajectory
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  pangolin::OpenGlRenderState s_cam(
      pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
      pangolin::ModelViewLookAt(10, 10, 8.,
                                0, 0, 5.,
                                0.0, 0., 1.0)
  );

  pangolin::View &d_cam = pangolin::CreateDisplay()
      .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
      .SetHandler(new pangolin::Handler3D(s_cam));


  while (pangolin::ShouldQuit() == false) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    d_cam.Activate(s_cam);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    PlotLineWithPointsFromTrajectory(traj, 2, 0., 0., 0.8);

    pangolin::FinishFrame();
    usleep(5000);   // sleep 5 ms
  }

}


void DrawTrajectory(const TrajectoryType &true_traj, const TrajectoryType &noisy_traj)
{

  pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);    // create pangolin window and plot the trajectory
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  pangolin::OpenGlRenderState s_cam(
      pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
      pangolin::ModelViewLookAt(10, 10, 8.,
                                0, 0, 5.,
                                0.0, 0., 1.0)
  );

  pangolin::View &d_cam = pangolin::CreateDisplay()
      .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
      .SetHandler(new pangolin::Handler3D(s_cam));


  while (pangolin::ShouldQuit() == false) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    d_cam.Activate(s_cam);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    PlotLineWithPointsFromTrajectory(true_traj,
                                     2,             // line width
                                     0., 0., 0.8);  // line color R, G, B
    PlotLineWithPointsFromTrajectory(noisy_traj,
                                              2,    // line width
                                    0.8, 0., 0.);   // line color R, G, B

    pangolin::FinishFrame();
    usleep(5000);   // sleep 5 ms
  }

}
