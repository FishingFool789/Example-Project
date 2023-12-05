#include "main.h"
#include "globals.hpp"
pros::Controller master(pros::E_CONTROLLER_MASTER);

// pros::Motor L1(9);
// pros::Motor L2(-10);
// pros::Motor L3(-8);
// pros::Motor R1(-4);
// pros::Motor R2(13);
// pros::Motor R3(19);
// pros::Motor intake(20);
// pros::Motor catapult(11);
// pros::MotorGroup lefty({L1, L2, L3});
// pros::MotorGroup righty({R1, R2, R3});
// pros::ADIDigitalOut flaps('G');
// pros::ADIButton limit('F');
// pros::ADIDigitalOut arm('H');
/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {9, -10, -8}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{-4, 13, 19}

  // IMU Port
  ,21

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,3.25

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,.6

  // Uncomment if using tracking wheels
  /*
  // Left Tracking Wheel Ports (negative port will reverse it!)
  // ,{1, 2} // 3 wire encoder
  // ,8 // Rotation sensor

  // Right Tracking Wheel Ports (negative port will reverse it!)
  // ,{-3, -4} // 3 wire encoder
  // ,-9 // Rotation sensor
  */

  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  // ,1
);



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

// void far(){
// std::shared_ptr<OdomChassisController> bob =
//       ChassisControllerBuilder()
//             .withMotors({9, 10, 8}, //left motors
//                         {4, 13, 19}
//                         )  //right motors
//             // Green gearset, external ratio of (36.0 / 60.0), 4 inch wheel diameter, 11.5 inch wheel track 3.51
//             .withDimensions({AbstractMotor::gearset::blue, (36.0 / 60.0)}, {{3.25_in, 12_in}, imev5GreenTPR})
//             .withSensors(
//                         RotationSensor{9}, // Left encoder in V5 port 1
//                         RotationSensor{10}, // Right encoder in V5 port 2 (reversed)
//                         RotationSensor{20}  //middle encoder
//                          )
//             // speci fy the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
//             // specif y the middle encoder distance (1 in) and diameter (2.75 in)
//           .withOdometry({{2.725_in, 3.50_in, 5.5_in, 2.725_in}, quadEncoderTPR},StateMode::CARTESIAN)
//           .buildOdometry();
// pros::delay(100); 
// bob->setMaxVelocity(300);
// bob->moveDistance(38_in);
// // bob->waitUntilSettled();
// bob->turnAngle(75_deg);
// intake.move_velocity(1000);
// pros::delay(400);
// lefty.move_velocity(-350);
// righty.move_velocity(-350);
// intake.move_velocity(-10000);
// pros::delay(1000);
// lefty.move_velocity(300);
// righty.move_velocity(-50);
// pros::delay(900);
// lefty.move_velocity(0);
// righty.move_velocity(0);
// pros::delay(400);
// lefty.move_velocity(-300);
// righty.move_velocity(120);
// pros::delay(650);
// lefty.move_velocity(0);
// righty.move_velocity(0);
// lefty.move_velocity(-300);
// righty.move_velocity(-300);
// pros::delay(600);
// lefty.move_velocity(0);
// righty.move_velocity(0);
// bob->moveDistance(18_in);
// intake.move_velocity(1000);
// pros::delay(300);
// bob->moveDistance(-15_in);
// flaps.se t_value(true);  
// bob->turnAngle(141_deg);
// bob->setMaxVelocity(10000);
// bob->moveDistance(-30_in);
// bob->moveDistance(5_in);





// }


// void close(){
//   intake.move_velocity(-100);
// }


