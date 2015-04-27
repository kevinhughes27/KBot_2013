#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/DriveCmd.h"

Drive::Drive() : Subsystem("Drive")
{
	leftMotor = RobotMap::leftMotor;
	rightMotor = RobotMap::rightMotor;
	robotDrive = RobotMap::robotDrive;
	speedSet = false;
}

void Drive::InitDefaultCommand()
{
	SetDefaultCommand(new DriveCmd());
}

void Drive::stop()
{
	robotDrive->TankDrive(0.0,0.0);
}

void Drive::wesleyDrive(float leftStick, float rightStick)
{
	if(CommandBase::oi->m_driver->getTrigger() == 1)
	{
		speedSet = true;
	}
	else
	{
		speedSet = false;
	}

	//Deadband to stop drifting controller
	if(fabs(leftStick) < DRIVER_DEADBAND)
	{
		leftStick = 0;
	}

	else if(fabs(rightStick) < DRIVER_DEADBAND)
	{
		rightStick = 0;
	}

	if(speedSet)
	{
		leftStick = 0.5 * leftStick;
		rightStick = 0.5 * rightStick;
	}
	else if(!speedSet)
	{
		leftStick = leftStick;
		rightStick = rightStick;
	}

	robotDrive->TankDrive(-leftStick, -rightStick, true);
}

void Drive::halfSpeed(bool speed)
{
	speedSet = speed;
}

void Drive::regularDrive(float leftStick, float rightStick)
{
	if(fabs(leftStick) < DEADBAND)
	{
		leftStick = 0.0;
	}
	if(fabs(rightStick) < DEADBAND)
	{
		rightStick = 0.0;
	}
	//printf("Is working: values are %f and %f\n", leftStick, rightStick);
	robotDrive->TankDrive(-leftStick, -rightStick, true);
}
