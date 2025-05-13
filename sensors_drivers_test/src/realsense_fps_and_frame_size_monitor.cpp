#include <librealsense2/rs.hpp>         // RealSense SDK
#include <chrono>                       // For timing
#include <iostream>                     

int main() 
{
    // STEP 1: Create and configure the pipeline
    rs2::pipeline pipe;
    rs2::config cfg;
    cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_BGR8, 30);  // 30 FPS expected
    pipe.start(cfg);  // Start the camera

    // STEP 2: Variables to track FPS
    int frame_count = 0;
    const int num_frames = 60;  // We'll average over 60 frames for stability
    auto start_time = std::chrono::steady_clock::now();  // Start time for FPS timer

    std::cout << "RealSense FPS + Frame Size Monitor Started\n";

    // STEP 3: Frame capture loop
    while (true) 
    {
        // Wait for the next frame from the camera
        rs2::frameset frames = pipe.wait_for_frames();

        // Get the color frame from the frameset
        rs2::video_frame color_frame = frames.get_color_frame();

        // Extract frame resolution
        int width = color_frame.get_width();
        int height = color_frame.get_height();

        // Compute total size of the frame in bytes
        // Stride = bytes per row; total = stride × number of rows
        int size_in_bytes = color_frame.get_stride_in_bytes() * height;

        // Increase frame counter
        frame_count++;

        // Print frame info
        std::cout << "Frame " << frame_count
                  << " | Resolution: " << width << "x" << height
                  << " | Size: " << size_in_bytes << " bytes"
                  << std::endl;

        // STEP 4: If we've collected enough frames, calculate FPS
        if (frame_count >= num_frames) 
        {
            // Stop timer and calculate time duration
            auto end_time = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed = end_time - start_time;

            // Calculate average FPS = total frames / time elapsed
            double fps = frame_count / elapsed.count();

            std::cout << "------------------------------------------------------------\n";
            std::cout << "Average FPS over " << frame_count << " frames: " << fps << " fps\n";
            std::cout << "Resolution: " << width << "x" << height << "\n";
            std::cout << "Frame size: " << size_in_bytes << " bytes\n";
            std::cout << "------------------------------------------------------------\n";

            // Reset counters and timer for next FPS measurement
            frame_count = 0;
            start_time = std::chrono::steady_clock::now();
        }
    }

    pipe.stop(); 
    return 0;
}
