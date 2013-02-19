#include "Drive.h"
#include "../Robotmap.h"
#include "math.h"
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
	float passX;
	float passY;
	if(CommandBase::oi->m_driver->getTrigger() == 1)
	{
		speedSet = true;
	}
	else
	{
		speedSet = false;
	}
	//speedSet = CommandBase::oi->m_driver->getTrigger();
	
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
		passX = 0.5 * leftStick;
		passY = 0.5 * rightStick;
	}
	else if(!speedSet)
	{
		passX = leftStick;
		passY = rightStick;
	}
	robotDrive->TankDrive(-passX, -passY, true);
}

void Drive::halfSpeed(bool speed)
{
	speedSet = speed;
}
