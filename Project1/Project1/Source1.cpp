//bit one a
using namespace std;
#include <iostream>
#include "sdl.h"
#include <vector>
class character {
public:
	character() {}
	virtual ~character() {}
	virtual void draw() = 0;
};

class player : public character {
public:
	void draw() {
		cout << "draw player" << endl;
	}
};
class boss : public character {
public: void draw() {
	cout << "draw boss" << endl;
}
};

//end bit a
//bit one b
class factory
{
public:
	virtual character* createplayer() = 0;
	virtual character* createopponents() = 0;
};

class characterfactory : public factory {
public:
	character* createplayer() {
		return new player;
	}
	character* createopponents() {
		return new boss;
	}
};

int main() {

	//	sdl_init(sdl_init_everything);
//	sdl_quit();

	factory* factory = new characterfactory;
	
	vector<character*> characters;
	characters.push_back(factory->createplayer());
	characters.push_back(factory->createopponents());
	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
	}
	return 0;
}
// end bit one and bit one b

