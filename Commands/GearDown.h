#ifndef GEARDOWN_H
#define GEARDOWN_H

#include "../CommandBase.h"

class GearDown: public Command
{
public:
	GearDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
