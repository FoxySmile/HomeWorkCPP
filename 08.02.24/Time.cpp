#include "Time.h"


Time::Time(Lines line)
{
	string* arr = line.getArr();
	year = arr[0];
	month = arr[1];
	day = arr[2];
	hour = arr[3];
	minutes = arr[4];
	seconds = arr[5];
}

string Time::toString()
{
	return "Date: " + day + "." + month + "." + year + "\nTime: " + hour + ":" + minutes + ":" + seconds;
}
