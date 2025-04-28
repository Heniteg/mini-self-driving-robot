// Include RealSense and OpenCV headers
#include <librealsense2/rs.hpp>  // RealSense SDK main header
#include <opencv2/opencv.hpp>    // OpenCV main header
#include <iostream>
#include <chrono>
#include <thread>

int main() 
{
    try 
    {
        // Create a pipeline to configure, start and stop camera streaming
        rs2::pipeline pipe;
        rs2::config cfg;
        
        // Configure the pipeline to stream only color frames
        cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_BGR8, 30);
        
        // Start streaming with the selected configuration
        pipe.start(cfg);

        // Wait a bit to ensure the camera is warmed up
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "RealSense camera streaming started. Press 'q' to exit." << std::endl;

        while (true) 
        {
            // Wait for the next set of frames from the camera
            rs2::frameset frames = pipe.wait_for_frames();
            
            // Get the color frame
            rs2::video_frame color_frame = frames.get_color_frame();

            // Create an OpenCV matrix from the color frame data
            cv::Mat color(cv::Size(640, 480), CV_8UC3, (void*)color_frame.get_data(), cv::Mat::AUTO_STEP);

            // Show the image in an OpenCV window
            cv::imshow("RealSense RGB Stream", color);

            // Wait for 1 ms and check if 'q' is pressed
            char key = static_cast<char>(cv::waitKey(1));
            if (key == 'q' || key == 'Q') {
                std::cout << "Exit requested. Stopping pipeline..." << std::endl;
                break;
            }
        }

        // Stop the camera pipeline cleanly
        pipe.stop();
        std::cout << "Pipeline stopped successfully." << std::endl;

        // Destroy OpenCV window
        cv::destroyAllWindows();
    }
    catch (const rs2::error& e) 
    {
        std::cerr << "RealSense error calling " << e.get_failed_function() 
                  << "(" << e.get_failed_args() << "): " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
