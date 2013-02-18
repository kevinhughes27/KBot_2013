#include "AimPID.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/Aiming.h"


AimPID::AimPID() : PIDSubsystem("AimPID", Kp, Ki, Kd) {
	motor = RobotMap::aimingMotor;
	pot = RobotMap::aimPot;
	topLimit = RobotMap::topLimit;
	bottomLimit = RobotMap::bottomLimit;
	
	//SetSetpoint(0.0);
	//Enable();
}

double AimPID::ReturnPIDInput() {
	return pot->GetVoltage();
}

void AimPID::UsePIDOutput(double output) {
	motor->Set(output);
}

void AimPID::InitDefaultCommand() {
	SetDefaultCommand(new Aiming());
}

void AimPID::aimPID(float aimDirection)
{
	if(aimDirection > DEADBAND)
	{
		SetSetpointRelative(-STEP_DISTANCE);
	}
	else if(aimDirection < DEADBAND)
	{
		SetSetpointRelative(STEP_DISTANCE);
	}
	else
	{
		SetSetpointRelative(0.0);
	}
}

void AimPID::aimUpPID()
{
	SetSetpointRelative(STEP_DISTANCE);
}

void AimPID::aimDownPID()
{
	SetSetpointRelative(-STEP_DISTANCE);
}

void AimPID::aim(float joystickInput)
{
	joystickInput *= -1;
	printf("Pot: %f\n", pot->GetVoltage());
	
	if(fabs(joystickInput) > DEADBAND && !(atBottom() || atTop()))
	{
		motor->Set(joystickInput * AIM_SPEED);
	}
	else if(atBottom())
	{
		//printf("bottom switch pressed\n");
		if(joystickInput > 0.0)
			joystickInput = 0.0;
		motor->Set(joystickInput * AIM_SPEED);
	}
	else if(atTop())
	{
		//printf("top switch pressed\n");
		if(joystickInput < 0.0)
			joystickInput = 0.0;
		motor->Set(joystickInput * AIM_SPEED);
	}
}

void AimPID::aimUp()
{
	motor->Set(AIM_SPEED);
}

void AimPID::aimDown()
{
	motor->Set(-AIM_SPEED);
}

bool AimPID::atBottom()
{
	return (bottomLimit->Get() == LIMIT_SWITCH_ON);
}

bool AimPID::atTop()
{
	return (topLimit->Get() == LIMIT_SWITCH_ON);
}

void AimPID::moveFromLimit()
{
	if(atBottom())
	{
		aimUp();
	}
	else if(atTop())
	{
		aimDown();
	}
}
