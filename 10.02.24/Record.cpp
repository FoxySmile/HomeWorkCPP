#include "Record.h"

Record::Record()
{
	uniqId = id++;
}

Record::Record(string text, string date) : Record()
{
	this->text = text;
	this->date = date;
}

int Record::getId()
{
	return uniqId;
}

void Record::showInfo()
{
	cout << "Text: " << text << " - " << date << endl;
}


int Record::id = 0;
