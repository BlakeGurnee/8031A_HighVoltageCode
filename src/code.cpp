//const int DRIVE_SPEED = 70;
    // Spin flap forward initially
   // setFlap(127);
   // pros::delay(250);  // Wait for the action

    // Drive forward and get ring
    //chassis.pid_drive_set(-5_in, DRIVE_SPEED, true);
   // chassis.pid_wait();

    //Get clamp in
    //clamp1.extend();  
    //pros::delay(350);

    //turn on combine and intake ring
    //setCombine(-127);
    //pros::delay(500);

    //Use flap for accuracy
    //setFlap(-127);
   // pros::delay(200);
   // setFlap(127);
    //pros::delay(200);
    //setFlap(-127);
    //pros::delay(200); 
    //setFlap(127);
    //pros::delay(200);
    //setFlap(-127);
    //pros::delay(200);

    //Turn to ring
   // chassis.pid_turn_set(145_deg, TURN_SPEED);
    //chassis.pid_wait();

    //Keep it going
   // setCombine(-127);
   // setFlap(127);

    //Go to ring 1
   // chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
   // chassis.pid_wait();
/*
    //Intake ring 1
   // setFlap(-127);
   // pros::delay(200);
   // setFlap(127);
   // pros::delay(200);
   // setFlap(-127);
    pros::delay(200); 
    setFlap(127);
    pros::delay(200);
    setFlap(-127);
    pros::delay(200);

    //Turn to ring 2
   chassis.pid_turn_set(90_deg, TURN_SPEED);
   chassis.pid_wait();

    //Go to ring 2
   chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    //Intake ring 2
   setCombine(-127);
   setFlap(127);

    //Use flap for accuracy
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
   */

  /*
    //Turn to ring 3
   chassis.pid_turn_set(90_deg, TURN_SPEED);
   chassis.pid_wait();

    //Go to ring 3
   chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
   chassis.pid_wait();

    //Intake ring 3
   setCombine(-127);
   setFlap(127);

    //Use flap for accuracy
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

    //Go to ring 4
   chassis.pid_drive_set(6_in, DRIVE_SPEED, true);
   chassis.pid_wait();

   //Intake ring 4
   setCombine(-127);
   setFlap(127);

    //Use flap for accuracy
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

    //Turn to ring 5
   chassis.pid_turn_set(45_deg, TURN_SPEED);
   chassis.pid_wait();

   //Go to ring 5
   chassis.pid_drive_set(6_in, DRIVE_SPEED, true);
   chassis.pid_wait();

   //Intake ring 5
   setCombine(-127);
   setFlap(127);

    //Use flap for accuracy
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

    //Turn to + corner
   chassis.pid_turn_set(180_deg, TURN_SPEED);
   chassis.pid_wait();

   //Go to + corner
   chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
   chassis.pid_wait();

    //Get clamp out
   clamp1.retract();  
   pros::delay(350);

   //Get out of positive corner
   chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
   chassis.pid_wait();

    //Turn to Mobile Goal 2
   chassis.pid_turn_set(105_deg, TURN_SPEED);
   chassis.pid_wait();

   //Go to Mobile Goal 2
   chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
   chassis.pid_wait();

    //Get clamp in
   clamp1.extend();  
   pros::delay(350);

   //Turn to ring 6
   chassis.pid_turn_set(-90_deg, TURN_SPEED);
   chassis.pid_wait();

    //Go to ring 6
   chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
   chassis.pid_wait();

    //Intake ring 6
   setCombine(-127);
   setFlap(127);

   //Use flap for accuracy
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

    //Go to ring 7
   chassis.pid_drive_set(6_in, DRIVE_SPEED, true);
   chassis.pid_wait();

    //Intake ring 7
   setCombine(-127);
   setFlap(127);

    //Use flap for accuracy
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

    //Turn to ring 8
   chassis.pid_turn_set(-45_deg, TURN_SPEED);
   chassis.pid_wait();

   //Go to ring 8
   chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
   chassis.pid_wait();

    //Intake ring 8
   setCombine(-127);
   setFlap(127);

    //Use flap for accuracy
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

   //Turn to ring 9
   chassis.pid_turn_set(-45_deg, TURN_SPEED);
   chassis.pid_wait();

    //Go to ring 9
   chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
   chassis.pid_wait();

    //Intake ring 9
   setCombine(-127);
   setFlap(127);

   //Use flap for accuracy
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

   //Turn to ring 10
   chassis.pid_turn_set(45_deg, TURN_SPEED);
   chassis.pid_wait();

   //Intake ring 10
   setCombine(-127);
   setFlap(127);

    //Use flap for accuracy
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

   //Turn to get rid of mobile goal 2
   chassis.pid_turn_set(180_deg, TURN_SPEED);
   chassis.pid_wait();

    //Get clamp out
   clamp1.retract();  
   pros::delay(350);

   //Turn back to mobile goal 3
   chassis.pid_turn_set(180_deg, TURN_SPEED);
   chassis.pid_wait();  
   */