#include "VisionSystem.h"

#include "../Robotmap.h"
#include "../CommandBase.h"

VisionSystem::VisionSystem() : Subsystem("VisionSystem") 
{
	toggleCamera = CommandBase::oi->runVision;
	ringLED = RobotMap::ringLED;
	
	toggleRingLED = RobotMap::ringLED->Get();
}
    
void VisionSystem::InitDefaultCommand() {}

void VisionSystem::onOff()
{
	toggleCamera = SmartDashboard::GetBoolean("runVision");
	SmartDashboard::PutBoolean("runVision", !toggleCamera);
	toggleRingLED = !toggleRingLED;
	ringLED->Set(toggleRingLED);
}
