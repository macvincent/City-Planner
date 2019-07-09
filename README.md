# City Planner

City Planner is a C++ application that simulates the movements of vehicles in a through real cities.

## Installation

### To test you can clone the repo [City planner](https://github.com/macvincent/city-planner)

The project also requires
- GCC 4.4.x or later
- CMake 2.8.7 or higher
- Git
- GTK+2.x or higher, including headers (libgtk2.0-dev)

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
### Next we would need to install the Opencv library
To compile and run our project we would go back to the 'City_planner` repo creat another build directory, run cmake and then run our simulation

```
cmake ..
make
./traffic_simulation
```