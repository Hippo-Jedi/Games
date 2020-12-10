/*Program Name: Hangman.cpp
 * Author: Michael Smith
 * Date: 5/12,2019
 * Description: Hangman game
 * Input: The users guesss and the word they are trying to guess
 * Output: the progress of the word and the letters you've already guessed
 */
#include <iostream>
#include <string>
using std::string;
using namespace std;

bool mystery_word(char guess, int *num, string mysteryword, string *wordprog);
int main() 
{
        char letter;
	int tries, num, guesses;
	string word;
	
	guesses = 0;
	cout << "Welcome to Hangman\n";
	cout << "Enter a word for the game: ";
	cin >> word;
	tries = word.length() + 1;
	string mystery(word.length(), '_');
	string used;
	cout << "Welcome to Hangman\n";
	cout << "You have " << tries << " tries to guess the mystery word";
	
	do  
	{
		cout << endl << mystery << endl << "guess a letter: ";
		cin >> letter;
		used = used + letter + ' ';
			if (mystery_word(letter, &num, word, &mystery) == false)
			{
				cout << "The mystery word doesn't contain that letter\n";
				tries--;
			}else 
			{
				cout << "You guessed correctly!!!\n";
			}
		cout << "You have " << tries << " tries left\n"; 		
		cout << "Letters used: " << used << endl;
			if (mystery == word)
			{
				cout << "Congratulations!!!!\n";
				cout << "You guessed the mystery word\n";
				cout << word;
				break;
			}
	}while (tries > 0);
	if (tries == 0)
	{
		cout << "You ran out of tries to guess the mystery word\n";
		cout << "You lost\n";
		cout << "The word was " << word << endl;
	}
	return 0;
}

bool mystery_word(char guess, int *num, string mysteryword, string *wordprog)
{
        for (int i = 0; i <= mysteryword.length(); i++)
        {
                if (mysteryword[i] == guess)
                {
			*num += 1;
			(*wordprog)[i] = guess;
                	return true;
		}
	}
}




