#include "WPILib.h"
#include "Commands/Command.h"

#include "RobotMap.h"
#include "CommandBase.h"

#include "Commands/Autonomous/BackCenter3.h"
#include "Commands/Autonomous/BackCenter3_wDrive.h"

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
		//autonomousCommand = new BackCenter3_wDrive();
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

/*
 * In DriveCmd.cpp, changed Execute function to "CommandBase::drive->
 * 	regularDrive(float, float);... It used to be wesleyDrive(float float).
 * 	
 * Also, added regularDrive to Drive subsystem.
 */
