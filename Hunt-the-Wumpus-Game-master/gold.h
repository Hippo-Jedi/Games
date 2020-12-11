#ifndef GOLD_H
#define GOLD_H
#include <iostream>
#include "room.h"
#include "event.h"

using namespace std;

class Gold : public Event {
public:
	Gold();
	void output();
	void encounter();
};
#endif
