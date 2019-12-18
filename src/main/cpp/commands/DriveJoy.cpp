/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveJoy.h"

#include <cmath>

#include "RobotMap.h"
#include "Robot.h"

DriveJoy::DriveJoy() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::driveTrain);
}

// Called just before this Command runs the first time
void DriveJoy::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveJoy::Execute() {
  double speed = applyDeadzone(Robot::oi.getAxis(AXIS_LEFT_Y), .05);
  double turn = applyDeadzone(Robot::oi.getAxis(AXIS_RIGHT_X), .05);
  Robot::driveTrain.arcadeDrive(driveProfile(speed, 0.25, .8), driveProfile(turn, 0.25, .8));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveJoy::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveJoy::End() {
  Robot::driveTrain.arcadeDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveJoy::Interrupted() {
  Robot::driveTrain.arcadeDrive(0, 0);
}

double DriveJoy::driveProfile(double input, double min, double max){
  if(input == 0){
    return 0;
  }

  double slope = max-min;
  double output = slope * std::pow(std::abs(input), 2) + min;
  
  if (input < 0){
    output *= -1;
  }

  return output;
}

double DriveJoy::applyDeadzone(double input, double deadzone){
  if(abs(input) < abs(deadzone)){
    return 0;
  }

  return input;
}