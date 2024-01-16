#include <iostream>

using namespace std;

class Car {
private:
	string model;
	string power;
	string color;
	int price;
public:
	Car() {}

	Car(string model, string power, string color, int price) {
		this->model = model;
		this->power = power;
		this->color = color;
		this->price = price;
	}

	void show() {
		cout << "Model: " << model << endl;
		cout << "Power: " << power << endl;
		cout << "Color: " << color << endl;
		cout << "Price: " << price << "\n\n";
	}

	void setModel(string model) { this->model = model; }
	void setPower(string power) { this->power = power; }
	void setColor(string color) { this->color = color; }
	void setPrice(int price) { this->price = price; }

	string getModel() { return model; }
	string getPower() { return power; }
	string getColor() { return color; }
	int getPrice() { return price; }
};

int main() {
	Car car1("Lada", "1.6", "Black", 800000);
	car1.show();

	Car car2("Mazda", "1.8", "Yellow", 1600000);
	car2.show();

	Car car3, car4;
	car3.setModel("Audi");
	car3.setPower("2.0");
	car3.setColor("Blue");
	car3.setPrice(1800000);

	cout << "Model: " << car3.getModel() << endl;
	cout << "Power: " << car3.getPower() << endl;
	cout << "Color: " << car3.getColor() << endl;
	cout << "Price: " << car3.getPrice() << "\n\n";

	car4.setModel("Infiniti");
	car4.setPower("2.5");
	car4.setColor("Green");
	car4.setPrice(2000000);

	cout << "Model: " << car4.getModel() << endl;
	cout << "Power: " << car4.getPower() << endl;
	cout << "Color: " << car4.getColor() << endl;
	cout << "Price: " << car4.getPrice() << "\n\n";
}