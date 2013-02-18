#include "DriveCmd.h"

DriveCmd::DriveCmd() 
{
	Requires(CommandBase::drive);
}

void DriveCmd::Initialize() 
{}

void DriveCmd::Execute() 
{
	float leftStick = CommandBase::oi->m_logitech->getjoyLeftY();
	float rightStick = CommandBase::oi->m_logitech->getjoyRightY();
	
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
