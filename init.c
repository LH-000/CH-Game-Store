#include<stdio.h>
#include<stdlib.h>

#include"init.h"
#include"another.h"

/*����ʼ�Ľ���*/
void init_in_out(int* choose, int init_in_out_scanf_state)
{
	printf("\t\t\t\t\t --------------------------------------\n");
	printf("\t\t\t\t\t|--------------------------------------|\n");
	printf("\t\t\t\t\t|      ��      ��      ��      Ϸ      |\n");
	printf("\t\t\t\t\t --------------------------------------\n");
	printf("\t\t\t\t\t|    1.�� ʼ    |        |   0.�� ��   |\n");
	printf("\t\t\t\t\t --------------------------------------\n");
	printf("����ѡ����ʲô:");
	init_in_out_scanf_state = scanf_s("%d", choose);	
	//printf("init_in_out_state = %d\n", init_in_out_scanf_state);	//������	(Ĭ�Ϲر�)

	/*����Ϊ��ʼ*/
	if (*choose == 1)
	{
		;
	}
	/*�û��������ȷ����ָ��--�ַ�*/
	while (!init_in_out_scanf_state)
	{
		printf("��������ȷ��ָ������!\n");
		printf("����ѡ����ʲô:");
		rubbish_();	//������������
		init_in_out_scanf_state = scanf_s("%d", choose);
	}
	/*�û�ѡ���˳�ѡ��*/
	if (*choose == 0) {
		printf("�ڴ������´�����!\n");
		exit(EXIT_SUCCESS);
	}
	/*�û��������ȷָ��--����*/
	while (*choose != 1)
	{
		printf("��������ȷ��ָ������!!\n");
		printf("����ѡ����ʲô:");
		rubbish_();	//������������
		init_in_out_scanf_state = scanf_s("%d", choose);
	}
}
/*ս�� - ���� ����*/
void init_fight_excape()
{
	printf(" ----------------------------------------------\n");
	printf("|1.ս��| |16.�����������| |3.�������| |0.����|\n");
	printf(" ----------------------------------------------\n");
	printf("���ѡ����:");
}