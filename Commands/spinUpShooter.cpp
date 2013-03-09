#include "SpinUpShooter.h"

SpinUpShooter::SpinUpShooter() 
{
	//Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void SpinUpShooter::Initialize() 
{
	CommandBase::shooter->spinUpShooter(0.0);
}

// Called repeatedly when this Command is scheduled to run
void SpinUpShooter::Execute() 
{
	CommandBase::shooter->spinUpShooter(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool SpinUpShooter::IsFinished() {
	return false || IsTimedOut();
}

// Called once after isFinished returns true
void SpinUpShooter::End() 
{
	CommandBase::shooter->spinUpShooter(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinUpShooter::Interrupted() 
{
	CommandBase::shooter->spinUpShooter(0.0);
}
