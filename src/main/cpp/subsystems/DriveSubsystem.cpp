// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//Imports and Includes
#include "subsystems/DriveSubsystem.h"
#include "Constants.h"
#include <frc/XboxController.h>

//Calls Namespace constants
using namespace driveConstants;
using namespace controllerConstants;

DriveSubsystem::DriveSubsystem() {
  // Implementation of subsystem constructor goes here.
  //Sets differentialDrive deadband and maxoutput.
  m_mecanumDrive.SetDeadband(motorDeadband);
  m_mecanumDrive.SetMaxOutput(motorMaxOutput);

  m_motorFrontRight.SetInverted(true);
  m_motorRearRight.SetInverted(true);


  //mecanum drive is newly implemented. 

   
}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
m_mecanumDrive.DriveCartesian(m_controllerMain.GetLeftY(),
                                (-m_controllerMain.GetLeftX()*(2)),
                                -m_controllerMain.GetRightX());
}

void DriveSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
