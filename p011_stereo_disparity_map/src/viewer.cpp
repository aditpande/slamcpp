#include "viewer.hpp"
#include "commons.hpp"

using namespace Eigen;
using namespace std;

void viewer::showPointCloud(
    const vector<Eigen::Vector4d, Eigen::aligned_allocator<Eigen::Vector4d>>
        &pointcloud) {

  if (pointcloud.empty()) {
    cerr << "Point cloud is empty!" << endl;
    return;
  } else {
    std::cout << "pointcloud.size(): " << pointcloud.size() << endl;
  }

  double x_mid=0., y_mid=0., z_mid=0.;
  for (auto &p : pointcloud){
    x_mid += p[0];
    y_mid += p[1];
    z_mid += p[2];
  }
  x_mid /= pointcloud.size();
  y_mid /= pointcloud.size();
  z_mid /= pointcloud.size();
  cout << "Mid point: " << x_mid <<" , "<< y_mid <<" , " << z_mid << endl;

  double viewing_distance_along_axis = 100;
  double scale = 0.01;
  double lookat_x = x_mid*scale, lookat_y=y_mid*scale, lookat_z=z_mid*scale;
  double lookfrom_x=(lookat_x-viewing_distance_along_axis)*scale;
  double lookfrom_y=(lookat_y-viewing_distance_along_axis)*scale;
  double lookfrom_z=(lookat_z-viewing_distance_along_axis)*scale;

  cout << "NOTE: Point cloud is scaled for it to be able to fit the screen!"<< endl;
  cout << "Scale factor is <" << scale <<">" << endl;

  pangolin::CreateWindowAndBind("Point Cloud Viewer", 1024, 768);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  pangolin::OpenGlRenderState s_cam(
      pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
      pangolin::ModelViewLookAt(lookfrom_x, lookfrom_y, lookfrom_z, lookat_x, lookat_y, lookat_z, 0.0, -1.0, 0.0));

  pangolin::View &d_cam = pangolin::CreateDisplay()
                              .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175),
                                         1.0, -1024.0f / 768.0f)
                              .SetHandler(new pangolin::Handler3D(s_cam));

  while (!pangolin::ShouldQuit()) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    d_cam.Activate(s_cam);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glPointSize(5);
    glBegin(GL_POINTS);
    for (auto &p : pointcloud) {
      glColor3f(p[3], p[3], p[3]);
      glVertex3d(p[0]*scale, p[1]*scale, p[2]*scale);
      // cout << p[3] << endl;

    }
    glEnd();
    // cout << pointcloud.size() << endl;
    pangolin::FinishFrame();
    usleep(1000); // sleep 5 ms
  }
  return;
}
