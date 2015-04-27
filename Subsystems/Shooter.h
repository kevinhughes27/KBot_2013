#ifndef SHOOTER_H
#define SHOOTER_H

#include "WPILib.h"
#include "Commands/Subsystem.h"

#include "math.h"

#define DEADBAND 0.10
#define BACK_CONSTANT 1.0
#define FRONT_CONSTANT 1.0

class Shooter: public Subsystem
{
private:
	SpeedController* shooterFront;
	SpeedController* shooterBack;
	Solenoid* piston;
	AnalogChannel* pot;
public:
	Shooter();
	void InitDefaultCommand();
	void pushFrisbee(bool);
	void spinUpShooter(float);
	void autonomousShoot();
	void autonomousShootN(int);
};

#endif
