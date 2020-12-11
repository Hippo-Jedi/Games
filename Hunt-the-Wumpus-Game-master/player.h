#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "event.h"

using namespace std;

class Player {
public:
	bool wump;
	bool gold;
	int arrows;
	int x;
	int y;
	int initial_x;
	int initial_y;

	Player();
	Player(int n);
	void set_gold(bool n) { this-> gold = n; }
	bool get_gold() { return gold; }
	void set_wump(bool n) { this-> wump = n; }
	bool get_wump(){ return wump; }
	void set_x(int n);
	void set_y(int n);
	void reset();

};
#endif
