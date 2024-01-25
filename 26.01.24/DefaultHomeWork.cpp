#include <iostream>
#include <string>
#define random(a,b) (rand() % (b - a + 1) + a)
using namespace std;

class Car {
private:
	string model = "no model";
	string power = "no power";
	string color = "no color";
	int price = 0;
    static int number;
    int uniqNumber;
public:
    Car() {}

	Car(string model, string power, string color, int price) {
        uniqNumber = number++;
		this->model = model;
		this->power = power;
		this->color = color;
		this->price = price;
	} 

	string toString() {
		return	"Model: " + model + "\nPower: " + power + "\nColor:" + color
			+ "\nPrice: " + to_string(price) + "\nNumber: " + to_string(uniqNumber);
	}
};

class Garage {
private:
    Car* cars = nullptr;
    int countOfCars = 0;
public:
    void addCar(Car newCar) {
        Car* buf = new Car[countOfCars + 1];
        for (int i = 0; i < countOfCars; i++) {
            buf[i] = cars[i];
        }
        buf[countOfCars++] = newCar;
        delete[]cars;
        cars = buf;
    }

    void removeCarByNumber(int index) {
        if (countOfCars < 0) {
            return;
        }
        Car* buf = new Car[countOfCars - 1];
        for (int i = 0; i < index; i++) {
            buf[i] = cars[i];
        }
        for (int i = index + 1; i < countOfCars; i++) {
            buf[i - 1] = cars[i];
        }
        delete[]cars;
        cars = buf;
        countOfCars--;
    }

    void showAll() {
        for (int i = 0; i < countOfCars; i++) {
            cout << cars->toString() << endl << endl;
        }
    }
};

int Car::number = 100;

int main() {
	srand(time(NULL));
	Car car1("LADA", "1.6", "Black", 180000);
	Car car2("LADA", "1.8", "Yellow", 170000);
	Car car3("LADA", "1.3", "Blue", 160000);
	Car car4("LADA", "1.5", "Green", 140000);
	Car car5("LADA", "2.0", "Red", 190000);

    Garage garage1;
    garage1.addCar(car1);
    garage1.addCar(car2);
    garage1.addCar(car3);
    garage1.addCar(car4);
    garage1.addCar(car5);
    garage1.showAll();
}

/*Дополнить программу с машинами следующими пунктами.
Реализовать класс гараж. В который можно добавлять машины и убирать их.
У машины должен быть уникальный идентификатор 
(номер машины(достаточно генерировать трехзначное число уникальное))*/