#include "BackCenter3_wDrive.h"

BackCenter3_wDrive::BackCenter3_wDrive() 
{
	Requires(CommandBase::drive);
	Requires(CommandBase::shooter);
	Requires(CommandBase::aimer);
	SetTimeout(15);
}

// Called just before this Command runs the first time
void BackCenter3_wDrive::Initialize() 
{
	CommandBase::drive->stop();
	CommandBase::aimer->aim(0.0);
	CommandBase::shooter->spinUpShooter(0.0);
}

// Called repeatedly when this Command is scheduled to run
void BackCenter3_wDrive::Execute() 
{
	CommandBase::drive->wesleyDrive(AUTONOMOUS_DRIVE, AUTONOMOUS_DRIVE);
	Wait(2);
	CommandBase::drive->stop();
	CommandBase::aimer->autonomousAim(0.88);
	CommandBase::shooter->autonomousShoot3();
	Wait(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool BackCenter3_wDrive::IsFinished() 
{
	return true || IsTimedOut();
}

// Called once after isFinished returns true
void BackCenter3_wDrive::End() 
{
	CommandBase::drive->stop();
	CommandBase::aimer->aim(0.0);
	CommandBase::shooter->spinUpShooter(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BackCenter3_wDrive::Interrupted() 
{
	End();
}
