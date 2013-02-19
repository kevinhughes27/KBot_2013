#include "GearDown.h"

GearDown::GearDown() 
{
	Requires(CommandBase::pistons);
}

// Called just before this Command runs the first time
void GearDown::Initialize() 
{
	//pass
}

// Called repeatedly when this Command is scheduled to run
void GearDown::Execute() 
{
	CommandBase::pistons->gearChange(false);
}

// Make this return true when this Command no longer needs to run execute()
bool GearDown::IsFinished() 
{
	return false;
}

// Called once after isFinished returns true
void GearDown::End() 
{
	//pass
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearDown::Interrupted() 
{
	//pass
}
