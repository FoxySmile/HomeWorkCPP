#include <iostream>
#include <Windows.h>
#include "FileReader.h"
#include "Time.h"
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*	
	FileReader fr;
	Lines lines = fr.read("DateTime.xml");
	string* arr = lines.getArr();
	for (int i = 0; i < lines.getCountString(); i++) {
		cout << arr[i] << endl;
	}
	*/

	FileReader fr;
	Lines lines = fr.read("DateTime.xml");
	Lines line(lines.getArr()[0], '-', 'T', ':');
	Time t(line);
	cout << t.toString() << endl;
}