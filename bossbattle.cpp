/******************************************************
 * ** Program: bossbattle.cpp
 * ** Author: Michael Smith
 * ** Date: 04/14/2019
 * ** Description: The user battles and attempts to kill a boss
 * ** Input: The users choices
 * ** Output: Changes depending on the users choices and displays the path they chose
 */
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;
int main() {
	srand(time(NULL));
        int rnum = rand() % 5, arrow;
        int tries = 3;
//	int tries2 = 2;
        rnum = rnum + 1;	

	int boss;
	int choice1;
	int choice2;
	int choice3;
	int choice4;
        cout << "WARNING WARNING, YOU ARE ABOUT TO PLAY THE GREATEST GAME OF ALL TIME SO PREPARE YOURSELF BOTH MENTALLY AND PHYSICALLY\n" << "You are a humble mage, who has just waken up not knowing where he is or how he got there. You are given an option, You can either fight a giant troll or an evil witch. You get to decide.";
        cout << "Enter 1 to fight the troll and 2 to fight the witch: ";
        cin >> boss;
        if (boss == 1) {
		cout << "You have chosen to fight the troll. The beast is 10 feet tall and weighs more than ten elephants. He sees you and advances so you prepare to counter his attack. The troll tries toswing at you but he's too slow. You're able to dodge and manage to get behind the massive beast.\n" << "Now is your chance, should you attack his upper body or lower body with your swo		    rd?\n" << "Enter 1 to attack the trolls legs and 2 to attack his upper body: "; 
		cin >> choice1;
		if (choice1 == 1) {
			cout << "You decide to attack the trolls legs and swing your sword as hard as you can. Fortunetly, your strike was able to cripple the trolls left calf and he backs off. The troll begins to grab a giant boulder, giving you a clear view of the trolls eyes. You grab your arrow and draw an arow. Luckily you attacked his legs, making him more immobilized and increasing your chances of hitting him.\n" << "You have a one in five chance of hitting the troll, but you only have three arrows.\n" << "You have three shots, enter a random number between 1 and 5 to see if you hit him: ";
			cin >> arrow;
			do {
				cout << "You missed, you have " << --tries  << " arrows left. Try again: ";
				cin >> arrow;			  
			}while (arrow != rnum and tries != 1);
				if (arrow == rnum) {
					cout << "Nice shot! You hit the troll in the eye. You wounded him badly, but this only makes him angrier. He's finally able to pick up the boulder and he hurls it toward you.\n" << "Enter 1 to shoot a fireball at the boulder to destroy it or 2 to jump out of the way: ";
					cin >> choice2;
					if (choice2 == 1) {
						cout << "You pull out your wand and shoot a fireball at the boulder. Unfortunetly, the fireball is too weak to break the boulder and it hits you. You fall down and see that your leg is broken. The troll walks over to you, knowing he has the upper hand.\n" << "Enter 1 to crawl away or 2 to stay and fight the troll one on one: ";
						cin >> choice3;
						if (choice3 == 1) {
							cout << "You try to crawl away but your too injured to get very far. The troll walks up to you and smashes your head. You are dead.\n" << "GAME OVER, YOU LOSE";
						}else {
							cout << "You decide to stay and fight. The troll sprints over to you and tries step on your chest. Luckily, you think fast and draw your sword, stabbing the bottom the trolls foot. The sword goes deep and the troll is stunned. You see the window and manage to hop on the trolls back. You grab your dagger and stab the troll multiple times in the head.\n" << "You have successfully killed the troll, CONGRATULATIONS!!!!!\n" << "GAME OVER";

}
					}else {
						cout << "The arrow in the trolls eye has taken its toll, decreasing his ability to aim. The boulder isn't direct and you're easily able to dodge it. The troll charges you and is able to grab your leg. He squeezes your leg and you can feel it shatter. The troll throws you across the room and you're badly injured.\n" << "Enter 1 to crawl away or 2 to stay and fight the troll one on one: "; 
						cin >> choice3;
						if (choice3 == 1) {
                                                        cout << "You try to crawl away but your too injured to get very far. The troll walks up to you and smashes your head. You are dead.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The troll sprints over to you and tries step on your chest. Luckily, you think fast and draw your sword, stabbing the bottom the trolls foot. The sword goes deep and the troll is stunned. You see the window and manage to hop on the trolls back. You grab your dagger and stab the troll multiple times in the head.\n" << "You have successfully killed the troll, CONGRATULATIONS!!!!!\n" << "GAME OVER";

} 
}
				}else if (tries == 1) {
					cout << "You're out of arrows and you've missed all of your shots. The troll picks up the boulder and hurls it straight at you.\n" << "Enter 1 to shoot a fireball at the boulder to destroy it or 2 to jump out of the way: ";
					cin >> choice2;
					if (choice2 == 1) {
                                                cout << "You pull out your wand and shoot a fireball at the boulder. Unfortunetly, the fireball is too weak to break the boulder and it hits you. You fall down and see that your leg is broken. The troll walks over to you, knowing he has the upper hand.\n" << "Enter 1 to crawl away or 2 to stay and fight the troll one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but your too injured to get very far. The troll walks up to you and smashes your head. You are dead.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The troll sprints over to you and tries step on your chest. Luckily, you think fast and draw your sword, stabbing the bottom the trolls foot. The sword goes deep and the troll is stunned. You see the window and manage to hop on the trolls back. You grab your dagger and stab the troll multiple times in the head.\n" << "You have successfully killed the troll, CONGRATULATIONS!!!!!\n" << "GAME OVER";

}						
					}else {
						cout << "You attempt to dodge the boulder but since you didn't hit the troll with any of your arrows, he is able to throw accurately. The boulder hits you and you're badly injured. You can either stay and fight the troll or you can try to crawl away.\n" << "Enter 1 to crawl away or 2 to stay and fight: ";
						cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but your too injured to get very far. The troll walks up to you and smashes your head. You are dead.\n" << "GAME OVER, YOU LOSE";
                                                }else {
							cout << "You decide to stay and fight but you've done little damage to the troll and you're about to die from your own injuries. The troll walks over to you, grabs your head and crushes it. He then eats your body. I'm sorry but you have died.\n" << "GAME OVER";
}
} 
}
		}else {
			cout << "You decide to attack the trolls chest but he's it has no effect. He swings his arm and it hits you hard right in the chest. You get the wind knocked out of you and the blow launches you across the room. You recover and stand up. The troll starts to charge at you so you draw you bow and arrow. You have three arrows but since the troll is running at you, you only have time to shoot two of them. You draw the first arrow and aim for the trolls eyes.\n" << "Enter a random number between 1 and 5 to see if you hit him: "; 
			cin >> arrow;
			do {
				cout << "You missed, you have time to shoot " << --tries << " more arrow. Try again: ";
				cin >> arrow;
			}while (arrow != rnum and tries != 2);
				if (arrow == rnum) {
					cout << "Nice shot! You hit the troll in the eye with an arrow and he stops charging you. Instead, the giant troll picks up a boulder and throws it at you.\n" << "Enter 1 to shoot a fireball at the boulder to destroy it or 2 to jump out of the way: ";
                                        cin >> choice2;
                                        if (choice2 == 1) {
                                                cout << "You pull out your wand and shoot a fireball at the boulder. Unfortunetly, the fireball is too weak to break the boulder and it hits you. You fall down and see that your leg is broken. The troll walks over to you, knowing he has the upper hand.\n" << "Enter 1 to crawl away or 2 to stay and fight the troll one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but your too injured to get very far. The troll walks up to you and smashes your head. You are dead.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The troll sprints over to you and tries step on your chest. Luckily, you think fast and draw your sword, stabbing the bottom the trolls foot. The sword goes deep and the troll is stunned. You see the window and manage to hop on the trolls back. You grab your dagger and stab the troll multiple times in the head.\n" << "You have successfully killed the troll, CONGRATULATIONS!!!!!\n" << "GAME OVER";

}
                                        }else {
                                                cout << "The arrow in the trolls eye has taken its toll, decreasing his ability to aim. The boulder isn't direct and you're easily able to dodge it. The troll charges you and is able to grab your leg. He squeezes your leg and you can feel it shatter. The troll throws you across the room and you're badly injured.\n" << "Enter 1 to crawl away or 2 to stay and fight the troll one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but your too injured to get very far. The troll walks up to you and smashes your head. You are dead.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The troll sprints over to you and tries step on your chest. Luckily, you think fast and draw your sword, stabbing the bottom the trolls foot. The sword goes deep and the troll is stunned. You see the window and manage to hop on the trolls back. You grab your dagger and stab the troll multiple times in the head.\n" << "You have successfully killed the troll, CONGRATULATIONS!!!!!\n" << "GAME OVER";

}
}
				}else if (tries == 2) {
					cout << "You try to shoot the third arrow but the troll gets to you before you're able to. He grabs your right arm, rips it off, then throws you across the room. Your badly injured and confused. As you start to recover from the deadly blow, the troll grabs a boulder and throws it at you.\n" << "Enter 1 to shoot a fireball at the boulder to destroy it or 2 to jump out of the way: ";
                                        cin >> choice2;
                                        if (choice2 == 1) {
                                                cout << "You pull out your wand and shoot a fireball at the boulder. Unfortunetly, the fireball is too weak to break the boulder and it hits you. You fall down and see that your leg is broken. The troll walks over to you, knowing he has the upper hand.\n" << "Enter 1 to crawl away or 2 to stay and fight the troll one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but your too injured to get very far. The troll walks up to you and smashes your head. You are dead.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The troll sprints over to you and tries step on your chest. Luckily, you think fast and draw your sword, stabbing the bottom the trolls foot. The sword goes deep and the troll is stunned. You see the window and manage to hop on the trolls back. You grab your dagger and stab the troll multiple times in the head.\n" << "You have successfully killed the troll, CONGRATULATIONS!!!!!\n" << "GAME OVER";

}
                                        }else {
                                                cout << "You try to dodge the boulder but you're too injured and it hits you. You are about to die and the troll is walking over to you.\n" << "Enter 1 to crawl away or 2 to stay and fight the troll one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but your too injured to get very far. The troll walks up to you and smashes your head. You are dead.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The troll sprints over to you and tries step on your chest. Luckily, you think fast and draw your sword, stabbing the bottom the trolls foot. The sword goes deep and the troll is stunned. You see the window and manage to hop on the trolls back. You grab your dagger and stab the troll multiple times in the head.\n" << "You have successfully killed the troll, CONGRATULATIONS!!!!! Unfortunetly, you sustained too many injuries and you bleed out.\n" << "GAME OVER";

}
}
}
}
	}else if (boss == 2) {
		cout << "You have decided to fight the witch. She is an ugly, dwarf-like creature with immense magical power. You know that her weakness is hand-to-hand combat so you sprint as fast as you can towards her. She sees this and tries to retreat but you're able to catch her. You have a clear shot at her head.\n" << "Enter 1 to use your sword and chop off her head or 2 to use your dagger to stab her gut: ";
		cin >> choice1;
			if (choice1 == 1) {
				cout << "You swipe your sword but it phases through her body and she dissapears. You are confused for a second until you turn around and see the witch behind you. You grab your bow and load an arrow. You only have 3 arrows so make them count.\n" << "Enter a random number between 1 and 5 to see if you hit her with one of the arrows. Take a shot: ";
				cin >> arrow;
                        do {
                                cout << "You missed, you have " << --tries  << " arrows left. Try again: ";
                                cin >> arrow;
                        }while (arrow != rnum and tries != 1);
				if (arrow == rnum) {
					cout << "Nice shot! You hit the witch in the leg making her a slower target. She is angered by the arrow and shoots and electric bolt at you. You are caught off guard and have to act quick.\n" << "Enter 1 to shoot a lightning bolt back to block it or 2 to attempt a dodge: ";
					cin >> choice2;
					if (choice2 == 1) {
                                                cout << "You pull out your wand and shoot a lightning bolt at her spell. Unfortunetly, your spell is too weak compared to the power of the witch. The witches bolt hits you, launching you into the back wall. You're badly injured and are laying on the floor. The witch advances and you must protect yourself.\n" << "Enter 1 to crawl away or 2 to stay and fight the witch one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but by the time you get to your feet, the witch has already cast multiple spell. A huge fireball comes at you and you jump out of the way. The dodge was successfull but as you refocus yourself, another lightning bolt hits you right in the head. Your brain explodes from the bolt and you die.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The witch zooms at you on her broom and is able to get a solid punch in but she has less physical power then you so it barely hurt. You grab her by the arm and plunge your dagger into her side. She screams and manages to back off. As she's retreating, you shoot a fireball at her and she starts to burn. The fire burns her to ashes.\n" << "You have successfully killed the witch, CONGRATULATIONS!!!!!\n" << "GAME OVER";
}
                                        }else {
                                                cout << "The damage your arrow caused has taken a toll on the witch and has drained some of her magical powers. Her lightning bolt was weak so you were easily able to dodge it. while you dodge, the witch uses all of her energy to shoot another bolt and its a direct hit. You fly back and take massive damage. You're on the floor trying to get back on your feet but they are paralyzed. \n" << "Enter 1 to crawl away or 2 to stay and fight the troll one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but the witch is able to grab you. She screams as she eats your face. You are dead.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The witch zooms at you on her broom and is able to get a solid punch in but she has less physical power then you so it barely hurt. You grab her by the arm and plunge your dagger into her side. She screams and manages to back off. As she's retreating, you shoot a fireball at her and she starts to burn. The fire burns her to ashes.\n" << "You have successfully killed the witch, CONGRATULATIONS!!!!!\n" << "GAME OVER";
}
}					
				}else if (tries == 1) {
					cout << "You missed all three times and are all out of arrows. The witch casts a spell, sending a huge lightning bolt toward you.\n" << "Enter 1 to shoot a lightning bolt back to block it or 2 to attempt a dodge: ";
					cin >> choice2;
                                        if (choice2 == 1) {
                                                cout << "You pull out your wand and shoot a lightning bolt at her spell. Unfortunetly, your spell is too weak compared to the power of the witch. The witches bolt hits you, launching you into the back wall. You're badly injured and are laying on the floor. The witch advances and you must protect yourself.\n" << "Enter 1 to crawl away or 2 to stay and fight the witch one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but by the time you get to your feet, the witch has already cast multiple spell. A huge fireball comes at you and you jump out of the way. The dodge was successfull but as you refocus yourself, another lightning bolt hits you right in the head. Your brain explodes from the bolt and you die.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The witch zooms at you on her broom and is able to get a solid punch in but she has less physical power then you so it barely hurt. You grab her by the arm and plunge your dagger into her side. She screams and manages to back off. As she's retreating, you shoot a fireball at her and she starts to burn. The fire burns her to ashes.\n" << "You have successfully killed the witch, CONGRATULATIONS!!!!!\n" << "GAME OVER";
}
					}else {
						cout << "You jump out of the way of the lightning bolt but you're hit in the face with some depris and it injures you badly. You're on the floor and you cant get back to your feet.\n" << "Enter 1 to crawl away or 2 to stay and fight the witch one on one: ";
						cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but by the time you get to your feet, the witch has already cast multiple spell. A huge fireball comes at you and you jump out of the way. The dodge was successfull but as you refocus yourself, another lightning bolt hits you right in the head. Your brain explodes from the bolt and you die.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The witch zooms at you on her broom and is able to get a solid punch in but she has less physical power then you so it barely hurt. You grab her by the arm and plunge your dagger into her side. She screams and manages to back off. As she's retreating, you shoot a fireball at her and she starts to burn. The fire burns her to ashes.\n" << "You have successfully killed the witch, CONGRATULATIONS!!!!!\n" << "GAME OVER";
}
}
}
			}else {
				cout << "You pull out your dagger and try to stab her but shes able to grab your wrist before the blade made contact. You both are struggling with each other until you're able to grab her neck. You put her in a choke hold, then she smiles and then her body phases away. You are confused for a second until you turn around and see the witch behind you. You grab your bow and load an arrow. You only have 3 arrows so make them count.\n" << "Enter a random number between 1 and 5 to see if you hit her with one of the arrows. Take a shot: ";
                                cin >> arrow;
                        do {
                                cout << "You missed, you have " << --tries  << " arrows left. Try again: ";
                                cin >> arrow;
                        }while (arrow != rnum and tries != 1);
                                if (arrow == rnum) {
					 cout << "Nice shot! You hit the witch in the leg making her a slower target. She is angered by the arrow and shoots and electric bolt at you. You are caught off guard and have to act quick.\n" << "Enter 1 to shoot a lightning bolt back to block it or 2 to attempt a dodge: ";
                                        cin >> choice2;
                                        if (choice2 == 1) {
                                                cout << "You pull out your wand and shoot a lightning bolt at her spell. Unfortunetly, your spell is too weak compared to the power of the witch. The witches bolt hits you, launching you into the back wall. You're badly injured and are laying on the floor. The witch advances and you must protect yourself.\n" << "Enter 1 to crawl away or 2 to stay and fight the witch one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but by the time you get to your feet, the witch has already cast multiple spell. A huge fireball comes at you and you jump out of the way. The dodge was successfull but as you refocus yourself, another lightning bolt hits you right in the head. Your brain explodes from the bolt and you die.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The witch zooms at you on her broom and is able to get a solid punch in but she has less physical power then you so it barely hurt. You grab her by the arm and plunge your dagger into her side. She screams and manages to back off. As she's retreating, you shoot a fireball at her and she starts to burn. The fire burns her to ashes.\n" << "You have successfully killed the witch, CONGRATULATIONS!!!!!\n" << "GAME OVER";
}
                                        }else {
                                                cout << "The damage your arrow caused has taken a toll on the witch and has drained some of her magical powers. Her lightning bolt was weak so you were easily able to dodge it. while you dodge, the witch uses all of her energy to shoot another bolt and its a direct hit. You fly back and take massive damage. You're on the floor trying to get back on your feet but they are paralyzed. \n" << "Enter 1 to crawl away or 2 to stay and fight the troll one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but the witch is able to grab you. She screams as she eats your face. You are dead.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The witch zooms at you on her broom and is able to get a solid punch in but she has less physical power then you so it barely hurt. You grab her by the arm and plunge your dagger into her side. She screams and manages to back off. As she's retreating, you shoot a fireball at her and she starts to burn. The fire burns her to ashes.\n" << "You have successfully killed the witch, CONGRATULATIONS!!!!!\n" << "GAME OVER";
}
}
                                }else if (tries == 1) {
                                        cout << "You missed all three times and are all out of arrows. The witch casts a spell, sending a huge lightning bolt toward you.\n" << "Enter 1 to shoot a lightning bolt back to block it or 2 to attempt a dodge: ";
                                        cin >> choice2;
                                        if (choice2 == 1) {
                                                cout << "You pull out your wand and shoot a lightning bolt at her spell. Unfortunetly, your spell is too weak compared to the power of the witch. The witches bolt hits you, launching you into the back wall. You're badly injured and are laying on the floor. The witch advances and you must protect yourself.\n" << "Enter 1 to crawl away or 2 to stay and fight the witch one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but by the time you get to your feet, the witch has already cast multiple spell. A huge fireball comes at you and you jump out of the way. The dodge was successfull but as you refocus yourself, another lightning bolt hits you right in the head. Your brain explodes from the bolt and you die.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The witch zooms at you on her broom and is able to get a solid punch in but she has less physical power then you so it barely hurt. You grab her by the arm and plunge your dagger into her side. She screams and manages to back off. As she's retreating, you shoot a fireball at her and she starts to burn. The fire burns her to ashes.\n" << "You have successfully killed the witch, CONGRATULATIONS!!!!!\n" << "GAME OVER";
}
                                        }else {
                                                cout << "You jump out of the way of the lightning bolt but you're hit in the face with some depris and it injures you badly. You're on the floor and you cant get back to your feet.\n" << "Enter 1 to crawl away or 2 to stay and fight the witch one on one: ";
                                                cin >> choice3;
                                                if (choice3 == 1) {
                                                        cout << "You try to crawl away but by the time you get to your feet, the witch has already cast multiple spell. A huge fireball comes at you and you jump out of the way. The dodge was successfull but as you refocus yourself, another lightning bolt hits you right in the head. Your brain explodes from the bolt and you die.\n" << "GAME OVER, YOU LOSE";
                                                }else {
                                                        cout << "You decide to stay and fight. The witch zooms at you on her broom and is able to get a solid punch in but she has less physical power then you so it barely hurt. You grab her by the arm and plunge your dagger into her side. She screams and manages to back off. As she's retreating, you shoot a fireball at her and she starts to burn. The fire burns her to ashes.\n" << "You have successfully killed the witch, CONGRATULATIONS!!!!!\n" << "GAME OVER"; 
}
}
}
}
}
return 0;
}





