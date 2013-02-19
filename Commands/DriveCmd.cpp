#include "DriveCmd.h"

DriveCmd::DriveCmd() 
{
	Requires(CommandBase::drive);
}

void DriveCmd::Initialize() 
{}

void DriveCmd::Execute() 
{
	float leftStick = CommandBase::oi->m_driver->getjoyLeftY();
	float rightStick = CommandBase::oi->m_driver->getjoyRightY();
		
	CommandBase::drive->wesleyDrive(leftStick, rightStick);
}

bool DriveCmd::IsFinished() 
{
	return false;
}

void DriveCmd::End() 
{
	CommandBase::drive->stop();
}

void DriveCmd::Interrupted() {
	End();
}
