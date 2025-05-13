#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <iostream>

// Function to initialize and start RealSense pipeline
rs2::pipeline initializePipeline() 
{
    rs2::pipeline pipe;
    rs2::config cfg;
    cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_RGB8, 30);
    pipe.start(cfg);
    return pipe;
}

// Function to capture a color frame from the RealSense pipeline
rs2::video_frame getColorFrame(rs2::pipeline& pipe) 
{
    rs2::frameset frames = pipe.wait_for_frames();
    return frames.get_color_frame();
}

// Function to convert RealSense RGB frame to OpenCV RGB and BGR Mat
void convertToOpenCV(const rs2::video_frame& frame, cv::Mat& rgb_image, cv::Mat& bgr_image) 
{
    int width = frame.get_width();
    int height = frame.get_height();

    // RealSense frame is RGB, OpenCV expects BGR
    rgb_image = cv::Mat(cv::Size(width, height), CV_8UC3, (void*)frame.get_data(), cv::Mat::AUTO_STEP);
    cv::cvtColor(rgb_image, bgr_image, cv::COLOR_RGB2BGR);
}

// Function to show both RGB and BGR images side by side
void displayFrames(const cv::Mat& rgb, const cv::Mat& bgr) 
{
    cv::Mat combined;
    cv::hconcat(rgb, bgr, combined);
    cv::imshow("RGB (native) vs BGR (OpenCV)", combined);
}

// Function to calculate average FPS over N frames
double calculateFPS(int& frame_count, const int num_frames, std::chrono::steady_clock::time_point& start_time) 
{
    frame_count++;

    if (frame_count >= num_frames) 
    {
        auto end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_time = end_time - start_time;

        double fps = frame_count / elapsed_time.count();

        std::cout << "Average FPS over " << frame_count << " frames: " << fps << " fps" << std::endl;

        frame_count = 0;
        start_time = std::chrono::steady_clock::now();
        return fps;
    }
    return -1.0; // Skip update
}

// -------------------- MAIN FUNCTION ------------------------
int main() 
{
    rs2::pipeline pipe = initializePipeline();

    int frame_count = 0;
    const int num_frames = 60;
    auto start_time = std::chrono::steady_clock::now();

    std::cout << "Press 'q' to quit.\n";

    while (true) 
    {
        // 1. Capture frame
        rs2::video_frame color_frame = getColorFrame(pipe);

        // 2. Convert to OpenCV Mat formats
        cv::Mat rgb, bgr;
        convertToOpenCV(color_frame, rgb, bgr);

        // 3. Display side-by-side
        displayFrames(rgb, bgr);

        // 4. Calculate and optionally print FPS
        calculateFPS(frame_count, num_frames, start_time);

        // 5. Quit on 'q' key
        char key = static_cast<char>(cv::waitKey(1));
        if (key == 'q' || key == 27) break;
    }

    pipe.stop();
    cv::destroyAllWindows();
    return 0;
}
