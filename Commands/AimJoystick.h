#ifndef AIMJOYSTICK_H
#define AIMJOYSTICK_H

#include "../CommandBase.h"

#include "math.h"

class AimJoystick: public CommandBase
{
public:
	AimJoystick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
