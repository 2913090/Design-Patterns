#include <iostream>
using namespace std;
class Sword {
public:
    virtual void atack() = 0;
    virtual ~Sword() = default;
};

class Katana :public Sword {
public:
    void atack() override {
        cout << "Swinging the Katana" << endl;
    }
};

class Broadsword :public Sword {
public:
    void atack() override {
        cout << "Swinging the Broadsword" << endl;
    }
};

class Ulfbert :public Sword {
public:
    void atack() override {
        cout << "Swinging the Ulfbert" << endl;
    }
};

class Blacksmith {
public:
    virtual Sword* createSword() = 0;
    virtual ~Blacksmith() = default;
};

class JapaneseBlacksmith :public Blacksmith {
public:
    Sword* createSword() {
        Katana* katana = new Katana();
        return katana;
    }
};

class EuropeanBlacksmith :public Blacksmith {
public:
    Sword* createSword() {
        Broadsword* broadsword = new Broadsword();
        return broadsword;
    }
};

class SkandinavianBlacksmith :public Blacksmith {
public:
    Sword* createSword() {
        Ulfbert* ulfbert = new Ulfbert();
        return ulfbert;
    }
};

int main()
{
    string country = "Skandinavia";
    Blacksmith* someBlacksmith = nullptr;
    if (country == "Japan") {
        someBlacksmith = new JapaneseBlacksmith();
    }
    else if (country == "Europe") {
        someBlacksmith = new EuropeanBlacksmith();
    }
    else if (country == "Skandinavia") {
        someBlacksmith = new SkandinavianBlacksmith();
    }
    if (someBlacksmith != nullptr) {
        Sword* someSword = someBlacksmith->createSword();
        someSword->atack();
    }
    
}