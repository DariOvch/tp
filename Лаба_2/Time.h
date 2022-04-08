#pragma once
#include<iostream>
#include<locale>
class Time
{
public:
	int hours;
	int minutes;
	int seconds;
	Time();
	explicit Time(int a, int b, int c);
	Time(const Time& x);
	~Time();
	//Префексиная
	friend Time operator++(Time& ref);
	friend Time operator--(Time& ref);
	//Постфиксная
	Time& operator--(int);
	Time& operator++(int);
};
