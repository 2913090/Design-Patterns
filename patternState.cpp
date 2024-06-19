#include <iostream>

using namespace std;

class State {
public:
	virtual ~State() = default;
	virtual void play() = 0;
	virtual void pause() = 0;
	virtual void stop() = 0;
};

class MusicPlayer {
private:
	State* currentState;
	State* playingState;
	State* pausedState;
	State* stoppedState;
public:
	MusicPlayer();

	void setState(State* state) {
		currentState = state;
	}
	~MusicPlayer() {
		delete playingState;
		delete pausedState;
		delete stoppedState;
	}
	void play() {
		currentState->play();
	}
	void pause() {
		currentState->pause();
	}
	void stop() {
		currentState->stop();
	}
	State* getPlayingState() {
		return playingState;
	}
	State* getPausedState() {
		return pausedState;
	}
	State* getStoppedState() {
		return stoppedState;
	}
};

class PlayingState : public State {
private:
	MusicPlayer* player;
public:
	PlayingState(MusicPlayer* player) :player(player) {}
	void play() {
		cout << "Music player is already playing" << endl;
	}
	void pause() {
		cout << "Music player is paused" << endl;
		player->setState(player->getPausedState());
	}
	void stop() {
		cout << "Music player is stopped" << endl;
		player->setState(player->getStoppedState());
	}
};

class PausedState : public State {
private:
	MusicPlayer* player;
public:
	PausedState(MusicPlayer* player) :player(player) {}
	void play() {
		cout << "Starting playback" << endl;
		player->setState(player->getPlayingState());
	}
	void pause() {
		cout << "Music player is already paused" << endl;
	}
	void stop() {
		cout << "Music player is stopped" << endl;
		player->setState(player->getStoppedState());
	}
};

class StoppedState : public State {
private:
	MusicPlayer* player;
public:
	StoppedState(MusicPlayer* player) :player(player) {}
	void play() {
		cout << "Starting playback" << endl;
		player->setState(player->getPlayingState());
	}
	void pause() {
		cout << "Music player is paused" << endl;
		player->setState(player->getPausedState());
	}
	void stop() {
		cout << "Music player is already stopped" << endl;
	}
};

MusicPlayer::MusicPlayer() {
	this->playingState = new PlayingState(this);
	this->pausedState = new PausedState(this);
	this->stoppedState = new StoppedState(this);
	currentState = stoppedState;
}

int main()
{
	MusicPlayer p;
	p.play();
	p.play();
	p.pause();
}