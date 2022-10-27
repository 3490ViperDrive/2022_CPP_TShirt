// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
  //Imports and Includes
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/DriveSubsystem.h>

  /**
   * An Drive command that uses an Drive subsystem.
   *
   * <p>Note that this extends CommandHelper, rather extending CommandBase
   * directly; this is crucially important, or else the decorator functions in
   * Command will *not* work!
  */
  //Names the command
class DriveCommand
    : public frc2::CommandHelper<frc2::CommandBase, DriveCommand> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  //Names the subsystem
  explicit DriveCommand(DriveSubsystem* subsystem);

 private:
  DriveSubsystem* m_subsystem;
};
