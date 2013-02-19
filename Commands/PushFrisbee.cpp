#include "PushFrisbee.h"

PushFrisbee::PushFrisbee() 
{
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void PushFrisbee::Initialize() 
{
	CommandBase::shooter->pushFrisbee(true);
}

// Called repeatedly when this Command is scheduled to run
void PushFrisbee::Execute() 
{
	// pass
}

// Make this return true when this Command no longer needs to run execute()
bool PushFrisbee::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PushFrisbee::End() 
{
	CommandBase::shooter->pushFrisbee(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PushFrisbee::Interrupted() 
{
	CommandBase::shooter->pushFrisbee(false);
}
