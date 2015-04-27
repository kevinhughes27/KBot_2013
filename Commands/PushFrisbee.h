#ifndef PUSHFRISBEE_H
#define PUSHFRISBEE_H

#include "../CommandBase.h"

class PushFrisbee: public Command
{
public:
	PushFrisbee();
	PushFrisbee(float time);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
