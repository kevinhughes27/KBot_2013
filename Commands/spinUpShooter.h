#ifndef SHOOTFRISBEE_H
#define SHOOTFRISBEE_H

#include "../CommandBase.h"

class spinUpShooter: public Command 
{
public:
	spinUpShooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
