#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    int wheels;
    string color;
    string engine;
    int seats;
    bool gps;
    void show() {
        cout << "Wheels: " << wheels << endl;
        cout << "Color: " << color << endl;
        cout << "Engine: " << engine << endl;
        cout << "Seats: " << seats << endl;
        cout << "GPS: " << gps << endl;
    }

};

class CarBuilder {
private:
    Car* result;
public:
    CarBuilder() {

    }
    ~CarBuilder() {
        delete result;
    }
    CarBuilder& reset() {
        this->result = new Car();
        return *this;
    }
    CarBuilder& setWheels(int count) {
        this->result->wheels = count;
        return *this;
    }
    CarBuilder& setColor(string color) {
        this->result->color = color;
        return *this;
    }
    CarBuilder& setEngine(string engine) {
        this->result->engine = engine;
        return *this;
    }
    CarBuilder& setSeats(int seats) {
        this->result->seats = seats;
        return *this;
    }
    CarBuilder& setGPS(bool gps) {
        this->result->gps = gps;
        return *this;
    }
    Car* getResult() {
        return this->result;
    }
};

class Director {
private:
    CarBuilder car;
public:
    Car* constructSportCar() {
        car.reset().setColor("red").setEngine("sport engine").setGPS(true).setSeats(2).setWheels(4);
        return car.getResult();
    }
    Car* constructMuscleCar() {
        this->car = car.reset().setColor("blue").setEngine("muscle engine").setGPS(true).setSeats(4).setWheels(4);
        return car.getResult();
    }
    Car* constructElectroCar() {
        this->car = car.reset().setColor("white").setEngine("electro engine").setGPS(true).setSeats(5).setWheels(4);
        return car.getResult();
    }
};

int main()
{
    CarBuilder carBuilder;
    carBuilder.reset();
    carBuilder.setColor("white").setGPS(true).setWheels(4);
    carBuilder.getResult()->show();
    cout << endl;
    Director director;
    Car car1 = *director.constructElectroCar();
    car1.show();
}