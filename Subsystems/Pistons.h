#ifndef PISTONS_H
#define PISTONS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pistons: public Subsystem {
private:
	Solenoid* gearPiston;
	Solenoid* chickenRelease;
	bool previousChicken;

public:
	Pistons();
	void InitDefaultCommand();
	void gearChange(bool);
	void toggleChicken();
};

#endif
