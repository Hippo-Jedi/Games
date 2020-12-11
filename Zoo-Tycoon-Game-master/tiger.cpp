/***********************i*
 ** Program: tiger.cpp 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: Holds function bodies for Tiger class type to run the zoo tycoon game
 ** Input: None 
 ** Output: Tiger data
 ***************************/
#include <iostream>
#include "tiger.h"

using namespace std;

//default constructor
Tiger::Tiger() {
}

//non-default constructor
Tiger::Tiger(int a){
	age = a;	
}

//mutator function that assigns old age to new age
Tiger &Tiger::operator = (const Tiger &old){
	this-> age = old.age;
	return *this;
}
