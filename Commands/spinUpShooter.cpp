#include "spinUpShooter.h"

spinUpShooter::spinUpShooter() 
{
	//Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void spinUpShooter::Initialize() 
{
	CommandBase::shooter->spinUpShooter(0.0);
}

// Called repeatedly when this Command is scheduled to run
void spinUpShooter::Execute() 
{
	CommandBase::shooter->spinUpShooter(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool spinUpShooter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void spinUpShooter::End() 
{
	CommandBase::shooter->spinUpShooter(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void spinUpShooter::Interrupted() 
{
	CommandBase::shooter->spinUpShooter(0.0);
}
