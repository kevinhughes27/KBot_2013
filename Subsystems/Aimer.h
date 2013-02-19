#ifndef AIMER_H
#define AIMER_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
#include "SmartDashboard/SmartDashboard.h"

#include "math.h"

#define PID_STEP 0.1
#define AIM_SPEED 0.20
#define AUTON_SPEED 0.10

#define OPERATOR_DEADBAND 0.100

#define LIMIT_SWITCH_ON 1

#define POT_BOTTOM 0.2
#define POT_TOP 0.2
#define POT_AIM 0.8

class Aimer: public PIDSubsystem 
{
private:
	static const double Kp = 1.0;
	static const double Ki = 0.0;
	static const double Kd = 0.0;
	
	AnalogChannel* pot;
	DigitalInput* topLimit;
	DigitalInput* bottomLimit;
	SpeedController* motor;
public:
	Aimer();
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
	void autonomousAim(float);
};

#endif
