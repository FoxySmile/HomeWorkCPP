#pragma once
#include <iostream>
using namespace std;

class Lines
{
private:
	string* arr = nullptr;
	int countString = 0;
public:
	Lines();
	Lines(string str, char sep, char sep1, char sep2);
	void push_back(string str);
	int getCountString();
	string* getArr();
};

