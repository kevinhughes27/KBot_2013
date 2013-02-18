#ifndef PUSHFRISBEE_H
#define PUSHFRISBEE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author KBotics
 */
class PushFrisbee: public Command {
public:
	PushFrisbee();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
