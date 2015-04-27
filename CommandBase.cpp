#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name)
{}

CommandBase::CommandBase() : Command()
{}

Drive* CommandBase::drive = NULL;
Pistons* CommandBase::pistons = NULL;
Shooter* CommandBase::shooter = NULL;
Aimer* CommandBase::aimer = NULL;
VisionSystem* CommandBase::vision = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init()
{
	drive = new Drive();
	pistons = new Pistons();
	shooter = new Shooter();
	aimer = new Aimer();
	vision = new VisionSystem();
	oi = new OI();
}
