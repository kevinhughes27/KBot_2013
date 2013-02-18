#include "VisionSystem.h"
#include "../Robotmap.h"
#include "../CommandBase.h"

VisionSystem::VisionSystem() : Subsystem("VisionSystem") {
	toggleCamera = CommandBase::oi->runVision;
	toggleLights = RobotMap::visionLights;
	toggleLights->Set(toggleLights->Get());
}
    
void VisionSystem::InitDefaultCommand() {}

void VisionSystem::onOff()
{
	toggleLights->Set(!toggleLights->Get());
	toggleCamera = !toggleCamera;
}
