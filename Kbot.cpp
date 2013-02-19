#include "WPILib.h"
#include "Commands/Command.h"

#include "RobotMap.h"
#include "CommandBase.h"

#include "Commands/Autonomous/BackCenter3.h"

class Kbot : public IterativeRobot 
{

private:
	LiveWindow *lw;
	
	Command *autonomousCommand;
	
	virtual void RobotInit() 
	{
		RobotMap::init();
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		
		autonomousCommand = new BackCenter3();
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
	
	virtual void DisabledPeriodic()
	{
		
	}
	
	virtual void TestPeriodic() 
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Kbot);
