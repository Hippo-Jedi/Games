/***********************i*
 ** Program: zoo.cpp 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: Holds function bodies for zoo type to run the zoo tycoon game
 ** Input: None 
 ** Output: Zoo data
 **************************/
#include <iostream>
#include "zoo.h"
#include "animal.h"
#include "tiger.h"
#include "sealion.h"
#include "blackbear.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

//Zoo class Constructor
Zoo::Zoo(){
	name = "";
	cash = 100000;
	revenue = 0;
	tiger_num = 0;
	sealion_num = 0;
	blackbear_num = 0;
	tigers = new Tiger[tiger_num];
        sealions = new Sealion[sealion_num];
        blackbears = new Blackbear[blackbear_num];
}

//Zoo class Constructor(Not Default)
Zoo::Zoo(const Zoo &old){
	name = old.name;
	cash = old.cash;
	tiger_num = old.tiger_num;
	sealion_num = old.sealion_num;
	blackbear_num = old.blackbear_num;
}

//Zoo clas destructor
Zoo::~Zoo(){
	delete [] tigers;
	delete [] sealions;
	delete [] blackbears;
}

/*******************
 ** Function: add_tiger
 ** Description: adds a tiger to the array of tiger animals and to your zoo
 ** Parameters: none
 ** Pre-Conditions: function called
 ** Post-Conditions: Tiger is added to the animal class array
 *********************/
void Zoo::add_tiger(int n){
	Tiger * newTigers = new Tiger[tiger_num + 1];
	for (int i=0; i<tiger_num; i++){
		newTigers[i] = tigers[i];
	}

	delete [] tigers;

	Tiger t(n);
	newTigers[tiger_num] = t;

	tigers = newTigers;
	tiger_num++;
}

/*******************
 ** Function: add_tigerBabies
 ** Description: adds a tiger baby to the array of tiger animals and to your zoo
 ** Parameters: none
 ** Pre-Conditions: function called
 ** Post-Conditions: Tiger baby is added to the animal class array
 **********************/
void Zoo::add_tigerBabies(){
	int n;
	cout << "Special Event: A litter of tigers has been born at your zoo!!!" << endl << " Three baby tigers have been added to your zoo" << endl;
	cout << "Enter a number to continue: ";
	cin >> n;
	add_tiger(0 - 1);
	add_tiger(0 - 1);
	add_tiger(0 - 1);
}


/*******************
 ** Function: remove_tiger
 ** Description: removes a tiger from the array of tiger animals and to your zoo
 ** Parameters: none
 ** Pre-Conditions: function called
 ** Post-Conditions: Tiger is removed from the animal class array
 *********************/
void Zoo::remove_tiger(){
	Tiger *newTigers = new Tiger[tiger_num - 1];
	for (int i=0; i<tiger_num - 1; i++){
		newTigers[i] = tigers[i];
	}

	delete [] tigers;

	tigers = newTigers;
	tiger_num--;
}

//Function that calls pay_sick_fee function when a tiger is sick
void Zoo::sick_tiger(){
	int type = 1;
	pay_sick_fee(type);
}

/*******************
 ** Function: add_sealion
 ** Description: adds a sealion to the array of tiger animals and to your zoo
 ** Parameters: none
 ** Pre-Conditions: function called
 ** Post-Conditions: Sealion is added to the animal class array
 **********************/
void Zoo::add_sealion(int n){
	Sealion *newSealions = new Sealion[sealion_num + 1];
	for (int i=0; i<sealion_num; i++){
		newSealions[i] = sealions[i];
	}

	delete [] sealions
;
	Sealion s(n);
	newSealions[sealion_num] = s;
	sealions = newSealions;
	sealion_num++;
}

/*******************
 ** Function: add_sealionBabies
 ** Description: adds a sealion baby to the array of tiger animals and to your zoo
 ** Parameters: none
 ** Pre-Conditions: function called
 ** Post-Conditions: Sealion baby is added to the animal class array
 **********************/
void Zoo::add_sealionBabies(){
	int n;
	cout << "Special Event: A baby sealion has been born at your zoo!!" << endl;
	cout << "Enter a number to continue: ";
        cin >> n;
	add_sealion(0 - 1);
}

