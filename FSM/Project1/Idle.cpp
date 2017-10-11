#include "Idle.h"
#include "Jumping.h"
#include "Climbing.h"


void Idle::jumping(Animation* a)
{
	cout << "B" << endl;
	a->setCurrent(new Jumping());
	delete this;
}


void Idle::climbing(Animation* a)
{
	cout << "F" << endl;
	a->setCurrent(new Climbing());
	delete this;
}