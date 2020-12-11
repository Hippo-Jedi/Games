/***********************i*
 ** Program: game.cpp 
 ** Author: Michael Smith
 ** Date: 11/22/2019
 ** Description: Holds function bodies for cave class 
 ** Input: None 
 ** Output: cave data
 **************************/
#include "game.h"
#include <iostream>
#include "player.h"
#include "room.h"
#include "wump.h"
#include "gold.h"
#include "bats.h"
#include "pit.h"
#include <vector>
#include <cstdlib>

using namespace std;

//default constructor for cave class
Cave::Cave(){
	w = 0;
}

//non_default constructor for cave class
Cave::Cave(int n){
	this->w = n;
	p = new Player(w);
}

/*******************
 ** Function: make_cave
 ** Description: creates an array of rooms that make up the cave using vectors
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: dynamic array of rooms
 *********************/
void Cave::make_cave(){
	cave = vector< vector<Room> > (w, vector<Room>(w));
	for (int i=0; i<w; i++){
		for (int j=0; j<w; j++){
			Room r;
			cave[i][j] = r;
		}
	}
}

/*******************
 ** Function: cave_output
 ** Description: displays the cave
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: the cave is displayed 
 *********************/
void Cave::cave_output(){
	for (int i=0; i<w; i++){
		for (int j=0; j<w; j++){
			cout << "+---";
		}
		cout << "+" << endl;
		for (int k=0; k<w; k++){
			if ((i == this->p->x) && (k == this->p->y)){
				cout << "|" << " * ";
			}else {
				cout << "|" << "   ";
			}
		}
		cout << "|" << endl;
	}
	for (int l=0; l<w; l++){
		cout << "+---";
	}
	cout << "+" << endl;
}

/*******************
 ** Function: debug_output
 ** Description: displays the cave without any hints
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: the cave is displayed without any hints
 *********************/
void Cave::debug_output(){
	for (int i=0; i<w; i++){
		for (int j=0; j<w; j++){
			cout << "+---";
		}
		cout << "+" << endl;
		for (int k=0; k<w; k++){
			if ((i == this->p->x) && (k == this->p->y)){
				cout << "|" << " * ";
			}else {
				cout << "|" << cave[i][k].get_mark();
			}
		}
		cout << "|" << endl;
	}
	for (int l=0; l<w; l++){
		cout << "+---";
	}
	cout << "+" << endl;
}

/*******************
 ** Function: fill_rooms
 ** Description: fills the cave array of rooms with marks randomly
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: The cave is filled with the events and objects marks
 *********************/
void Cave::fill_rooms(){
	bool hold;
	srand(time(NULL));
	cave[this->p->x][this->p->y].set_rope(true);
	cave[this->p->x][this->p->y].set_event(true);
	Room wump(0);
	Room rope(0);
	Room gold(1);
	Room pit1(2);
	Room pit2(2);
	Room bats1(3);
	Room bats2(3);
	for (int i=0; i<7; i++){
		int n = rand() % w, m = rand() % w;
		hold = true;
		while(hold){
			if (cave[n][m].get_event()){
				n = rand() % w, m = rand() % w;
			}else {
				hold = false;
			}
		}
		switch(i){
			case 0: cave[n][m] = wump; break;
			case 1: cave[n][m] = gold; break;
			case 2: cave[n][m] = pit1; break;
			case 3: cave[n][m] = pit2; break;
			case 4: cave[n][m] = bats1; break;
			case 5: cave[n][m] = bats2; break;
		}
	}
	cave[this->p->x][this->p->y].set_event(false);
}

/*******************
 ** Function: choice
 ** Description: asks player to shoot or move every turn
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: calls functions depending on the player choice
 *********************/
void Cave::choice(){
	int choice;
	cout << "Enter 1 to move" << endl;
	cout << "Enter 2 to shoot an arrow" << endl;
	cout << "Choice: ";
	cin >> choice;
	switch(choice){
		case 1: move(); break;
		case 2: shoot(); break;
	}
}

/*******************
 ** Function: shoot
 ** Description: function that is called when player decides to shoot and arrow, asks for which direction they wish to shoot
 ** Parameters: none
 ** Pre-Conditions: user decides to shoot an arrow
 ** Post-Conditions: an arrow is shot in the direction entered and kills the wumpus if it is hit
 *********************/
