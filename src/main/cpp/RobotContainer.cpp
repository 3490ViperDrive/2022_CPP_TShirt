// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

  //Imports and Includes
#include "RobotContainer.h"

  //Calls in both subsystems and commands
RobotContainer::RobotContainer() : m_shooterCommand(&m_shooterSubsystem), m_driveCommand(&m_drive) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  //Returns the function within the subsystem.
  return &m_driveCommand;
  return &m_shooterCommand;
}