void initialize() {
  ez::as::auton_selector.add_autons({
    Auton("Autonomous 1\nDoes far", far), 
    Auton("Autonomous 2\nDoes close", close),
    Auton("Autonomous 3\nDoes skills", skills),

  });
    // ez::as::auton_selector.call_selected_auton(); 
  
// std::shared_ptr<OdomChassisController> bob =
//       ChassisControllerBuilder()
//             .withMotors({9, 10,      8}, //left motors
//                         {4, 13, 19}
//                         )  //right motors
//             // Green gearset, external ratio of (36.0 / 60.0), 4 inch wheel diameter, 11.5 inch wheel track 3.51
//             .withDimensions({AbstractMotor::gearset::blue, (36.0 / 60.0)}, {{3.25_in, 12_in}, imev5GreenTPR})
//             .withSensors(
//                         RotationSensor{9}, // Left encoder in V5 port 1
//                         RotationSensor{10}, // Right encoder in V5 port 2 (reversed)
//                         RotationSensor{20}  //middle encoder
//                          )
//             // speci fy the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
//             // specif y the middle encoder distance (1 in) and diameter (2.75 in)
//           .withOdometry({{2.725_in, 3.50_in, 5.5_in, 2.725_in}, quadEncoderTPR},StateMode::CARTESIAN)
//           .buildOdometry();
// pros::delay(100); 
// bob->setMaxVelocity(300);
// bob->moveDistance(38_in);
// // bob->waitUntilSettled();
// bob->turnAngle(75_deg);
// intake.move_velocity(1000);
// pros::delay(400);
// lefty.move_velocity(-350);
// righty.move_velocity(-350);
// intake.move_velocity(-10000);
// pros::delay(1000);
// lefty.move_velocity(300);
// righty.move_velocity(-50);
// pros::delay(900);
// lefty.move_velocity(0);
// righty.move_velocity(0);
// pros::delay(400);
// lefty.move_velocity(-300);
// righty.move_velocity(120);
// pros::delay(650);
// lefty.move_velocity(0);
// righty.move_velocity(0);
// lefty.move_velocity(-300);
// righty.move_velocity(-300);
// pros::delay(600);
// lefty.move_velocity(0);
// righty.move_velocity(0);
// bob->moveDistance(18_in);
// intake.move_velocity(1000);
// pros::delay(300);
// bob->moveDistance(-15_in);
// flaps.set_value(true);  
// bob->turnAngle(141_deg);
// bob->setMaxVelocity(10000);
// bob->moveDistance(-30_in);
// bob->moveDistance(5_in);



   

// tom->turnAngle(-15_deg);
// tom->moveDistance(7_in);


  // Print our branding over your terminal :D
  ez::print_ez_template();
  
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.

  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(4, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  default_constants(); // Set the drive to your own constants from autons.cpp!
  exit_condition_defaults(); // Set the exit conditions to your own constants from autons.cpp!

  
  chassis.initialize();
  ez::as::initialize();
}
 







// // }

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
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
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
//  */
void autonomous() {
  
  // std::shared_ptr<OdomChassisController> jeff =
  //     ChassisControllerBuilder()
  //           .withMotors({9, 10,      8}, //left motors
  //                       {4, 13, 19}
  //                       )  //right motors
  //           // Green gearset, external ratio of (36.0 / 60.0), 4 inch wheel diameter, 11.5 inch wheel track 3.51
  //           .withDimensions({AbstractMotor::gearset::blue, (36.0 / 60.0)}, {{3.25_in, 12_in}, imev5GreenTPR})
  //           .withSensors(
  //                       RotationSensor{9}, // Left encoder in V5 port 1
  //                       RotationSensor{10}, // Right encoder in V5 port 2 (reversed)
  //                       RotationSensor{20}  //middle encoder
  //                        )
  //           // speci fy the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
  //           // specif y the middle encoder distance (1 in) and diameter (2.75 in)
  //         .withOdometry({{2.725_in, 3.50_in, 5.5_in, 2.725_in}, quadEncoderTPR},StateMode::CARTESIAN)
          // .buildOdometry();
// pros::delay(100); 

// lefty.move_velocity(5);
// righty.move_velocity(5);
// pros::delay(300);
// righty.move_velocity(0);
// catapult.move_velocity(-120);
// pros::delay(3000);

//   std::shared_ptr<OdomChassisController> bob =
//       ChassisControllerBuilder()
//             .withMotors({9, 10,      8}, //left motors
//                         {4, 13, 19}
//                         )  //right motors
//             // Green gearset, external ratio of (36.0 / 60.0), 4 inch wheel diameter, 11.5 inch wheel track 3.51
//             .withDimensions({AbstractMotor::gearset::blue, (36.0 / 60.0)}, {{3.25_in, 12_in}, imev5GreenTPR})
//             .withSensors(
//                         RotationSensor{9}, // Left encoder in V5 port 1
//                         RotationSensor{10}, // Right encoder in V5 port 2 (reversed)
//                         RotationSensor{20}  //middle encoder
//                          )
//             // speci fy the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
//             // specif y the middle encoder distance (1 in) and diameter (2.75 in)
//           .withOdometry({{2.725_in, 3.50_in, 5.5_in, 2.725_in}, quadEncoderTPR},StateMode::CARTESIAN)
//           .buildOdometry();
// pros::delay(100); 
// bob->setMaxVelocity(300);
// bob->moveDistance(38_in);
// // bob->waitUntilSettled();
// bob->turnAngle(75_deg);
// intake.move_velocity(1000);
// pros::delay(400);
// lefty.move_velocity(-350);
// righty.move_velocity(-350);
// intake.move_velocity(-10000);
// pros::delay(1000);
// lefty.move_velocity(300);
// righty.move_velocity(-50);
// pros::delay(900);
// lefty.move_velocity(0);
// righty.move_velocity(0);
// pros::delay(400);
// lefty.move_velocity(-300);
// righty.move_velocity(120);
// pros::delay(650);
// lefty.move_velocity(0);
// righty.move_velocity(0);
// lefty.move_velocity(-300);
// righty.move_velocity(-300);
// pros::delay(600);
// lefty.move_velocity(0);
// righty.move_velocity(0);
// bob->moveDistance(18_in);
// intake.move_velocity(1000);
// pros::delay(300);
// bob->moveDistance(-15_in);
// flaps.set_value(true);  
// bob->turnAngle(141_deg);
// bob->setMaxVelocity(10000);
// bob->moveDistance(-30_in);
// bob->moveDistance(5_in);


 



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

tom->moveDistance(39_in);
intake.move_velocity(10000);
pros::delay(1000);

  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.

  // ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
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
  bool flaps_out;
	flaps_out = false;
  	int cata;
	cata=1;
  // This is preference to what you like to drive on.
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);

  while (true) {
    if(master.get_digital(DIGITAL_L2)){
		intake.move_velocity(1000);
	}
	else if(master.get_digital(DIGITAL_L1)){
		intake.move_velocity(-1000);
	}
	else{
		intake.move_velocity(0);
	}

  flaps.set_value(flaps_out);

		if (master.get_digital(DIGITAL_R1) & flaps_out == true)
		{
			flaps_out = false;
			pros::delay(150);
		}
		if (master.get_digital(DIGITAL_R1) & flaps_out == false)
		{
			flaps_out = true;
			pros::delay(150);

		}

    if((cata==1) & (limit.get_value()== 0)){
		catapult.set_brake_mode(MOTOR_BRAKE_COAST);
		catapult.move_velocity(-90);
	}

	else{
		catapult.set_brake_mode(MOTOR_BRAKE_BRAKE);
		catapult.move_velocity(0);
	}

		// shoot cata normally
	if(master.get_digital(DIGITAL_R2)){
		catapult.set_brake_mode(MOTOR_BRAKE_BRAKE);
		catapult.move_velocity(-1000);
		pros::delay(150);
		catapult.move_velocity(0);
		cata=1;
	}

if(master.get_digital(DIGITAL_X)){
			arm.set_value(true);
		}

		else if(master.get_digital(DIGITAL_B)){
			arm.set_value(false);
		}

	

    chassis.tank(); // Tank control
    // chassis.arcade_standard(ez::SPLIT); // Standard split arcade
    // chassis.arcade_standard(ez::SINGLE); // Standard single arcade
    // chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
    // chassis.arcade_flipped(ez::SINGLE); // Flipped single arcade

    // . . .
    // Put more user control code here!
    // . . .

    pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
