#pragma once
#include "Animation.h"
using namespace std;

#include <iostream>
class State
{
public:
	virtual void idle(Animation* a) { cout << "state::idle" << endl; }


	virtual void jumping(Animation* a) { cout << "state::b" << endl; }


	virtual void climbing(Animation* a) { cout << "state::f" << endl; }
};