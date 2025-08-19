#include <iostream>
#include "Status.h"
using namespace std;


int main()
{
	int hpPotion = 0;
	int mpPotion = 0;

	CharacterStatus player;
	player.inputStatus();
    player.setPotion(5, &hpPotion, &mpPotion);
	int choise;
	
    while (true)
    {
        player.showMenu();
        cout << "선택: ";
        cin >> choise;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "잘못된 입력입니다. 숫자를 입력해주세요.\n";
            continue;
        }
        player.handleChoise(choise);
        if (choise == 7)
            break;
    }


	return 0;

 
}


