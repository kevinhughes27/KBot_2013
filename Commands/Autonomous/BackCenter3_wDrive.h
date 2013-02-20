#ifndef BACKCENTER3WDRIVE_H
#define BACKCENTER3WDRIVE_H

#include "../../CommandBase.h"

#define AUTONOMOUS_DRIVE -0.5

class BackCenter3_wDrive: public CommandBase 
{
public:
	BackCenter3_wDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
