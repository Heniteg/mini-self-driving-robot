#include <librealsense2/rs.hpp> // Include RealSense Cross Platform API
#include <iostream>
#include <iostream>
#include <chrono>
#include <thread>

int main() 
{
    rs2::pipeline pipe;
    pipe.start();
    std::cout << "Streaming RealSense D435i..." << std::endl;
    
    // a small delay to let camera warm up
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Capture 30 frames
    for (int i = 0; i < 30; i++) 
    { 
        rs2::frameset frames = pipe.wait_for_frames();
    }

    pipe.stop();
    std::cout << "Stopped streaming." << std::endl;
    return 0;
}
