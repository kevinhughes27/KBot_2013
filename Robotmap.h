#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

//Motor Defines
#define LEFT_MOTOR 1
#define RIGHT_MOTOR 2
#define AIMING_MOTOR 3
#define SHOOTER_FRONT 4
#define SHOOTER_BACK 6

//Compressor and Pistons
#define COMPRESSOR_RELAY_CHANNEL 8
#define COMPRESSOR_SWITCH_CHANNEL 14
#define CHICKEN_RELEASE 1
#define GEAR_PISTON 2
#define SHOOTER_PISTON 3
#define VISION_LIGHTS 4
#define FAN_LIGHTS 5

//Digital I/O
#define POTENTIOMETER 1
#define TOP_LIMIT 10
#define BOTTOM_LIMIT 12

class RobotMap
{
private:
public:

	//Defining Driver objects
	static SpeedController* leftMotor;
	static SpeedController* rightMotor;
	static RobotDrive* robotDrive;
	static Solenoid* gearPiston;
	
	//Defining Operator objects
	static SpeedController* shooterFront;
	static SpeedController* shooterBack;
	static SpeedController* aimingMotor;
	static AnalogChannel* aimPot;
	static Solenoid* shooterPiston;
	static Solenoid* chicken_little;
	
	//Defining Other objects
	static Compressor* compressor;
	static DigitalInput* topLimit;
	static DigitalInput* bottomLimit;
	static Solenoid* visionLights;
	static Solenoid* fanLights;
	
	static void init();
};

#endif
