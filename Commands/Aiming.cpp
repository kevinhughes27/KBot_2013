#include "Aiming.h"
#include "math.h"

Aiming::Aiming() {
	Requires(CommandBase::aimPID);
}

// Called just before this Command runs the first time
void Aiming::Initialize() {
	aimPID->aim(0);
}

// Called repeatedly when this Command is scheduled to run
void Aiming::Execute() {
	aimPID->aim(CommandBase::oi->m_xbox->getjoyLeftY());
}

// Make this return true when this Command no longer needs to run execute()
bool Aiming::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Aiming::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Aiming::Interrupted() {}
