#include <iostream>

using namespace std;

class Command {
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class Light {
private:
	string location;
public:
	Light(string location) : location(location){}
	void on() {
		cout << location << " lights is ON" << endl;
	}

	void off() {
		cout << location << " lights is OFF" << endl;
	}
};

class LightOnCommand : public Command {
private:
	Light* light;
public:
	LightOnCommand(Light* light) :light(light){}

	void execute() {
		light->on();
	}

	void undo() {
		light->off();
	}
};

class LightOffCommand : public Command {
private:
	Light* light;
public:
	LightOffCommand(Light* light) :light(light) {}

	void execute() {
		light->off();
	}

	void undo() {
		light->on();
	}
};

class RemoteControl {
private:
	Command* command;
public:
	void setCommand(Command* cmd) {
		command = cmd;
	}

	void pressButton() {
		if (command) {
			command->execute();
		}
	}

	void pressUndo() {
		if (command) {
			command->undo();
		}
	}
};




int main()
{
	Light* livingRoomLight = new Light("Living Room");

	LightOnCommand* lightOn = new LightOnCommand(livingRoomLight);
	LightOffCommand* lightOff = new LightOffCommand(livingRoomLight);

	RemoteControl* remote = new RemoteControl();
	remote->setCommand(lightOn);
	remote->pressButton();
}