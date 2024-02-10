#include "Journal.h"

void Journal::addSheet(Sheet sheet)
{
	Sheet** buf = new Sheet * [countSheets + 1];
	for (int i = 0; i < countSheets; i++) {
		buf[i] = sheets[i];
	}
	buf[countSheets++] = new Sheet(sheet);
	delete[]sheets;
	sheets = buf;
}

void Journal::showSheet(int index)
{
	sheets[index]->showInfo();
}
