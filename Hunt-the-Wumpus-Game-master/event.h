#ifndef EVENT_H
#define EVENT_H
#include <iostream>

using namespace std;

class Event {
public:
	virtual void encounter() = 0;
	virtual void output() = 0;
};

#endif
