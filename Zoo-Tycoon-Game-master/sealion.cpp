/***********************i*
 ** Program: sealion.cpp 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: Holds function bodies for Sealion class type to run the zoo tycoon game
 ** Input: None 
 ** Output: sealion data
 ****************************/
#include <iostream>
#include "sealion.h"

using namespace std;

//default constructor
Sealion::Sealion() {
}

//non-default constructor
Sealion::Sealion(int a) {
	age = a;
}

//mutator function that sets new age to old age
Sealion& Sealion::operator = (const Sealion &old) {
	this-> age = old.age;
	return *this;
}
