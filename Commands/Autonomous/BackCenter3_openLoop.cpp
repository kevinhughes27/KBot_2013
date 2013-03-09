#include "BackCenter3_openLoop.h"

BackCenter3_openLoop::BackCenter3_openLoop() 
{
	Requires(CommandBase::shooter);
	Requires(CommandBase::aimer);
	SetTimeout(14);
}

// Called just before this Command runs the first time
void BackCenter3_openLoop::Initialize() 
{
	CommandBase::aimer->aim(0.0);
	CommandBase::shooter->spinUpShooter(0.0);
}

// Called repeatedly when this Command is scheduled to run
void BackCenter3_openLoop::Execute() 
{
	CommandBase::aimer->aimUp();
	Wait(AIM_TIME);
	CommandBase::aimer->aim(0); //stop
	CommandBase::shooter->spinUpShooter(1.0);
	Wait(0.5);
	
	// shoot
	for(int i = 0; i <= 3; i++)
	{
		CommandBase::shooter->autonomousShoot();
		Wait(0.5);
	}
	Wait(1.5);
	CommandBase::shooter->spinUpShooter(0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool BackCenter3_openLoop::IsFinished() 
{
	return true || IsTimedOut();
}

// Called once after isFinished returns true
void BackCenter3_openLoop::End() 
{
	CommandBase::aimer->aim(0.0);
	CommandBase::shooter->spinUpShooter(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BackCenter3_openLoop::Interrupted() 
{
	CommandBase::aimer->aim(0.0);
	CommandBase::shooter->spinUpShooter(0.0);
}
