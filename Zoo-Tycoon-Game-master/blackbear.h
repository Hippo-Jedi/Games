/************************
 ** Program: blackbear.h 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: class declaration for the Blackbear class, contains member variables and functions
 ****************************/
#ifndef BLACKBEAR_H
#define BLACKBEAR_H
#include <iostream>
#include "animal.h"

using namespace std;

class Blackbear : public Animal {
public:
	Blackbear();
	Blackbear(int a);
	Blackbear &operator = (const Blackbear &old);
};

#endif

