#include "RobotMap.h"

SpeedController* RobotMap::leftMotor = NULL;
SpeedController* RobotMap::rightMotor = NULL;
SpeedController* RobotMap::shooterFront = NULL;
SpeedController* RobotMap::shooterBack = NULL;
SpeedController* RobotMap::aimingMotor = NULL;
RobotDrive* RobotMap::robotDrive = NULL;
Solenoid* RobotMap::shooterPiston = NULL;
Solenoid* RobotMap::gearPiston = NULL;
Solenoid* RobotMap::chickenLittle = NULL;
Solenoid* RobotMap::ringLED = NULL;
Solenoid* RobotMap::fanLights = NULL;
Compressor* RobotMap::compressor = NULL;
AnalogChannel* RobotMap::aimPot = NULL;
DigitalInput* RobotMap::bottomLimit = NULL;
DigitalInput* RobotMap::topLimit = NULL;

void RobotMap::init()
{	
	//Starting compressor
	compressor = new Compressor(COMPRESSOR_SWITCH_CHANNEL, COMPRESSOR_RELAY_CHANNEL);
	compressor->Start();
	
	//Start pistons
	gearPiston = new Solenoid(GEAR_PISTON);
	gearPiston->Set(true);
	chicken_little = new Solenoid(CHICKEN_RELEASE);
	chicken_little->Set(false);
	shooterPiston = new Solenoid(SHOOTER_PISTON);
	shooterPiston->Set(false);
	
	//Starting Vision Lights
	ringLED = new Solenoid(VISION_LIGHTS);
	ringLED->Set(false);
	fanLights = new Solenoid(FAN_LIGHTS);
	fanLights->Set(true); //true is on, false is offb
	
	//Initializing motors
	leftMotor = new Talon(LEFT_MOTOR);
	rightMotor = new Talon(RIGHT_MOTOR);
	
	//Setting Shooter Motor
	shooterFront = new Talon(SHOOTER_FRONT);
	shooterBack = new Talon(SHOOTER_BACK);
	aimingMotor = new Talon(AIMING_MOTOR);
	
	//Setting Defaults of RobotDrive
	robotDrive = new RobotDrive(leftMotor, rightMotor);
	robotDrive->SetMaxOutput(1.0);
	robotDrive->SetExpiration(0.01);
	robotDrive->SetSafetyEnabled(false);

	//Initializing Potentiometer
	aimPot = new AnalogChannel(POTENTIOMETER);
	
	//Initializing Limit Switches
	topLimit = new DigitalInput(TOP_LIMIT);
	bottomLimit = new DigitalInput(BOTTOM_LIMIT);
}
