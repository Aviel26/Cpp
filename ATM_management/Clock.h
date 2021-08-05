#pragma once
#include<iostream>
using namespace std;

class Clock
{
private:
	int hour;
	int minute;
	int second;

public:
	
	
	Clock(int myHours = 0, int myMinutes = 0, int mySeconds = 0) {// constructor to choice the hour-minute-second
		hour = myHours;
		minute = myMinutes;
		second = mySeconds;
		try {//if o,e of parameter is in wrong format
			if (myHours < 0 || myHours >= 24 || myMinutes < 0 || myMinutes >= 60 || mySeconds < 0 || myHours >= 60)
			{
				hour = 0;
				minute = 0;
				second = 0;

				throw "Wrong time format.";
			}
		}
		catch (const char* mssg) {
			cout << mssg;
		}

	}
	Clock(Clock&);//copy cstr
	
	void setHour(int);
	int getHour() { return hour; }
	void setMinute(int);
	int getMinute() { return minute; }
	void setSecond(int);
	int getSecond() { return second; }
	
	Clock& operator += (int); // to add seconcds to the time oclock
	friend ostream &operator<<(ostream&, Clock&);
	friend istream &operator>>(istream&, Clock&);
	
};

