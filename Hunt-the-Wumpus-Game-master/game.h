#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "player.h"
#include "room.h"

using namespace std;

class Cave{
private:
	vector< vector<Room> > cave;
	int w;
	Player *p;
public:
	Cave();
	Cave(int n);
	void make_cave();
	void cave_output();
	void miss();
	void find();
	void percepts_check();
	void fill_rooms();
	void shoot();
	void move();
	int up_check(int n);
	int down_check(int n);
	int right_check(int n);
	int left_check(int n);
	void kill_wumpus();
	void game(int &run, bool d);
	void gold_found();
	void debug_output();
	void choice();
	void win_check(int &run);
	void play_again(int &p, bool &again);
	void reset();
	void clear();
	void event_check(int &run, bool d);
	void new_game();
	void bats(bool d);
	void guidelines(int &p, int &run, bool &again, int dim, string arg);	
	void begin(int &p, int &run, bool &again, int dim, string arg);
};

#endif




