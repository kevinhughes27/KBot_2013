#include "Pistons.h"
#include "../Robotmap.h"

Pistons::Pistons() : Subsystem("Pistons") 
{
	gearPiston = RobotMap::gearPiston;
	chickenRelease = RobotMap::chicken_little;
	previousChicken = false;
}
    
void Pistons::InitDefaultCommand() 
{}

void Pistons::gearChange(bool change)
{
	gearPiston->Set(change);
}

void Pistons::toggleChicken()
{
	previousChicken = !previousChicken;
	chickenRelease->Set(previousChicken);
}