#include <iostream>
#include<map>
using namespace std;

class Singleton {
private:
    string name;
    static Singleton* instance;
    Singleton(string name) {
        this->name = name;
    }
public:
    static Singleton* getInstance(string name) {
        if (instance == nullptr) {
            instance = new Singleton(name);
        }
        return instance;
    }
    string getName() {
        return name;
    }
};
Singleton* Singleton::instance = nullptr;



class ConfigManager {
private:
    map<string, string> parameters;
    static ConfigManager* configManager;
    ConfigManager() {

    }
public:
    static ConfigManager* getInstance(string name) {
        if (configManager == nullptr) {
            configManager = new ConfigManager();
        }
        return configManager;
    }
    static ConfigManager* getInstance() {
        if (configManager == nullptr) {
            configManager = new ConfigManager();
        }
        return configManager;
    }
    void setParameters(string key, string value) {
        parameters[key] = value;
    }
    string getParameters(string key) {
        return parameters[key];
    }
};
ConfigManager* ConfigManager::configManager = nullptr;



int main()
{
    Singleton* odinochka1 = Singleton::getInstance("qwerty");
    cout << odinochka1->getName() << endl;
    Singleton* odinochka2 = Singleton::getInstance("qaz");
    cout << odinochka2->getName() << endl;
    cout << &(*odinochka1) << "\t" << &(*odinochka1) << endl;

    cout << endl;

    ConfigManager* mapOdinochka1 = ConfigManager::getInstance();
    mapOdinochka1->setParameters("q", "qwerty");
    cout << mapOdinochka1->getParameters("q") << endl;
    ConfigManager* mapOdinochka2 = ConfigManager::getInstance();
    cout << mapOdinochka2->getParameters("q") << endl;




}