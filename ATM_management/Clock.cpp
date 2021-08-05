#include"Clock.h"
#include <iostream>

using namespace std;



Clock::Clock(Clock &copyClock) {

	hour = copyClock.hour;
	minute = copyClock.minute;
	second = copyClock.second;
}
void Clock::setHour(int myHour)//set hour
{
	try {
		if (myHour < 0)
		{
			hour = 0;
			throw "Invalid time - negative number of hours."; // negative
		}
		if (myHour > 23)
		{
			hour = 0;
			throw "Invalid time - more than 24 hours."; // more than 24
		}
		hour = myHour;
	}
	catch (const char*str)
	{
		cout << str;
	}
}
void Clock::setMinute(int myMinutes)//set minute
{
	try {
		if (myMinutes < 0)
		{
			minute = 0;
			throw "Invalid time - negative number of minutes.";
		}
		if (myMinutes > 59)
		{
			minute = 0;
			throw "Invalid time - more than 59 minutes."; // in hour the max is 59 min
		}
		minute = myMinutes;
	}
	catch (const char*str)
	{
		cout << str;
	}
}
void Clock::setSecond(int s1)//set seconds
{
	try {
		if (s1 < 0)
		{
			second = 0;
			throw "Invalid time - negative number of seconds.";
		}
		if (s1 > 59)
		{
			second = 0;
			throw "Invalid time - more than 59 seconds."; // in minute the max is 59 secons
		}
		second = s1;
	}
	catch (const char*str)
	{
		cout << str;
	}
}
Clock& Clock::operator +=(int addSeconds) {

	while (addSeconds > 59)
	{
		if (minute == 59)
		{
			hour = (hour + 1) % 24; // to limit the max hour at 24
			minute = 0;
		}
		else
		{
			minute++;
		}
		addSeconds -= 60;
	}
	second += addSeconds;
	if (second > 59)
	{
		second -= 60;
		minute++;
		if (minute > 59)
		{
			minute = 0;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}
	   	

ostream& operator<< (ostream&os, Clock &myClock){
	
	if (myClock.hour>= 10)
	{
		os << myClock.hour << ":";
	}
	else
	{
		os << "0" << myClock.getHour()<<":"; // to display the good format with two character in all the cases HH/MM/SS
	}
	if (myClock.getMinute() >= 10)
	{
		os << myClock.getMinute()<<":";
	}
	else
	{
		os << "0" << myClock.getMinute()<<":";
	}
	if (myClock.getSecond() >= 10)
	{
		os << myClock.getSecond();
	}
	else
	{
		os << "0" << myClock.getSecond();
	}
	return os;
}

istream&operator>>(istream &is, Clock &myClock) {
	char slash;                                     //slash to put the slash bar
	
	is >>myClock.hour>> slash >> myClock.minute >> slash >> myClock.second;
	return is;
}



