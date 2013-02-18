#include "WPILib.h"

#include "RobotMap.h"

#include "Commands/Command.h"
#include "Commands/AutonomousCommand.h"
#include "CommandBase.h"

class Kbot : public IterativeRobot 
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	
	virtual void RobotInit() 
	{
		RobotMap::init();
		CommandBase::init();
		autonomousCommand = new AutonomousCommand();
		lw = LiveWindow::GetInstance();
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
		//Keep this so autonomous stops when Teleop initiates
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

