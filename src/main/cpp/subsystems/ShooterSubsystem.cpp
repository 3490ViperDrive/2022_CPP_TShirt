// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//Imports and Includes
#include "subsystems/ShooterSubsystem.h"
#include "Constants.h"
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include "ctre/phoenix/motorcontrol/can/TalonSRX.h"
#include "ctre/Phoenix.h"
#include "WPILibVersion.h"
//#include "cameraserver/CameraServer.h"

//Calls namespace constants
using namespace shooterConstants;
using namespace controllerConstants;

ShooterSubsystem::ShooterSubsystem() {
  // Implementation of subsystem constructor goes here.
  /*Enables current limits on the talons connected to 
  the solenoids. Also configures*/

  //Enable Current Limit Shooter
  m_ShootersolenoidTalonR.EnableCurrentLimit(true);
  m_ShootersolenoidTalonL.EnableCurrentLimit(true);
  //Enable Current Limit Primer
  m_PrimingsolenoidTalonL.EnableCurrentLimit(true);
  m_PrimingsolenoidTalonR.EnableCurrentLimit(true);

  //Continuous Current Limit Shooter
  m_ShootersolenoidTalonR.ConfigContinuousCurrentLimit(2,0);
  m_ShootersolenoidTalonL.ConfigContinuousCurrentLimit(2,0);
  //Continuous Current Limit Primer
  m_PrimingsolenoidTalonL.ConfigContinuousCurrentLimit(2,0);
  m_PrimingsolenoidTalonR.ConfigContinuousCurrentLimit(2,0);

  //Peak Current Limit Shooter
  m_ShootersolenoidTalonR.ConfigPeakCurrentLimit(2.5,0);
  m_ShootersolenoidTalonL.ConfigPeakCurrentLimit(2.5,0);
  //Peak Current Limit Primer
  m_PrimingsolenoidTalonL.ConfigPeakCurrentLimit(3,0);
  m_PrimingsolenoidTalonR.ConfigPeakCurrentLimit(3,0);

  //sets the max output and deadband of the shooter solenoids TEMPORARY
  m_shooter.SetDeadband(shooterDeadBand);
  m_shooter.SetMaxOutput(shooterMaxOutput);

  m_shooter.SetSafetyEnabled(false);


   
}

//REMEMBER TO PRIME TANKS BEFORE FIRING!!!

void ShooterSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.

  
  //Press and hold Xbutton to continuously prime. if start button is released solenoids close.
  if(m_controllerMain.GetStartButton()){
    m_PrimingsolenoidTalonR.Set(primingMaxOutput);
  }else{
    m_PrimingsolenoidTalonR.Set(0);
  }
  if(m_controllerMain.GetBackButton()){
    m_PrimingsolenoidTalonL.Set(primingMaxOutput);
  }else{
     m_PrimingsolenoidTalonL.Set(0);
  }

  //Shooter Actuator. Use bumpers to go up and down.
  if(m_controllerMain.GetRightBumper() 
    && !m_controllerMain.GetLeftBumper()){
    m_shooterActuator.Set(ActuatorMaxOutput);
  }else if(m_controllerMain.GetLeftBumper() 
    && !m_controllerMain.GetRightBumper()){
    m_shooterActuator.Set(-ActuatorMaxOutput);
  }else{
    m_shooterActuator.Set(0);
  }

  /*Using Tank drive to control each solenoid independently
  By using Tank Drive left trigger can control left solenoid 
  right trigger can control right solenoid firing. 
  */
  if(m_controllerMain.GetAButton()){
    m_shooter.TankDrive(m_controllerMain.GetRightTriggerAxis(),
                      m_controllerMain.GetLeftTriggerAxis());
  }

 

}
void ShooterSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
