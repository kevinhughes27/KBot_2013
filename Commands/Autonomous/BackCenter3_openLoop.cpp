#include "BackCenter3_openLoop.h"

BackCenter3_openLoop::BackCenter3_openLoop() 
{
	AddSequential( new AimDown(AIM_TIME) );
	AddParallel( new SpinUpShooter() );	
	AddSequential( new WaitCommand(2.0) );
	AddSequential( new PushFrisbee(0.5) );
	AddSequential( new WaitCommand(1.5) );
	AddSequential( new PushFrisbee(0.5) );
	AddSequential( new WaitCommand(1.5) );
	AddSequential( new PushFrisbee(0.5) );
	AddSequential( new WaitCommand(1.5) );
}
