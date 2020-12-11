#ifndef UNI_H
#define UNI_H
#include <iostream>
#include "course.h"
#include "catalog.h"

class University {
private:
        string name;
        string address;
        string current_term;
        int num_teachers;
	struct teacher *teachers;
	int num_courses;
        Catalog cat;
public:
        University(int nc, int nt);
	~University(); 
	void make_uni();
	void make_teachers(int num_teachers);
	int teacher_choice();
	int student_choice();
	int welcome();
	void run_teacher(int &run, int choice);
	void view_catalog(int choice);
	void run_student(int &run, int choice);
	void student_options(int &run, int choice);
	void teacher_options(int &run, int choice);
	bool login(string id, string password, int &n);
        bool run_login();
	void search_time(int choice);
	void get_time(int n, string hour, int choice);
	void search_time_student(int choice);
	void search_term_student(int c);
	void search_term(int c);
};

int check_int(string n);
int get_num_courses();
int get_num_teachers();
#endif
