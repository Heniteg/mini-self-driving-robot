cmake_minimum_required(VERSION 3.1)
project(images_processing)

# Use system-installed OpenCV (installed via make install)
set(OpenCV_INCLUDE_DIRS "/usr/local/include/opencv4")
set(OpenCV_LIB_DIR "/usr/local/lib")

# Standard OpenCV modules you likely need
set(OpenCV_LIBS
    opencv_core
    opencv_imgproc
    opencv_highgui
    opencv_videoio
    opencv_imgcodecs
)

# RealSense still required
find_package(realsense2 REQUIRED)

# Output binaries to bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Include and link paths
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

# Build targets
add_executable(visualizing_roi_perspective src/visualizing_roi_perspective.cpp)
target_link_libraries(visualizing_roi_perspective realsense2 ${OpenCV_LIBS})

add_executable(realtime_pixel_info_hovering_mouse src/realtime_pixel_info_hovering_mouse.cpp)
target_link_libraries(realtime_pixel_info_hovering_mouse realsense2 ${OpenCV_LIBS})


