# 🚗 Mini Self-Driving Car Project (In Progress)

A modular, DIY robotics project to prototype and learn autonomous driving systems using Raspberry Pi 4, Arduino Uno, RealSense D435i, OpenCV, and more.  
This repository includes real-time control, perception, and planning experiments for a small 4-wheeled robot.

📘 [Visit my website](https://henoktegegn.com)  
📒 [View detailed project logs](https://www.notion.so/Mini-Self-Driving-Car-Project-Overview-1f5bc9851ae780dd8717d8afeb42d59b)

---

## 📁 Project Structure

### `Arduino-Controller/`
Motor control logic using L298N H-Bridge and Arduino PWM.

🔗 [motorControl.ino](https://github.com/Heniteg/mini-self-driving-robot/blob/main/Arduino-Controller/motorControl/motorControl.ino)  
📒 [Hardware + Motor Control Overview](https://www.notion.so/Mini-Self-Driving-Car-Project-Overview-1f5bc9851ae780dd8717d8afeb42d59b)

---

### `sensors_drivers_test/`
Testing and integrating Intel RealSense D435i on Raspberry Pi.

- 🔗 [realsense_test.cpp](https://github.com/Heniteg/mini-self-driving-robot/blob/main/sensors_drivers_test/src/realsense_test.cpp) – Basic RealSense pipeline test
- 🔗 [rs_opencv_realtime.cpp](https://github.com/Heniteg/mini-self-driving-robot/blob/main/sensors_drivers_test/src/rs_opencv_realtime.cpp) – OpenCV color stream with RealSense

📒 [OpenCV + RealSense Installation](https://www.notion.so/OpenCV-and-RealSense-D435i-Installation-on-Raspberry-Pi-4-Ubuntu-22-04-1f8bc9851ae7804fa565c24b9d616855)  
📒 [Testing RealSense Output](https://www.notion.so/Working-with-realsense-on-raspberry-pi-4-Ubuntu-22-04-1f8bc9851ae7808793daf5c57bd727d4)

---

### `images_processing/`
Image utilities for ROI definition and lane detection preparation.

- 🔗 [realtime_pixel_info_hovering_mouse.cpp](https://github.com/Heniteg/mini-self-driving-robot/blob/main/images_processing/src/realtime_pixel_info_hovering_mouse.cpp) – Real-time pixel coordinate tracker
- 🔗 [visualizing_roi_perspective.cpp](https://github.com/Heniteg/mini-self-driving-robot/blob/main/images_processing/src/visualizing_roi_perspective.cpp) – Perspective transform + ROI visualization

📒 [Pixel Coordinate Tracker – Notion](https://www.notion.so/Real-Time-Mouse-Hover-Pixel-Coordinate-Tracking-1f8bc9851ae7802b9f30e35da7b2a64c)

---

## 🎯 Project Goals
- Build a fully functional modular robot for indoor lane-based navigation
- Learn and apply perception, motion control, and planning techniques
- Test localization and depth perception using RealSense + encoders
- Scale to real-time autonomous navigation with path planning

---

## 📚 Blog Posts

📝 [What I Learned from Building My First Robot](https://medium.com/@heni1032.tegegn/how-i-started-building-my-own-mini-self-driving-car-lessons-from-day-1-541e7878ce6e)  
🧠 [Using a Kalman Filter for Localization in ROS](https://medium.com/@heni1032.tegegn/how-i-used-a-kalman-filter-to-teach-my-robot-where-it-actually-is-52468e674c4a)

---

## 🌐 Follow My Work
- 🔗 Website: [henoktegegn.com](https://henoktegegn.com)
- 💻 GitHub: [github.com/Heniteg](https://github.com/Heniteg)
- ✍️ Medium: [@heni1032.tegegn](https://medium.com/@heni1032.tegegn)
- 💼 LinkedIn: [Henok Tegegn](https://www.linkedin.com/in/henok-tegegn-0a7506160/)

---

## 🤝 Let’s Connect
I'm open to **collaboration**, feedback, and **opportunities** in robotics, AI, and embedded systems.  
Let’s build something impactful together!
