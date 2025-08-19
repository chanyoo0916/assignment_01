#include "Status.h"
using namespace std;

CharacterStatus::CharacterStatus() : maxHP(0), maxMP(0), healAmount(20), hpPotion(0), mpPotion(0)
{
	for (int i = 0; i < 4; ++i) status[i] = 0;
}

void CharacterStatus ::inputStatus()
{
	do 
	{
		cout << "HP�� MP�� �Է����ּ��� : ";
		cin >> status[0] >> status[1];
		
		this->maxHP = status[0];
		this->maxMP = status[1];
		
		if (status[0] < 50 || status[1] < 50)
		{
			cout << "HP�� MP�� ���� �ʹ��۽��ϴ�. �ٽ� �Է����ּ���\n";
		}
	} while (status[0] < 50 || status[1] < 50);

	do 
	{
		cout << "���ݷ��� �Է����ּ��� : ";
		cin >> status[2];

		cout << "���¸� �Է����ּ��� : ";
		cin >> status[3];

		if (status[2] <= 0 || status[3] <= 0)
		{
			cout << "���°� ���ݷ��� ��� 0�̻� �̾�� �մϴ�. �ٽ��Է����ּ���.\n";
		}
	} while (status[2] <= 0 || status[3] <= 0);


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
	cout << "\n";
}

void CharacterStatus :: handleChoice(int choise)
{
	switch (choise)
	{
	case 1:  //1. HP ȸ��
			
		/*if (status[0] >= maxHP)
		{
			cout << "�̹� HP�� �ִ�ġ �Դϴ�.\n";
		}*/
        if (hpPotion > 0)
		{
			status[0] += healAmount;
			/*if (status[0] > maxHP)
				//status[0] = maxHP; // HP�� �ִ��Ͻ� ȸ�� ���ϴ� ����*/ 
			hpPotion--;
			cout << "HP�� 20 ȸ�� �Ǿ����ϴ� ������ 1�� �����˴ϴ�." << " ���� HP : " << status[0] << " ���� ���� �� : " << hpPotion << "\n";
		}
		else
		{
			cout << "������ �����մϴ�.\n";
		}
			break;

	case 2: // 2. MP ȸ��
			
		/*if (status[1] >= maxMP)
		{
			cout << "�̹� MP�� �ִ�ġ �Դϴ�.\n";
		}*/
		if(mpPotion > 0)
		{
			status[1] += healAmount;
			/*if (status[1] > maxMP)
			{ 
			status[1] = maxMP; // MP�� �ִ��Ͻ� ȸ�� ���ϴ� ���� 
			}*/
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
			this->maxHP *= 2;
			cout << "HP�� 2��� ���� �Ǿ����ϴ� ��ȭ �� HP : " << this->maxHP << "\n";
			break;

	case 4: //4. MP��ȭ
			this->maxMP *= 2;
			cout << "MP�� 2��� ���� �Ǿ����ϴ� ��ȭ �� MP : " << this->maxMP << "\n";
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



	