#include "Time.h"
Time::Time()
{
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}
Time::Time(int a = 0, int b = 0, int c = 0)
{
	this->hours = a;
	this->minutes = b;
	this->seconds = c;
}
Time::~Time()
{
}
Time::Time(const Time& x)
{
	this->hours = x.hours;
	this->minutes = x.minutes;
	this->seconds = x.seconds;
}
Time operator++(Time& ref)
{
	ref.seconds++;
	if (ref.seconds == 60) {
		ref.seconds = 0;
		ref.minutes++;
	}
	if (ref.minutes == 60)
	{
		ref.minutes = 0;
		ref.hours++;
	}
	return ref;
}
Time operator--(Time& ref)
{
	ref.seconds--;
	if (ref.seconds == -1) {
		if (ref.minutes == 0 && ref.hours == 0)
		{
			ref.seconds = 0;
			return ref;
		}
		ref.seconds = 59;
		ref.minutes--;
	}
	if (ref.minutes == -1)
	{
		ref.minutes = 59;
		ref.hours--;
	}
	if (ref.hours)
		return ref;
}
Time& Time::operator++(int)
{
	this->seconds++;
	if (this->seconds == 60) {
		this->seconds = 0;
		this->minutes++;
	}
	if (this->minutes == 60)
	{
		this->minutes = 0;
		this->hours++;
	}
		return *this;
}
Time& Time::operator--(int)
{
	this->seconds--;
	if (this->seconds == -1) {
		if (this->minutes == 0 && this->hours == 0)
		{
			this->seconds = 0;
			return *this;
		}
		this->seconds = 59;
		this->minutes--;
	}
	if (this->minutes == -1)
	{
		this->minutes = 59;
		this->hours--;
	}
	if (this->hours)
		return *this;
}
