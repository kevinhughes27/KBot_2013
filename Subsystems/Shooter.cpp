#include "Shooter.h"
#include "../Robotmap.h"
#include "math.h"

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

void Shooter::shootFrisbee(float motorSpeed)
{
	shooterFront->Set(FRONT_CONSTANT * motorSpeed);
	shooterBack->Set(BACK_CONSTANT * motorSpeed);
}

void Shooter::autonomousShoot()
{
	shooterFront->Set(FRONT_CONSTANT);
	shooterBack->Set(BACK_CONSTANT);
	Wait(2.5);
	piston->Set(true);
	Wait(0.5);
	piston->Set(false);
}

void Shooter::autonomousShoot3()
{
	shooterFront->Set(FRONT_CONSTANT);
	shooterBack->Set(BACK_CONSTANT);
	Wait(3);
	piston->Set(true);
	Wait(0.5);
	piston->Set(false);

	for(int i = 0; i < 2; i++)
	{
		Wait(2);
		piston->Set(true);
		Wait(0.5);
		piston->Set(false);
	}
	Wait(2);
}

