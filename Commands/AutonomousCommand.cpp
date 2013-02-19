#include "AutonomousCommand.h"

AutonomousCommand::AutonomousCommand() {
	Requires(CommandBase::shooter);
	Requires(CommandBase::aimPID);
	SetTimeout(12);
}

// Called just before this Command runs the first time
void AutonomousCommand::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void AutonomousCommand::Execute() {
	aimPID->autonomousAim(0.88);
	shooter->autonomousShoot3();
	Wait(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousCommand::IsFinished() {
	return true || IsTimedOut();
}

// Called once after isFinished returns true
void AutonomousCommand::End() {
	shooter->shootFrisbee(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousCommand::Interrupted() {
	shooter->shootFrisbee(0.0);
}
