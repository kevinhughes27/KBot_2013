#include "AimPot.h"

AimPot::AimPot(float _setPoint)
{
	Requires(CommandBase::aimer);
	setPoint = _setPoint;
}

// Called just before this Command runs the first time
void AimPot::Initialize()
{
	CommandBase::aimer->aim(0);
}

// Called repeatedly when this Command is scheduled to run
void AimPot::Execute()
{
	CommandBase::aimer->aimDown();
}

// Make this return true when this Command no longer needs to run execute()
bool AimPot::IsFinished()
{
	return (CommandBase::aimer->getPot() <= setPoint)
		 || CommandBase::aimer->atBottom();
}

// Called once after isFinished returns true
void AimPot::End()
{
	CommandBase::aimer->aim(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimPot::Interrupted()
{
	CommandBase::aimer->aim(0.0);
}
