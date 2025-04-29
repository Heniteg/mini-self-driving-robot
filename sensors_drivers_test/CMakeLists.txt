cmake_minimum_required(VERSION 3.1)
project(sensors_drivers_test)

find_package(realsense2 REQUIRED)
find_package(OpenCV REQUIRED)

# Set output binaries to bin/ folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(realsense_test src/realsense_test.cpp)
target_link_libraries(realsense_test realsense2 ${OpenCV_LIBS})

add_executable(rs_opencv_realtime src/rs_opencv_realtime.cpp)
target_link_libraries(rs_opencv_realtime realsense2 ${OpenCV_LIBS})
