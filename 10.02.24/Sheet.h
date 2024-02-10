#pragma once
#include <iostream>
#include "Record.h"
using namespace std;

class Sheet
{
private:
	Record** records;
	int countRecords = 0;

	int getIndexRecordById(int id);
public:
	void addRecord(Record record);
	void delRecord(int index);
	void showInfo();
};

