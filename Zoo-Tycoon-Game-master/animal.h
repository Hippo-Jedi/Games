/************************
 ** Program: animal.h 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: class declaration for the Animal class, contains member variables and functions
 ****************************/
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

using namespace std;

class Animal {
protected:
	string name;
	int age;
	double food_cost;
	double payoff;
public:
	Animal();
	void set_age(int n);
	int get_age();
	void set_name(string n);
	string get_name();
	void set_food_cost(double n);
	double get_food_cost();
	void set_payoff(double n);
	double get_payoff();
	void increment_month();
};

#endif
