#include "ShootFrisbee.h"

ShootFrisbee::ShootFrisbee() 
{
	//Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void ShootFrisbee::Initialize() 
{}

// Called repeatedly when this Command is scheduled to run
void ShootFrisbee::Execute() 
{
	CommandBase::shooter->shootFrisbee(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool ShootFrisbee::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootFrisbee::End() 
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootFrisbee::Interrupted() 
{
	CommandBase::shooter->shootFrisbee(0.0);
}
