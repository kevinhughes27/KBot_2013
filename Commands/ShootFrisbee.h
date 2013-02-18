#ifndef SHOOTFRISBEE_H
#define SHOOTFRISBEE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author KBotics
 */
class ShootFrisbee: public Command {
public:
	ShootFrisbee();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
