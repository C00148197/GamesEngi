#pragma once
using namespace std;
#include <iostream>
#include <list>
#include <iterator>
class Command
{
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
	//virtual void Undo() = 0;
protected:
	Command() {}
};


class MacroCommand : public Command {
public:
	MacroCommand() { commands = new list<Command*>; };
	virtual ~MacroCommand() {};
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void redo();
	virtual void Execute();
private:
	list<Command*>* commands;
	list<Command*>* redoCommands;
};



class JumpCommand : public Command
{
public:
	virtual void Execute() { jump(); }
	void jump();
};

class FireCommand : public Command
{
public:
	virtual void Execute() { fire(); }
	void fire();
};