/*******************
 ** Function: remove_sealion
 ** Description: removes a sealion from the array of tiger animals and to your zoo
 ** Parameters: none
 ** Pre-Conditions: function called
 ** Post-Conditions: Sealion is removed from the animal class array
 **********************/
void Zoo::remove_sealion(){
	Sealion *newSealions = new Sealion[sealion_num - 1];
        for (int i=0; i<sealion_num - 1; i++){
                newSealions[i] = sealions[i];
        }

        delete [] sealions;

	sealions = newSealions;
	sealion_num--;
}

//Function that calls the pay_sick_fee function when a sealion is sick
void Zoo::sick_sealion(){
	int type = 2;
	pay_sick_fee(type);
}

/*******************
 ** Function: add_blackbear
 ** Description: adds a black bear to the array of tiger animals and to your zoo
 ** Parameters: none
 ** Pre-Conditions: function called
 ** Post-Conditions: black bear is added to the animal class array
 **********************/
void Zoo::add_blackbear(int n){
	Blackbear *newBlackbears = new Blackbear[blackbear_num + 1];
	for (int i=0; i<blackbear_num; i++){
		newBlackbears[i] = blackbears[i];
	}

	delete [] blackbears;

	Blackbear b(n);
	newBlackbears[blackbear_num] = b;
	blackbears = newBlackbears;
	blackbear_num++;
}

/*******************
 ** Function: add_blackbearBabies
 ** Description: adds a black bear baby to the array of tiger animals and to your zoo
 ** Parameters: none
 ** Pre-Conditions: function called
 ** Post-Conditions: black bear baby is added to the animal class array
 **********************/
void Zoo::add_blackbearBabies(){
	int n;
	cout << "Special Event: A litter of baby black bears has been born at you zoo!!" << endl << " Two baby black bears have been added to your zoo" << endl;
	cout << "Enter a number to continue: ";
        cin >> n;
	add_blackbear(0 - 1);
	add_blackbear(0 - 1);
}

/*******************
 ** Function: remove_blackbear
 ** Description: removes a black bear from the array of tiger animals and to your zoo
 ** Parameters: none
 ** Pre-Conditions: function called
 ** Post-Conditions: black bear is removed from the animal class array
 **********************/
void Zoo::remove_blackbear(){
	Blackbear *newBlackbears = new Blackbear[blackbear_num - 1];
        for (int i=0; i<blackbear_num - 1; i++){
                newBlackbears[i] = blackbears[i];
        }

        delete [] blackbears;

	blackbears = newBlackbears;
	blackbear_num--;	
}

//Function that calls the pay_sick_fee function when a black bear is sick
void Zoo::sick_blackbear(){
	int type = 3;
	pay_sick_fee(type);
}

/*******************
 ** Function: random_event
 ** Description: generates a random event every month
 ** Parameters: none
 ** Pre-Conditions: function called
 ** Post-Conditions: function is ran based on the random event generated
 *********************/
void Zoo::random_event(){
	int random_event = rand() % 4 + 1;
	int bonus;

	switch (random_event){
		case 1: sickness(); break;
		case 2: attendance_boom(bonus); break;
		case 3: baby_born();	break;	
		case 4: 
			cout << "Special Event: Nothing special happened" << endl;
			break;
	}
}

/*******************
 ** Function: get_type
 ** Description: gets the type of animal that can be used for the random event
 ** Parameters: boolean for each type of animal
 ** Pre-Conditions: function called
 ** Post-Conditions: boolean parameters are cahnged accordingly
 **********************/
void Zoo::get_type(bool &t, bool &s, bool &b){
	if (tiger_num){
		t = true; 
	}
	if (sealion_num){
		s = true;
	}
	if (blackbear_num){
		b = true;
	}
}

/*******************
 ** Function: sickness
 ** Description: function for sickness random event
 ** Parameters: none
 ** Pre-Conditions: randomly chosen
 ** Post-Conditions: randomly decides an animal in the zoo to get sick
 **********************/
