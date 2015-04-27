#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Pistons.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Aimer.h"
#include "Subsystems/VisionSystem.h"
#include "OI.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();

	// single static instance of all subsystems
	static Drive* drive;
	static Pistons* pistons;
	static Shooter* shooter;
	static Aimer* aimer;
	static VisionSystem* vision;
	static OI *oi;
};

#endif
