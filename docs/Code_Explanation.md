# 📜 Code Explanation for 8031A High Voltage

This document explains the core files and important functions in our robot's code.

## 📁 File Descriptions
- **main.cpp**: Entry point for the robot's operation. Handles initialization, user control, and match logic.  
- **globals.cpp**: Stores global constants, variables, and sensor initialization.  
- **autons.cpp**: Contains all autonomous routines for different starting positions.  
- **helpers.cpp**: Reusable helper functions for common tasks (like our clap, intake, and lady brown).  

---

## 📜 Key Functions
### 1️⃣ **void autonomous()** 
> Located in `main.cpp`

- **What it does**: Runs the autonomous routine based on the match starting position.  
- **How it works**: Uses conditional logic to choose one of four pre-programmed routines for each corner.  

### 2️⃣ **void pidControl(int target, int maxSpeed)**
> Located in `helpers.cpp`

- **What it does**: Uses a Proportional-Integral-Derivative (PID) control loop to make precise robot movements.  
- **How it works**: Takes a target position and adjusts motor speed to reach that target without overshooting.  
