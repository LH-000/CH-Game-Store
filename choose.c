#include<stdio.h>

#include"choose.h"
#include"init.h"
#include"another.h"

/*ѡ�� ս�� - ���� ����*/
void choose_fight_excape(int* choose_Fight_Excape, int* leave)
{
	init_in_out_scanf_state = scanf_s("%d", choose_Fight_Excape);
	if (*choose_Fight_Excape == 1) {
		;
	}
	if (*choose_Fight_Excape == 0) {
		printf("���ܳɹ�!\n");
		return;
	}
	if (*choose_Fight_Excape == 0x10) {
		printf("�Ѿ�����ս������!\n");
		*leave = 0;
		return;
	}
	if (*choose_Fight_Excape == 3) {
		printf("�Ѿ�������������ҳ��!\n");
	}
	/*�û��������ȷָ��--����*/
	while (*choose_Fight_Excape != 0x01 && *choose_Fight_Excape != 0x03) {
		printf("������׼ȷ����Ϣָ��! Err:1 \n");
		printf("����ѡ����ʲô:");
		rubbish_();
		init_in_out_scanf_state = scanf_s("%d", choose_Fight_Excape);
	}
		/*�û��������ȷ����ָ��--�ַ�*/
	while (!init_in_out_scanf_state) {
		printf("������׼ȷ����Ϣָ��!\n");
		printf("����ѡ����ʲô:");
		rubbish_();
		init_in_out_scanf_state = scanf_s("%d", choose_Fight_Excape);
	}
}