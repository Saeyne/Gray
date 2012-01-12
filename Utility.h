#ifndef UTILITY_H
#define UTILITY_H

#include <SFML\Graphics.hpp>
#include <fstream>
#include <sstream>

namespace base
{
	class Utility;	//class used for misc stuff like screenshots
	class Logger;	//a class used to create a log file during the game
	class Timer;	//timer class that inherits a clock

	class Utility
	{
	private:
		sf::RenderWindow* windowRef;					//a reference to our window
		sf::Image ScreenShot;							//an image to store a screenshot
	public:
		Utility() { }
		~Utility();
		void Initialize(sf::RenderWindow* window);		//gets our window reference
		void TakeScreenShot();							//creates a screenshot with a timestamp filename
	};

	class Logger
	{
	private:
		time_t rawTime;
		struct tm *TI;
		std::ofstream ofstream;				//a stream used for file operations
		std::stringstream sstream;			//a stream used for string manipulations
		void Reset();
	public:
		Logger() { }
		~Logger();
		void Initialize(char* filename);	//opens our file stream
		void Write(char* text);				//writes the chars to our file
		void Write(std::string text);		//writes the string to our file
		std::string Timestamp();			//returns a timestamp: 'MM/DD/YYYY Hour:Min:Sec: '
		std::string TimestampMDY();			//returns a timestamp: 'MM/DD/YYYY: '
		std::string TimestampHMS();			//returns a timestamp: 'Hour:Min:Sec: '
		std::string TimestampSS();			//returns a timestamp: 'Screenshots/Sept29/53700.png'
		std::string GetDay();				//returns a string representation of the day
		std::string GetMonth();				//returns a string representation of the month
	};

	class Timer : public sf::Clock
	{
	private:
		float endTime;						//the duration of the timer
	public:
		Timer() { }
		Timer(float milliseconds);			//creates a timer
		~Timer() { }
		bool Complete();					//returns if the timer is complete
		float TimeRemaining();				//returns the time remaining
		void SetTime(float milliseconds);
	};

	extern Logger	gLogger;		//a global Logger
	extern Utility	gUtility;		//a global Utility
}

#endif