#include "main.h"
#define VISION_PORT 12
#define REDRING_SIG 1
#define BLUERING_SIG 2

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 70;
const int TURN_SPEED = 90;
const int SWING_SPEED = 95;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(20, 0, 100);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);
  
  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

void redLeftSide() // 4 ring
{
  const int DRIVE_SPEED = 70;
  // Spin flap forward initially
  setFlap(127);
  pros::delay(250);  // Wait for the action

  // Drive forward 30 inches
  chassis.pid_drive_set(-30_in, DRIVE_SPEED, true);
  chassis.pid_wait(); // wait for pid

  clamp1.extend(); // extend clamp
  pros::delay(350); // wait 350 miliseconds

  // spin combine motor forward at max speed
  setCombine(-127);
  pros::delay(1000); // wait 1000 miliseconds

  
  setFlap(-127); // Swing flap
  pros::delay(500); // wait 500 miliseconds
  setFlap(127); // Swing flap
  pros::delay(500);// wait 500 miliseconds
  setFlap(-127); // Swing flap
  pros::delay(500);// wait 500 miliseconds
  // Flap forward, combine reverse, and turn 180 degrees
  setFlap(127); // swing flap up
  setCombine(-127); //spin combine forward at full speed
  chassis.pid_turn_set(-285_deg, TURN_SPEED); // turn -285 degrees
  chassis.pid_wait(); // wait for pid

  // Drive forward 28 inches
  chassis.pid_drive_set(28_in, DRIVE_SPEED, true);
  chassis.pid_wait(); // wait for pid
    

  setFlap(-127); //swing flap down
  pros::delay(250);// wait 250 miliseconds
  setFlap(127);//swing flap up
  pros::delay(250);// wait 250 miliseconds
  setFlap(-127);//swing flap down
  setFlap(0); // set flap to 0
  pros::delay(250); // wait 250 miliseconds
  setFlap(127);//swing flap up

  DRIVE_SPEED == 95; // set drive speed to 95

  setFlap(-127);
  pros::delay(250);
  setFlap(127);
  pros::delay(250);
  setFlap(-127);
  pros::delay(250);
  setFlap(127);
  pros::delay(250);
  setFlap(-127);
  pros::delay(250);
  setFlap(127);
  pros::delay(250);
  setFlap(-127);
  pros::delay(250);
  setFlap(127);

  chassis.pid_turn_set(-108_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(45_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

void redRightSide() // Auton for right (or far) side of the field scores 2 rings on mobile goal and touches the ladder
{
  const int DRIVE_SPEED = 70;
  // Spin flap forward initially
  setFlap(127);
  pros::delay(250);  // Wait for the action

  // Drive forward 30 inches
  chassis.pid_drive_set(-30_in, DRIVE_SPEED, true);
  chassis.pid_wait();

   clamp1.extend();  
   pros::delay(350);
  // Reverse combine motor
  setCombine(-127);
  pros::delay(1000);

  // Reverse flap for 1 second  
  setFlap(-127);
  pros::delay(500);
  setFlap(127);
  pros::delay(500);
  setFlap(-127);
  pros::delay(500);

  // Flap forward, combine reverse, and turn 180 degrees
  setFlap(127);
  setCombine(-127);
  chassis.pid_turn_set(285_deg, TURN_SPEED);
  chassis.pid_wait();

  // Drive forward 28 inches
  chassis.pid_drive_set(28_in, DRIVE_SPEED, true);
  chassis.pid_wait();
    

  // Reverse flap briefly, then toggle directions
  setFlap(-127);
  pros::delay(250);
  setFlap(127);
  pros::delay(250);
  setFlap(-127);
  setFlap(0);
  pros::delay(250);
  setFlap(127);

  DRIVE_SPEED == 95;

  setFlap(-127);
  pros::delay(250);
  setFlap(127);
  pros::delay(250);
  setFlap(-127);
  pros::delay(250);
  setFlap(127);
  pros::delay(250);
  setFlap(-127);
  pros::delay(250);
  setFlap(127);
  pros::delay(250);
  setFlap(-127);
  pros::delay(250);
  setFlap(127);

   chassis.pid_turn_set(110_deg, TURN_SPEED);
   chassis.pid_wait();

   chassis.pid_drive_set(45_in, DRIVE_SPEED, true);
   chassis.pid_wait();
}

void blueLeftSide()
{
  const int DRIVE_SPEED = 70;
    // Spin flap forward initially
    setFlap(127);
    pros::delay(250);  // Wait for the action

    // Drive forward 30 inches
    chassis.pid_drive_set(-30_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    clamp1.extend();  
    pros::delay(350);

    // Reverse combine motor
    setCombine(-127);
    pros::delay(1000);

    // Reverse flap for 1 second
    setFlap(-127);
    pros::delay(500);
    setFlap(127);
    pros::delay(500);
    setFlap(-127);
    pros::delay(500);

    // Flap forward, combine reverse, and turn 180 degrees
    setFlap(127);
    setCombine(-127);
    chassis.pid_turn_set(-285_deg, TURN_SPEED);
    chassis.pid_wait();

    // Drive forward 28 inches
    chassis.pid_drive_set(28_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    

    // Reverse flap briefly, then toggle directions
    setFlap(-127);
    pros::delay(250);
    setFlap(127);
    pros::delay(250);
    setFlap(-127);
    setFlap(0);
    pros::delay(250);
    setFlap(127);

    DRIVE_SPEED == 95;

    setFlap(-127);
    pros::delay(250);
    setFlap(127);
    pros::delay(250);
    setFlap(-127);
    pros::delay(250);
    setFlap(127);
    pros::delay(250);
    setFlap(-127);
    pros::delay(250);
    setFlap(127);
    pros::delay(250);
    setFlap(-127);
    pros::delay(250);
    setFlap(127);

   chassis.pid_turn_set(-108_deg, TURN_SPEED);
   chassis.pid_wait();

   chassis.pid_drive_set(45_in, DRIVE_SPEED, true);
   chassis.pid_wait();
}

void blueRightSide() { // 4 ring
  const int DRIVE_SPEED = 70;
    // Spin flap forward initially
    setFlap(127);
    pros::delay(250);  // Wait for the action

    // Drive forward 30 inches
    chassis.pid_drive_set(-30_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    clamp1.extend();  
    pros::delay(350);

    // Reverse combine motor
    setCombine(-127);
    pros::delay(1000);

    // Reverse flap for 1 second
    setFlap(-127);
    pros::delay(500);
    setFlap(127);
    pros::delay(500);
    setFlap(-127);
    pros::delay(500);

    // Flap forward, combine reverse, and turn 180 degrees
    setFlap(127);
    setCombine(-127);
    chassis.pid_turn_set(285_deg, TURN_SPEED);
    chassis.pid_wait();

    // Drive forward 28 inches
    chassis.pid_drive_set(28_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    // Reverse flap briefly, then toggle directions
    setFlap(-127);
    pros::delay(250);
    setFlap(127);
    pros::delay(250);
    setFlap(-127);
    setFlap(0);
    pros::delay(250);
    setFlap(127);

    DRIVE_SPEED == 95;

    setFlap(-127);
    pros::delay(250);
    setFlap(127);
    pros::delay(250);
    setFlap(-127);
    pros::delay(250);
    setFlap(127);
    pros::delay(250);
    setFlap(-127);
    pros::delay(250);
    setFlap(127);
    pros::delay(250);
    setFlap(-127);
    pros::delay(250);
    setFlap(127);

   chassis.pid_turn_set(110_deg, TURN_SPEED);
   chassis.pid_wait();

   chassis.pid_drive_set(45_in, DRIVE_SPEED, true);
   chassis.pid_wait();
}
void soloWp() //Scores 1 ring on alliance wall stake and 2 rings on alliance mobile goal and touches the ladder
{

  chassis.pid_drive_set(-15_in, DRIVE_SPEED, true); // Drive backwards a smidge to allign with wall stake
  chassis.pid_wait(); // wait for pid

  chassis.pid_turn_set(-85, TURN_SPEED); //turn -85 degrees
  chassis.pid_wait(); // wait for pid

  setCombine(127); // spin combine to get ring on wall stake
  pros::delay(1000); //wait 1000 miliseconds
  setCombine(0); //stop combine

  chassis.pid_drive_set(10_in, DRIVE_SPEED, true); // Drive forwards
  chassis.pid_wait(); // wait for pid

  
}
void skills() //Auton for skills matches
{
  const int DRIVE_SPEED = 100; // sets drive speed
  setCombine(127); // spin combine in reverse to get ring on wall stake
  pros::delay(1000); //wait 1000 milliseconds

  setCombine(0); //stop combine

  chassis.pid_drive_set(15_in, DRIVE_SPEED, true); //drive 15 inches
  chassis.pid_wait(); //wait for pid to finish

  chassis.pid_turn_set(-85_deg, TURN_SPEED); //turn -85 degrees
  chassis.pid_wait(); //wait for pid to finish

  chassis.pid_drive_set(-25_in, DRIVE_SPEED, true); //drive backwards 25 inches
  chassis.pid_wait(); //wait for pid to finish

  clamp1.extend();  //extend clamp
  pros::delay(300); //wait 300 miliseconds

  setFlap(127);
  
  chassis.pid_turn_set(-180_deg, TURN_SPEED); //turn 180 degrees
  chassis.pid_wait(); //wait for pid to finish

  chassis.pid_drive_set(20_in, DRIVE_SPEED, true); //drive 20 inches
  chassis.pid_wait(); //wait for pid to finish

  setCombine(-127); // spin combine in reverse to get ring on mobile stake
  chassis.pid_turn_set(180_deg, TURN_SPEED); //turn 180 degrees
  chassis.pid_wait(); //wait for pid to finish
  setFlap(-127);
  pros::delay(100);  // Wait for the action
  setFlap(127);

  chassis.pid_drive_set(20_in, DRIVE_SPEED, true); //drive 20 inches
  chassis.pid_wait(); //wait for pid to finish

  chassis.pid_turn_set(180_deg, TURN_SPEED); //turn 180 degrees
  chassis.pid_wait(); //wait for pid to finish

  setFlap(-127);
  pros::delay(100);  // Wait for the action
  setFlap(127);

  chassis.pid_drive_set(20_in, DRIVE_SPEED, true); //drive 20 inches
  chassis.pid_wait(); //wait for pid to finish

  chassis.pid_turn_set(-180_deg, TURN_SPEED); //turn -180 degrees
  chassis.pid_wait(); //wait for pid to finish

  setFlap(-127);
  pros::delay(100);  // Wait for the action
  setFlap(127);

  chassis.pid_drive_set(10_in, DRIVE_SPEED, true); //drive 10 inches
  chassis.pid_wait(); //wait for pid to finish

  chassis.pid_turn_set(-40_deg, TURN_SPEED); //turn -40 degrees
  chassis.pid_wait(); //wait for pid to finish

  chassis.pid_drive_set(10_in, DRIVE_SPEED, true); //drive 10 inches
  chassis.pid_wait(); //wait for pid to finish

  chassis.pid_turn_set(40_deg, TURN_SPEED); //turn 40 degrees
  chassis.pid_wait(); //wait for pid to finish

  setFlap(-127);
  pros::delay(100);  // Wait for the action
  setFlap(127);

  chassis.pid_drive_set(-10_in, DRIVE_SPEED, true); //drive backwards 10 inches
  chassis.pid_wait(); //wait for pid to finish

  clamp1.retract();  //extend clamp
  pros::delay(300); //wait 300 miliseconds

  chassis.pid_drive_set(10_in, DRIVE_SPEED, true); //drive forwards 10 inches
  chassis.pid_wait(); //wait for pid to finish

}


void test() // auton for testing purposes
{
  const int DRIVE_SPEED = 100;  //drive speed set to 100

    // Spin flap forward initially
   // setFlap(127);
   // pros::delay(50);  // Wait for the action
    //setFlap(0);

   // chassis.pid_drive_set(-5_in, DRIVE_SPEED, true); // Drive backwards a smidge to allign with wall stake
    //chassis.pid_wait();

    chassis.pid_drive_set(-15_in, DRIVE_SPEED, true); // Drive backwards a smidge to allign with wall stake
    chassis.pid_wait(); // wait for pid

    chassis.pid_turn_set(-85, TURN_SPEED); //turn -85 degrees
    chassis.pid_wait(); // wait for pid

    setCombine(127); // spin combine to get ring on wall stake
    pros::delay(3000); //wait 3000 miliseconds

    setCombine(0); //stop combine
}
void autonTest() // auton for testing purposes
{
const int DRIVE_SPEED = 70; // set drive speed to 70
    // Spin flap forward initially
    setFlap(127);
    pros::delay(250);  // Wait for the action

    // Drive forward and get two rings
    chassis.pid_drive_set(-5_in, DRIVE_SPEED, true); //
    chassis.pid_wait(); // wait for pid

    clamp1.extend();  //extend clamp
    pros::delay(350); // wait 350 miliseconds

    setCombine(-127); // spin combine fwd at max speed
    pros::delay(500); //wait 500 miliseconds 

    setFlap(-127);
    pros::delay(200);
    setFlap(127);
    pros::delay(200);
    setFlap(-127);
    pros::delay(200); 
    setFlap(127);
    pros::delay(200);
    setFlap(-127);
    pros::delay(200);

    chassis.pid_drive_set(-10_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    chassis.pid_turn_set(-50_deg, TURN_SPEED);
    chassis.pid_wait();

    setCombine(127);
    setFlap(-127);

    chassis.pid_drive_set(43_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    setFlap(-127);
    pros::delay(200);
    setFlap(127);
    pros::delay(200);
    setFlap(-127);
    pros::delay(200); 
    setFlap(127);
    pros::delay(200);
    setFlap(-127);
    pros::delay(200);
    setFlap(127);
    pros::delay(200);
     setFlap(-127);
    pros::delay(200);
    setFlap(127);
    pros::delay(200);
    setFlap(-127);
    pros::delay(200);
    setFlap(127);
    pros::delay(200);

    chassis.pid_turn_set(130_deg, TURN_SPEED);
    chassis.pid_wait();
    

    setFlap(-127);
    pros::delay(200);
    setFlap(127);
    pros::delay(200);
    setFlap(-127);
    pros::delay(200);
    setFlap(127);
    pros::delay(200);

    chassis.pid_drive_set(-10_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    pros::delay(500);

    setFlap(-127);
    pros::delay(200);
    setFlap(127);
    pros::delay(200);

    clamp1.retract();  
    pros::delay(350);

    chassis.pid_drive_set(20_in, DRIVE_SPEED, true);
    chassis.pid_wait();
}

// add more normal autons here
//
//

//tuner autons (Just leave these here)
void drive_48(){
  chassis.pid_drive_set(48_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void drive_96(){
  chassis.pid_drive_set(96_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void driveBack_48(){
  chassis.pid_drive_set(48_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(-48_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void driveBack_96(){
  chassis.pid_drive_set(96_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(-96_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void turn_90(){
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}
void turn_180(){
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
}
void turn_360(){
  chassis.pid_turn_set(360_deg, TURN_SPEED);
  chassis.pid_wait();
}
void turnBack(){
  chassis.pid_turn_set(360_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}