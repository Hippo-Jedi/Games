/***********************i*
 ** Program: room.cpp 
 ** Author: Michael Smith
 ** Date: 11/22/2019
 ** Description: Holds function bodies for room class 
 ** Input: None 
 ** Output: room data
 **************************/
#include <iostream>
#include "wump.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"
#include "room.h"

using namespace std;

//default constructor for the room class
Room::Room(){
	mark = "   ";
	event_array = 0;
	event = false;
}

//non-default constructor for room class 
Room::Room(int n){
	switch(n){
		case 0: event_array = new Wumpus; mark = " W "; break;
		case 1: event_array = new Gold; mark = " G "; break;
		case 2: event_array = new Bats; mark = " B "; break;
		case 3: event_array = new Pit; mark = " P "; break;
	}
	event = true;
}

void Room::set_mark(string n){
	this->mark = n;
}

string Room::get_mark(){
	return this->mark;
}

void Room::set_event(bool n){
	this->event = n;
}

bool Room::get_rope(){
	return this->rope;
}

bool Room::get_event(){
	return this->event;
}

void Room::set_rope(bool n){
	this->rope = true;
}

void Room::clean(){
	delete [] this->event_array;
}

void Room::output(){
	this->event_array->output();
}















