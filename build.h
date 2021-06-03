#pragma once

#define CHARTER_STATE 1		//������ Ĭ�� 1
#define MONSTER_STATE 2		//������ Ĭ�� 2
#define MONSTER_ADD_ATT 0.25	//����ÿ�غϸ�������
#define CHARTER_MAX_ATT 25	//�����ʼ��������������޶� 25
#define MONSTER_MAX_ATT	10	//�����ʼ����������޶� 10

void Build_Charter_Att();	//�������Գ�ʼ��
void Build_Monster_Att(int*);	//�������Գ�ʼ��
void Build_Charter_Monster_Test(int, int*);	//����-���� ��ʼ�����Լ��

/* - - - - - - �� ʱ �� �� �� �� - - - - - -*/
void Build_Charter_Monster_Question(int);	//����-���� ��ʼ��������������

/*�����������*/
struct Charter
{
	int Aggressivity;	//������
	int Defensive_Power;//������
	int Health;			//����ֵ
	int Speed;			//��  ��
	int Exp;			//����ֵ(3 -> 1)
	int Grade;			//����ȼ� 
	int Att;			//���Ե�
}charter;

/*�����������*/
struct Monster
{
	int Aggressivity;	//������
	int Defensive_Power;//������
	int Health;			//����ֵ
	int Speed;			//��  ��
	int Grade;			//����ȼ�(��ʱ���ɼ�)
	int Frequency;		//�������ɴ���(�ж��Ƿ���Ҫ������һ�ι������Ը���)
}monster;

/*������Դ洢���*/
struct _Charter_Max
{
	int Charter_Max_Health;	//�������ֵ��Ŵ�
}_Charter;