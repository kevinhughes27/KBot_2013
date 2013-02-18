#include "AimDown.h"

AimDown::AimDown() {
	Requires(CommandBase::aimPID);
}

// Called just before this Command runs the first time
void AimDown::Initialize() {
	aimPID->aimDown();
}

// Called repeatedly when this Command is scheduled to run
void AimDown::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool AimDown::IsFinished() {
	return aimPID->atBottom();
}

// Called once after isFinished returns true
void AimDown::End() {
	aimPID->aimUp();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimDown::Interrupted() {
	aimPID->aim(0.0);
}
