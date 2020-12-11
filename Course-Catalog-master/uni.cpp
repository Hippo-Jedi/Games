#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "uni.h"
#include "course.h"
#include "catalog.h"

using namespace std;

//Constructor for University class
University::University(int nc, int nt){
	name = "";
	address = "";
	current_term = "";
	num_teachers = nt;
	teachers = new teacher[num_teachers];
	this-> make_teachers(num_teachers);
	this->make_uni();
	num_courses = nc;
	Catalog cat;
	this->cat.make_courses();	 
}

//Destructor for University class
University::~University(){
	delete [] teachers;
}

/***************
 ** Function: welcome
 ** Description: welcomes the user and runs functions for a teacher or a student
 ** Parameters: none 
 ** Pre-conditions: function is ran or user has logged out
 ** Post-conditions: teacher or student login is called or quit program is called;
 ****************/
int University::welcome(){
	int run = 1;
	int choice;
	while(run){
		cout << "Welcome to the Course Catalog" << endl;
		cout << endl << "University Informatin:" << endl;
		cout << "Name: " << name << endl;
		cout << "Address: " << address << endl;
		cout << "Current Term: " << current_term << endl << endl;
		cout << "Are you a student (press 1) or a teacher (press 2) or would you like to quit (press 3)? ";
		cin >> choice;
		if (choice == 1){
			run_student(run, choice);
		}
		else if (choice == 2){
			if (run_login()){
				run_teacher(run, choice);
			}
			else {
				cout << endl << "Teacher Login Failed" << endl;
			}
		}
		else if (choice == 3){
			run = 0;
		}
		else {
			cout << endl << "Please enter a valid input" << endl;
		}	
	}
	return 0;
}

/***************
 ** Function: login 
 ** Description: checks id and passwords with teacher struct array
 ** Parameters: string id password and n for to find correct teacher 
 ** Pre-conditions: teacher login information is recieved
 ** Post-conditions: login info is either accepted or denied
 ****************/
bool University::login(string id, string password, int &n){
	for (int i=0; i<num_teachers; i++){
		int c = 0;
		if (id == teachers[i].id){
			c++;
		}
		if (strcmp(password.c_str(), teachers[i].password.c_str()) == 0){
			c++;
		}
		if (c == 2){
			n = i;
			return true;
		}
	}
	return false;
}

/***************
 ** Function: run_login
 ** Description: either welcomes teacher with first and last name or denies login
 ** Parameters: none
 ** Pre-conditions: teacher login
 ** Post-conditions: teacher is accepted or denied access
 ****************/
bool University::run_login(){
	int place, n;
	string id, password;
	
	cout << endl << "TEACHER LOGIN" << endl;

	cout << "Enter Teacher ID: " << endl;
	cin >> id;

	cout << "Enter Teacher Password: " << endl;
	cin >> password;

	if(login(id, password, n)){
		cout << endl << "Welcome " << teachers[n].first << " " << teachers[n].last << endl << endl;
		return true;
	}
	else {
		return false;
	}	
}

/***************
 ** Function: run_teacher
 ** Description: runs the teacher options screen for search choice
 ** Parameters: none
 ** Pre-conditions: teacher has been logged in
 ** Post-conditions: choices are displayed to the user
 ****************/
void University::run_teacher(int &run, int choice){
	while(run){
		teacher_options(run, choice);
	}
}

/***************
 ** Function: run_student
 ** Description: runs the student options screen for search choice
 ** Parameters: none
 ** Pre-conditions: student has been logged in
 ** Post-conditions: choices are displayed to the user
 *****************/
void University::run_student(int &run, int choice){
	while(run){
		student_options(run, choice);
	}
}

/***************
 ** Function: teacher_choice 
 ** Description:  Gets teacher choice from the option for search and checks it
 ** Parameters: none
 ** Pre-conditions: teacher has logged in
 ** Post-conditions: teacher has picked a search option
 *****************/
