#pragma once
#include <iostream>
#include "Product.h"
using namespace std;

class Fish : public Product
{
private:
	static string img;
public:
	Fish(string name);
};