void Cave::shoot(){
	this->p->arrows--;
	string direction;
	bool hit = false;
	cout << "What direction would you like to shoot your arrow?" << endl;
	cout << "Choice: ";
	cin >> direction;
	if (direction == "w"){
		cout << "An arrow has been shot up" << endl;
		for (int i=this->p->x-1; i>=0; i--){
			if (cave[i][this->p->y].get_mark() == " W ") {
				cout << endl << endl << "Your arrow has hit the Wumpus and he has died!!!" << endl;
				hit = true;
				kill_wumpus();
			}
		}
	}
	else if (direction == "s"){
		cout << "An arrow has been shot down" << endl;
		for (int i=this->p->x+1; i<w; i++){
			if (cave[i][this->p->y].get_mark() == " W "){
				cout << endl << "Your arrow has hit the Wumpus and he has died!!!" << endl;
				hit = true;
				kill_wumpus();
			}
		}
	}else if (direction == "a"){
		cout << "An arrow has been shot to the left" << endl;
		for (int i=this->p->y-1; i>=0; i--){
			if (cave[this->p->x][i].get_mark() == " W "){
				cout << endl << "Your arrow has hit the Wumpus and he has died!!!" << endl;
				hit = true;
				kill_wumpus();
			}
		}
	}else if (direction == "d"){
		cout << "An arrow has been shot to the right" << endl;
		for (int i=this->p->y+1; i<w; i++){
			if (cave[this->p->x][i].get_mark() == " W "){
				cout << endl << "Your arrow has hit the Wumpus and he has died!!!" << endl;
				hit = true;
				kill_wumpus();
			}
		}
	}
	if (!(hit)){
		miss();
	}
}

/*******************
 ** Function: move
 ** Description: function that is called when user decides to move, asks player for the direction they wish to move
 ** Parameters: none
 ** Pre-Conditions: user decides to move there character to a different room
 ** Post-Conditions: the player has moved into the room in the direction of choice
 *********************/
void Cave::move(){
	string choice;
	cout << "What direction do you wish to move?" << endl << "Choice: ";
	cin >> choice;
	if (choice == "a"){
		if (left_check(this->p->y)){
			this->p->y = this->p->y-1;
		}
	}
	if (choice == "d"){
		if (right_check(this->p->y)){
			this->p->y = this->p->y+1;
		}
	}
	if (choice == "s"){
		if (down_check(this->p->x)){
			this->p->x = this->p->x+1;
		}
	}
	if (choice == "w"){
		if (up_check(this->p->x)){
			this->p->x = this->p->x-1;
		}
	}
}

/*******************
 ** Function: miss
 ** Description: if the users arrow misses the wumpus, this function is called. moves the wumpus to a new location
 ** Parameters: none
 ** Pre-Conditions: arrow misses wumpus
 ** Post-Conditions: relocates the wumpus
 *********************/
void Cave::miss(){
	srand(time(NULL));
	int n = rand() % 3;
	if (n != 1){
		cout << "Your arrow has missed" << endl << "The Wumpus moved..." << endl;
		Room r;
		for (int i=0; i<w; i++){
			for (int j=0; j<w; j++){
				if (cave[i][j].get_mark() == " W "){
					cave[i][j] = r;
				}
			}
		}
		int n = rand() % w;
		int m = rand() % w;
		bool hold = true;
		while(hold){
			if (cave[n][m].get_event()){
				n = rand() % w;
				m = rand() % w;
			}else {
				hold = false;
			}
		}
		Room wump(0);
		cave[n][m] = wump;	
	}else {
		cout << "The Wumpus is still asleep..." << endl;
	}
}

/*******************
 ** Function: event_check
 ** Description: checks to see if the player is next to any of the cave objects, then displays the correct percepts
 ** Parameters: address of run variable 
 ** Pre-Conditions: none
 ** Post-Conditions: displays percepts if player is in a valid location
 *********************/
void Cave::event_check(int &run, bool d){
	if (cave[this->p->x][this->p->y].get_mark() == " W "){
		cout << "You have found the Wumpus!!" << endl;
		run = 0;
	}
	if (cave[this->p->x][this->p->y].get_mark() == " P "){
		cout << "You fell into a bottemless pit!!" << endl;
		run = 0;
	}
	if (cave[this->p->x][this->p->y].get_mark() == " B "){
		cout << "You are whisked away by a horde of super bats!!" << endl << "You are moved to a random room within the cave" << endl;
		bats(d); 
	}
	if (cave[this->p->x][this->p->y].get_mark() == " G "){
		gold_found();
	}
	if (this->p->arrows == 0){
		cout << "You have ran out of arrows and you haven't killed the Wumpus" << endl;
		run = 0;
	}
}

