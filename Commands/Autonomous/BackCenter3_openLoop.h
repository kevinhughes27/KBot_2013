#ifndef BACKCENTER3_OPENLOOP_H
#define BACKCENTER3_OPENLOOP_H

#include "../AimDown.h"
#include "../SpinUpShooter.h"
#include "../PushFrisbee.h"

#define AIM_TIME 0.5

class BackCenter3_openLoop: public CommandGroup
{
public:
	BackCenter3_openLoop();
};

#endif
