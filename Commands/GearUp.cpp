#include "GearUp.h"

GearUp::GearUp() {
	Requires(CommandBase::pistons);
}

// Called just before this Command runs the first time
void GearUp::Initialize() 
{
}

// Called repeatedly when this Command is scheduled to run
void GearUp::Execute() 
{
	CommandBase::pistons->gearChange(true);	
}

// Make this return true when this Command no longer needs to run execute()
bool GearUp::IsFinished() 
{
	return false;
}

// Called once after isFinished returns true
void GearUp::End() 
{}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearUp::Interrupted() 
{
}