int University::teacher_choice(){
	int valid = 0, choice;
	string n;
	cout << "How would you like to view or or change the catalog? (Enter number)" << endl;
	cout << "1. Search by Term" << endl << "2. Search by Time" << endl << "3. View Entire Catalog" << endl << "4. Logout" << endl;
	cout << "Choice: ";	
	cin >> n;
	while(!(valid)){
		if (!(check_int(n))){
			choice = atoi(n.c_str());
			if (choice > 0 && choice < 5){
				valid = 1;
			}
			else{
				cout << "Enter a valid choice: ";
				cin >> n;
			}
		}
		else{
			cout << "Enter a valid choice: ";
			cin >> n;
		}
	}
	return choice;
}

/***************
 ** Function: teacher_options
 ** Description: runs functions based on teacher input from teacher_choice func
 ** Parameters: run reference
 ** Pre-conditions: option choice is received from user
 ** Post-conditions: correct functions are ran based on user choice
 ****************/
void University::teacher_options(int &run, int choice){
	int c = teacher_choice();
	switch(c){
		case 1: search_term(choice); break;
                case 2: search_time(choice); break;
                case 3: view_catalog(choice); break;
                case 4: run = 0; break;
	}
}

/***************
 ** Function: student_choice 
 ** Description:  Gets student choice from the option for search and checks it
 ** Parameters: none
 ** Pre-conditions: student has logged in
 ** Post-conditions: student has picked a search option
 ****************/
int University::student_choice(){
	int valid = 0, choice;
	string input;
	cout << "How would you like to search the catalog? " << endl;
        cout << "1. Search by Term" << endl << "2. Search by Time" << endl << "3. View Entire Catalog" << endl << "4. Logout" << endl;
        cout << "Choice: ";
	cin >> input;
        while(!(valid)){
                if (!(check_int(input))){
                        choice = atoi(input.c_str());
                        if (choice > 0 && choice < 5){
                                valid = 1;
                        }
                        else{
                                cout << "Enter a valid choice: ";
                                cin >> input;
                        }
                }
                else{
                        cout << "Enter a valid choice: ";
                        cin >> input;
                }
        }
        return choice;
}

/***************
 ** Function: student_options
 ** Description: runs functions based on student input from student_choice func
 ** Parameters: run reference
 ** Pre-conditions: option choice is received from user
 ** Post-conditions: correct functions are ran based on user choice
 *****************/
void University::student_options(int &run, int choice){
	int c = student_choice();
	switch(c){
		case 1: search_term_student(choice); break;
		case 2: search_time_student(choice); break;
		case 3: view_catalog(choice); break;
		case 4: run = 0; break;
	}
}

/***************
 ** Function: make_teachers
 ** Description: makes and puts teacher data to the constructor's' array
 ** Parameters: none
 ** Pre-conditions: teacher text file is present and filled
 ** Post-conditions: teacher array is filled with input from file
 ****************/
void University::make_teachers(int num_teachers){
	ifstream data;
	data.open("teachers.txt");
	
	for (int i=0; i<num_teachers; i++){
		string hold;
		getline(data, hold, ' ');
		teachers[i].id = hold;
	
		getline(data, hold, ' ');
		teachers[i].password = hold;
		
		getline(data, hold, ' ');
		teachers[i].first = hold;
		
		getline(data, hold, '\n');
		teachers[i].last = hold;
	}
	data.close();
}

/***************
 ** Function: make_uni
 ** Description: makes and puts university data to University class members 
 ** Parameters: none
 ** Pre-conditions: university text file
 ** Post-conditions: university info is set and available within class
 **************/
void University::make_uni(){
	ifstream data;
	data.open("university.txt", ifstream::in);
	
	getline(data, name);
	getline(data, address);
	getline(data, current_term);
	
	data.close();
}

/***************
 ** Function: view_catalog
 ** Description: runs catalog function to print catalog 
 ** Parameters: none
 ** Pre-conditions: catalog data
 ** Post-conditions: catalog data is presented to user
 ***************/
void University::view_catalog(int choice){
	cat.get_courses(choice);
}

/***************
 ** Function: search_term_student
 ** Description: searches and runs functions based on term searched 
 ** Parameters: none
 ** Pre-conditions: course and catalog data
 ** Post-conditions: search results are presented to user
 ****************/
