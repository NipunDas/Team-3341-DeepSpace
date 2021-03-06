/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "Commands/Piston_Extend.h"
#include "Commands/Piston_Off.h"
#include "Commands/Piston_Retract.h"
#include "Commands/Servo_Extend.h"
#include "Commands/Servo_Retract.h"
#include "Commands/Hatch_Extend.h"
#include "Commands/Hatch_Retract.h"
#include "Commands/Compressor_On.h"
#include "Commands/Compressor_Off.h"

#include <frc/WPILib.h>

OI::OI() : leftJoy(new Joystick(0)), rightJoy(new Joystick(1)),
pistonExtendButton(new JoystickButton(rightJoy, 5)), 
servoExtendButton(new JoystickButton(rightJoy, 3)),
hatchRetractButton(new JoystickButton(rightJoy, 1)), 
pistonOffButton(new JoystickButton(rightJoy, 8)),
compressorOnButton(new JoystickButton(rightJoy, 10)), 
compressorOffButton(new JoystickButton(rightJoy, 9))
{
  // Process operator interface input here.
  //hatchExtendButton->WhenPressed(new Hatch_Extend());
  pistonExtendButton->WhenPressed(new Piston_Extend());
  servoExtendButton->WhenPressed(new Servo_Extend());
	hatchRetractButton->WhenPressed(new Hatch_Retract());
  pistonOffButton->WhenPressed(new Piston_Off());
  compressorOnButton->WhenPressed(new Compressor_On());
  compressorOffButton->WhenPressed(new Compressor_Off());


}

Joystick* OI::getLeft(){
  return leftJoy;
}

Joystick* OI::getRight(){
  return rightJoy;
}
