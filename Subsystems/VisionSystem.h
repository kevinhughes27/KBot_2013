#ifndef VISIONSYSTEM_H
#define VISIONSYSTEM_H

#include "WPILib.h"
#include "Commands/Subsystem.h"

class VisionSystem: public Subsystem
{
private:
	Solenoid* ringLED;
	bool toggleCamera;
	bool toggleRingLED;
public:
	VisionSystem();
	void InitDefaultCommand();
	void onOff();
};

#endif
