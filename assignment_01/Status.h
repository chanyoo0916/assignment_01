#pragma once
#include <iostream>

class CharacterStatus
{
    private:
    int status[4]; // 0: HP, 1: MP, 2: 공격력, 3: 방어력
    int maxHP;
    int maxMP;
    int healAmount;
    int hpPotion;
    int mpPotion;

public:
    CharacterStatus();
	void inputStatus();
	void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
	void showMenu() const;
	void handleChoice(int choice);
};



