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
	bool toggleLights;
	bool fanLights;
	Solenoid* lights;
	Solenoid* fan;
public:
	VisionSystem();
	void InitDefaultCommand();
	void onOff();
	void isAimed();
};

#endif
