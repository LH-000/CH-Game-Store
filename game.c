#include<stdio.h>
#include<windows.h>

#include"game.h"
#include"init.h"
#include"choose.h"
#include"build.h"
#include"watch.h"
#include"another.h"

int escape = 1;

static int num = 0;

/*��Ϸ��ʼ���д�*/
void Game_Start()
{
	int leave = 1;	//����ս������
	int add_att = 0;
	int _charter_run_ = 0;
	_Charter.Charter_Max_Health = charter.Health;
	while (leave)
	{
		Build_Monster_Att(&escape);

		/*�鿴����-���� ���Խ���*/
		Watch_Charter_Monster_Att(name);

		init_fight_excape();	//ս�� ���� ���� ����

		choose_fight_excape(&choose_Fight_Excape, &leave);	//ѡ��ս�� ���� ����

		if (choose_Fight_Excape == 3) {
			add_att = 1;
		}
		if (choose_Fight_Excape == 0) {
			_charter_run_++;
			if (_charter_run_ == 10) {	//�ﵽ��������
				for (int i = 0; i < 10; i++) {
					printf("�Ѿ��������ˣ������ܻ��ܵ��Ʋõ�!\n");
					Sleep(1000);
				}
			}
			if (_charter_run_ == 11) {
				charter.Health -= 10;
				printf("���Ѿ����۳�10������ֵ!\n");
				Sleep(3000);
				_charter_run_ = 0;
				printf("�����������......\n");
				system("pause");
			}
			continue;
		}

		/*���� �������� ����*/
		while (choose_Fight_Excape == 3 && add_att == 1)
		{
			Att_Add(&Att_,&Att_State);	//��������ģ�� -> �ش�����״̬
			if (Att_State)	//�ش�״̬����
			{
				printf("�����мӵ���Ҫô[1][0]: ");
				scanf_s("%d", &add_att);
			}
			if (Att_ == 0) {	//���ִ��� �ж�usr �Ƿ� ����ִ�� �ӵ�����
				printf("���ִ���,�Ƿ����ִ�мӵ�����:[1]����ִ�мӵ����� [2]�˳��ӵ����� :-:");	
				scanf_s("%d", &add_att);
			}
			if (add_att == 1) {	//���� ִ�� �ӵ�����
				;
			}
		}
		/*ѡ��Ϊ����ʱ����*/
		if (choose_Fight_Excape == 1)
		{
			Gudgement_Speed(&who);	//�ٶ��ж�

			/*�� ʱ ͣ ��*/
			//Defensive_Power(&who, &Defensive_Power_Hight_Low);	//������ -> �������ж�	

			while (charter.Health > 0 && monster.Health > 0)
			{
				Fight_charter_monster(&who, &fight_who);	//ս������
				if (charter.Health <= 0) {
					printf("Game OVER!");
					printf("�����Ĳ����� %d.\n", monster.Frequency - 1);
					return;
				}
				if (monster.Health <= 0) {
					printf("����������! Exp+1!\n");
					charter.Exp++;
					Charter_Upgrade();	//���������ж�
				}
			}
		}
	}
}

/*�ٶ��ж�ģ��*/
void Gudgement_Speed(int* who)
{
	if (charter.Speed >= monster.Speed) {	//�����ٶ� > �����ٶ�
		*who = CHARTER_STATE;
	}
	else {	//�����ȳ���
		*who = MONSTER_STATE;
	}
}
/*������ -> �������ж�*/	/*�� ʱ ͣ ��*/
//void Defensive_Power(int* who, int* Defensive_Power_Hight_Low)
//{
//	if (*who == CHARTER_STATE) {
//		*Defensive_Power_Hight_Low = charter.Aggressivity * SISTY_PERCENT - monster.Defensive_Power;
//	}
//}

/*����-���� ��ʼս�� */
void Fight_charter_monster(int* who, int* fight_who)
{
	if (*who == CHARTER_STATE && charter.Aggressivity > monster.Defensive_Power + monster.Health) {	//�����ȳ��� 
		monster.Health = monster.Health + monster.Defensive_Power - charter.Aggressivity;
		*who = MONSTER_STATE;	//״̬Ϊ 2 ����ת��
	}
	else if (*who == CHARTER_STATE && charter.Aggressivity <= monster.Health + monster.Defensive_Power) {
		monster.Health -= 3;
		*who = MONSTER_STATE;
	}

	else if (*who == MONSTER_STATE && monster.Aggressivity > charter.Aggressivity + charter.Defensive_Power) {
		charter.Health = charter.Health + charter.Defensive_Power - monster.Aggressivity;
		*who = CHARTER_STATE;
	}
	else if (*who == MONSTER_STATE && monster.Aggressivity <= charter.Health + charter.Defensive_Power) {
		charter.Health -= 3;
		*who = CHARTER_STATE;
	}
}

/*�� �� �� �� �� ��*/
void Att_Add(int* Att_, int* state)
{
	int Att = 0;
	int** p_Att_ = &Att_;
	Charter_Att_Add();	//�������Խ���
	printf("��������������������:");
	scanf_s("%d", &Att);
	switch (Att)
	{
	case 1:printf("�������� | ������ |:"); scanf_s("%d", &Add_Any_Att); Charter_Att_(&Add_Any_Att, p_Att_);
		if (*Att_ == 0) {	//���Բ��� �˳�
			return;
		}	
		charter.Aggressivity += Add_Any_Att; *state = OK;
		charter.Att -= Add_Any_Att;
		break;

	case 2:printf("�������� | ����ֵ |:"); scanf_s("%d", &Add_Any_Att); Charter_Att_(&Add_Any_Att, p_Att_);
		if (*Att_ == 0) {	//���Բ��� �˳�
			return;
		}	
		charter.Health += Add_Any_Att;
		_Charter.Charter_Max_Health += Add_Any_Att; *state = OK; 
		charter.Att -= Add_Any_Att;
		break;

	case 3:printf("�������� | ������ |:"); scanf_s("%d", &Add_Any_Att); Charter_Att_(&Add_Any_Att, p_Att_);
		if (*Att_ == 0) {	//���Բ��� �˳�
			return;
		}	
		charter.Defensive_Power += Add_Any_Att; *state = OK; 
		charter.Att -= Add_Any_Att;
		break;

	case 4:printf("�������� | ��  �� |:"); scanf_s("%d", &Add_Any_Att); Charter_Att_(&Add_Any_Att, p_Att_);
		if (*Att_ == 0) {	//���Բ��� �˳�
			return;
		}	
		charter.Speed += Add_Any_Att; *state = OK;
		charter.Att -= Add_Any_Att;
		break;

	default:printf("��������ȷ�������������!\n"); 
	}
}

///*�ж���������ֵ�Ƿ������ֵ*/	/* �� ͣ ʹ ��*/
//void charter_health_full()
//{
//	//����ֵ = �������ֵ
//	if (charter.Health == _Charter.Charter_Max_Health) {
//		;
//	}
//}

/*����ʣ�������ж�*/
void Charter_Att_(int* Add_Att, int** Att_)
{
	if (charter.Att < *Add_Att) {	//���Ե㲻��
		printf("�Բ���!����ʣ�����Ե㲻��!\n");
		**Att_ = 0;
	}
	else {	//���Ե��㹻
		**Att_ = 1;
	}
}

/*�� �� �� �� �� �� �� ��*/
void Charter_Upgrade()
{
	num++;
	if (charter.Exp % 3 == 0 && num > 1) {
		charter.Health = _Charter.Charter_Max_Health;	//�ָ��������ֵ
		charter.Att += 3;
		charter.Exp = 0;
	}
}