void Zoo::sickness(){
	bool t = false;
	bool s = false;
	bool b = false;
	int n, i = 0;
	get_type(t, s, b);
	if (t){
                if (s){
                        if (b){
                                n = rand() % 3 + 1;
                                switch(n){
                                        case 1: sick_tiger(); break;
                                        case 2: sick_sealion(); break;
                                        case 3: sick_blackbear(); break;
                                }
                        }
                        else {
                                n = rand() % 2 + 1;
                                switch(n){
                                        case 1: sick_tiger(); break;
                                        case 2: sick_sealion(); break;
                                }
                        }
                }
                else {
                        sick_tiger();
                }
        }
        else if (s){
                if (b){
                        n = rand() % 2 + 1;
                        switch(n){
                                case 1: sick_sealion(); break;
                                case 2: sick_blackbear(); break;
                        }
                }
                else {
                        sick_sealion();
                }
        }
        else if (b){
                sick_blackbear();
        }
        else {
                cout << "Special Event: Nothing special happened" << endl;
        }
}

/*******************
 ** Function: pay_sick_fee
 ** Description: function for sickness random event
 ** Parameters: none
 ** Pre-Conditions: sickness random event has been called
 ** Post-Conditions: asks user if they wish to save the animal, if not the animal is removed
 **********************/
void Zoo::pay_sick_fee(int type){
	int n;
	if (type == 1){
		cout << "The sick animal is a tiger, the medical bill to save them is $" << 6000 << endl;
		cout << "Enter 1 if you want to pay this bill: ";
		cin >> n;
		if (n == 1){
			cash = cash - 6000;
		}
		else {
			cout << "A tiger has died from there illness" << endl;
			remove_tiger();	
		}
	}
	else if (type == 2){
		cout << "The sick animal is a sealion, the medical bill to save them is $" << 350 << endl;
		cout << "Enter 1 if you want to pay this bill: ";
		cin >> n;
		if (n == 1){
			cash = cash - 350;
		}
		else {
			cout << "A sealion has died from there illness" << endl;
			remove_sealion();
		}
	}
	else if (type == 3){
		cout << "The sick animal is a black bear, the medical bill to save them is $" << 2500 << endl;
		cout << "Enter 1 if you want to pay this bill: ";
		cin >> n;
		if (n == 1){
			cash = cash - 2500;
		}
		else {
			cout << "A black bear has died from there illness" << endl;
			remove_blackbear();
		}
	}
}

/*******************
 ** Function: attendance_boom
 ** Description: function for attendance boom random event
 ** Parameters: none
 ** Pre-Conditions: sealions must be currently in the zoo
 ** Post-Conditions: sealions generate extra revenue for the zoo
 **********************/
void Zoo::attendance_boom(int &bonus){
	int total = 0;
	int n;
	if (sealion_num > 0){
		cout << "Special Event: There has been a boom in zoo attendance" << endl;
		for (int i=0; i<sealion_num; i++){
			bonus = rand() % 151 + 250;
			sealions[i].set_payoff(sealions[i].get_payoff() + bonus);
			total = total + bonus;
		}
		cout << "The Zoo is poppin and your Sealions have earned you an extra $" << total << endl;
		cout << "Enter a number to continue: ";
		cin >> n;
	}
	else {
		cout << "Special Event: Nothing special happened" << endl;
	}
	
}

/*******************
 ** Function: baby_born
 ** Description: checks to see if you have enough animals for a baby to be born
 ** Parameters: none
 ** Pre-Conditions: must have enough adult animals
 ** Post-Conditions: animal type is born and a baby is added to the animal class array
 **********************/
