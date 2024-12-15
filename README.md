
![Logo](https://i.ibb.co/9wBYq0C/Screenshot-2024-12-08-204044.png)


# 📢 8031A High Voltage - 2024 "High Stakes" Code Repository

Welcome to 8031A High Voltage's official codebase for the 2024 VEX Robotics "High Stakes" competition. This repository contains the source code for our robot, written in C++ using the PROS development environment and the EZ Template.

We use Git and GitHub for version control, which allows us to:

✅ Stay organized — Code is broken down into logical, well-labeled files.
✅ Track changes — Revert to previous versions if issues arise.
✅ Back up our work — Code is stored safely in the cloud to avoid data loss.
This process makes our development faster, more efficient, and highly collaborative. 🚀


## 🚀 Key Features

Our robot is equipped with advanced features to dominate the "High Stakes" competition. Here’s a look at what makes our code stand out:

## 🎯 Ring Detection

Uses an optical sensor to identify and categorize rings for precision placement.
## 🔄 PID Control

Implements Proportional, Integral, and Derivative control to ensure accurate motor movements and alignment.
## 🧠 Sensor Integration

Our robot uses multiple sensors to enhance its performance:

  - 🔵 Optical Sensor - For sorting out wrong color rings.
  - 🔵 Inertial Sensor — To track orientation and ensure accurate turns.
  - 🔵 Rotation Sensor — Measures position for precision movements.
  - 🔵 Distance Sensor  — Detects obstacles and helps with autonomous alignment.


## 📚 File Structure

To keep our project maintainable and easy to navigate, we’ve organized the files into a simple, intuitive structure:

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

#### 🔹 Are the programs cleanly written, well-commented, and easy to follow?

Yes! Our code is clean, organized, and well-commented. Each major section of the code is properly labeled, making it easy for new and experienced team members to understand. We follow a modular design approach, separating logic into dedicated files for autonomous routines, global variables, and helper functions.

#### 🔹 Is the programming effective at solving game challenges for Qualification Matches and Autonomous Skills Challenges?

Absolutely! Our program is battle-tested and competition-ready. Here’s how we dominate both modes:

# Autonomous in Qualification Matches 
Our program enables the robot to:
  - Score a ring on the alliance wall stake.
  - Place two rings on a mobile goal.
  - Touch the center ladder
    
This earns us the autonomous win point and it works for all four starting positions on the field with minimal error.

# Autonomous Skills 
- Prioritizes speed and precision to ensure consistency and high scores in skills runs.

## 📈 Version Control with GitHub

How we use GitHub for version control:

- 🌿 Feature Branches: Every new feature or change starts in a new branch (like feature/PID-tuning) to avoid disrupting the main code.
- 🔍 Pull Requests & Code Reviews: Code is reviewed before being merged into the main branch to ensure it works properly.
- 🏷️ Release Tags: We tag stable versions (like v1.0.0) to track our progress over time.

🕵️‍♂️ Check our commit history to see how our code has evolved to solve key challenges.

## 📕 Documentation

[Documentation](https://blakegurnee.github.io/8031A_HighVoltageCode/)

## 📲 Contact Us

Have questions, suggestions, or just want to connect? Reach out to us on Instagram!
We’re always happy to share our journey, learn from others, and inspire the next generation of robotics champions.

