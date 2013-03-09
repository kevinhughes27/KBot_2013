#ifndef AIMER_H
#define AIMER_H

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "SmartDashboard/SmartDashboard.h"

#include "math.h"

#define OPERATOR_DEADBAND 0.100
#define LIMIT_SWITCH_ON 1
#define AIM_SPEED 0.20


class Aimer: public Subsystem 
{
private:
	AnalogChannel* pot;
	DigitalInput* topLimit;
	DigitalInput* bottomLimit;
	SpeedController* motor;
public:
	Aimer();
	void InitDefaultCommand();
	
	void aim(float);
	void aimUp();
	void aimDown();
	
	float getPot();
	bool atBottom();
	bool atTop();
	
	void autonomousAim(float);
};

#endif
