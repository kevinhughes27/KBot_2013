#include "Joystick.h"
#define GUITAR_GREEN 1
#define GUITAR_RED 2
#define GUITAR_BLUE 3
#define GUITAR_YELLOW 4
#define GUITAR_ORANGE 5
#define GUITAR_BACK 7
#define GUITAR_START 8
#define GUITAR_WHAMMY 4
#define GUITAR_STAR_POWER 5
#define GUITAR_DPAD_X 6

class GuitarController
{
public:
	
	Joystick* m_joy;
	
	GuitarController(int number)
	{
		m_joy = new Joystick(number);
	}

	~GuitarController()
	{
		delete m_joy;
	}

	bool getGreen()
	{
		return m_joy->GetRawButton(1);
	}

	bool getRed()
	{
		return m_joy->GetRawButton(2);
	}

	bool getBlue()
	{
		return m_joy->GetRawButton(3);
	}

	bool getYellow()
	{
		return m_joy->GetRawButton(4);
	}

	bool getOrange()
	{
		return m_joy->GetRawButton(5);
	}

	bool getBack()
	{
		return m_joy->GetRawButton(7);
	}
	
   	 bool getStart()
	{
		return m_joy->GetRawButton(8);
	}

	float getWhammy()
	{
		return m_joy->GetRawAxis(4);
	}

	float getStarPower()
	{
		return m_joy->GetRawAxis(5);
	}

	float getFlipSwitch()
	{
		return m_joy->GetRawAxis(3);
	}

    float getDPADX()
	{
		return m_joy->GetRawAxis(6);
	}
};
