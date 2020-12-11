/************************
 ** Program: tiger.h 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: class declaration for the Tiger class, contains member variables and functions
 ****************************/
#ifndef TIGER_H
#define TIGER_H
#include <iostream>
#include "animal.h"

using namespace std;

class Tiger : public Animal {
public:
	Tiger();
	Tiger(int a);
	Tiger &operator = (const Tiger &old);
};

#endif
