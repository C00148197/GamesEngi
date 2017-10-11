
#include "Jumping.h"
#include "Idle.h"

void Jumping::idle(Animation* a)
{
	cout << "going from B to idling" << endl;
	a->setCurrent(new Idle());
	delete this;
}
