#include "Command.h"


//void Command::Execute()
//{
//	list<Command*>::iterator i = commands->begin();
//
//	for (auto &i : *commands)
//	{
//		Command *c = i;
//		c->Execute();
//	}
//	cout << "macrod" << endl;
//}



void MacroCommand::Execute() {

	list<Command*>::iterator i = commands->begin();

	for (auto &i : *commands)
	{
		Command *c = i;
		c->Execute();
	}
	cout << "macrod" << endl;
}

void JumpCommand::jump()
{
	cout << "jump" << endl;
}

void FireCommand::fire()
{
	cout << "fire" << endl;
}

//void JumpCommand::Execute() {
//
//	cout << "jump" << endl;
//
//}
//
//void FireCommand::Execute() {
//
//	cout << "fire" << endl;
//}

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

//void MacroCommand::Undo()
//{
//
//}


//for (i; i != commands->end(); ++i)
//{
//
//	Command *c = *i;
//	c->Execute();
//}
