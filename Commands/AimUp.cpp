#include "AimUp.h"

AimUp::AimUp() {
	Requires(CommandBase::aimPID);
}

// Called just before this Command runs the first time
void AimUp::Initialize() {
	aimPID->aimUp();
}

// Called repeatedly when this Command is scheduled to run
void AimUp::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool AimUp::IsFinished() {
	return aimPID->atTop();
}

// Called once after isFinished returns true
void AimUp::End() {
	aimPID->aimDown();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimUp::Interrupted() {
	aimPID->aim(0.0);
}
