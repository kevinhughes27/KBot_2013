#include "AimUp.h"

AimUp::AimUp() {
	Requires(CommandBase::aimer);
}

// Called just before this Command runs the first time
void AimUp::Initialize()
{
	CommandBase::aimer->aim(0.0);
}

// Called repeatedly when this Command is scheduled to run
void AimUp::Execute()
{
	if(!CommandBase::aimer->atTop())
	{
		CommandBase::aimer->aim(1);
	}
	else
	{
		CommandBase::aimer->aim(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AimUp::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AimUp::End()
{
	CommandBase::aimer->aim(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimUp::Interrupted()
{
	CommandBase::aimer->aim(0.0);
}
