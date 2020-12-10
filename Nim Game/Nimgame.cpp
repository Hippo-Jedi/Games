/*Progam name: Nimgame.cpp
 * Author: Michael Smith
 * Date: 4/29/19
 * Description: A two person game called NIM
 * Input: The user inputs multiple variables such as name, which pile, and how much the player wants to remove
 * Outputs: After removing the users input from the pile, the output is its new value
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string player_names() {//Function that asks for the players names
        string names;
	cout << "Enter the two players' names: ";
	cin >> names;
	return names;
}
//Functions that perform each turn, subtracting values
	int turn_A(int A) {
		int num;
		cin >> num;
		return (A - num);
}
	int turn_B(int B) {
		int num;
		cin >> num;
		return (B - num);
}
	int turn_C(int C) {
		int num;
		cin >> num;
		return (C - num);
}
int main() {//Main function with game
	srand(time(NULL));//Random number generator to create random pile quantities
	int A = (rand() % 10) + 1;
	int B = (rand() % 10) + 1;
	int C = (rand() % 10) + 1;

	cout << "You are playing NIM\n";
	char num;
	string player1 = player_names();
	cout << "Player one is named " << player1 << endl;
	string player2 = player_names();
	cout << "Player two is named " << player2 << endl;
	//While loop so the game will run until all piles are empty	
	while (A > 0 and B > 0 and C > 0) {
		cout << "Pile A contains " << A << " counters"<< endl;
		cout << "Pile B contains " << B << " counters"<< endl;
		cout << "Pile C contains " << C << " counters"<< endl;
		cout << player1 << " choose a pile: " << endl;
		cin >> num;

		if (num == 'a') {
			cout << "You may take up to 3 counters from a pile" << endl;
			A = turn_A(A);
			if (A < 0) {
				cout << "A pile cannot have a negative value" << endl;
				return 0;
			}else {
				cout << "Pile A contains " << A << " counters"<< endl;
               			cout << "Pile B contains " << B << " counters"<< endl;
                		cout << "Pile C contains " << C << " counters"<< endl; 
		}
		}else if (num == 'b') {
			cout << "You may take up to 3 counters fom a pile" << endl;
			B = turn_B(B);
			if (B < 0) {
				cout << "A pile cannot have a negative value" << endl;
				return 0;
			}else {
				cout << "Pile A contains " << A << " counters"<< endl;
                                cout << "Pile B contains " << B << " counters"<< endl;
                                cout << "Pile C contains " << C << " counters"<< endl;
		}
		}else if (num == 'c') {
			cout << "You may take up to 3 counters from a pile" << endl;
			C = turn_C(C);
			if (C < 0) {
				cout << "A pile cannot have a negative value" << endl;
				return 0;
			}else {
				cout << "Pile A contains " << A << " counters"<< endl;
                                cout << "Pile B contains " << B << " counters"<< endl;
                                cout << "Pile C contains " << C << " counters"<< endl;
		}
		}//Same code but for player two
		cout << player2 << " choose a pile: " << endl;
                cin >> num;

                if (num == 'a') {
                        cout << "You may take up to 3 counters from a pile" << endl;
                        A = turn_A(A);
                        if (A < 0) {
                                cout << "A pile cannot have a negative value" << endl;
                                return 0;
                        }else {
                                cout << "Pile A contains " << A << " counters"<< endl;
                                cout << "Pile B contains " << B << " counters"<< endl;
                                cout << "Pile C contains " << C << " counters"<< endl;
		}
                }else if (num == 'b') {
                        cout << "You may take up to 3 counters fom a pile" << endl;
                        B = turn_B(B);
                        if (B < 0) {
                                cout << "A pile cannot have a negative value" << endl;
                                return 0;
                        }else {
                                cout << "Pile A contains " << A << " counters"<< endl;
                                cout << "Pile B contains " << B << " counters"<< endl;
                                cout << "Pile C contains " << C << " counters"<< endl;
		}
                }else if (num == 'c') {
                        cout << "You may take up to 3 counters from a pile" << endl;
			C = turn_C(C);
                        if (C < 0) {
                                cout << "A pile cannot have a negative value" << endl;
                                return 0;
                        }else {
                                cout << "Pile A contains " << A << " counters"<< endl;
                                cout << "Pile B contains " << B << " counters"<< endl;
                                cout << "Pile C contains " << C << " counters"<< endl;
		}
		}
		cout << "The player who took the last counter from the last pile is the loser and is horrible at this game." << endl;//Display when the game is over
	}	
	return 0;
}





