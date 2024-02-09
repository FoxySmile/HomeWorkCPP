#pragma once
#include <iostream>
#include "Lines.h"
#include <string>


class Time
{
private:
	string year;
	string month;
	string day;
	string hour;
	string minutes;
	string seconds;
public:
	Time(Lines line);
	string toString();
};
/*2020-05-12T23:50:21.817Z*/

