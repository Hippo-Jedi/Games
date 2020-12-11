#ifndef BATS_H
#define BATS_H
#include <iostream>
#include "room.h"
#include "event.h"

using namespace std;

class Bats : public Event {
public:
	Bats();
	void encounter();
	void output();
};
#endif
