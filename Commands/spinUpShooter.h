#ifndef SPINUPSHOOTER_H
#define SPINUPSHOOTER_H

#include "../CommandBase.h"

class SpinUpShooter: public Command
{
public:
	SpinUpShooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