void Zoo::baby_born(){
	int n, i = 0;
	bool t_check = false, s_check = false, b_check = false;
	baby_check(t_check, s_check, b_check);
	if (t_check){
		if (s_check){
			if (b_check){
				n = rand() % 3 + 1;
				switch(n){
					case 1: add_tigerBabies(); break;
					case 2: add_sealionBabies(); break;
					case 3: add_blackbearBabies(); break;
				}
			}
			else {
				n = rand() % 2 + 1;
				switch(n){
					case 1: add_tigerBabies(); break;
					case 2: add_sealionBabies(); break;
				}
			}
		}
		else {
			add_tigerBabies();
		}
	}
	else if (s_check){
		if (b_check){
			n = rand() % 2 + 1;
			switch(n){
				case 1: add_sealionBabies(); break;
				case 2: add_blackbearBabies(); break;
			}
		}
		else {
			add_sealionBabies();
		}
	}
	else if (b_check){
		add_blackbearBabies();
	}
	else {
		cout << "You don't have enough adults for a birth" << endl;
	}
}

/*******************
 ** Function: baby_check
 ** Description: checks zoo animals to see if a baby can be born
 ** Parameters: boolean variables for each animal
 ** Pre-Conditions: baby is born has been called for random event
 ** Post-Conditions: checks for 2 adults, changes boolean parameters accordingly
 **********************/
void Zoo::baby_check(bool &t_check, bool &s_check, bool &b_check){
	int t, s, b = 0;
	for (int i=0; i<tiger_num; i++){
		if (tigers[i].get_age() > 48){
			t++;
		}
	}
	if (t >= 2){
		t_check = true;
	}
	for (int j=0; j<sealion_num; j++){
		if (sealions[j].get_age() > 48){
			s++;
		}
	}
	if (s >= 2){
		s_check = true;
	}
	for (int k=0; k<blackbear_num; k++){
		if (blackbears[k].get_age() > 48){
			b++;
		}
	}
	if (b >= 2){
		b_check = true;
	}
}

/*******************
 ** Function: get_profit
 ** Description: displays the revenue for the month
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: adds to revenue and displays monthly revenue
 **********************/
void Zoo::get_profit(){
	for (int i=0; i<tiger_num; i++){
		if (tigers[i].get_age() > 6){
			tigers[i].set_payoff(1200);
			revenue = revenue + tigers[i].get_payoff();
		}
		else {
			tigers[i].set_payoff(2400);
                        revenue = revenue + tigers[i].get_payoff();
		}
	}
	for (int j=0; j<sealion_num; j++){
		if (sealions[j].get_age() > 6){
			sealions[j].set_payoff(140);
			revenue = revenue + sealions[j].get_payoff();
		}
		else {
			sealions[j].set_payoff(280);
                        revenue = revenue + sealions[j].get_payoff();
		}
	}
	for (int k=0; k<blackbear_num; k++){
		if (blackbears[k].get_age() > 6){
			blackbears[k].set_payoff(500);
			revenue = revenue + blackbears[k].get_payoff();
		}
		else {
			blackbears[k].set_payoff(1000);
                        revenue = revenue + blackbears[k].get_payoff();
		}
	}
	cout << endl << "Total revenue for the month: $" << get_revenue() << endl << "_________________________________________" << endl;
}

/*******************
 ** Function: grow
 ** Description: gets and adds food costs for the month/addes a monthly to all animals ages in the zoo
 ** Parameters: address to total food cost for the month
 ** Pre-Conditions: none
 ** Post-Conditions: food cost is gotten and added to total expense for the month
 **********************/
void Zoo::grow(double &total){
	double tiger_cost, sealion_cost, blackbear_cost;
	for (int i=0; i<tiger_num; i++){
		tiger_cost = rand() % 64 + 32;
		tigers[i].set_age(tigers[i].get_age() + 1);
		tigers[i].set_food_cost(5 * tiger_cost);
		cash = cash - tigers[i].get_food_cost();
		total = total + tigers[i].get_food_cost();
	}
	for (int j=0; j<sealion_num; j++){
		sealion_cost = rand() % 64 + 32;
		sealions[j].set_age(sealions[j].get_age() + 1);
		sealions[j].set_food_cost(sealion_cost);
		cash = cash - sealions[j].get_food_cost();
		total = total + sealions[j].get_food_cost();
	}
	for (int k=0; k<blackbear_num; k++){
		blackbear_cost = rand() % 64 + 32;
		blackbears[k].set_age(blackbears[k].get_age() + 1);
		blackbears[k].set_food_cost(3 * blackbear_cost);
		cash = cash - blackbears[k].get_food_cost();
		total = total + blackbears[k].get_food_cost();
	}
}

