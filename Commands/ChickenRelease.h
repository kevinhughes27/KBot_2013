#ifndef CHICKENRELEASE_H
#define CHICKENRELEASE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author KBotics
 */
class ChickenRelease: public Command {
public:
	ChickenRelease();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
