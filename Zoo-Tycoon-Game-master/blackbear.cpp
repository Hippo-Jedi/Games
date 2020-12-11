/***********************i*
 ** Program: blackbear.cpp 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: Holds function bodies for Blackbear class type to run the zoo tycoon game
 ** Input: None 
 ** Output: black bear data
 ***************************/
#include <iostream>
#include "blackbear.h"

using namespace std;

//default constructor
Blackbear::Blackbear() {
}

//non-default constructor
Blackbear::Blackbear(int a) {
	age = a;
}

//mutator function that sets new age to old age
Blackbear &Blackbear::operator = (const Blackbear &old) {
	this-> age = old.age;
	return *this;
}
