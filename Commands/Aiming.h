#ifndef AIMING_H
#define AIMING_H

#include "../CommandBase.h"

/**
 *
 *
 * @author KBotics
 */
class Aiming: public CommandBase {
public:
	Aiming();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif