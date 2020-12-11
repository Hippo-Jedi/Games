/************************
 ** Program: zoo.h 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: class declaration for the Zoo class, contains member variables and functions
 ****************************/
#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include "animal.h"
#include "tiger.h"
#include "sealion.h"
#include "blackbear.h"

using namespace std;

class Zoo {
private:
	Tiger *tigers;
	Sealion *sealions;
	Blackbear *blackbears;
	string name;
	int tiger_num;
	int sealion_num;
	int blackbear_num;
	double cash;
	double revenue;
	double expense;
public:
	Zoo();
	Zoo(const Zoo&);
	~Zoo();
	void add_tiger(int n);
	void sick_tiger();
	void remove_tiger();
	void add_tigerBabies();
	void add_sealion(int n);
	void sick_sealion();
	void remove_sealion();
	void add_sealionBabies();
	void add_blackbear(int n);
	void add_blackbearBabies();
	void sick_blackbear();
	void remove_blackbear();
	void random_event();
	void get_type(bool &t, bool &s, bool &b);
	void sickness();
	void pay_sick_fee(int type);
	void attendance_boom(int &bonus);
	void baby_check(bool &t_check, bool &s_check, bool &b_check);
	void baby_born();
	void get_profit();
	void grow(double &total);
	void set_cash(double n);
	double get_cash();
	void set_name(string n);
	string get_name();
	void reset_revenue();
	double get_revenue();
	void show_stats(double total);
	void game_info();
	void start_game(bool &play, bool &exit);
	void exit(bool &play);
	void run_game(bool &play);
	void show_animals();
	void buy();
	string get_status(int age);
};
int check_int(string n);

#endif
