#ifndef AIMDOWN_H
#define AIMDOWN_H

#include "../CommandBase.h"

/**
 *
 *
 * @author KBotics
 */
class AimDown: public CommandBase {
public:
	AimDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
