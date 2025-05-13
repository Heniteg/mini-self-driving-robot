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

add_executable(capture_save_image src/capture_save_image.cpp)
target_link_libraries(capture_save_image realsense2 ${OpenCV_LIBS})

add_executable(realsense_fps_and_frame_size_monitor src/realsense_fps_and_frame_size_monitor.cpp)
target_link_libraries(realsense_fps_and_frame_size_monitor realsense2 ${OpenCV_LIBS})

add_executable(realsense_fps_with_opencv src/realsense_fps_with_opencv.cpp)
target_link_libraries(realsense_fps_with_opencv realsense2 ${OpenCV_LIBS})







