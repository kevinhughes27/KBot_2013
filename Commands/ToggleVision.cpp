#include "ToggleVision.h"

ToggleVision::ToggleVision()
{
	Requires(CommandBase::vision);
}

// Called just before this Command runs the first time
void ToggleVision::Initialize()
{
	vision->onOff();
}

// Called repeatedly when this Command is scheduled to run
void ToggleVision::Execute()
{
	//pass
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleVision::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleVision::End()
{
	//pass
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleVision::Interrupted()
{
	//pass
}
