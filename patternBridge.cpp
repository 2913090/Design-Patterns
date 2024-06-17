#include <iostream>

using namespace std;


class Device {
public:
	virtual int getMaxChannel() = 0;

	virtual bool isEnable() = 0;

	virtual void enable() = 0;

	virtual void disable() = 0;

	virtual int getVolume() = 0;

	virtual void setVolume(int percent) = 0;

	virtual int getChannel() = 0;

	virtual void setChannel(int channel) = 0;
};

class Remote {
protected:
	Device* device;
public:
	Remote(Device* device) : device(device){}

	void togglePower() {
		if (device->isEnable()) device->disable();
		else device->enable();
	}

	void volumeDown() {
		if (device->getVolume() == 0) return;
		device->setVolume(device->getVolume() + 1);
	}

	void volumeUp() {
		if (device->getVolume() == 100) return;
		device->setVolume(device->getVolume() - 1);
	}

	void channelDown() {
		if (device->getChannel() == 0) device->setChannel(device->getMaxChannel());
		else device->setChannel(device->getChannel() - 1);
	}

	void channelUp() {
		if (device->getChannel() == device->getMaxChannel()) device->setChannel(0);
		else device->setChannel(device->getChannel() + 1);
	}
};

class AdvancedRemote : public Remote {
public:
	AdvancedRemote(Device* device) : Remote(device){}

	void mute() {
		device->setVolume(0);
	}
};

class TV: public Device {
private:
	bool power = false;
	int volume = 0;
	int channel = 1;
	int maxChannel = 30;
public:
	int getMaxChannel() {
		return this->maxChannel;
	}

	bool isEnable() {
		return this->power;
	}

	void enable() {
		this->power = true;
	}

	void disable() {
		this->power = false;
	}

	int getVolume() {
		return this->volume;
	}

	void setVolume(int percent) {
		this->volume = percent;
	}

	int getChannel() {
		return this->channel;
	}

	void setChannel(int channel) {
		this->channel = channel;
	}
};

class Radio : public Device {
private:
	bool power;
	int volume;
	int channel;
	int maxChannel = 30;
public:
	Radio() : power(false), volume(10), channel(1) {}

	int getMaxChannel() {
		return this->maxChannel;
	}

	bool isEnable() {
		return this->power;
	}

	void enable() {
		this->power = true;
	}

	void disable() {
		this->power = false;
	}

	int getVolume() {
		return this->volume;
	}

	void setVolume(int percent) {
		this->volume = percent;
	}

	int getChannel() {
		return this->channel;
	}

	void setChannel(int channel) {
		this->channel = channel;
	}
};


int main()
{
	Device* tv = new TV();
	Remote* remote = new Remote(tv);



}