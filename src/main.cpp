#include "main.h"
#include "autons.hpp"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double hue;
bool intakeActive = false;

int autonSelected = 0; // 0 = no auton selected

const int numStates = 3;
int states[numStates] = {0, 25, 195};
int currentState = 0;
int target = 0;

void nextState() {
    currentState += 1;
    if (currentState == numStates) {
        currentState = 0;
    }
    target = states[currentState];
}

void liftControl() {
    double kp = 3.15;
    //double error = target - rotation_sensor.get_position();
    //double velocity = kp * error;
   // ladyBrown.move(velocity);
   ladyBrown.move(kp * (target - (rotation_sensor.get_position()/100.0)));
}

rd_view_t *image_view = rd_view_create("Image");


rd::Selector selector({
    {"Red Left", redLeftSide},
    {"Red Right", redRightSide},
    {"Blue Left", blueLeftSide},
    {"Blue Right", blueRightSide},
    {"Skills", skills}
});

rd::Console console;

rd::Image image("S/usd/logo.bin", "Team Logo");

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-3, -2, -20},     // Left Chassis Ports (negative port will reverse it!)
    {1, 5, 9},  // Right Chassis Ports (negative port will reverse it!)

    7,      // IMU Port
    275,  // Wheel Diameter  (Remember, 4" wheels without screw holes are actually 4.125!)
    360);   // Wheel RPM


    void colorSortRed() {
    if (intakeActive) {
        optical_sensor.set_led_pwm(100);
        // Use a single check without a blocking infinite loop.
        double hue = optical_sensor.get_hue();
        if ((hue < 10 || hue > 355)) {
            setIntake(0);
            pros::delay(1000);
        }
    }
    else {
        setIntake(0);
    }
}

void colorSortBlue() {
    if (intakeActive) {
        setIntake(-115);
        double hue = optical_sensor.get_hue();
        if ((200 < hue && hue < 240)) {
            setIntake(0);
            pros::delay(1000);
        }
    }
    else {
        setIntake(0);
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  
  pros::delay(500);  // Stop the user from doing anything while legacy ports configure

  console.println("Console inititalized!");
  console.printf("System time: %d\n", pros::millis());

  rotation_sensor.reset_position();

    // Launch the lift control task with proper yielding
    pros::Task liftControlTask([]{
        while (true) {
            liftControl();
            pros::delay(10);
        }
    });

    // Launch the color sort task with a delay in each loop iteration
    /*
    pros::Task colorSortTask([]{
        while (true) {
            if (alliance == 1) {
                colorSortRed();
            }
            else if (alliance == 2) {
                colorSortBlue();
            }
            pros::delay(50); // Yield to allow other tasks to run
        }
    });
    */

  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(true);  // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(2);    // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(0, 0);     // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp!
  default_constants();

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.opcontrol_curve_buttons_left_set(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);  // If using tank, only the left side is used.
  // chassis.opcontrol_curve_buttons_right_set(pros::E_CONTROLLER_DIGITAL_Y, pros::E_CONTROLLER_DIGITAL_A);

  /*
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
  */

  // Initialize chassis and auton selector
  chassis.initialize();
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
  
  //ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
  selector.run_auton();
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

  // This is preference to what you like to drive on
  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;

  chassis.drive_brake_set(driver_preference_brake);

  while (true) {

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
      intakeActive = true;
      //colorSortRed();
      setIntake(-127);
    }
    else if (master.get_digital(DIGITAL_DOWN))
    {
      intakeActive = true;
      setIntake(115);
    }
    else if (master.get_digital(DIGITAL_RIGHT))
    {
      intakeActive = false;
      setIntake(0);
    }

    if (master.get_digital_new_press(DIGITAL_R1))
    {
      clamp1.toggle();
    }

     if (controller.get_digital_new_press(DIGITAL_Y)) {
            tipper.toggle();
      }

    if (controller.get_digital_new_press(DIGITAL_L1)) {
          nextState();
    }

    

 
    // . . .

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  } 
}
