#include "main.h"
#include "globals.hpp"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}



///
// Drive Example
///
// void shart() {
//   // The first parameter is target inches
//   // The second parameter is max speed the robot will drive at
//   // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
//   // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


//   chassis.set_drive_pid(24, DRIVE_SPEED, true);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-12, DRIVE_SPEED);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-12, DRIVE_SPEED);
//   chassis.wait_drive();
// }

void far(){
std::shared_ptr<OdomChassisController> bob =
      ChassisControllerBuilder()
            .withMotors({9, 10,      8}, //left motors
                        {4, 13, 19}
                        )  //right motors
            // Green gearset, external ratio of (36.0 / 60.0), 4 inch wheel diameter, 11.5 inch wheel track 3.51
            .withDimensions({AbstractMotor::gearset::blue, (36.0 / 60.0)}, {{3.25_in, 12_in}, imev5GreenTPR})
            .withSensors(
                        RotationSensor{9}, // Left encoder in V5 port 1
                        RotationSensor{10}, // Right encoder in V5 port 2 (reversed)
                        RotationSensor{20}  //middle encoder
                         )
            // speci fy the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
            // specif y the middle encoder distance (1 in) and diameter (2.75 in)
          .withOdometry({{2.725_in, 3.50_in, 5.5_in, 2.725_in}, quadEncoderTPR},StateMode::CARTESIAN)
          .buildOdometry();
pros::delay(100); 
bob->setMaxVelocity(300);
bob->moveDistance(38_in);
// bob->waitUntilSettled();
bob->turnAngle(75_deg);
intake.move_velocity(1000);
pros::delay(400);
lefty.move_velocity(-350);
righty.move_velocity(-350);
intake.move_velocity(-10000);
pros::delay(1000);
lefty.move_velocity(300);
righty.move_velocity(-50);
pros::delay(900);
lefty.move_velocity(0);
righty.move_velocity(0);
pros::delay(400);
lefty.move_velocity(-300);
righty.move_velocity(120);
pros::delay(650);
lefty.move_velocity(0);
righty.move_velocity(0);
lefty.move_velocity(-300);
righty.move_velocity(-300);
pros::delay(600);
lefty.move_velocity(0);
righty.move_velocity(0);
bob->moveDistance(18_in);
intake.move_velocity(1000);
pros::delay(300);
bob->moveDistance(-15_in);
flaps.set_value(true);  
bob->turnAngle(141_deg);
bob->setMaxVelocity(10000);
bob->moveDistance(-30_in);
bob->moveDistance(5_in);
}

void close(){
  
  std::shared_ptr<OdomChassisController> tom =
        ChassisControllerBuilder()
            .withMotors({9, 10,      8}, //left motors
                        {4, 13, 19}
                        )  //right motors
            // Green gearset, external ratio of (36.0 / 60.0), 4 inch wheel diameter, 11.5 inch wheel track 3.51
            .withDimensions({AbstractMotor::gearset::blue, (36.0 / 60.0)}, {{3.25_in, 12_in}, imev5GreenTPR})
            .withSensors(
                        RotationSensor{9}, // Left encoder in V5 port 1
                        RotationSensor{10}, // Right encoder in V5 port 2 (reversed)
                        RotationSensor{20}  //middle encoder
                         )
            // speci fy the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
            // specif y the middle encoder distance (1 in) and diameter (2.75 in)
          .withOdometry({{2.725_in, 3.50_in, 5.5_in, 2.725_in}, quadEncoderTPR},StateMode::CARTESIAN)
          .buildOdometry();
pros::delay(100); 
arm.set_value(false);
pros::delay(700);
righty.move_velocity(200);
lefty.move_velocity(-30);
pros::delay(400);
righty.move_velocity(0);
lefty.move_velocity(0);
arm.set_value(true);
tom->setMaxVelocity(200);
tom->turnAngle(5_deg);

tom->moveDistance(36_in);
intake.move_velocity(10000);
}

void skills(){
  std::shared_ptr<OdomChassisController> jeff =
      ChassisControllerBuilder()
            .withMotors({9, 10,      8}, //left motors
                        {4, 13, 19}
                        )  //right motors
            // Green gearset, external ratio of (36.0 / 60.0), 4 inch wheel diameter, 11.5 inch wheel track 3.51
            .withDimensions({AbstractMotor::gearset::blue, (36.0 / 60.0)}, {{3.25_in, 12_in}, imev5GreenTPR})
            .withSensors(
                        RotationSensor{9}, // Left encoder in V5 port 1
                        RotationSensor{10}, // Right encoder in V5 port 2 (reversed)
                        RotationSensor{20}  //middle encoder
                         )
            // speci fy the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
            // specif y the middle encoder distance (1 in) and diameter (2.75 in)
          .withOdometry({{2.725_in, 3.50_in, 5.5_in, 2.725_in}, quadEncoderTPR},StateMode::CARTESIAN)
          .buildOdometry();
pros::delay(100); 

lefty.move_velocity(5);
righty.move_velocity(5);
pros::delay(300);
righty.move_velocity(0);
catapult.move_velocity(-120);
pros::delay(3000);
}
  


 



///
// Swing Example
///
// void swing_example() {
//   // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
//   // The second parameter is target degrees
//   // The third parameter is speed of the moving side of the drive


//   chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
//   chassis.wait_drive();

//   chassis.set_drive_pid(24, DRIVE_SPEED, true);
//   chassis.wait_until(12);

//   chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
//   chassis.wait_drive();
// }



///
// Auto that tests everything
///
// void combining_movements() {
//   chassis.set_drive_pid(24, DRIVE_SPEED, true);
//   chassis.wait_drive();

//   chassis.set_turn_pid(45, TURN_SPEED);
//   chassis.wait_drive();

//   chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
//   chassis.wait_drive();

//   chassis.set_turn_pid(0, TURN_SPEED);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-24, DRIVE_SPEED, true);
//   chassis.wait_drive();
// }



///
// Interference example
///
// void tug (int attempts) {
//   for (int i=0; i<attempts-1; i++) {
//     // Attempt to drive backwards
//     printf("i - %i", i);
//     chassis.set_drive_pid(-12, 127);
//     chassis.wait_drive();

//     // If failsafed...
//     if (chassis.interfered) {
//       chassis.reset_drive_sensor();
//       chassis.set_drive_pid(-2, 20);
//       pros::delay(1000);
//     }
//     // If robot successfully drove back, return
//     else {
//       return;
//     }
//   }
// }

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
// void interfered_example() {
//  chassis.set_drive_pid(24, DRIVE_SPEED, true);
//  chassis.wait_drive();

//  if (chassis.interfered) {
//    tug(3);
//    return;
//  }

//  chassis.set_turn_pid(90, TURN_SPEED);
//  chassis.wait_drive();
// }



// . . .
// Make your own autonomous functions here!
// . . .