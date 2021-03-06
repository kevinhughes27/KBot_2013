#include "ChickenRelease.h"

ChickenRelease::ChickenRelease()
{
	Requires(CommandBase::pistons);
}

// Called just before this Command runs the first time
void ChickenRelease::Initialize()
{
	CommandBase::pistons->toggleChicken();
}

// Called repeatedly when this Command is scheduled to run
void ChickenRelease::Execute()
{
	// pass
}

// Make this return true when this Command no longer needs to run execute()
bool ChickenRelease::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ChickenRelease::End()
{
	// pass
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChickenRelease::Interrupted()
{
	// pass
}
