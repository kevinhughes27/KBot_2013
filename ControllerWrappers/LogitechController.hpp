#include "Joystick.h"
#define LOGITECH_1 1
#define LOGITECH_2 2
#define LOGITECH_3 3
#define LOGITECH_4 4
#define LOGITECH_RIGHT_BUMPER 6
#define LOGITECH_RIGHT_TRIGGER 8
#define LOGITECH_LEFT_BUMPER 5
#define LOGITECH_LEFT_TRIGGER 7
#define LOGITECH_L3 11
#define LOGITECH_R3 12
#define LOGITECH_LEFT_Y 6
#define LOGITECH_LEFT_X 5
#define LOGITECH_RIGHT_Y 4
#define LOGITECH_RIGHT_X 3
#define LOGITECH_START 10
#define LOGITECH_SELECT 9

class LogitechController
{
public:
	
	Joystick* m_joy;
	
	LogitechController(int number)
	{
		m_joy = new Joystick(number);
	}
	
	~LogitechController()
	{
		delete m_joy;
	}

	bool get1()
	{
		return m_joy->GetRawButton(1);
	}

	bool get2()
	{
		return m_joy->GetRawButton(2);
	}

	bool get3()
	{
		return m_joy->GetRawButton(3);
	}

	bool get4()
	{
		return m_joy->GetRawButton(4);
	}

	bool getRightTrigger1()
	{
		return m_joy->GetRawButton(6);
	}

	bool getRightTrigger2()
	{
		return m_joy->GetRawButton(8);
	}

	bool getLeftTrigger1()
	{
		return m_joy->GetRawButton(5);
	}

	bool getLeftTrigger2()
	{
		return m_joy->GetRawButton(7);
	}

	bool getL3()
	{
		return m_joy->GetRawButton(11);
	}

	bool getR3()
	{
		return m_joy->GetRawButton(12);
	}

	bool getStart()
	{
		return m_joy->GetRawButton(10);
	}

	bool getSelect()
	{
		return m_joy->GetRawButton(9);
	}

	float getjoyRightX()
	{
		return m_joy->GetRawAxis(3);
	}

	float getjoyRightY()
	{
		return m_joy->GetRawAxis(4);
	}

	float getjoyLeftX()
	{
		return m_joy->GetRawAxis(1);
	}

	float getjoyLeftY()
	{
		return m_joy->GetRawAxis(2);
	}
};
