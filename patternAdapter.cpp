#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car {
public:
	string category;
	string color;
	int seats;
	int volume;
	void carInfo() {
		cout << "Category: " << category << ", color: " << color << ", seats: " << seats << ", volume: " << volume;
	}
	Car(string category, string color, int seats, int volume) :category(category), color(color), seats(seats), volume(volume){}
};

class CarAdapter {
	Car* car;
public:
	CarAdapter(string parameters) {
		int symbol = 0;
		string category = "";
		string color = "";
		string buf = "";
		int seats;
		int volume;
		while (parameters[symbol] != ';') {
			category += parameters[symbol++];
		}
		symbol++;
		while (parameters[symbol] != ';') {
			color += parameters[symbol++];
		}
		symbol++;
		while (parameters[symbol] != ';') {
			buf += parameters[symbol++];
		}
		symbol++;
		seats = stoi(buf);
		buf = "";
		while (parameters[symbol] != '\0') {
			buf += parameters[symbol++];
		}
		volume = stoi(buf);
		this->car = new Car(category, color, seats, volume);
	}
	Car getCar() {
		return *car;
	}
};




class Parking {
private:
	vector<Car> cars;
public:
	void addCar(Car car) {
		cars.push_back(car);
	}
	void info() {
		for (int i = 0; i < cars.size(); i++) {
			cars[i].carInfo();
		}
	}
};







int main()
{
	Parking park;
	CarAdapter stringToCar("Mercedes;White;4;150");
	park.addCar(stringToCar.getCar());
	park.info();
}