#include "WPILib.h"
#include "Commands/Command.h"

#include "RobotMap.h"
#include "CommandBase.h"

#include "Commands/Autonomous/BackCenter3.h"
//#include "Commands/Autonomous/BackCenter3_wDrive.h"
#include "Commands/Autonomous/BackCenter3_openLoop.h"

class Kbot : public IterativeRobot
{

public:

	LiveWindow *lw;

	Command *autonomousCommand;

	DriverStationLCD *lcd;

	virtual void RobotInit()
	{
		RobotMap::init();
		CommandBase::init();
		lw = LiveWindow::GetInstance();

		autonomousCommand = new BackCenter3();
		//autonomousCommand = new BackCenter3_wDrive();
		//autonomousCommand = new BackCenter3_openLoop();
	}

	virtual void AutonomousInit()
	{
		autonomousCommand->Start();
	}

	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TeleopInit()
	{
		autonomousCommand->Cancel();
	}

	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Kbot);
