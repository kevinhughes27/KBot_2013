#ifndef AIMUP_H
#define AIMUP_H

#include "../CommandBase.h"

class AimUp: public CommandBase
{
public:
	AimUp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
