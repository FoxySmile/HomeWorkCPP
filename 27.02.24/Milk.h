#pragma once
#include <iostream>
#include "Product.h"
using namespace std;

class Milk : public Product
{
private:
	static string img;
public:
	Milk(string name);
};

