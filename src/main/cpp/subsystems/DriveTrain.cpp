/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

#include "RobotMap.h"
#include "commands/Drivejoy.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
  frontLeftMotor(PWM_FRONT_LEFT_MOTOR),
  backLeftMotor(PWM_BACK_LEFT_MOTOR),
  frontRightMotor(PWM_FRONT_RIGHT_MOTOR),
  backRightMotor(PWM_BACK_RIGHT_MOTOR),
  leftGroup(frontLeftMotor, backLeftMotor),
  rightGroup(frontRightMotor, backRightMotor),
  robotDrive(leftGroup, rightGroup)
{}

void DriveTrain::InitDefaultCommand() {
  SetDefaultCommand(new DriveJoy());
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::arcadeDrive(double speed, double turn){
  robotDrive.ArcadeDrive(speed, turn, false);
}