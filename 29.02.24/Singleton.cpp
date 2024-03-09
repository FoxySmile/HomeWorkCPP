#include "Singleton.h"

Singleton::Singleton(string name)
{
	this->name = name;
}

Singleton* Singleton::getSingl(string name)
{
	if (singl == nullptr) {
		singl = new Singleton(name);
	}
	return singl;
}

void Singleton::showInfo()
{
	cout << this << " : " << name << endl;
}

Singleton* Singleton::singl = nullptr;
