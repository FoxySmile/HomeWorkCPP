#pragma once
#include <iostream>
using namespace std;

class Singleton
{
private:
	string name;
	static Singleton* singl;
	Singleton(string name);
public:
	static Singleton* getSingl(string name);
	void showInfo();
};

