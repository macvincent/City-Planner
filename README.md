# City Planner

City Planner is a C++ application that multi-threaded traffic simulation showing vehicular movement in a real-world city.
## Installation
The project requires
- GCC 4.4.x or later
- CMake 2.8.7 or higher
- Git
- GTK+2.x or higher, including headers (libgtk2.0-dev)
- Opencv

The packages can be installed from the terminal using the following commands:
```
sudo apt-get install build-essential
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
```
### Next we would need to install the Opencv library
```
git clone https://github.com/opencv/opencv.git

git clone https://github.com/opencv/opencv_contrib.git
```
Afer cloning
1. Create a build directory 
```
cd ~/opencv

mkdir build && cd build
```
2. From the build directory run
```
cmake ..

make -j7
```
to build the Opencv library
3. To install libraries, execute the following command from build directory
```
sudo make install
```
### To run compile and run City_Planner
We would go back to the 'City_planner` repo, create a build directory, run cmake from the build directory to build our make file, run make to build our object files, and then the run our traffic simulation

```
cd ~/City-Planner
cd L1_Projects
mkdir build && build
cmake ..
make
./traffic_simulation
```