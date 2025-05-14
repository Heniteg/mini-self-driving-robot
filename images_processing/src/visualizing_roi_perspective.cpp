#include <librealsense2/rs.hpp>     // RealSense SDK
#include <opencv2/opencv.hpp>       // OpenCV
#include <iostream>

// Warp a rectangular ROI to a top-down rectangle
cv::Mat warpRectROI(const cv::Mat& frame,
                    const std::vector<cv::Point2f>& src_points,
                    const cv::Size& output_size) 
{
    // Define destination points: a perfect rectangle (e.g. full window size)
    std::vector<cv::Point2f> dst_points = {
        cv::Point2f(0, 0),                                              // top-left
        cv::Point2f(output_size.width - 1, 0),                          // top-right
        cv::Point2f(output_size.width - 1, output_size.height - 1),     // bottom-right
        cv::Point2f(0, output_size.height - 1)                          // bottom-left
    };

    // Compute perspective transform matrix
    cv::Mat transform_matrix = cv::getPerspectiveTransform(src_points, dst_points);

    // Apply the warp
    cv::Mat warped;
    cv::warpPerspective(frame, warped, transform_matrix, output_size);

    return warped;
}

int main() 
{
    // 1. Initialize RealSense pipeline
    rs2::pipeline pipe;
    rs2::config cfg;
    cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_RGB8, 30);
    pipe.start(cfg);

    std::cout << "Press 'q' or 'ESC' to quit.\n";

    while (true) 
    {
        // 2. Capture RealSense frame
        rs2::frameset frames = pipe.wait_for_frames();
        rs2::video_frame color_frame = frames.get_color_frame();

        int width = color_frame.get_width();
        int height = color_frame.get_height();

        // Convert to OpenCV Mat and BGR format
        cv::Mat frame(cv::Size(width, height), CV_8UC3, (void*)color_frame.get_data(), cv::Mat::AUTO_STEP);
        cv::cvtColor(frame, frame, cv::COLOR_RGB2BGR);

        // 3. Define rectangular ROI (manually set based on your camera view)
        // Adjust these points to tightly fit your lane in real-world view
        std::vector<cv::Point2f> src_points = {
            cv::Point2f(95, 400),       // top-left corner of ROI in image
            cv::Point2f(525, 400),     // top-right
            cv::Point2f(640, 480),   // bottom-right
            cv::Point2f(0, 480)    // bottom-left
        };

        // 4. Draw the rectangular ROI on the original image
        for (int i = 0; i < 4; i++) 
        {
            cv::line(frame, src_points[i], src_points[(i + 1) % 4], cv::Scalar(0, 255, 0), 2);
        }

        // 5. Warp the ROI to top-down view
        cv::Size warp_size(300, 300);  // output resolution of the bird's-eye view
        cv::Mat warped = warpRectROI(frame, src_points, warp_size);

        // 6. Display original and warped view
        cv::imshow("Original Frame with Rectangle ROI", frame);
        cv::imshow("Warped ROI (Top-down View)", warped);

        // 7. Exit on keypress
        char key = static_cast<char>(cv::waitKey(1));
        if (key == 'q' || key == 27) break;  // 'q' or ESC to quit
    }

    // 8. Cleanup
    pipe.stop();
    cv::destroyAllWindows();
    return 0;
}
