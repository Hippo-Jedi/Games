#ifndef CATALOG_H
#define CATALOG_H
#include <iostream>
#include "course.h"

using namespace std;

class Catalog {
private:
	int num_courses;
	Course *courses;
public:
	Catalog();
	~Catalog();
	Catalog(const Catalog &obj);
	void count_courses();
	void make_courses();
	void set_num_courses();
	int get_num_courses() const;
	void show_term_student(string choice, int i);
	void show_term(string choice, int i);
	void show_am_time(string hour, int i);
	void show_pm_time(string hour, int i);
	void get_courses(int choice);
	void enroll(int x, string name, string id);
};
#endif
