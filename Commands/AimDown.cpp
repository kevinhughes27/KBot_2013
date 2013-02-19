#include "AimDown.h"

AimDown::AimDown() 
{
	Requires(CommandBase::aimer);
}

// Called just before this Command runs the first time
void AimDown::Initialize() 
{
	CommandBase::aimer->aim(0.0);
}

// Called repeatedly when this Command is scheduled to run
void AimDown::Execute() 
{
	CommandBase::aimer->aim(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool AimDown::IsFinished() 
{
	return false;
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
