#ifndef VISIONSYSTEM_H
#define VISIONSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author KBotics
 */
class VisionSystem: public Subsystem {
private:
	bool toggleCamera;
	Solenoid* toggleLights;
public:
	VisionSystem();
	void InitDefaultCommand();
	void onOff();
};

#endif
