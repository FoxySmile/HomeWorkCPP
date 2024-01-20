#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Fraction {
private:
	int num;
	int denom;
	int NOD(int x, int y) {
		if (y == 0) { return x; }
		return NOD(y, x % y);
	}
public:
	Fraction(int num, int denom) {
		this->num = num;
		this->denom = denom;
	}

	void mult(int x) { num *= x; }
	void div(int x) { denom *= x; }
	void sum(int x) { num += (x * denom); }
	void sub(int x) { num -= (x * denom); }
	
	int broadcastFraction(){
		return NOD(num, denom);
	}

	void reductFraction(int x){
		num /= x;
		denom /= x;
	}

	string showFraction() {
		return to_string(num) + "/" + to_string(denom);
	}
};

int main() {
	setlocale(LC_ALL, "RU");
	int num, denom, x;
	char ch;

	while (true) {
		cout << "������� ���������: ";
		cin >> num;
		cout << "������� �����������: ";
		cin >> denom;
		cout << endl;

		Fraction f(num, denom);
		f.reductFraction(f.broadcastFraction());
		cout << "������� �����: " << f.showFraction() << endl;

		cout << R"(
1)	��������� ����� � �����
2)	������ ����� �� �����
3)	�������� ����� �� �����
4)	������ ����� �� �����

N)	����������� ������

�������� ����������� ��������: )";
		ch = _getch();

		if (ch == '1') {
			system("cls");
			cout << "������� ���������: ";
			cin >> x;
			f.sum(x);
			cout << "���������� �����: " << f.showFraction() << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (ch == '2') {
			system("cls");
			cout << "������� ����������: ";
			cin >> x;
			f.sub(x);
			cout << "���������� �����: " << f.showFraction() << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (ch == '3') {
			system("cls");
			cout << "������� ���������: ";
			cin >> x;
			f.mult(x);
			cout << "���������� �����: " << f.showFraction() << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (ch == '4') {
			system("cls");
			cout << "������� ��������: ";
			cin >> x;
			f.div(x);
			cout << "���������� �����: " << f.showFraction() << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (ch == 'n' || ch == 'N') {
			break;
		}
	}
}