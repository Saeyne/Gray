#include "Utility.h"

#include <iostream>
#include <sstream>
#include <boost\filesystem.hpp>

namespace base
{
	Logger gLogger;

	void Logger::Initialize(char* filename)
	{
		ofstream.open(boost::filesystem::current_path().string() + "\\" + filename);
		Write("Log successfully created " + TimestampMDY());
	}

	void Logger::Write(char* text)
	{
		ofstream << TimestampHMS() << text << std::endl;
	}

	void Logger::Write(std::string text)
	{
		ofstream << TimestampHMS() << text << std::endl;
	}

	Logger::~Logger()
	{
		Write("Log successfully ended");
		ofstream.close();
	}

	void Logger::Reset()
	{
		time(&rawTime);
		TI = localtime(&rawTime);
		sstream.str("");
	}

	std::string Logger::Timestamp()
	{
		//get the time data, and clear the stream
		Reset();		

		//format: 'MM/DD/YYYY Hour:Min:Sec: '
		sstream << TI->tm_mon << "/" << TI->tm_mday << "/" << TI->tm_hour<< " ";
		sstream << TI->tm_hour << ":" << TI->tm_min << ":" << TI->tm_sec << ": ";

		return sstream.str();
	}

	std::string Logger::TimestampMDY()
	{		
		//get the time data, and clear the stream
		Reset();	

		//format: 'MM/DD/YYYY: '
		sstream << TI->tm_mon << "/" << TI->tm_mday << "/" << TI->tm_hour << ": ";

		return sstream.str();
	}

	std::string Logger::TimestampHMS()
	{		
		//get the time data, and clear the stream
		Reset();	

		//format: 'Hour:Min:Sec: '
		sstream << TI->tm_hour << ":" << TI->tm_min << ":" << TI->tm_sec << ": ";

		return sstream.str();
	}

	std::string Logger::TimestampSS()
	{
		//get the time data, and clear the stream
		Reset();

		//format: "Screenshots/Sept29/53700.png"
		sstream << "Screenshots\\" << GetMonth() << TI->tm_mday << "\\" << TI->tm_hour << TI->tm_min << TI->tm_sec << ".png";

		return sstream.str();
	}

	std::string Logger::GetDay()
	{
		switch (TI->tm_wday)
		{
			case 0: return "Sunday";
			case 1: return "Monday";
			case 2: return "Tuesday";
			case 3: return "Wednesday";
			case 4: return "Thursday";
			case 5: return "Friday";
			case 6: return "Saturday";
			default: return "ERROR-Logger::GetDay()";
		}
	}

	std::string Logger::GetMonth()
	{
		switch (TI->tm_mon)
		{
			case 0: return "January";
			case 1: return "February";
			case 2: return "March";
			case 3: return "April";
			case 4: return "May";
			case 5: return "June";
			case 6: return "July";
			case 7: return "August";
			case 8: return "September";
			case 9: return "October";
			case 10: return "November";
			case 11: return "December";
			default: return "ERROR-Logger::GetMonth()";
		}
	}
}