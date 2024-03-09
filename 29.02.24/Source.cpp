#include <iostream>
#include "Singleton.h"
#include "Builder.h"

using namespace std;

int main() {
	/*Singleton* singl1 = Singleton::getSingl("Vova");
	singl1->showInfo();
	Singleton* singl2 = Singleton::getSingl("Vova");
	singl1->showInfo();*/

	StudentBuilder stBuild;
	PasportBuilder pasBuild;

	stBuild.setFirstName("Oleg");
	stBuild.setLastName("Vovkin");
	stBuild.setYear("21");
	stBuild.getResult().showInfo();

	pasBuild.setFirstName("Oleg");
	pasBuild.setLastName("Vovkin");
	pasBuild.setYear("21");
	pasBuild.getResult().showPasport();
}