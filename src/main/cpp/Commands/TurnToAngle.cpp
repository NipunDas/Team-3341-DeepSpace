/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/TurnToAngle.h"

TurnToAngle::TurnToAngle(double targetAngle) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get())
  targetAngleInput = targetAngle;
}

// Called just before this Command runs the first time
void TurnToAngle::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TurnToAngle::Execute() {
  myAngle = Robot::ahrs->GetYaw();
  if (targetAngleInput > myAngle) {
      Robot::m_drive->tankDrive(0.2, -0.2);
  } else if (targetAngleInput < myAngle) {
      Robot::m_drive->tankDrive(-0.2, 0.2);
  } else {
      Robot::m_drive->tankDrive(0, 0);
  }
}

bool TurnToAngle::IsFinished() { 
// Make this return true when this Command no longer needs to run execute(é)

  while (targetAngleInput-myAngle > 2 || targetAngleInput-myAngle < -2) {                                  
    return false; 
  }
  return true;
}

// Called once after isFinished returns true
void TurnToAngle::End() {Robot::m_drive->tankDrive(0, 0);}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnToAngle::Interrupted() {}
