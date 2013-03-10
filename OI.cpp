#include "OI.h"
#include "Commands/GearUp.h"
#include "Commands/GearDown.h"
#include "Commands/PushFrisbee.h"
#include "Commands/SpinUpShooter.h"
#include "Commands/ChickenRelease.h"
#include "Commands/AimUp.h"
#include "Commands/AimDown.h"
#include "Commands/ToggleVision.h"

OI::OI() 
{	
	//Creating Joysticks
	m_driver = new LogitechF310(DRIVER_PORT);
	m_xbox = new XboxController(OPERATOR_PORT);
	//m_guitar = new GuitarController(GUITAR_PORT);

	//Attaching the runVision boolean to the smart dashboard key
	runVision = false;
	SmartDashboard::PutBoolean("runVision", runVision);
	
	
	/** Creating Logitech Buttons for Driver **/
		/*GearUp sets drive to High Gear
		 * GearDown sets drive to Low Gear
		 */
	gearUp = new JoystickButton(m_driver->m_joy, XBOX_RB);
	gearUp->WhenPressed(new GearUp());
	gearDown = new JoystickButton(m_driver->m_joy, XBOX_LB);
	gearDown->WhenPressed(new GearDown());	
	chickenRelease = new JoystickButton(m_driver->m_joy, XBOX_A);
	chickenRelease->WhenPressed(new ChickenRelease());
	
	/** Creating Xbox Buttons for Operator **/
		/* Shoot starts up the motors on the shooter
		 * Push fires the piston that puts the frisbee through the shooter
		 * ChickenRelease deploys the hanging mechanism
		 * visionOnOff toggles the vision system
		 */
	shoot = new JoystickButton(m_xbox->m_joy, XBOX_RB);
	shoot->WhileHeld(new SpinUpShooter());
	
	push = new JoystickButton(m_xbox->m_joy, XBOX_A);
	push->WhileHeld(new PushFrisbee());
	
	/*chickenRelease = new JoystickButton(m_xbox->m_joy, XBOX_LB);
	chickenRelease->WhenPressed(new ChickenRelease());*/
	
	visionOnOff = new JoystickButton(m_xbox->m_joy, XBOX_B);
	visionOnOff->WhenPressed(new ToggleVision());
	
	
	/** Creating Guitar Buttons for Operator **/
		 /* GuitarShoot starts the shooter motors
		  * GuitarPush deploys the shooter piston
		  * GuitarChicken releases the hanging mechanism
		  * ShooterUp moves the shooter up
		  * ShooterDown moves the shooter down
		  * GuitarVision toggles the vision system
		  */
	//guitarPush = new JoystickButton(m_guitar->m_joy, GUITAR_GREEN);
	//guitarPush->WhileHeld(new PushFrisbee());
	
	//guitarShoot = new JoystickButton(m_guitar->m_joy, GUITAR_START);
	//guitarShoot->WhileHeld(new SpinUpShooter());
	
	//guitarChicken = new JoystickButton(m_guitar->m_joy, GUITAR_BACK);
	//guitarChicken->WhileHeld(new ChickenRelease());
	
	//shooterUp = new JoystickButton(m_guitar->m_joy, GUITAR_YELLOW);
	//shooterUp->WhileHeld(new AimUp());
	
	//shooterDown = new JoystickButton(m_guitar->m_joy, GUITAR_RED);
	//shooterDown->WhileHeld(new AimDown());
	
	//guitarVision = new JoystickButton(m_guitar->m_joy, GUITAR_BLUE);
	//guitarVision->WhenPressed(new ToggleVision());
}
