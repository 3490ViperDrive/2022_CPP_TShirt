// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubsystem* subsystem)
    : m_subsystem{subsystem} {}
//Names the subsystem and states here.