#ifndef DRIVECMD_H
#define DRIVECMD_H

#include "../CommandBase.h"

class DriveCmd: public CommandBase 
{
public:
	DriveCmd();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
