#include "BackCenter3.h"

BackCenter3::BackCenter3()
{
	AddSequential( new AimPot(POT_VAL) );
	AddParallel( new SpinUpShooter() );
	AddSequential( new WaitCommand(3.5) );
	AddSequential( new PushFrisbee(0.5) );
	AddSequential( new WaitCommand(1.5) );
	AddSequential( new PushFrisbee(0.5) );
	AddSequential( new WaitCommand(1.5) );
	AddSequential( new PushFrisbee(0.5) );
	AddSequential( new WaitCommand(1.5) );
}
