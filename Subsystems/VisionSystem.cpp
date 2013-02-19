#include "VisionSystem.h"
#include "../Robotmap.h"
#include "../CommandBase.h"

VisionSystem::VisionSystem() : Subsystem("VisionSystem") {
	toggleCamera = CommandBase::oi->runVision;
	toggleLights = RobotMap::visionLights->Get();
	fanLights = RobotMap::fanLights->Get();
	lights = RobotMap::visionLights;
	fan = RobotMap::fanLights;
}
    
void VisionSystem::InitDefaultCommand() {}

void VisionSystem::onOff()
{
	toggleCamera = SmartDashboard::GetBoolean("runVision");
	SmartDashboard::PutBoolean("runVision", !toggleCamera);
	toggleLights = !toggleLights;
	lights->Set(toggleLights);
	//fanLights = !fanLights;
	//fan->Set(fanLights);
}

/*void VisionSystem::isAimed()
{
	if(toggleLights)
	{
		if(SmartDashboard:)
	}
}*/
