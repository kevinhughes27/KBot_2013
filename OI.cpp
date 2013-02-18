#include "OI.h"
#include "Commands/GearUp.h"
#include "Commands/GearDown.h"
#include "Commands/PushFrisbee.h"
#include "Commands/ShootFrisbee.h"
#include "Commands/ChickenRelease.h"
#include "Commands/AimUp.h"
#include "Commands/AimDown.h"
#include "Commands/ToggleVision.h"

OI::OI() 
{
	//Attaching the runVision boolean to the smart dashboard key
	runVision = true;
	SmartDashboard::PutBoolean("runVision", runVision);
	
	//Creating Joysticks
	m_logitech = new XboxController(DRIVER_PORT);
	m_xbox = new XboxController(OPERATOR_PORT);
	m_guitar = new GuitarController(GUITAR_PORT);
	
	//Creating Logitech Buttons for Driver
		/* GearUp sets drive to High Gear
		 * GearDown sets drive to Low Gear
		 */
	gearUp = new JoystickButton(m_logitech->m_joy, XBOX_RB);
	gearUp->WhenPressed(new GearUp());
	
	gearDown = new JoystickButton(m_logitech->m_joy, XBOX_LB);
	gearDown->WhenPressed(new GearDown());
	
	//Creating Xbox Buttons for Operator
		/* Shoot starts up the motors on the shooter
		 * Push fires the piston that puts the frisbee through the shooter
		 * ChickenRelease deploys the hanging mechanism
		 * visionOnOff toggles the vision system
		 */
	shoot = new JoystickButton(m_xbox->m_joy, XBOX_RB);
	shoot->WhileHeld(new ShootFrisbee());
	
	push = new JoystickButton(m_xbox->m_joy, XBOX_A);
	push->WhileHeld(new PushFrisbee());
	
	chickenRelease = new JoystickButton(m_xbox->m_joy, XBOX_LB);
	chickenRelease->WhenPressed(new ChickenRelease());
	
	visionOnOff = new JoystickButton(m_xbox->m_joy, XBOX_X);
	visionOnOff->WhenPressed(new ToggleVision());
	
	//Creating Guitar Buttons for Operator
		 /* GuitarShoot starts the shooter motors
		  * GuitarPush deploys the shooter piston
		  * GuitarChicken releases the hanging mechanism
		  * ShooterUp moves the shooter up
		  * ShooterDown moves the shooter down
		  * GuitarVision toggles the vision system
		  */
	guitarPush = new JoystickButton(m_guitar->m_joy, GUITAR_GREEN);
	guitarPush->WhileHeld(new PushFrisbee());
	
	guitarShoot = new JoystickButton(m_guitar->m_joy, GUITAR_START);
	guitarShoot->WhileHeld(new ShootFrisbee());
	
	guitarChicken = new JoystickButton(m_guitar->m_joy, GUITAR_BACK);
	guitarChicken->WhileHeld(new ChickenRelease());
	
	shooterUp = new JoystickButton(m_guitar->m_joy, GUITAR_ORANGE);
	shooterUp->WhileHeld(new AimUp());
	
	shooterDown = new JoystickButton(m_guitar->m_joy, GUITAR_YELLOW);
	shooterDown->WhileHeld(new AimDown());
	
	guitarVision = new JoystickButton(m_guitar->m_joy, GUITAR_BLUE);
	guitarVision->WhenPressed(new ToggleVision());
}
