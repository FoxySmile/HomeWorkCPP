#include "Product.h"

Product::Product(string name)
{
	this->name = name;
}

void Product::getInfo()
{
	cout << type << " : " << name << endl;
}
