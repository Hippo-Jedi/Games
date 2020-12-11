/***********************i*
 ** Program: player.cpp 
 ** Author: Michael Smith
 ** Date: 11/22/2019
 ** Description: Holds function bodies for player class
 ** Input: None 
 ** Output: player coordinates and data
 **************************/
#include <iostream>
#include <cstdlib>
#include "player.h"

using namespace std;

//default constructor for player class
Player::Player(){
	wump = false;
	gold = false;
	arrows = 3;
}

//non-default constructor for play class
Player::Player(int n){
	srand(time(NULL));
	wump = false;	
	gold = false;
	arrows = 3;
	int a = rand() % n, b = rand() % n;
	initial_x = a;
	initial_y = b;
	x = a;
	y = b;
}

void Player::set_x(int n){
	this->x = n;
}	

void Player::set_y(int n){
	this->y = n;
}

void Player::reset(){
	this->x = initial_x;
	this->y = initial_y;
	this->arrows = 3;
	this->gold = false;
	this->wump = false;
}






