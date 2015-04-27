#ifndef PISTONS_H
#define PISTONS_H

#include "WPILib.h"
#include "Commands/Subsystem.h"

class Pistons: public Subsystem
{
private:
	Solenoid* gearPiston;
	Solenoid* chickenLittle;
	bool previousChicken;

public:
	Pistons();
	void InitDefaultCommand();
	void gearChange(bool);
	void toggleChicken();
};

#endif
