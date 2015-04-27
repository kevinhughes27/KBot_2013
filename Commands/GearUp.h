#ifndef GEARUP_H
#define GEARUP_H

#include "../CommandBase.h"

class GearUp: public Command
{
public:
	GearUp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
