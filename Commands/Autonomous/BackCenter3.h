#ifndef BACKCENTER3_H
#define BACKCENTER3_H

#include "../../CommandBase.h"

class BackCenter3: public CommandBase 
{
public:
	BackCenter3();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
