#include <iostream>

using namespace std;

class Car {
private:
	string model;
	double power;
	string color;
	int price;
public:
	Car(string model, double power, string color, int price) {
		this->model = model;
		this->power = power;
		this->color = color;
		this->price = price;
	}

	void show() {
		cout << "Model: " << model << endl;
		cout << "Power: " << power << endl;
		cout << "Color: " << color << endl;
		cout << "Prise: " << price << endl << endl;
	}
};

class Car1 {
private:
	string model;
	double power;
	string color;
	int price;
public:
	void setModel(string model) {
		this->model = model;
	}
	void setPower(double power) {
		this->power = power;
	}
	void setColor(string color) {
		this->color = color;
	}
	void setPrise(int price) {
		this->price = price;
	}

	string getModel() { return model; }
	double getPower() { return power; }
	string getColor() { return color; }
	int getPrise() { return price; }
};

int main() {
	Car car1("LADA", 1.6, "Black", 800000);
	car1.show();
	Car car2("Mazda", 1.8, "Yellow", 1600000);
	car2.show();

	Car1 car3;
	car3.setModel("AUDI");
	car3.setPower(2.0);
	car3.setColor("Green");
	car3.setPrise(1800000);
	cout << "Model: " << car3.getModel() << endl;
	cout << "Power: " << car3.getPower() << endl;
	cout << "Color: " << car3.getColor() << endl;
	cout << "Prise: " << car3.getPrise() << endl << endl;

	Car1 car4;
	car4.setModel("Infiniti");
	car4.setPower(2.5);
	car4.setColor("Blue");
	car4.setPrise(2000000);
	cout << "Model: " << car4.getModel() << endl;
	cout << "Power: " << car4.getPower() << endl;
	cout << "Color: " << car4.getColor() << endl;
	cout << "Prise: " << car4.getPrise() << endl << endl;

}


/*
get - вывод
set - ввод

Необходимо создать класс автомобиль.
У авто есть цена, цвет, модель, объем двигателя.
Создать конструктор со всем параметрами, все методы аксессоры и мутаторы.
Реализовать метод show() выводящий всю информацию о машине.
Сделать 4 разные машины. Проверить все методы.*/