/*******************
 ** Function: kill_wumpus
 ** Description: changes player member variable to true 
 ** Parameters: none
 ** Pre-Conditions: user has killed the wumpus
 ** Post-Conditions: the wumpus has been killed
 *********************/
void Cave::kill_wumpus(){
	for (int i=0; i<w; i++){
		for (int j=0; j<w; j++){
			if (cave[i][j].get_mark() == " W "){
				Room r;
				cave[i][j] = r;
			}
		}
	}
	this->p->wump = true;
}

/*******************
 ** Function: clear
 ** Description: deletes all dynamic arrays by calling class member functions to delete
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: player and cave are deleted
 *********************/
void Cave::clear(){
	for (int i=0; i<w; i++){
		for (int j=0; j<w; j++){
			if (cave[i][j].get_event()){
				cave[i][j].clean();
			}
		}
	}	
	delete this->p;
}

/*******************
 ** Function: game
 ** Description: calls functions depending on commandline arguments
 ** Parameters: address of run variable, commandline boolean argument
 ** Pre-Conditions: none
 ** Post-Conditions: calls functions to create proper game flow
 *********************/
void Cave::game(int &run, bool d){
	if (d == true){
		cout << endl << endl;
		debug_output();
	}else if (d == false){
		cout << endl << endl;
		cave_output();
	}
	event_check(run, d);
	if (run != 0){
		percepts_check();
		choice();
	}
	win_check(run);
}

/*******************
 ** Function: percepts_check
 ** Description: checks up, down, left and right from player position for any cave objects
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: calls check functions for all directions and displays percepts
 *********************/
void Cave::percepts_check(){
	if (up_check(this->p->x)){
		if (cave[this->p->x-1][this->p->y].get_event()){
			cave[this->p->x-1][this->p->y].output();
		}
	}
	if (down_check(this->p->x)){
		if (cave[this->p->x+1][this->p->y].get_event()){
			cave[this->p->x+1][this->p->y].output();
		}
	}
	if (right_check(this->p->y)){
		if (cave[this->p->x][this->p->y+1].get_event()){
			cave[this->p->x][this->p->y+1].output();
		}
	}
	if (left_check(this->p->y)){
		if (cave[this->p->x][this->p->y-1].get_event()){
			cave[this->p->x][this->p->y-1].output();
		}
	}
}

/*******************
 ** Function: up_check
 ** Description: checks the room above the player for cave objects
 ** Parameters: x coordinate of the player
 ** Pre-Conditions: none
 ** Post-Conditions: returns 0 or 1
 *********************/
int Cave::up_check(int n){
	if (n-1 >= 0){
		return 1;
	}
	else {
		return 0;
	}
}

/*******************
 ** Function: down_check
 ** Description: checks the room beneath the player for cave objects
 ** Parameters: x coordinate of the player
 ** Pre-Conditions: none
 ** Post-Conditions: returns 0 or 1
 *********************/
int Cave::down_check(int n){
	if (n+1 < w){
		return 1;
	}
	else {
		return 0;
	}
}

/*******************
 ** Function: left_check
 ** Description: checks the room to the left of the player for cave objects
 ** Parameters: y coordinate of the player
 ** Pre-Conditions: none
 ** Post-Conditions: returns 1 or 0
 *********************/
int Cave::left_check(int n){
	if (n-1 >= 0){
		return 1;
	}else {
		return 0;
	}
}

/*******************
 ** Function: right_check
 ** Description: checks the room to the right of the player for cave objects
 ** Parameters: y coordinate of the player
 ** Pre-Conditions: none
 ** Post-Conditions: returns 0 or 1
 *********************/
int Cave::right_check(int n){
	if (n+1 < w){
		return 1;
	}
	else {
		return 0;
	}
}

/*******************
 ** Function: gold_found
 ** Description: function if called if player has found the gold object within the cave
 ** Parameters: none
 ** Pre-Conditions: player has found the gold
 ** Post-Conditions: displays that you have found the gold and changes player boolean class member variable
 *********************/
void Cave::gold_found(){
	cout << "You have found and collected the gold!!!" << endl;
	this->p->gold = true;
	Room n;
	cave[this->p->x][this->p->y] = n;
}

