#include "main.h"

//motors
//pros::Motor combine(4, pros::v5::MotorGears::green);
pros::Motor combine(4, pros::v5::MotorGears::green);
pros::Motor hooks(16, pros::v5::MotorGears::green);
pros::Motor ladyBrown(18, pros::v5::MotorGears::green);
 

//Pneumatics
pros::adi::Pneumatics clamp1('H', false);

//Sensors
pros::Optical optical_sensor(14);
pros::Rotation rotationSensor(3);
int alliance = 1;

