/************************
 ** Program: Zoo Tycoon 
 ** Author: Michael Smith
 ** Date: 11/7/2019
 ** Description: Runs the Zoo Tycoon game (driver file)
 ** Input: Zoo info
 ** Output: runs game
 ****************************/
#include <iostream>
#include "zoo.h"
#include "animal.h"
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	srand(time(NULL));
	bool play = false;
	bool exit = false;
	int month = 1;
	
	Zoo z;
	z.start_game(play, exit);

	while (play){
		system("clear");
		cout << endl << z.get_name() << " Zoo => Month: " << month++ << endl;
		z.run_game(play);
	}
}
