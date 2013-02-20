#include "Joystick.h"


class LogitechF310
{
public:
	
	Joystick* m_joy;
	
	LogitechF310(int number)
	{
		m_joy = new Joystick(number);
	}

	~LogitechF310()
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
