#include "Status.h"
using namespace std;

CharacterStatus::CharacterStatus() : maxHP(0), maxMP(0), healAmount(20), hpPotion(0), mpPotion(0)
{
	for (int i = 0; i < 4; ++i) status[i] = 0;
}

void CharacterStatus ::inputStatus()
{
	// HP와 MP 입력
	while (true) 
	{
		cout << "HP와 MP를 입력해주세요 : ";
		cin >> status[0] >> status[1];

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "잘못된 입력입니다. 숫자를 입력해주세요.\n";
			continue;
		}

		if (status[0] < 50 || status[1] < 50)
		{
			cout << "HP나 MP의 값이 너무 작습니다.다시 입력해주세요." << "\n";
			continue;
		}
		break;
	}

	// 공격력과 방어력 입력
	while (true) 
	{
		cout << "공격력과 방어력을 입력해주세요 : ";
		cin >> status[2] >> status[3];

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다. 숫자를 입력해주세요.\n";
			continue;
		}

		if (status[2] <= 0 || status[3] <= 0) 
		{
			cout << "공격력과 방어력은 0이상 이어야 합니다.\n";
			continue;
		}
		break;
	}

}

void CharacterStatus::setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	if (p_HPPotion != nullptr && p_MPPotion != nullptr)
	{
		*p_HPPotion = count;
		*p_MPPotion = count;

		hpPotion = *p_HPPotion;
		mpPotion = *p_MPPotion;
		cout << "\n포션이 지급되었습니다 HP 포션: " << *p_HPPotion <<"개" << " MP 포션: " << *p_MPPotion << "개" << "\n";
	}
	else
	{
		cout << "포인터 중 하나 이상이 null입니다.포션 지급 실패 확인필요";
	}
}

void CharacterStatus :: showMenu() const
{
	cout << "\n번호를 선택해주세요\n";
	cout << "1. HP 회복\n";
	cout << "2. MP 회복\n";
	cout << "3. HP 강화\n";
	cout << "4. MP 강화\n";
	cout << "5. 공격 스킬 사용\n";
	cout << "6. 필살기 사용\n";
	cout << "7.나가기";
	cout << "\n";
}

void CharacterStatus :: handleChoise(int choise)
{
	switch (choise)
	{
	case 1:  //1. HP 회복
        if (hpPotion > 0)
		{
			status[0] += healAmount;
			hpPotion--;
			cout << "HP가 20 회복 되었습니다 포션이 1개 차감됩니다." << " 현재 HP : " << status[0] << " 남은 포션 수 : " << hpPotion << "\n";
		}
		else
		{
			cout << "포션이 부족합니다.\n";
		}
			break;

	case 2: // 2. MP 회복
		if(mpPotion > 0)
		{
			status[1] += healAmount;
			mpPotion--;
			cout << "MP가 20 회복 되었습니다 포션이 1개 차감됩니다." << " 현재 MP : " << status[1] << " 남은 포션 수 : " << mpPotion << 
				
				"\n";
		}
		else
		{
			cout << "포션이 부족합니다.\n";
		}
			break;

	case 3: //3. HP 강화
			status[0] *= 2;
			cout << "HP가 2배로 증가 되었습니다 강화 후 HP : " << status[0] << "\n";
			break;

	case 4: //4. MP강화
			status[1] *= 2;
			cout << "MP가 2배로 증가 되었습니다 강화 후 MP : " << status[1] << "\n";
			break;

	case 5: //5. 공격스킬사용
			if (status[1] >= 50) 
			{
				status[1] -= 50;
				cout << "스킬을 사용하여 MP가 50 소모되었습니다." << "현재 MP :" << status[1] << "\n";
			}
			else
			{
				cout << "MP가 부족해 스킬사용이 불가능 합니다.\n";
			}
			break;

	case 6: // 6. 필살기 사용
			if (status[1] > 0) 
			{
				status[1]/= 2;
				cout << "스킬을 사용하여 MP가 50% 소모되었습니다." << "현재 MP :" << status[1] << "\n";
			}
			else
			{
				cout << "MP가 부족해 스킬사용이 불가능 합니다.\n";
			}
			break;

	case 7 : // 프로그램 종료
			cout << "프로그램을 종료합니다.\n";
			break;
	default: 	
			std::cout << "잘못된 선택입니다\n";
			break;


	}
}



	