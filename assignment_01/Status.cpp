#include "Status.h"
using namespace std;

CharacterStatus::CharacterStatus() : maxHP(0), maxMP(0), healAmount(20), hpPotion(0), mpPotion(0)
{
	for (int i = 0; i < 4; ++i) status[i] = 0;
}

void CharacterStatus ::inputStatus()
{
	// HP�� MP �Է�
	while (true) 
	{
		cout << "HP�� MP�� �Է����ּ��� : ";
		cin >> status[0] >> status[1];

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���.\n";
			continue;
		}

		if (status[0] < 50 || status[1] < 50)
		{
			cout << "HP�� MP�� ���� �ʹ� �۽��ϴ�.�ٽ� �Է����ּ���." << "\n";
			continue;
		}
		break;
	}

	// ���ݷ°� ���� �Է�
	while (true) 
	{
		cout << "���ݷ°� ������ �Է����ּ��� : ";
		cin >> status[2] >> status[3];

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���.\n";
			continue;
		}

		if (status[2] <= 0 || status[3] <= 0) 
		{
			cout << "���ݷ°� ������ 0�̻� �̾�� �մϴ�.\n";
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
		cout << "\n������ ���޵Ǿ����ϴ� HP ����: " << *p_HPPotion <<"��" << " MP ����: " << *p_MPPotion << "��" << "\n";
	}
	else
	{
		cout << "������ �� �ϳ� �̻��� null�Դϴ�.���� ���� ���� Ȯ���ʿ�";
	}
}

void CharacterStatus :: showMenu() const
{
	cout << "\n��ȣ�� �������ּ���\n";
	cout << "1. HP ȸ��\n";
	cout << "2. MP ȸ��\n";
	cout << "3. HP ��ȭ\n";
	cout << "4. MP ��ȭ\n";
	cout << "5. ���� ��ų ���\n";
	cout << "6. �ʻ�� ���\n";
	cout << "7.������";
	cout << "\n";
}

void CharacterStatus :: handleChoise(int choise)
{
	switch (choise)
	{
	case 1:  //1. HP ȸ��
        if (hpPotion > 0)
		{
			status[0] += healAmount;
			hpPotion--;
			cout << "HP�� 20 ȸ�� �Ǿ����ϴ� ������ 1�� �����˴ϴ�." << " ���� HP : " << status[0] << " ���� ���� �� : " << hpPotion << "\n";
		}
		else
		{
			cout << "������ �����մϴ�.\n";
		}
			break;

	case 2: // 2. MP ȸ��
		if(mpPotion > 0)
		{
			status[1] += healAmount;
			mpPotion--;
			cout << "MP�� 20 ȸ�� �Ǿ����ϴ� ������ 1�� �����˴ϴ�." << " ���� MP : " << status[1] << " ���� ���� �� : " << mpPotion << 
				
				"\n";
		}
		else
		{
			cout << "������ �����մϴ�.\n";
		}
			break;

	case 3: //3. HP ��ȭ
			status[0] *= 2;
			cout << "HP�� 2��� ���� �Ǿ����ϴ� ��ȭ �� HP : " << status[0] << "\n";
			break;

	case 4: //4. MP��ȭ
			status[1] *= 2;
			cout << "MP�� 2��� ���� �Ǿ����ϴ� ��ȭ �� MP : " << status[1] << "\n";
			break;

	case 5: //5. ���ݽ�ų���
			if (status[1] >= 50) 
			{
				status[1] -= 50;
				cout << "��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�." << "���� MP :" << status[1] << "\n";
			}
			else
			{
				cout << "MP�� ������ ��ų����� �Ұ��� �մϴ�.\n";
			}
			break;

	case 6: // 6. �ʻ�� ���
			if (status[1] > 0) 
			{
				status[1]/= 2;
				cout << "��ų�� ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�." << "���� MP :" << status[1] << "\n";
			}
			else
			{
				cout << "MP�� ������ ��ų����� �Ұ��� �մϴ�.\n";
			}
			break;

	case 7 : // ���α׷� ����
			cout << "���α׷��� �����մϴ�.\n";
			break;
	default: 	
			std::cout << "�߸��� �����Դϴ�\n";
			break;


	}
}



	