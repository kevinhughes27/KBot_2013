#include "AimDown.h"

AimDown::AimDown() 
{
	Requires(CommandBase::aimer);
}

AimDown::AimDown(float time) 
{
	Requires(CommandBase::aimer);
	SetTimeout(time);
}

// Called just before this Command runs the first time
void AimDown::Initialize() 
{
	CommandBase::aimer->aim(0.0);
}

// Called repeatedly when this Command is scheduled to run
void AimDown::Execute() 
{
	if(!CommandBase::aimer->atBottom())
	{
		CommandBase::aimer->aim(-1);
	}
	else
	{
		CommandBase::aimer->aim(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AimDown::IsFinished() 
{
	return false || IsTimedOut();
}

// Called once after isFinished returns true
void AimDown::End() 
{
	CommandBase::aimer->aim(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimDown::Interrupted() 
{
	CommandBase::aimer->aim(0.0);
}
