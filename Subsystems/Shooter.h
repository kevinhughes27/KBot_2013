#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author KBotics
 */
class Shooter: public Subsystem 
{
private:
	SpeedController* shooterFront;
	SpeedController* shooterBack;
	Solenoid* piston;
public:
	Shooter();
	void InitDefaultCommand();
	void pushFrisbee(bool);
	void shootFrisbee(float);
	void autonomousShoot();
};

#endif
