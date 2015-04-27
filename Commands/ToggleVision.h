#ifndef TOGGLEVISION_H
#define TOGGLEVISION_H

#include "../CommandBase.h"

class ToggleVision: public CommandBase
{
public:
	ToggleVision();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
