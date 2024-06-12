#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class ServiceInterface {
public:
    virtual string downloadVideoByID(int id) = 0;
};

class Service : public ServiceInterface {
private:
    string* files = new string[10];
    string removePoint(string str) {
        while (str[0] >= 48 && str[0] <= 57) {
            str = str.substr(1);
        }
        str = str.substr(2);
        return str;
    }
public:
    vector<string> download() {
        vector<string> strings;
        ifstream in("text.txt");
        string line = "";
        if (in.is_open()) {
            while (getline(in, line)) {
                strings.push_back(line);
            }
        }
        in.close();
        for (int i = 0; i < strings.size(); i++) {
            strings[i] = removePoint(strings[i]);
        }
        
        return strings;
    }

    string downloadVideoByID(int id) {
        cout << "Service handling request" << endl;
        ifstream in("text.txt");
        string line = "";
        string myId = to_string(id);
        myId += ". ";
        bool flag = false;
        if (in.is_open()) {
            while (getline(in, line)) {
                flag = true;
                for (int i = 0; i < myId.size(); i++) {
                    if (myId[i] != line[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) break;
            }
        }
        in.close();
        if (flag) return line;
        else throw "ID can not be found";
    }

    string getDate() {
        ifstream in("text.txt");
        string line = "";
        if (in.is_open()) {
            getline(in, line);
            return line;
        }
        else throw "Stream is not open";
    }
};

class Proxy : public ServiceInterface {
private:
    Service* realService;
    string date;
    vector<string> cache;
    string removePoint(string str) {
        string myStr;
        while (str[0] >= 48 && str[0] <= 57) {
            str = str.substr(1);
        }
        str = str.substr(2);
        return str;
    }
public:
    Proxy(Service* realService, string date): realService(realService), date(date) {}

    vector<string> download() {
        return realService->download();
    }

    string downloadVideoByID(int id) {
        cout << "Proxy handling request" << endl;
        if (this->date != realService->getDate()) {
            this->date = realService->getDate();
            cache.clear();
        }
        bool flag = false;
        int curId;
        for (int i = 0; i < cache.size(); i++) {
            flag = true;
            curId = i;
            for (int j = 0; j < to_string(id).size(); j++) {
                if (to_string(id)[j] != cache[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) {
            return removePoint(cache[curId]);
        }
        try {
            return removePoint(realService->downloadVideoByID(id));
        }
        catch (...) {
            return "ID can not be found";
        }
    }

};

int main()
{
    Service* realService = new Service;
    Proxy* proxy = new Proxy(realService,"12.06.2024");
    cout << proxy->downloadVideoByID(0);
    cout << endl << endl;
    vector<string> array = proxy->download();
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << endl;
    }





}