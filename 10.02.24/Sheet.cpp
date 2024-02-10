#include "Sheet.h"

int Sheet::getIndexRecordById(int id)
{
	for (int i = 0; i < countRecords; i++) {
		if (records[i]->getId() == id) {
			return i;
		}
	}
	return -1;
}

void Sheet::addRecord(Record record)
{
	Record** buf = new Record * [countRecords + 1];
	for (int i = 0; i < countRecords; i++) {
		buf[i] = records[i];
	}
	buf[countRecords++] = new Record (record);
	delete[]records;
	records = buf;
}

void Sheet::delRecord(int id)
{
	if (countRecords == 0) {
		return;
	}
	int index = getIndexRecordById(id);
	if (index == -1) {
		return;
	}
	Record** buf = new Record * [countRecords - 1];
	for (int i = 0; i < index; i++) {
		buf[i] = records[i];
	}
	for (int i = index + 1; i < countRecords; i++) {
		buf[i - 1] = records[i];
	}
	delete[]records;
	records = buf;
	countRecords--;
}

void Sheet::showInfo()
{
	for (int i = 0; i < countRecords; i++) {
		records[i]->showInfo();
	}
}
