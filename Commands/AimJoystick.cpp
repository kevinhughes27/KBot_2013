#include "AimJoystick.h"

AimJoystick::AimJoystick() 
{
	Requires(CommandBase::aimer);
}

// Called just before this Command runs the first time
void AimJoystick::Initialize() 
{
	CommandBase::aimer->aim(0);
}

// Called repeatedly when this Command is scheduled to run
void AimJoystick::Execute() 
{
	CommandBase::aimer->aim(CommandBase::oi->m_xbox->getjoyLeftY());
}

// Make this return true when this Command no longer needs to run execute()
bool AimJoystick::IsFinished() 
{
	return false;
}

// Called once after isFinished returns true
void AimJoystick::End() 
{
	CommandBase::aimer->aim(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimJoystick::Interrupted() 
{
	CommandBase::aimer->aim(0.0);
}
