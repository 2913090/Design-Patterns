#include <iostream>
#include <vector>

using namespace std;

class FileSystemComponent {
public:
	virtual ~FileSystemComponent() = default;
	virtual void add(FileSystemComponent* component) = 0;
	virtual void remove(string name) = 0;
	virtual float getWeight() = 0;
	//virtual void display() = 0;
};

class File : public FileSystemComponent {
private:
	string name;
	float weight;
public:
	File(string name, float weight) : name(name), weight(weight){}

	float getWeight() {
		return this->weight;
	}

	void add(FileSystemComponent* component) {
		throw logic_error("Operation not supported");
	}

	void remove(string name) {
		throw logic_error("Operation not supported");
	}
};

class Directory : public FileSystemComponent {
private:
	string name;
	vector<FileSystemComponent*> components;
public:
	Directory(string name) :name(name){}

	~Directory() {
		for (auto component : components) {
			delete component;
		}
	}

	void add(FileSystemComponent* component) {
		components.push_back(component);
	}

	void remove(string name) {
		cout << "Remove" << endl;
	}

	float getWeight() {
		float result = 0;
		for (auto component : components) {
			result += component->getWeight();
		}
		return result;
	}
};



int main()
{
	Directory* d4 = new Directory("D1");
	Directory* d3 = new Directory("D2");
	Directory* d2 = new Directory("D3");
	Directory* d1 = new Directory("D4");
	File* f1 = new File("F1", 1.2);
	File* f2 = new File("F2", 1.2);
	File* f3 = new File("F3", 1.2);
	File* f4 = new File("F4", 1.2);
	File* f5 = new File("F5", 1.2);
	File* f6 = new File("F6", 1.2);
	File* f7 = new File("F7", 1.2);
	File* f8 = new File("F8", 1.2);

	d1->add(f1);
	d1->add(f2);
	d1->add(f3);

	d2->add(f4);
	d2->add(f5);

	d3->add(f6);
	d3->add(f7);
	d3->add(d1);
	d3->add(d2);

	d4->add(f8);
	d4->add(d3);

	cout << d1->getWeight() << endl;
	cout << d2->getWeight() << endl;
	cout << d3->getWeight() << endl;
	cout << d4->getWeight() << endl;
}