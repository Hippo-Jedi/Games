#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

struct teacher {
	string id;
        string password;
        string first;
        string last;
};

struct schedule {
	string days;
	string start;
	string end;
	string term;
	string location;
};

class Course {
private:
        //string name;
	//int number;
        string instructor;
        int current_enroll;
	string *roster;
	//schedule *course_time;
public:
	string name;
	int number;
	schedule *course_time;
        Course();
	~Course();
	Course(const Course &obj);
	void get_course_data(ifstream &data);
	void check_terms(string choice);
	void check_am_times(string hour);
	void check_pm_times(string hour);
	void show_courses(int i);	
        void set_name(string);
        string get_name();
        void set_instructor(string);
        string get_instructor();
        bool check_space(string line);
	void set_current_enrollment(int);
        int get_current_enrollment();
	void set_number(int);
	int get_number();
};

#endif




