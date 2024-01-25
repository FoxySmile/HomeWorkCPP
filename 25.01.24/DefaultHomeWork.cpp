#include <iostream>
#include <string>
using namespace std;

class Converter {
private:
	float money;
	float convertedMoney;
	string inputMoney;
	string outputMoney;
	
public:
	Converter(float money, string inputMoney, string outputMoney) {
		this->money = money;
		this->inputMoney = inputMoney;
		this->outputMoney = outputMoney;
	}

	void convertMoney() {
		if (inputMoney == "RUB") {
			if (outputMoney == "DOL") {
				convertedMoney = money * 0.011;
			}
			else if (outputMoney == "EUR") {
				convertedMoney = money * 0.01;
			}
			else if (inputMoney == "RUB") {
				convertedMoney = money;
			}
			else {
				cout << "ERROR" << endl;
				return;
			}
		}
		else if (inputMoney == "DOL") {
			if (outputMoney == "RUB") {
				convertedMoney = money * 88.7;
			}
			else if (outputMoney == "EUR") {
				convertedMoney = money * 0.92;
			}
			else if (outputMoney == "DOL") {
				convertedMoney = money;
			}
			else {
				cout << "ERROR" << endl;
				return;
			}
		}
		else if (inputMoney == "EUR") {
			if (outputMoney == "DOL") {
				convertedMoney = money * 1.08;
			}
			else if (outputMoney == "RUB") {
				convertedMoney = money * 96.13;
			}
			else if (inputMoney == "EUR") {
				convertedMoney = money;
			}
			else {
				cout << "ERROR" << endl;
				return;
			}
		}
		else {
			cout << "ERROR" << endl;
			return;
		}
	}

	string toString() {
		return inputMoney + ": " + to_string(money) + " -> " + outputMoney + ": " + to_string(convertedMoney);
	}
};

int main() {
	Converter val(12, "EUR", "RUB");
	val.convertMoney();
	cout << val.toString() << endl;
}