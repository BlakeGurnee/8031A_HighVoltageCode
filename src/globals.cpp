#include "main.h"

//motors
//pros::Motor combine(4, pros::v5::MotorGears::green);
pros::Motor combine(4, pros::v5::MotorGears::green);
pros::Motor combine2(16, pros::v5::MotorGears::green);
pros::Motor flap(18, pros::v5::MotorGears::green);

//Pneumatics
pros::adi::Pneumatics clamp1('H', false);  
pros::adi::Pneumatics arm('G', false);

//Sensors
pros::Vision vision(12);
