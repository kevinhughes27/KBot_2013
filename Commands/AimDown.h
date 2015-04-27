#ifndef AIMDOWN_H
#define AIMDOWN_H

#include "../CommandBase.h"

class AimDown: public CommandBase
{
public:
	AimDown();
	AimDown(float time);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
