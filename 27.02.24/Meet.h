#pragma once
#include <iostream>
#include "Product.h"
using namespace std;

class Meet : public Product
{
private:
	static string img;
public:
	Meet(string name);
};

