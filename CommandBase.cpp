#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) 
{}

CommandBase::CommandBase() : Command() 
{}

Drive* CommandBase::drive = NULL;
Pistons* CommandBase::pistons = NULL;
Shooter* CommandBase::shooter = NULL;
AimPID* CommandBase::aimPID = NULL;
VisionSystem* CommandBase::vision = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() 
{
	drive = new Drive();
	pistons = new Pistons();
	shooter = new Shooter();
	aimPID = new AimPID();
	vision = new VisionSystem();
	oi = new OI();
}