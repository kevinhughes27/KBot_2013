#include "Aimer.h"
#include "../Robotmap.h"
#include "../Commands/AimJoystick.h"

Aimer::Aimer() : Subsystem("Aimer") 
{
	motor = RobotMap::aimingMotor;
	pot = RobotMap::aimPot;
	topLimit = RobotMap::topLimit;
	bottomLimit = RobotMap::bottomLimit;
}

void Aimer::InitDefaultCommand() 
{
	SetDefaultCommand(new AimJoystick());
}

void Aimer::aim(float joystickInput)
{
	SmartDashboard::PutNumber("Pot", pot->GetVoltage());
	joystickInput *= -1;

	if(fabs(joystickInput) > OPERATOR_DEADBAND && !(atBottom() || atTop()))
	{
		// if going up
		if(joystickInput < 0)
		{
			motor->Set(joystickInput * (AIM_SPEED+0.1));
		}
		else // going down
		{
			motor->Set(joystickInput * AIM_SPEED);
		}
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
	else
	{
		motor->Set(0.0);
	}
}

void Aimer::aimUp()
{
	motor->Set(-AIM_SPEED-0.1);
}

void Aimer::aimDown()
{
	motor->Set(AIM_SPEED-0.1);
}

float Aimer::getPot() 
{
	return pot->GetVoltage();
}

bool Aimer::atBottom()
{
	return (bottomLimit->Get() == LIMIT_SWITCH_ON);
}

bool Aimer::atTop()
{
	return (topLimit->Get() == LIMIT_SWITCH_ON);
}
