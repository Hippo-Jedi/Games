/************************
 ** Program: sealion.h 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: class declaration for the Sealion class, contains member variables and functions
 ****************************/
#ifndef SEALION_H
#define SEALION_H
#include <iostream>
#include "animal.h"

using namespace std;

class Sealion : public Animal {
public:
	Sealion();
	Sealion(int a);
	Sealion &operator = (const Sealion &old);
};

#endif

