#include "Joystick.h"
#define JOY_1 1
#define JOY_2 2
#define JOY_3 3
#define JOY_4 4
#define JOY_5 5
#define JOY_6 6
#define JOY_7 7
#define JOY_8 8
#define JOY_9 9
#define JOY_10 10
#define JOY_11 11
#define JOY_Y 2
#define JOY_X 1
#define JOY_PLUSMINUS 3

class Attack3Joystick
{
public:

	Joystick* m_joy;

	Attack3Joystick(int number)
	{
		m_joy = new Joystick(number);
	}

	~Attack3Joystick()
	{
		delete m_joy;
	}

	bool getTrigger()
	{
		return m_joy->GetRawButton(1);
	}

	bool getButton2()
	{
		return m_joy->GetRawButton(2);
	}

	bool getButton3()
	{
		return m_joy->GetRawButton(3);
	}

	bool getButton4()
	{
		return m_joy->GetRawButton(4);
	}

	bool getButton5()
	{
		return m_joy->GetRawButton(5);
	}

	bool getButton6()
	{
		return m_joy->GetRawButton(6);
	}

	bool getButton7()
	{
		return m_joy->GetRawButton(7);
	}

	bool getButton8()
	{
		return m_joy->GetRawButton(8);
	}

	bool getButton9()
	{
		return m_joy->GetRawButton(9);
	}

	bool getButton10()
	{
		return m_joy->GetRawButton(10);
	}

	bool getButton11()
	{
		return m_joy->GetRawButton(11);
	}

	float getY()
	{
		return m_joy->GetRawAxis(2);
	}

	float getX()
	{
		return m_joy->GetRawAxis(1);
	}

	float getPlusMinus()
	{
		return m_joy->GetRawAxis(3);
	}
};