/*******************
 ** Function: game_info
 ** Description: displays rules for the game
 ** Parameters: none
 **********************/
void Zoo::game_info(){
	cout << "Game Guidlines" << endl;
	cout << "1. Play by month" << endl;
	cout << "2. Three types of animals: Tigers, Sealions, Black Bears" << endl;
	cout << "3. Animal is an adult at 4yrs old or 48 months" << endl;
	cout << "4. Every month there is a special event" << endl;
}

/*******************
 ** Function: start_game
 ** Description: begins the game and asks for initial adult animal to buy
 ** Parameters: boolean address for exit and play variables
 ** Pre-Conditions: user chooses to play game
 ** Post-Conditions: initial animals are added to the animal class array to begin the game
 **********************/
void Zoo::start_game(bool &play, bool &exit){
	int choice;
	string n;
	system("clear");
	cout << "__________ZOO TYCOON__________" << endl << endl;
	game_info();
	cout << endl << "Enter 1 => Play Zoo Tycoon" << endl;
	cout << "Enter 2 => Exit" << endl;
	cin >> choice;
	do {
		if (choice == 1){
			cout << "Enter the name of you Zoo: " << endl;
			cin >> n;
			name = n;
			cout << "You are starting the game with a cash balance of $" << cash << endl;
			buy();	
			play = true;
			exit = true;
		}
		else if (choice == 2){
			cout << endl << "Exiting...." << endl << endl;
			exit = true;
		}
	} while (!exit);

}

/*******************
 ** Function: get_status
 ** Description: gets age status for an animal
 ** Parameters: age of animal
 ** Pre-Conditions: none
 ** Post-Conditions: returns the age status of the animal as a string
 **********************/
string Zoo::get_status(int age){
	string status;
	if (age >= 48){
		status = "Adult";
	}
	else if (age < 48 && age > 6 ){
		status = "Adolescence";
	}
	else {
		status = "Baby";
	}
	return status;
}

/*******************
 ** Function: show_animals
 ** Description: displays animals to the user and their data
 ** Parameters: none
 ** Pre-Conditions: month has pased
 ** Post-Conditions: displays animal age, status, and monthly food cost
 **********************/
void Zoo::show_animals(){
	int t = 1;
	int s = 1;
	int b = 1;
	cout << "__________Animal Data____________________" << endl;
	cout << endl << "Tigers" << endl;
	for (int i=0; i<tiger_num; i++){
		cout << t << ".  " << tigers[i].get_age() << " months,  " << get_status(tigers[i].get_age()) << ",  Food Cost $" << tigers[i].get_food_cost() << ",  Revenue $" << tigers[i].get_payoff() << endl;
		t++;
	}
	cout << endl << "Sealions" << endl;
	for (int j=0; j<sealion_num; j++){
		cout << s << ".  " << sealions[j].get_age() << " months,  " << get_status(sealions[j].get_age()) << ",  Food Cost $" << sealions[j].get_food_cost() << ",  Revenue $" << sealions[j].get_payoff() << endl;
		s++;
	}
	cout << endl << "Black Bears" << endl;
	for (int k=0; k<blackbear_num; k++){
		cout << b << ".  " << blackbears[k].get_age() << " months,  " << get_status(blackbears[k].get_age()) << ",  Food Cost $" << blackbears[k].get_food_cost() << ",  Revenue $" << blackbears[k].get_payoff() <<  endl;
		b++;
	}
	cout << "_________________________________________" << endl << "_________________________________________" << endl;
}

/*******************
 ** Function: buy
 ** Description: asks the user if they wish to buy an adult animal
 ** Parameters: none
 ** Pre-Conditions: month has passed
 ** Post-Conditions: subtracts cost from total cash and adds an animal to the animal class array if an animal is bought
 **********************/
