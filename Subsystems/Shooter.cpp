#include "Shooter.h"
#include "../Robotmap.h"

Shooter::Shooter() : Subsystem("Shooter") 
{
	shooterFront = RobotMap::shooterFront;
	shooterBack = RobotMap::shooterBack;
	piston = RobotMap::shooterPiston;
	pot = RobotMap::aimPot;
}
    
void Shooter::InitDefaultCommand() 
{}

void Shooter::pushFrisbee(bool pistonSetting)
{
	piston->Set(pistonSetting);
}

void Shooter::spinUpShooter(float motorSpeed)
{
	shooterFront->Set(FRONT_CONSTANT * motorSpeed);
	shooterBack->Set(BACK_CONSTANT * motorSpeed);
}

void Shooter::autonomousShoot()
{
	spinUpShooter(1.0);
	Wait(3.0);
	// shoot
	piston->Set(true);
	Wait(0.5);
	piston->Set(false);
}

void Shooter::autonomousShoot3(int loops)
{
	spinUpShooter(1.0);
	Wait(2.5);
	// shoot
	piston->Set(true);
	Wait(0.5);
	piston->Set(false);

	for(int i = 0; i < loops; i++)
	{
		Wait(3);
		// shoot
		piston->Set(true);
		Wait(0.5);
		piston->Set(false);
	}
	Wait(2);
}