/*******************
 ** Function: bats
 ** Description: function is called when the player has ran into the bats object within the cave
 ** Parameters: none
 ** Pre-Conditions: player is in same room as super bats
 ** Post-Conditions: cave is outputed
 *********************/
void Cave::bats(bool d){
	srand(time(NULL));
	int a = rand() % w;
	int b = rand() % w;
	this->p->x = a;
	this->p->y = b;
	if (d == false){
		cave_output();
	}else if (d == true){
		debug_output();
	}
}

/*******************
 ** Function: win_check
 ** Description: checks to see if the player has won the game
 ** Parameters: address of run variable
 ** Pre-Conditions: none
 ** Post-Conditions: ends game if player has won the game
 *********************/
void Cave::win_check(int &run){
	int n = 0;
	if (this->p->gold == true){
		n++;
	}
	if (this->p->wump == true){
		n++;
	}
	if (this->p->x == this->p->initial_x && this->p->y == this->p->initial_y){
		n++;
	}
	if (n == 3){
		cout << endl << "You have won the game" << endl;
		cout << "Congratulations!!!" << endl;
		run = 0;
	}
}

/*******************
 ** Function: reset
 ** Description: calls the member function reset from the player class
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: resets the cave grid and player
 *********************/
void Cave::reset(){
	this->p->reset();	
}

/*******************
 ** Function: play_again
 ** Description: asks user if they want to play again after they have won
 ** Parameters: address of p variable, address of again boolean variable
 ** Pre-Conditions: none
 ** Post-Conditions: ends game or begins a second game depending on what the user decides
 *********************/
void Cave::play_again(int &p, bool &again){
	int choice;
	cout << "Would you like to play again?" << endl;
	cout << "Enter 1 for yes" << endl << "Enter 2 for no" << endl;
	cout << "Choice: ";
	cin >> p;
	if (p == 1){
		cout << "Enter 1 to play with the same cave" << endl << "Enter 2 to play with a different cave" << endl;
		cout << "Choice: ";
		cin >> choice;
		if (choice == 1){
			again = true;
		}else {
			again = false;
		}
	}
	else {
		p = 0;
	}
}

/*******************
 ** Function: guidelines
 ** Description: displays guidelines of the game before it begins
 ** Parameters: address of p variable, address of run variable, address of again boolean, cave dimensions, second commandline argument
 ** Pre-Conditions: none
 ** Post-Conditions: game begins
 *********************/
void Cave::guidelines(int &p, int &run, bool &again, int dim, string arg){
	int n;
	system("clear");
	cout << "HUNT THE WUMPUS" << endl;
	cout << "1. You must find and kill the Wumpus within the cave\n";
	cout << "2. Use w(up), s(down), a(left), d(right) keys to move\n";
	cout << "3. You must also find the gold hidden within the cave\n";
	cout << "4. You must collect the gold, kill the Wumpus, and make it back to your escape rope(initial position) in order to win\n";
	cout << "5. You only have three arrows to kill the Wumpus, use them wisely\n";
	cout << "Enter a number to begin the game: ";
	cin >> n;
	system("clear");
	begin(p, run, again, dim, arg);
}

/*******************
 ** Function: begin
 ** Description: begins and runs the game
 ** Parameters: address of p variable, address of run variable, address of again boolean, cave dimensions, second commandline argument
 ** Pre-Conditions: none
 ** Post-Conditions: loops the game until the player has lost or wins
 *********************/
void Cave::begin(int &p, int &run, bool &again, int dim, string arg){
	while(p == 1){
                make_cave();
                fill_rooms();
                if (arg == "false"){
                        while(run){
                                game(run, false);
                        }
                        play_again(p, again);
                        if (p != 1){
                                clear(); break;
                        }
                        if (again){
                                run = 1;
                                reset();
                                while(run){
                                        game(run, false);
                                }
                        }else { 
				clear(); break;
			}
                }else if(arg == "true"){
                        while(run){
                                game(run, true);
                        }
                        play_again(p, again);
                        if (p != 1){
                                clear(); break;
                        }
                        if (again){
                                run = 1;
                                reset();
                                while(run){
                                        game(run, true);
                                }
                        }else {
				clear(); break;
			}
                }else {
                        cout << "Arguments are invalid" << endl;
                        p = 0;
                }	
	}
	
}
















