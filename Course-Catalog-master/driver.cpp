/******************************************************
 * ** Program: assignment2(Course Catalog)
 * ** Author: Michael Smith
 * ** Date: 10/27/2019
 * ** Description: database of information includeing universities, courses within the university, teachers and students
 * ** Input: .txt files, teachers and student login info, catalog search and sorting inputs from user
 * ** Output: information on courses and universities requested by either teacher or students
 * ******************************************************/
#include <iostream>
#include <fstream>
#include "course.h"
#include "catalog.h"
#include "uni.h"

using namespace std;

int main(){
	int num_courses, num_teachers;
	num_courses = get_num_courses();
	num_teachers = get_num_teachers();

	University uni(num_courses, num_teachers);	
	
	uni.welcome();

	return 0; 	

}
