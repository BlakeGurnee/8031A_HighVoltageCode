#include "main.h"
#include "autons.hpp"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VISION_PORT 12
#define REDRING_SIG 1
#define BLUERING_SIG 2
double hue;

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-3, -2, -20},     // Left Chassis Ports (negative port will reverse it!)
    {1, 5, 10},  // Right Chassis Ports (negative port will reverse it!)

    7,      // IMU Port
    4.125,  // Wheel Diameter  (Remember, 4" wheels without screw holes are actually 4.125!)
    360);   // Wheel RPM

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  ez::ez_template_print();

  pros::delay(500);  // Stop the user from doing anything while legacy ports configure

  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(true);  // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(2);    // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(0, 0);     // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp!
  default_constants();

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.opcontrol_curve_buttons_left_set(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);  // If using tank, only the left side is used.
  // chassis.opcontrol_curve_buttons_right_set(pros::E_CONTROLLER_DIGITAL_Y, pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({
    Auton("Auton for Red left (or near) side of the field scores 2 rings on mobile goal and touches the ladder", redLeftSide),
    Auton("Auton for Red right (or far) side of the field scores 2 rings on mobile goal and touches the ladder", redRightSide),
    Auton("Auton for Blue left (or near) side of the field scores 2 rings on mobile goal and touches the ladder", blueLeftSide),
    Auton("Auton for Blue right (or far) side of the field scores 2 rings on mobile goal and touches the ladder", blueRightSide),
    Auton("Auton for Solo Win Point", soloWp),
    Auton("Auton For Programming Skills Matches", skills),
    Auton("Auton for setting the red alliance for drive test with optical sensor", setAllianceRed),
    Auton("Auton for setting the blue alliance for drive test with optical sensor", setAllianceBlue),

    // Testing autons these are still in development and are probaly not ready to be used on the field yet if tesing auton or vision sensor un comment these:
    Auton("Auton for Autonomus Testing", test), 
   //Auton("Auton for color sensor testing", colorSensorTest),

    // leave these here if tuning PID then un comment these should NOT be run during a match these are for tuning the PID and that only.
    Auton("drive 48", drive_48),
    Auton("drive 96", drive_96),
    Auton("drive back 48", driveBack_48),
    Auton("drive back 96", driveBack_96),
    Auton("turn 90", turn_90),
    Auton("turn 180", turn_180),
    Auton("turn 360", turn_360),
    Auton("turn back", turnBack),
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
  master.rumble(".");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit whe  n the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

  chassis.pid_targets_reset();    // Resets PID targets to 0
  chassis.drive_imu_reset();      // Reset gyro position to 0 

  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency
  setIntake(0);
  
  ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {
  /* leaving this here just in case we ever need it again in the future
  pros::Vision vision_sensor (VISION_PORT);

  pros::vision_signature_s_t RED_SIG =
    pros::Vision::signature_from_utility(REDRING_SIG, 5549, 9289, 7419, -881, -445, -663, 0.8, 0);
  vision_sensor.set_signature(REDRING_SIG, &RED_SIG);
 pros::vision_signature_s_t BLUE_SIG =
    pros::Vision::signature_from_utility(BLUERING_SIG, -4193, -3521, -3857, 2507, 7775, 5141, 0.6, 0);
 vision_sensor.set_signature(BLUERING_SIG, &BLUE_SIG);
 */


  // This is preference to what you like to drive on
  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;

  chassis.drive_brake_set(driver_preference_brake);

  while (true) {
     //detect_ring();  // Call the detection function continuously in operator control
     pros::delay(20);      // Delay to prevent overload

    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_X))
        chassis.pid_tuner_toggle();

      // Trigger the selected autonomous routine
      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
        autonomous();
        chassis.drive_brake_set(driver_preference_brake);
      }

      chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
    }

    chassis.opcontrol_tank();  // Tank control
    // chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
    // chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
    // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade

    // . . .
    // Put more user control code here!
    
    // Trigger the selected autonomous routine
    if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN))
    {
      autonomous();
    }

    if (master.get_digital(DIGITAL_UP))
    {
      setIntake(100);

      if (alliance = 1) { // 1 = red alliance so if red alliance run this
      hue = optical_sensor.get_hue(); //Gets hue from the optical sensor
        if (hue > 0) // If the hue is less than 360 (360 hue is the color blue) then intake red rings and reverse blue rings
        {
          setIntake(100); //If the ring color is red the intake will run normally
        }
        else 
        {
          setIntake(-100); //If the ring color is blue the intake will reverse
        }
        }
        else if (alliance = 2) { // 2 = blue alliance so if blue alliance run this
        hue = optical_sensor.get_hue(); //Gets hue from the optical sensor
          if (hue < 360) // If the hue is greater than 0 (0 hue is the color red) then intake blue rings and reverse red rings
          {
            setIntake(100); 
          }
          else 
          {
            setIntake(-100);
          }
      }
    }
    else if (master.get_digital(DIGITAL_DOWN))
    {
      setIntake(100); 
    }
    else if (master.get_digital(DIGITAL_RIGHT))
    {
      setIntake(0);
    }

    if (master.get_digital_new_press(DIGITAL_R1))
    {
      clamp1.toggle();
    }

    if (master.get_digital(DIGITAL_L1))
    {
      rotation_sensor.set_position(180);
    }
    if (master.get_digital(DIGITAL_L2))
    {
      rotation_sensor.set_position(0);
    }

    

 
    // . . .

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  } 
}
