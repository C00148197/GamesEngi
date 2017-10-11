#include "Command.h"

void MacroCommand::Execute() {

	list<Command*>::iterator i = commands->begin();

	for (auto &i : *commands)
	{
		Command *c = i;
		c->Execute();

	}
	cout << "macrod" << endl;
}



void MacroCommand::add(Command *c) {

	commands->push_back(c);
	cout << "added" << endl;
}

void MacroCommand::remove(Command *c) {

	redoCommands->push_back(c);
	commands->remove(c);
	cout << " removed " << endl;
}

void MacroCommand::redo() {

	commands->clear();
	commands = redoCommands;
	cout << "redo" << endl;
}



void JumpCommand::jump()
{
	cout << "jump" << endl;
}

void FireCommand::fire()
{
	cout << "fire" << endl;
}

