/***********************i*
 ** Program: animal.cpp 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: Holds function bodies for Animal class type to run the zoo tycoon game
 ** Input: None 
 ** Output: animal data
 ****************************/
#include "animal.h"
#include <iostream>

using namespace std;

//default constructor
Animal::Animal(){

}

//mutator function to get age
int Animal::get_age(){
	return age;
}

//mutator function to set age
void Animal::set_age(int n){
	age = n;
}

//function that increases age
void Animal::increment_month(){
	this-> age++;
}

//mutator function that gets food cost
double Animal::get_food_cost(){
	return food_cost;
}

//mutator function that sets food cost
void Animal::set_food_cost(double n){
	food_cost = n;
}

//mutator function that gets payoff
double Animal::get_payoff(){
	return payoff;
}

//mutator function that sets payoff 
void Animal::set_payoff(double n){
	payoff = n;
}