void Zoo::buy(){
	int choice1, choice2, n;
	int age = 48;
	cout << "What type and amount of animal would you like to buy? (2 max)" << endl;
	cout << "1. Tiger - $12000 each" << endl << "2. Sealion - $700 each" << endl << "3. Black Bear - $5000 each" << endl << "Selection: ";
	cin >> choice1;
	cout << "Quantity(1 or 2): ";
	cin >> choice2;
	
	if (choice1 == 1){
		if (choice2 == 2){
			add_tiger(age);
			add_tiger(age);
			cash = cash - 24000;
		}
		else {
			add_tiger(age);
                	cash = cash - 12000;
		}
	}
	if (choice1 == 2){
		if (choice2 == 2){
			add_sealion(age);
			add_sealion(age);
			cash = cash - 1400;
		}
		else {
			add_sealion(age);
                	cash = cash - 700;
		}
	}
	if (choice1 == 3){
		if (choice2 == 2){
			add_blackbear(age);
			add_blackbear(age);
			cash = cash - 10000;
		}
		else {
			add_blackbear(age);
                	cash = cash - 5000;
		}
	}
	cout << "Enter a number to continue: ";
	cin >> n;
}

/*******************
 ** Function: show_stats
 ** Description: displays monthly data, includes total cash balance and monthly total food cost
 ** Parameters: none
 **********************/
void Zoo::show_stats(double total){
	cout << "_________________________________________" << endl << "__________Monthly Balance Sheet__________" << endl;
	cout << "Current Balance: $" << cash << endl << endl;
	cout << "Total Cost of Food for the Month: $" << total << endl;
        get_profit();
}

/*******************
 ** Function: run_game
 ** Description: runs this function every month, runs other functions to diplay monthly data
 ** Parameters: boolean address for play variable
 ** Pre-Conditions: month has passed
 ** Post-Conditions: displays and runs data function for the monthly stats, also asks to buy animal and displays the random event
 **********************/
void Zoo::run_game(bool &play){
	double total;
	int choice, v = 0;
	string n;
	random_event();
	grow(total);
	show_stats(total);
	show_animals();
	if (cash < 0){
		cout << endl << "Your zoo has gone bankrupt! Game Over" << endl;
                cout << endl << "Exiting ..." << endl;
                play = false;
	}
	else if (cash > 1000000){
		cout << endl << "You have become a millionaire!" << endl;
                cout << "Congratulations, You win!!" << endl;
                cout << endl << "Exiting ..." << endl;
                play = false;
	}
	else{
		cout << "What would you like to do?" << endl;
		cout << "Buy animal (press 1)" << endl << "Skip to next month (press 2)" << endl << "End game (press 3)" << endl << "Selection: ";
		cin >> n;
		while(!(v)){
			if (!(check_int(n))){
				choice = atoi(n.c_str());
				if (choice > 0 && choice < 4){
					v = 1;
				}
				else {
					cout << "Enter a valid options: " << endl;
					cin >> n;
				}
			}
			else {
				cout << "Enter a valid option: " << endl;
				cin >> n;
			}
		}
		switch(choice){
			case 1: buy(); break;
			case 2: break;
			case 3: exit(play); break;
		}
	}
}

//function that exits the game
void Zoo::exit(bool &play){
	cout << endl << "Exiting ..." << endl << endl;
	play = false;
}

//mustator funtion to set cash value
void Zoo::set_cash(double n){
	cash = n;
}

//mutator funtion to reset total monthly revenue
void Zoo::reset_revenue(){
	revenue = 0;
}

//mutator function to get total cash value
double Zoo::get_cash(){
	return cash;
}

//mutator function to get total revenue
double Zoo::get_revenue(){
	return revenue;
}

//mutator function to set the name of zoo
void Zoo::set_name(string n){
	name = n;
}

//mutator function to get the name of the zoo
string Zoo::get_name(){
	return name;
}

/*******************
 ** Function: check_int
 ** Description: checks the input from the user to see if its valid
 ** Parameters: string variable to be checked
 **********************/
int check_int(string n){
	for (int i=0; i<n.length(); i++){
		if (!(n.at(i) > '0' && n.at(i) <= '9')) {
			return 1;
		}
	}
	return 0;
}









