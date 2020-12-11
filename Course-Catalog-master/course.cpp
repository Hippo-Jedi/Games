#include <iostream>
#include <sstream>
#include "course.h"
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;
/***************************
 **** Function: course
 **** Desription: sets all members of class Course to null
 *****************************/
Course::Course(){
        name = "";
        instructor = "";
	number = 0;
        current_enroll = 0;
	course_time = new schedule[NULL]	;
	roster = new string[NULL];
}

Course::Course(const Course &obj){
	srand (time(NULL));
	int r = rand() % 100 + 1;
	this-> name = obj.name;
	this-> instructor = obj.instructor;
	this-> number = obj.number;
	for (int i=0; i<5; i++){
		this-> course_time[i] = obj.course_time[i];
	}
	this-> current_enroll = obj.current_enroll;
	if (current_enroll > 0){
		for (int j=0; j<current_enroll; j++){
			this-> roster[j] = obj.roster[j];
		}
	}
}



Course::~Course(){
	delete [] course_time;
	
	delete [] roster;
}

void Course::get_course_data(ifstream &data){
	string hold, line;

	getline(data, hold, ' ');
	name = hold;

	getline(data, hold, ' ');
	instructor = hold;

	course_time = new schedule[5];
	getline(data, hold, ' ');
	course_time->term = hold;

	getline(data, hold, ' ');
	course_time->days = hold;

	getline(data, hold, ' ');
	course_time->start = hold;

	getline(data, hold, ' ');
	course_time->end = hold;

	getline(data, hold, ' ');
	course_time->location = hold;
	
	getline(data, line, '\n');
	stringstream s(line);

	if (check_space(line) == true){
		getline(s, hold, ' ');
		current_enroll = atoi(hold.c_str());
		roster = new string[current_enroll];
		for (int i=0; i<current_enroll; i++){
			getline(s, hold, ' ');
			roster[i] = hold;
		}	
	}	
	else {
		current_enroll = 0;
	}
}

bool Course::check_space(string line){
	for (int i=0; i<line.length(); i++){
		if (line.at(i) == ' '){
			return true;
		}
	}
	return false;
}

void Course::check_terms(string choice){
	for (int i=0; i<5; i++){
		if (choice == course_time[i].term){
			show_courses(i);
		}
	}
}

void Course::check_am_times(string hour){
	for (int i=0; i<5; i++){
		if (hour == course_time[i].start){
			show_courses(i);
		}
	}
}

void Course::check_pm_times(string hour){
	for (int i=0; i<5; i++){
                if (hour == course_time[i].start){
                        show_courses(i);
                }
        }
}

void Course::show_courses(int i){
	cout << "Courses Name: " << name << endl;
	cout << "Course Number: " << get_number() << endl;
	cout << "Instructor Name: " << instructor << endl;
	cout << "Current Enrollment: " << current_enroll << endl << endl;
	cout << "Schedule: " << endl;
	cout << "Term: " << course_time->term << endl;
	cout << "Days: " << course_time->days << endl;
	cout << "Start Time: " << course_time->start << endl;
	cout << "End Time: " << course_time->end << endl;
	cout << "Location: " << course_time->location;
	cout << endl << endl;
	cout << "Enrolled Student IDs: ";
	if (current_enroll > 0){
		for (int j=0; j<current_enroll; j++){
			cout << roster[j] << " ";
		}
	}
	else if (current_enroll == 0){
		cout << "none";
	}
	cout << endl << endl << "__________NEXT__________" << endl << endl;
}

void Course::set_name(string n){
        this->name = n;
}

string Course::get_name(){
        return name;
}

void Course::set_number(int n){
	number = n;
}

int Course::get_number(){
	return number;
}

void Course::set_instructor(string n){
        this->instructor = n;
}

string Course::get_instructor(){
        return instructor;
}

void Course::set_current_enrollment(int n){
        this->current_enroll = n;
}

int Course::get_current_enrollment(){
        return current_enroll;
}


