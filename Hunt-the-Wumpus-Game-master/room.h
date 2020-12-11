#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "event.h"

using namespace std;

class Room {
private:
	string mark;
	bool rope;
	bool event;
	Event *event_array;
public:
	Room();
	Room(int n);
	void set_mark(string n);
	string get_mark();
	void output();
	bool get_event();
	void set_event(bool n);
	bool get_rope();
	void set_rope(bool n);
	void clean();
};
#endif
