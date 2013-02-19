#ifndef VISIONSYSTEM_H
#define VISIONSYSTEM_H

#include "WPILib.h"
#include "Commands/Subsystem.h"

class VisionSystem: public Subsystem 
{
private:
	Solenoid* ringLED;
	Solenoid* fan;
	bool toggleCamera;
	bool toggleRingLED;
	bool fanLights;
public:
	VisionSystem();
	void InitDefaultCommand();
	void onOff();
	void isAimed();
};

#endif
