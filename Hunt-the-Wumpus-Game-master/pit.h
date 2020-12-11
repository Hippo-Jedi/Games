#ifndef PIT_H
#define PIT_H
#include <iostream>
#include "room.h"
#include "event.h"

using namespace std;

class Pit : public Event {
public:
	Pit();
	void output();
	void encounter();
};
#endif
