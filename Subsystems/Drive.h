#ifndef DRIVE_H
#define DRIVE_H

#include "WPILib.h"
#include "Commands/Subsystem.h"

#include "math.h"

#define DRIVER_DEADBAND 0.10

class Drive: public Subsystem
{
private:
	SpeedController* leftMotor;
	SpeedController* rightMotor;
	RobotDrive* robotDrive;
	bool speedSet;

public:
	Drive();
	void InitDefaultCommand();
	void stop();
	void wesleyDrive(float, float);
	void halfSpeed(bool);
	void regularDrive(float, float);
};

#endif
