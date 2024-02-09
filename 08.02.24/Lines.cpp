#include "Lines.h"

Lines::Lines()
{
}

Lines::Lines(string str, char sep, char sep1, char sep2)
{
	string buf = "";
	for (int i = 0; i < str[i] != '\0'; i++) {
		if (str[i] == sep || str[i] == sep1 || str[i] == sep2) {
			push_back(buf);
			buf = "";
			continue;
		}
		else if (str[i] == '.') {
			break;
		}
		buf += str[i];
	}
	push_back(buf);
}

void Lines::push_back(string str)
{
	string* buf = new string[countString + 1];
	for (int i = 0; i < countString; i++) {
		buf[i] = arr[i];
	}
	buf[countString++] = str;
	delete[]arr;
	arr = buf;
}

int Lines::getCountString()
{
	return countString;
}

string* Lines::getArr()
{
	return arr;
}
