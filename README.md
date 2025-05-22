# 🚗 Mini Self-Driving Car Project (In Progress)

A modular, DIY robotics project to prototype and learn autonomous driving systems using Raspberry Pi 4, Arduino Uno, RealSense D435i, OpenCV, and more.  
This repository includes real-time control, perception, and planning experiments for a small 4-wheeled robot.

📘 [Visit my website](https://henoktegegn.com)  
📒 [View detailed project logs](https://medium.com/@henoktegegn/mini-self-driving-car-project-series-overview-7bd7afa4e60e)

---

## 📁 Project Structure

### `Arduino-Controller/`
Motor control logic using L298N H-Bridge and Arduino PWM.

🔗 [motorControl.ino](https://github.com/Heniteg/mini-self-driving-robot/blob/main/Arduino-Controller/motorControl/motorControl.ino)  
📒 [Hardware + Motor Control Overview](https://medium.com/@henoktegegn/mini-self-driving-car-project-overview-7e3c25d73f52)

---

### `sensors_drivers_test/`
Testing and integrating Intel RealSense D435i on Raspberry Pi.

- 🔗 [realsense_test.cpp](https://github.com/Heniteg/mini-self-driving-robot/blob/main/sensors_drivers_test/src/realsense_test.cpp) – Basic RealSense pipeline test
- 🔗 [rs_opencv_realtime.cpp](https://github.com/Heniteg/mini-self-driving-robot/blob/main/sensors_drivers_test/src/rs_opencv_realtime.cpp) – OpenCV color stream with RealSense

📒 [OpenCV + RealSense Installation](https://medium.com/@henoktegegn/opencv-and-realsense-d435i-installation-on-raspberry-pi-4-ubuntu-22-04-bde9170671ef)  
📒 [Testing RealSense Output](https://medium.com/@henoktegegn/working-with-realsense-on-raspberry-pi-4-ubuntu-22-04-14f1739f8e03)

---

### `images_processing/`
Image utilities for ROI definition and lane detection preparation.

- 🔗 [realtime_pixel_info_hovering_mouse.cpp](https://github.com/Heniteg/mini-self-driving-robot/blob/main/images_processing/src/realtime_pixel_info_hovering_mouse.cpp) – Real-time pixel coordinate tracker
- 🔗 [visualizing_roi_perspective.cpp](https://github.com/Heniteg/mini-self-driving-robot/blob/main/images_processing/src/visualizing_roi_perspective.cpp) – Perspective transform + ROI visualization

📒 [Pixel Coordinate Tracker and ROI perspective](https://medium.com/@henoktegegn/real-time-mouse-hover-pixel-coordinate-tracking-and-roi-perspective-d116e4963193)

---

## 🎯 Project Goals
- Build a fully functional modular robot for indoor lane-based navigation
- Learn and apply perception, motion control, and planning techniques
- Test localization and depth perception using RealSense + encoders
- Scale to real-time autonomous navigation with path planning

---

## 📚 Blog Posts

📝 [What I Learned from Building My First Robot](https://medium.com/@henoktegegn/how-i-started-building-my-own-mini-self-driving-car-lessons-from-day-1-90b89bdabdd4)  
🧠 [Using a Kalman Filter for Localization in ROS](https://medium.com/@henoktegegn/how-i-used-a-kalman-filter-to-teach-my-robot-where-it-actually-is-6c677b71c6e7)

---

## 🌐 Follow My Work
- 🔗 Website: [henoktegegn.com](https://henoktegegn.com)
- 💻 GitHub: [github.com/Heniteg](https://github.com/Heniteg)
- ✍️ Medium: [@heni1032.tegegn](https://medium.com/@henoktegegn)
- 💼 LinkedIn: [Henok Tegegn](https://www.linkedin.com/in/henok-tegegn-0a7506160/)

---

## 🤝 Let’s Connect
I am open to **collaboration**, feedback, and **opportunities** in robotics, AI, and embedded systems.  
Let’s build something impactful together!
