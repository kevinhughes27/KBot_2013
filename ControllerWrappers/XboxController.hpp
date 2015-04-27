#include "Joystick.h"
#define XBOX_A 1
#define XBOX_B 2
#define XBOX_X 3
#define XBOX_Y 4
#define XBOX_LB 5
#define XBOX_RB 6
#define XBOX_TRIGGER 3
#define XBOX_LEFT_Y 2
#define XBOX_LEFT_X 1
#define XBOX_RIGHT_Y 5
#define XBOX_RIGHT_X 4
#define XBOX_START 8
#define XBOX_SELECT 7

class XboxController
{
public:

	Joystick* m_joy;

	XboxController(int number)
	{
		m_joy = new Joystick(number);
	}

	~XboxController()
	{
		delete m_joy;
	}

	bool getA()
	{
		return m_joy->GetRawButton(1);
	}

	bool getB()
	{
		return m_joy->GetRawButton(2);
	}

	bool getX()
	{
		return m_joy->GetRawButton(3);
	}

	bool getY()
	{
		return m_joy->GetRawButton(4);
	}

	bool getRB()
	{
		return m_joy->GetRawButton(6);
	}

	bool getLB()
	{
		return m_joy->GetRawButton(5);
	}

	bool getStart()
	{
		return m_joy->GetRawButton(8);
	}

	bool getSelect()
	{
		return m_joy->GetRawButton(7);
	}

	float getjoyRightX()
	{
		return m_joy->GetRawAxis(4);
	}

	float getjoyRightY()
	{
		return m_joy->GetRawAxis(5);
	}

	float getjoyLeftX()
	{
		return m_joy->GetRawAxis(1);
	}

	float getjoyLeftY()
	{
		return m_joy->GetRawAxis(2);
	}

	float getTrigger()
	{
		return m_joy->GetRawAxis(3);
	}

	float getDPADX()
	{
		return m_joy->GetRawAxis(6);
	}
};
