#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

#define DEADBAND 0.10
#define BACK_CONSTANT 1.0
#define FRONT_CONSTANT 1.0
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
	AnalogChannel* pot;
public:
	Shooter();
	void InitDefaultCommand();
	void pushFrisbee(bool);
	void shootFrisbee(float);
	void autonomousShoot();
	void autonomousShoot3();
};

#endif
