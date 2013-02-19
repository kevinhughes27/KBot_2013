#ifndef DRIVE_H
#define DRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#define DRIVER_DEADBAND 0.10

/**
 *
 *
 * @author KBotics
 */
class Drive: public Subsystem {
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
};

#endif
