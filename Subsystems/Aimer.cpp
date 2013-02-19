#include "Aimer.h"
#include "../Robotmap.h"
#include "../Commands/Aiming.h"

Aimer::Aimer() : PIDSubsystem("Aimer", Kp, Ki, Kd) 
{
	motor = RobotMap::aimingMotor;
	pot = RobotMap::aimPot;
	topLimit = RobotMap::topLimit;
	bottomLimit = RobotMap::bottomLimit;
	
	//SetSetpoint(P0T_TOP);
	// limit output ...PID_STEP
	//Enable();
}

double Aimer::ReturnPIDInput() 
{
	return pot->GetVoltage();
}

void Aimer::UsePIDOutput(double output) 
{
	motor->Set(output);
}

void Aimer::InitDefaultCommand() 
{
	SetDefaultCommand(new Aiming());
}

void Aimer::aimPID(float aimDirection)
{
	if(aimDirection > OPERATOR_DEADBAND)
	{
		SetSetpointRelative(-PID_STEP);
	}
	else if(aimDirection < OPERATOR_DEADBAND)
	{
		SetSetpointRelative(PID_STEP);
	}
	else
	{
		SetSetpointRelative(0.0);
	}
}

void Aimer::aimUpPID()
{
	SetSetpointRelative(PID_STEP);
}

void Aimer::aimDownPID()
{
	SetSetpointRelative(-PID_STEP);
}

void Aimer::aim(float joystickInput)
{
	SmartDashboard::PutNumber("Pot", pot->GetVoltage());
	joystickInput *= -1;

	if(fabs(joystickInput) > OPERATOR_DEADBAND && !(atBottom() || atTop()))
	{
		motor->Set(joystickInput * AIM_SPEED);
	}
	else if(atBottom())
	{
		printf("bottom switch pressed\n");
		if(joystickInput > 0.0)
			joystickInput = 0.0;
		motor->Set(joystickInput * AIM_SPEED);
	}
	else if(atTop())
	{
		printf("top switch pressed\n");
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
	motor->Set(AIM_SPEED);
}

void Aimer::aimDown()
{
	motor->Set(-AIM_SPEED);
}

bool Aimer::atBottom()
{
	return (bottomLimit->Get() == LIMIT_SWITCH_ON);
}

bool Aimer::atTop()
{
	return (topLimit->Get() == LIMIT_SWITCH_ON);
}

void Aimer::moveFromLimit()
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

void Aimer::autonomousAim(float setpoint)
{
	float potVal = 0.0;
	
	while(potVal <= setpoint)
	{
		potVal = pot->GetVoltage();
		printf("potVal: %f\n", potVal);
		motor->Set(AUTON_SPEED);
	}
	
	motor->Set(0);
}
