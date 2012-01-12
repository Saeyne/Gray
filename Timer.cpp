#include "Utility.h"

namespace base
{
	Timer::Timer(float time)
		: sf::Clock()
	{
		endTime = time;
	}

	bool Timer::Complete()
	{
		return (GetElapsedTime() > endTime);
	}

	float Timer::TimeRemaining()
	{
		if (Complete())
			return 0;
		else
			return (endTime - GetElapsedTime());
	}

	void Timer::SetTime(float milliseconds)
	{
		endTime = milliseconds;
	}
}