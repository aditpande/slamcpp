# p006_robot_transforms

The Agent1 and Agent2 are located in the world frame.


Coordinate frame | symbol
--- | ---
Agent1 | 1
Agent2 | 2
World | W


Description | Value
--- | ---
Agent1 position in world $t_{1}$ | $[0.4, 0.2, -0.5]$
Agent1 orientation in world $q_{1}$| $[0.63, -0.41, 0.56, 0.09]$
Agent2 position in world $t_{2}$| $[0.2, -0.45, 0.3]$
Agent2 orientation in world $q_{2}$| $[0.61, -0.44, 0.21, 0.52]$

Here, $q_{i}$ and $t_{i}$ express $T_{i,W}$ where $i \in \{1, 2\}$.  
$T_{i,W}$ is the World to the Agent$i$ transformation matrix.

Agent1 observes a point $p$ in its own coordinate frame at $p_{1} = [0.56, 0.01, 0.34]$. 

We write a program to find coordinates of $p$ in coordinate frame of Agent2 $p_{2}$.

Builds a project with Eigen.

## Build and Run

```bash
# build the project
cd slamcpp/p006_robot_transforms
chmod +x setup.sh
./setup.sh
mkdir build
cd build
cmake ..
make

./p006_robot_transforms     # running the executable
```

#### Build using Ninja (Faster build)

```bash
sudo apt install ninja-build
# build the project
cd slamcpp/p006_robot_transforms
chmod +x setup.sh
./setup.sh
mkdir build
cd build
cmake -GNinja ..
ninja

./p006_robot_transforms     # running the executable
```
