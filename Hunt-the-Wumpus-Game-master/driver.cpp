#include <iostream>
#include <vector>
#include <stdlib.h>
#include "game.h"
#include "room.h"
#include "gold.h"
#include "bats.h"
#include "pit.h"
#include "wump.h"
#include "event.h"

using namespace std;

int main(int argc, char *argv[]){
	int run = 1;
	int p = 1;
	bool again;
	if (argc != 3 || atoi(argv[1]) < 4){
		cout << "Arguments are invalid, exiting..." << endl;
		return 0;
	}
	int dim = atoi(argv[1]);
	string arg = string(argv[2]);
	Cave grid(dim);
	grid.guidelines(p, run, again, dim, arg);

	if (again == false && p == 1){
		p = 1;
		run = 1;
		Cave new_grid(dim);
		new_grid.guidelines(p, run, again, dim, arg);
	}	
}


















