#include <iostream>
#include "Record.h"
#include "Sheet.h"
#include "Journal.h"

using namespace std;

int main() {
	Record rec("Hello World 0", "20.02.24");
	Record rec1("Hello World 1", "20.02.24");
	Record rec2("Hello World 2", "20.02.24");
	Record rec3("Hello World 3", "20.02.24");
	Record rec4("Hello World 4", "20.02.24");

	Sheet sh;
	sh.addRecord(rec);
	sh.addRecord(rec1);
	sh.addRecord(rec2);
	sh.addRecord(rec3);
	sh.addRecord(rec4);

	Journal journal;
	journal.addSheet(sh);
	journal.showSheet(0);
}

/*���� ������, ����� � ������.

������ �������� �����.
���������� ��������� ������� ������ � �������

����� �������� ������.
������ �� ����� ��������� ���� �������.

������ �������� id ����� � ����(�����)

�������� ��������� ������� ���������:
������� ��� ������ ������� �� ��������� �����(index)

��������������� �������.*/