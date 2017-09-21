#include <SDL.h>
using namespace std;
#include <iostream>

class Character
{
public:
	Character() {}
		void Print() { cout << "printing" << endl; }
};

class HandleToCharacter
{
public:

	HandleToCharacter() : character(new Character()) {}
	Character* operator->() {
		return character;
	}
private:
	Character* character;

};

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Quit();


	HandleToCharacter handle;
	handle->Print();

	system("PAUSE");
	return 0;
}



















 //<summary>
 //das
 //</summary>
 //
 //#include <SDL.h>
//using namespace std;
//#include <iostream>
//class Character
//{
//public:
//	Character() {}
//	void Print() { cout << "printin boi" << endl; }
//
//	//void Draw(); 
//	virtual void Draw() = 0;
//};
//
//class Player : public Character
//{
//
//public:
//	Player(DrawAPI* api) { this->api = api; }
//	void Draw() { api->Draw(); }
//private:
//	DrawAPI* api;
//
//};
//
//class DrawAPI
//{
//public:
//	virtual void Draw() = 0;
//};
//
//class DrawImpl : public DrawAPI
//{
//public:
//	void Draw() { cout << "draw sutff" << endl; }
//};
//
//class HandleToCharacter
//{
//public:
//
//	HandleToCharacter() : character(new Character()) {}
//	Character* operator->() {
//		return character;
//	}
//private:
//	Character* character;
//
//};
//
//int main(int argc, char* argv[])
//{
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Quit();
//
//
//	HandleToCharacter handle;
//	handle->Print();
//
//	DrawAPI* api = new DrawImpl();
//	Character* character = new Player(api);
//	character->Draw();
//	cin.get();
//
//	system("PAUSE");
//	return 0;
//}