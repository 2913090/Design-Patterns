#include <iostream>

using namespace std;

class Coffee {
public:
	void prepareRecipe() {
		boilWater();
		brewCoffee();
		pourInCup();
		addCondiments();
	}
protected:
	void boilWater() {
		cout << "Boiling water" << endl;
	}

	void pourInCup() {
		cout << "Pour in cup" << endl;
	}

	virtual void brewCoffee() = 0;

	virtual void addCondiments() = 0;
};

class BlackCoffee : public Coffee {
protected:
	void brewCoffee() {
		cout << "Dripping coffee through filter" << endl;
	}

	void addCondiments() {
		cout << "No condiments" << endl;
	}
};

class LatteCoffee : public Coffee {
protected:
	void brewCoffee() {
		cout << "Making espresso" << endl;
	}

	void addCondiments() {
		cout << "Adding steamed milk" << endl;
	}
};





int main()
{
	Coffee* blackCoffee = new BlackCoffee();
	Coffee* latteCoffee = new LatteCoffee();

	blackCoffee->prepareRecipe();
	cout << endl;
	latteCoffee->prepareRecipe();
}