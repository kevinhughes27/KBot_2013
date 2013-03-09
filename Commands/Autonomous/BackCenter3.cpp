#include "BackCenter3.h"

BackCenter3::BackCenter3() 
{
	Requires(CommandBase::shooter);
	Requires(CommandBase::aimer);
	SetTimeout(14);
}

// Called just before this Command runs the first time
void BackCenter3::Initialize() 
{
	CommandBase::aimer->aim(0.0);
	CommandBase::shooter->spinUpShooter(0.0);
}

// Called repeatedly when this Command is scheduled to run
void BackCenter3::Execute() 
{
	CommandBase::aimer->autonomousAim(POT_VALUE);
	
	// shoot
	for(int i = 0; i <= 3; i++)
	{
		CommandBase::shooter->autonomousShoot();
		Wait(0.5);
	}
	CommandBase::shooter->spinUpShooter(0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool BackCenter3::IsFinished() 
{
	return true || IsTimedOut();
}

// Called once after isFinished returns true
void BackCenter3::End() 
{
	CommandBase::aimer->aim(0.0);
	CommandBase::shooter->spinUpShooter(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BackCenter3::Interrupted() 
{
	CommandBase::aimer->aim(0.0);
	CommandBase::shooter->spinUpShooter(0.0);
}
