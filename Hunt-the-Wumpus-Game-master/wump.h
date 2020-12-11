#ifndef WUMP_H
#define WUMP_H
#include <iostream>
#include "room.h"
#include "event.h"

using namespace std;

class Wumpus : public Event {
public:
	Wumpus();
	void encounter();
	void output();
};
#endif
