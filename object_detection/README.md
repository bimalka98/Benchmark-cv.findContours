# Single line execution command

```shell
g++ main.cpp -o output `pkg-config --cflags --libs opencv4`
```
# Execution using CMake

```shell
bimalka98@LAP-BIMALKA98:/mnt/e/Automated-Visual-Inspection/object_detection$ mkdir build
bimalka98@LAP-BIMALKA98:/mnt/e/Automated-Visual-Inspection/object_detection$ cd build
bimalka98@LAP-BIMALKA98:/mnt/e/Automated-Visual-Inspection/object_detection/build$ cmake ..
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenCV: /usr/local (found version "4.5.5")
-- OpenCV library status:
--     version: 4.5.5
--     config: /usr/local/lib/cmake/opencv4
--     include path: /usr/local/include/opencv4
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/e/Automated-Visual-Inspection/object_detection/build
bimalka98@LAP-BIMALKA98:/mnt/e/Automated-Visual-Inspection/object_detection/build$ make
Scanning dependencies of target object_detection
[ 50%] Building CXX object CMakeFiles/object_detection.dir/main.cpp.o
[100%] Linking CXX executable object_detection
[100%] Built target object_detection
bimalka98@LAP-BIMALKA98:/mnt/e/Automated-Visual-Inspection/object_detection/build$ ./object_detection
Time taken by connectedComponentsWithStats function: 10336 microseconds
Number of objects: 4
terminate called after throwing an instance of 'cv::Exception'
  what():  OpenCV(4.5.5-dev) /opt/opencv/modules/highgui/src/window_gtk.cpp:635: error: (-2:Unspecified error) Can't initialize GTK backend in function 'cvInitSystem'

Aborted
bimalka98@LAP-BIMALKA98:/mnt/e/Automated-Visual-Inspection/object_detection/build$
```
