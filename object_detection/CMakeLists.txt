cmake_minimum_required(VERSION 3.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# set the project name
project(object_detection)

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/belt.png" DESTINATION "${CMAKE_BINARY_DIR}")

# add the executable
add_executable(object_detection main.cpp)
target_link_libraries(object_detection ${OpenCV_LIBS})
