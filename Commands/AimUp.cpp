#include "AimUp.h"

AimUp::AimUp() {
	Requires(CommandBase::aimPID);
}

// Called just before this Command runs the first time
void AimUp::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void AimUp::Execute() {
	CommandBase::aimPID->aim(1);
}

// Make this return true when this Command no longer needs to run execute()
bool AimUp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AimUp::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimUp::Interrupted() {
	CommandBase::aimPID->aim(0.0);
}
