#ifndef AIMPOT_H
#define AIMPOT_H

#include "../CommandBase.h"

#include "math.h"

class AimPot: public CommandBase
{
public:
	AimPot(float _setPoint);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	float setPoint;
};

#endif
