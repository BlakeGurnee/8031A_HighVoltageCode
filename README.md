
![Logo](https://i.ibb.co/9wBYq0C/Screenshot-2024-12-08-204044.png)


# 📢 8031A High Voltage - 2024 "High Stakes" Code Repository

Welcome to 8031A High Voltage's official codebase for the 2024 VEX Robotics "High Stakes" competition. This repository contains the source code for our robot, written in C++ using the PROS development environment and the EZ Template.

We use Git and GitHub for version control, which allows us to:

- Keep our code well-organized.
- Easily revert to previous versions if issues arise.
- Back up our work in the cloud to prevent data loss.
This system makes our coding process faster, more efficient, and collaborative. 🚀




## 🚀 Key Features

- Ring Detection: Uses a color sensor to identify and categorize rings for precision placement.
- PID Control: Ensures accurate and consistent movement of motors for precise alignment and control.
- Sensor Integration: Uses a combination of the following sensors for enhanced performance:
  - Vision Sensor for object detection.
  - Inertial Sensor for orientation tracking.
  - Rotation Sensor for position accuracy.
  - Distance Sensor for obstacle detection.


## 📚 File Structure

Here's how we've organized our project files to keep things clean and maintainable:

📂 src/  
  ┣ 📜 main.cpp           // Main entry point for our robot's code  
  ┣ 📜 autons.cpp         // Autonomous routines for all field positions  
  ┣ 📜 globals.cpp        // Global variables and constants  
  ┗ 📜 helpers.cpp        // Reusable helper functions for code efficiency  

📂 include/  
  ┣ 📜 globals.hpp       // Header file for global variables and constants  
  ┗ 📜 helpers.hpp       // Header file for helper functions  

📂 docs/                // Documentation and notes for the codebase  
📂 tests/               // Test scripts and prototypes for new features    

## 💡 FAQ (Frequently Asked Questions)

#### 1️⃣ Are the programs cleanly written, well-commented, and easy to follow?

Yes, our code is clean, organized, and well-commented. We make sure every key section of the code is properly explained with comments, so both new and experienced team members can understand it. Our file structure separates the main logic, autonomous routines, global variables, and reusable helper functions. This makes the code easy to maintain and navigate.

#### 2️⃣ Is the programming effective at solving game challenges for Qualification Matches and Autonomous Skills Challenges?

Absolutely. Our code is designed to handle both Qualification Matches and the Autonomous Skills Challenge.

Qualification Matches: We prioritize the most efficient scoring path to maximize points and secure the autonomous win point.
Autonomous Skills: Our robot is capable of scoring a ring on the alliance wall stake, placing two rings on a mobile goal, and touching the center ladder, all within a consistent and reliable routine. This program works for all four starting positions on the field with minimal error.



## 📈 Version Control with GitHub

How we use GitHub for version control:

Feature Branches: Every new feature or change starts in a new branch (like feature/PID-tuning).
Pull Requests & Code Reviews: Code is reviewed before being merged into the main branch to ensure it works properly.
Release Tags: We tag stable versions (like v1.0.0) to track our progress over time.
You can check our commit history to see the evolution of our code and how we've solved key challenges. This approach ensures stability, efficiency, and teamwork.

## 📕 Documentation

[Documentation](https://blakegurnee.github.io/8031A_HighVoltageCode/)

## 📲 Contact Us

For any questions or inquiries, feel free to reach out to Team 8031A High Voltage on our Instagram. We’re always excited to share our journey and learn from others!

