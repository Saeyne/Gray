#include "Utility.h"

#include <Sfml\Graphics.hpp>

#include <iostream>
#include <boost\filesystem.hpp>

namespace base
{
	Utility gUtility;

	void Utility::Initialize(sf::RenderWindow* window)
	{
		windowRef = window;
	}

	void Utility::TakeScreenShot()
	{
		gLogger.Write(gLogger.TimestampSS());
		ScreenShot = windowRef->Capture();
		ScreenShot.SaveToFile(gLogger.TimestampSS());
	}

	Utility::~Utility()
	{

	}

}