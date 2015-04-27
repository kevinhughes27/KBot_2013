#ifndef CHICKENRELEASE_H
#define CHICKENRELEASE_H

#include "../CommandBase.h"

class ChickenRelease: public Command
{
public:
	ChickenRelease();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
