#include "Shooter.h"
#include "../Robotmap.h"
#include "math.h"

#define DEADBAND 0.10
#define BACKCONSTANT 1.0

Shooter::Shooter() : Subsystem("Shooter") 
{
	shooterFront = RobotMap::shooterFront;
	shooterBack = RobotMap::shooterBack;
	piston = RobotMap::shooterPiston;
}
    
void Shooter::InitDefaultCommand() 
{}

void Shooter::pushFrisbee(bool pistonSetting)
{
	piston->Set(pistonSetting);
}

void Shooter::shootFrisbee(float motorSpeed)
{
	shooterFront->Set(motorSpeed);
	shooterBack->Set(BACKCONSTANT * motorSpeed);
}

void Shooter::autonomousShoot()
{
	shooterFront->Set(1.0);
	shooterBack->Set(0.75);
	for(int i = 1; i < 4; i++)
	{
		piston->Set(false);
		Wait(0.5);
		piston->Set(true);
		Wait(1);
	}
}
