#include "VisionSystem.h"

#include "../Robotmap.h"
#include "../CommandBase.h"

VisionSystem::VisionSystem() : Subsystem("VisionSystem") 
{
	toggleCamera = CommandBase::oi->runVision;
	ringLED = RobotMap::ringLED;
	fan = RobotMap::fanLights;
	
	toggleLights = RobotMap::ringLED->Get();
	fanLights = RobotMap::fanLights->Get();
	
}
    
void VisionSystem::InitDefaultCommand() {}

void VisionSystem::onOff()
{
	toggleCamera = SmartDashboard::GetBoolean("runVision");
	SmartDashboard::PutBoolean("runVision", !toggleCamera);
	toggleLights = !toggleLights;
	lights->Set(toggleLights);
}

/*void VisionSystem::isAimed()
{
	if(toggleLights)
	{
		if(SmartDashboard:)
	}
	
	//fanLights = !fanLights;
	//fan->Set(fanLights);
	
}*/
