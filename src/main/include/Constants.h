// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

    // Maps The Xbox Controller
namespace controllerConstants {

    //USB Port Map on DriveStation PC.
    constexpr int controllerMain = 0;
    constexpr int controllerAux = 1;
}

namespace driveConstants {
    //CAN IDs For Drive Motors
    constexpr int motorFrontRight = 4;
    constexpr int motorRearRight = 2;
    constexpr int motorFrontLeft = 3;
    constexpr int motorRearLeft = 9;
    
    //MaxOuput and DeadBand for Drive.
    constexpr double motorMaxOutput = 0.4;
    constexpr double motorDeadband = 0.1;
}

namespace shooterConstants{
    //CAN IDs for Shooter.
    constexpr int ShootersolenoidTalonR = 5;
    constexpr int ShootersolenoidTalonL = 6;
    constexpr int PrimingsolenoidTalonR = 7;
    constexpr int PrimingsolenoidTalonL = 8;
    constexpr int shooterActuator = 10;

    //Max liftspeed, deadband, and maxoutput.
    constexpr int shooterDeadBand = 0.4;
    constexpr int shooterMaxOutput = 1;
    constexpr int primingMaxOutput = 1;
    constexpr double ActuatorMaxOutput = 1;
}
