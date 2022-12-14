// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
  //Imports and Includes
#include <frc2/command/Command.h>
#include "commands/DriveCommand.h"
#include "commands/ShooterCommand.h"

#include "subsystems/DriveSubsystem.h"
#include "subsystems/ShooterSubsystem.h"
#include <Constants.h>
#include <frc/XboxController.h>

  /**
  * This class is where the bulk of the robot should be declared.  Since
  * Command-based is a "declarative" paradigm, very little robot logic should
  * actually be handled in the {@link Robot} periodic methods (other than the
  * scheduler calls).  Instead, the structure of the robot (including subsystems,
  * commands, and button mappings) should be declared here.
  */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...

  //Drive
  DriveSubsystem m_drive;
  DriveCommand m_driveCommand;
  //Shooter
  ShooterSubsystem m_shooterSubsystem;
  ShooterCommand m_shooterCommand;

  void ConfigureButtonBindings();
};