#ifndef AIMPID_H
#define AIMPID_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "math.h"

#define STEP_DISTANCE 0.1
#define AIM_SPEED 0.1
#define DEADBAND 0.05
#define LIMIT_SWITCH_ON 1

/**
 *
 *
 * @author KBotics
 */
class AimPID: public PIDSubsystem {
private:
	static const double Kp = 1.0;
	static const double Ki = 0.0;
	static const double Kd = 0.0;
	
	AnalogChannel* pot;
	DigitalInput* topLimit;
	DigitalInput* bottomLimit;
	SpeedController* motor;
public:
	AimPID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void aimPID(float);
	void aimUpPID();
	void aimDownPID();
	void aim(float);
	void aimUp();
	void aimDown();
	bool atBottom();
	bool atTop();
	void moveFromLimit();
};

#endif
