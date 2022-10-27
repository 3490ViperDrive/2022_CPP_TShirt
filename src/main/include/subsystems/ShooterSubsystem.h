// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
  //Imports / Includes
#include "Constants.h"
#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include "ctre/phoenix/motorcontrol/can/TalonSRX.h"
#include "ctre/Phoenix.h"
#include "WPILibVersion.h"
//#include "cameraserver/CameraServer.h"

  //Calls Namespace
using namespace controllerConstants;
using namespace shooterConstants;

class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:
  //Xbox Controller Main Declared.
  //TalonSRXs Declared.
  WPI_TalonSRX m_shooterActuator{shooterActuator};
  //Differential Drive Declared for shooter
  frc::XboxController m_controllerMain{controllerMain};
  //ShooterTalons
  WPI_TalonSRX m_ShootersolenoidTalonR{ShootersolenoidTalonR};
  WPI_TalonSRX m_ShootersolenoidTalonL{ShootersolenoidTalonL};
  //PrimingTalons
  WPI_TalonSRX m_PrimingsolenoidTalonR{PrimingsolenoidTalonR};
  WPI_TalonSRX m_PrimingsolenoidTalonL{PrimingsolenoidTalonL};
  //Used For shooting
  frc::DifferentialDrive m_shooter{m_ShootersolenoidTalonR, m_ShootersolenoidTalonL};


};