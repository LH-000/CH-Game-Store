#pragma once

#define SISTY_PERCENT 0.6	//�������� 60%
#define OK 1


int who;
int Defensive_Power_Hight_Low;
int fight_who;
int Add_Any_Att;	//���� �κ� ����
//int add_Aggressivity;	//���ӵĹ�����
//int add_Health;			//��������ֵ
//int add_Defensive_Power;//	  ������
//int add_Speed;			//	  ��  ��
int Att_;				//����Ƿ���ʣ������
int Att_State;

void Game_Start();	//��Ϸ��ʼ���д�
void Gudgement_Speed(int*);		//�ٶ��ж�ģ��
void Fight_charter_monster(int*, int*);
void Charter_Att_(int*, int**);

void Charter_Upgrade();	//���������ж�
void Att_Add(int*, int*);			//������������

/*�� ͣ ʹ ��*/
void Defensive_Power(int*, int*);		//������ -> ������ �ж�	
void charter_health_full();		//�ж��Ƿ�Ϊ�������ֵ
