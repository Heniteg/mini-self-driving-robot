#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>

std::string generate_filename() 
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << "../src/saved_images/realsense_capture_"
       << std::put_time(std::localtime(&now_c), "%Y%m%d_%H%M%S") << ".png";

    return ss.str();
}

int main() 
{
    try 
    {
        // Start RealSense pipeline
        rs2::pipeline pipe;
        pipe.start();

        // Wait for a coherent color frame
        rs2::frameset frames = pipe.wait_for_frames();
        rs2::video_frame color_frame = frames.get_color_frame();

        // Get frame dimensions
        int width = color_frame.get_width();
        int height = color_frame.get_height();

        // Create OpenCV matrix from RealSense color frame
        cv::Mat color_image(cv::Size(width, height), CV_8UC3, 
                            (void*)color_frame.get_data(), cv::Mat::AUTO_STEP);
        
        cv::imshow("Preview", color_image);
        cv::waitKey(0);

        // Save image
        std::string filename = generate_filename();
        cv::imwrite(filename, color_image);

        std::cout << "Image captured and saved as: " << filename << std::endl;
    }
    catch (const rs2::error & e) 
    {
        std::cerr << "RealSense error: " << e.what() << std::endl;
    }
    catch (const std::exception & e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
