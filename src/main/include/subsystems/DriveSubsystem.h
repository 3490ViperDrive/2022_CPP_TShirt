// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
  //Imports or Includes
#include "Constants.h"
#include <frc2/command/SubsystemBase.h>
#include <frc/drive/MecanumDrive.h>
#include "rev/CANSparkMax.h"
#include "ctre/phoenix/motorcontrol/can/TalonFX.h"
#include <frc/XboxController.h>
  
  //Calls Namespace
using namespace driveConstants;
using namespace controllerConstants;

class DriveSubsystem : public frc2::SubsystemBase {
 public:

  DriveSubsystem();
  
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

  //Xbox Controller Declared.
  frc::XboxController m_controllerMain{controllerMain};

  //CANSparkMax Declared and Set Motor Type (Brushless).
  rev::CANSparkMax m_motorFrontLeft{motorFrontLeft, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_motorFrontRight{motorFrontRight, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_motorRearLeft{motorRearLeft, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_motorRearRight{motorRearRight, rev::CANSparkMax::MotorType::kBrushless};
  

  //MecanumDrive
  frc::MecanumDrive m_mecanumDrive{m_motorFrontLeft, m_motorRearLeft, m_motorFrontRight, m_motorRearRight};

  
};