void University::search_term_student(int c){
	string choice;
        cout << "What term would you like to search for? " << endl;
        cout << "Fall (Enter F)" << endl << "Winter (Enter W)" << endl << "Spring (Enter S)" << endl << "Summer (Enter U)" << endl << "Choice: ";
        cin >> choice;	

	if (choice == "F"){
		cout << endl << "Here are courses during Fall term:" << endl;
		cat.show_term_student(choice, c);
	}
	else if (choice == "W"){
		cout << endl << "Here are courses during Winter term:" << endl;
		cat.show_term_student(choice, c);
	}
	else if (choice == "S"){
		cout << endl << "Here are courses during Spring term:" << endl;
		cat.show_term_student(choice, c);
	}
	else if (choice == "U"){
		cout << endl << "Here are courses during Summer term:" << endl;
		cat.show_term_student(choice, c);
	}
}

/***************
 ** Function: search_term
 ** Description: searches and runs functions based on term searched 
 ** Parameters: none
 ** Pre-conditions: course and catalog data
 ** Post-conditions: search results are presented to user
 *****************/
void University::search_term(int c){
	string choice;
        cout << "What term would you like to search for? " << endl;
        cout << "Fall (Enter F)" << endl << "Winter (Enter W)" << endl << "Spring (Enter S)" << endl << "Summer (Enter U)" << endl << "Choice: ";
        cin >> choice;

	if (choice == "F"){
                cout << endl << "Here are courses during Fall term:" << endl;
                cat.show_term(choice, c);
        }
        else if (choice == "W"){
                cout << endl << "Here are courses during Winter term:" << endl;
                cat.show_term(choice, c);
        }
        else if (choice == "S"){
                cout << endl << "Here are courses during Spring term:" << endl;
                cat.show_term(choice, c);
        }
        else if (choice == "U"){
                cout << endl << "Here are courses during Summer term:" << endl;
                cat.show_term(choice, c);
        }
}

/***************
 ** Function: search_time_student
 ** Description: asks user for time slot they are searching for
 ** Parameters: none
 ** Pre-conditions: catalog data
 ** Post-conditions: search results are presented to user
 ****************/
void University::search_time_student(int choice){
	string hour;
	int n;
	cout << "Enter a start time of classes to search for: " << endl;
        cout << "Enter 1 for AM or enter 2 for PM: " << endl;
        cin >> n;

	cout << "Enter a start time of classes to search for: " << endl;
	cin >> hour;
	
	get_time(n, hour, choice);
}

/***************
 ** Function: get_time
 ** Description: runs catalog function to print courses by time 
 ** Parameters: none
 ** Pre-conditions: catalog data
 ** Post-conditions: catalog class functions are ran and data is presented to user
 ****************/
void University::get_time(int n, string hour, int choice){
	if (n == 1){
		hour = hour + ":00am";
		cat.show_am_time(hour, choice);
	}
	else if (n == 2){
		hour = hour + ":00pm";
		cat.show_pm_time(hour, choice);
	}
}
/***************
 ** Function: search_time
 ** Description: asks teacher for time slot they are searching for 
 ** Parameters: none
 ** Pre-conditions: catalog data
 ** Post-conditions: runs functins to display data
 ****************/
void University::search_time(int choice){
	string hour;
	int n;
	cout << "Enter a start time of classes to search for: " << endl;
        cout << "Enter 1 for AM or enter 2 for PM: " << endl;
        cin >> n;

	cout << "Enter the hour at which the course starts (just number): " << endl;
        cin >> hour;
        get_time(n, hour, choice);
	
}

int check_int(string n){
	for (int i=0; i<n.length(); i++){
		if (!(n.at(i) > '0' && n.at(i) <= '9')){
			return 1;
		}
	}
	return 0;
}

int get_num_courses(){
        int count = 0;
        string line;
        ifstream data("courses.txt");

        while(getline(data, line)){
                count++;
        }
        return count;
}

int get_num_teachers(){
        int count = 0;
        string line;
        ifstream data("teachers.txt");

        while(getline(data, line)){
                count++;
        }
        return count;
}



