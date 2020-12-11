#include <iostream>
#include <fstream>
#include "catalog.h"

using namespace std;

Catalog::Catalog(){
	num_courses = 0;
	this-> count_courses();
	courses = new Course[num_courses];
}

Catalog::~Catalog(){
	delete [] courses;
}

void Catalog::count_courses(){
	int count = 0;
	string n;
	ifstream file("courses.txt");

	while(getline(file, n)){
		count++;
	}
	num_courses = count;
}

void Catalog::make_courses(){
	ifstream file("courses.txt");
	for (int i=0; i<num_courses; i++){
		courses[i].get_course_data(file);
	}
}

void Catalog::show_term_student(string choice, int c){
	int n, x;
	string id, name;
	for (int i=0; i<num_courses; i++){
		courses[i].check_terms(choice);
	}
	if (c == 1){
		cout << endl << "Would you like to enroll in any of these classes?" << endl << "1 = yes, 2 = no" << endl;
		cin >> n;
		if (n == 1){
			cout << "Please Enter the cousrse number you would like to enroll in: ";
			cin >> x;
			cout << "What is your name: ";
			cin >> name;
			cout << "What is your Student ID: ";
			cin >> id;
			enroll(x, name, id);
		}
	}
}

void Catalog::enroll(int x, string name, string id){
	string course, term;
	for (int i=0; i<num_courses; i++){
		if (x == courses[i].number){
			course = courses[i].name;
			term = courses[i].course_time->term;
		} 
	}
	fstream data;
	data.open("enrollment.txt", fstream::in | fstream::out | fstream::app);
	data << name << ' ' << id << ' ' << course << ' ' << term << endl;
	data.close();
}


void Catalog::show_term(string choice, int c){
	for (int i=0; i<num_courses; i++){
		courses[i].check_terms(choice);
	}
}

void Catalog::show_am_time(string hour, int c){
	for (int i=0; i<num_courses; i++){
		courses[i].check_am_times(hour);
	}
}

void Catalog::show_pm_time(string hour, int c){
	for (int i=0; i<num_courses; i++){
		courses[i].check_pm_times(hour);
	}
}

void Catalog::get_courses(int choice){
	for (int i=0; i<num_courses; i++){
		courses[i].set_number(i);
		courses[i].show_courses(i);
	}
}

int Catalog::get_num_courses() const{
	return num_courses;
}

