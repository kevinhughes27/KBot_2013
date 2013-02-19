#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "../ControllerWrappers/LogitechController.hpp"
#include "../ControllerWrappers/XboxController.hpp"
#include "../ControllerWrappers/GuitarController.hpp"

#define DRIVER_PORT 1
#define OPERATOR_PORT 2
#define GUITAR_PORT 3

class OI 
{
private:

public:
	OI();
	bool runVision;
	XboxController* m_driver;
	XboxController* m_xbox;
	GuitarController* m_guitar;
	
	//Operator Buttons
		//Xbox
		JoystickButton* push;
		JoystickButton* shoot;
		JoystickButton* chickenRelease;
		JoystickButton* visionOnOff;
	
		//Guitar Buttons
		JoystickButton* guitarPush;
		JoystickButton* guitarShoot;
		JoystickButton* guitarChicken;
		JoystickButton* shooterUp;
		JoystickButton* shooterDown;
		JoystickButton* guitarVision;
	
	//Driver Buttons
	JoystickButton* gearUp;
	JoystickButton* gearDown;
};

#endif
