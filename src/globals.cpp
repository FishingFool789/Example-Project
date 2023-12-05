#include "main.h"
#include "globals.hpp"

pros::Motor L1(9);
pros::Motor L2(-10);
pros::Motor L3(-8);
pros::Motor R1(-4);
pros::Motor R2(13);
pros::Motor R3(19);
pros::Motor intake(20);
pros::Motor catapult(11);
pros::MotorGroup lefty({L1, L2, L3});
pros::MotorGroup righty({R1, R2, R3});
pros::ADIDigitalOut flaps('G');
pros::ADIButton limit('F');
pros::ADIDigitalOut arm('H');

