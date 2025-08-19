#include <iostream>
#include "Status.h"
using namespace std;


int main()
{
	int hpPotion = 0;
	int mpPotion = 0;

	CharacterStatus player;
	player.inputStatus();
	player.setPotion(5,&hpPotion, &mpPotion);
	int choise;
	
	do {
		player.showMenu();
		cin >> choise;
		player.handleChoice(choise);
	} while (choise != 7);
	
	return 0;

 
}


