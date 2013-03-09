#ifndef BACKCENTER3_OPENLOOP_H
#define BACKCENTER3_OPENLOOP_H

#include "../../CommandBase.h"
#define AIM_TIME 0.625

class BackCenter3_openLoop: public CommandBase 
{
public:
	BackCenter3_openLoop();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
