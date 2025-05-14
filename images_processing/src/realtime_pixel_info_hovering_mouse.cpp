#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

// Global variables to track mouse position
cv::Point mouse_position(-1, -1);  // initialized off-screen

// Mouse callback function
void mouseMoveCallback(int event, int x, int y, int, void*) 
{
    if (event == cv::EVENT_MOUSEMOVE) {
        mouse_position = cv::Point(x, y);  // update global position
    }
}

int main() 
{
    // Initialize RealSense pipeline
    rs2::pipeline pipe;
    rs2::config cfg;
    cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_RGB8, 30);
    pipe.start(cfg);

    // Create OpenCV window
    std::string window_name = "RealSense Live View";
    cv::namedWindow(window_name);
    cv::setMouseCallback(window_name, mouseMoveCallback);  // track mouse movement

    while (true) 
    {
        // Wait for a new frame
        rs2::frameset frames = pipe.wait_for_frames();
        rs2::video_frame color_frame = frames.get_color_frame();

        int width = color_frame.get_width();
        int height = color_frame.get_height();

        // Convert to OpenCV format (RGB to BGR)
        cv::Mat frame(cv::Size(width, height), CV_8UC3, (void*)color_frame.get_data(), cv::Mat::AUTO_STEP);
        cv::cvtColor(frame, frame, cv::COLOR_RGB2BGR);

        // Show coordinates and color value at mouse position
        if (mouse_position.x >= 0 && mouse_position.x < frame.cols &&
            mouse_position.y >= 0 && mouse_position.y < frame.rows) 
            {

            // Get BGR values at that point
            cv::Vec3b bgr = frame.at<cv::Vec3b>(mouse_position.y, mouse_position.x);

            // Build display text
            std::string text = "X: " + std::to_string(mouse_position.x) +
                               " | Y: " + std::to_string(mouse_position.y) +
                               " | BGR: (" +
                               std::to_string(bgr[0]) + ", " +
                               std::to_string(bgr[1]) + ", " +
                               std::to_string(bgr[2]) + ")";

            // Draw background rectangle for text
            cv::rectangle(frame, cv::Point(10, 10), cv::Point(10 + 420, 40), cv::Scalar(0, 0, 0), -1);

            // Draw the text
            cv::putText(frame, text, cv::Point(15, 35), cv::FONT_HERSHEY_SIMPLEX,
                        0.7, cv::Scalar(0, 255, 0), 2);
        }

        // Show video with overlay
        cv::imshow(window_name, frame);

        // Exit if 'q' or ESC is pressed
        char key = static_cast<char>(cv::waitKey(1));
        if (key == 'q' || key == 27) break;
    }

    // Cleanup
    pipe.stop();
    cv::destroyAllWindows();
    return 0;
}
