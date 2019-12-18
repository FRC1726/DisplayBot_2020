/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/VictorSP.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedControllerGroup.h>

class DriveTrain : public frc::Subsystem {
public:
  DriveTrain();
  void InitDefaultCommand() override;
  void arcadeDrive(double, double);
private:
  frc::VictorSP frontLeftMotor, backLeftMotor; 
  frc::VictorSP frontRightMotor, backRightMotor;
  frc::SpeedControllerGroup leftGroup, rightGroup;
  frc::DifferentialDrive robotDrive;
};
