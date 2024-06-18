#include <iostream>
#include <vector>

using namespace std;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(string magazineIssue) = 0;
};

class Subject {
public:
    virtual ~Subject() = default;
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

class MagazinePublisher : public Subject {
private:
    vector<Observer*> observers;
    string lastIssue;
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() {
        for (auto observer : observers) {
            observer->update(lastIssue);
        }
    }

    void releseNewIssue(string issue) {
        lastIssue = issue;
        notifyObservers();
    }
};

class Subscriber : public Observer {
private:
    string name;
public:
    Subscriber(string name) :name(name){}

    void update(string magazineIssue) {
        cout << "Subscriber " << name << " received new magazine issue: " << magazineIssue << endl;
    }
};

int main()
{
    Subscriber* s1 = new Subscriber("Tom");
    Subscriber* s2 = new Subscriber("Bob");
    Subscriber* s3 = new Subscriber("Andrew");
    Subscriber* s4 = new Subscriber("Bill");
    Subscriber* s5 = new Subscriber("Ben");

    MagazinePublisher m1;

    m1.addObserver(s1);
    m1.addObserver(s2);
    m1.addObserver(s3);

    m1.addObserver(s5);
    m1.removeObserver(s5);

    m1.releseNewIssue("NEWS");
}