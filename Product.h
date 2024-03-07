#pragma once
#include <iostream>
using namespace std;

class Product
{
protected:
	string name;
	string type;
public:
	Product(string name);
	void getInfo();
};

