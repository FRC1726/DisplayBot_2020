/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"


#include "RobotMap.h"

OI::OI() : 
  driveJoyStick(JOY_DRIVE)
{
  // Process operator interface input here.
}


double OI::getAxis (int axis){
  return driveJoyStick.GetRawAxis (axis);
}