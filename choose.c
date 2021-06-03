#include<stdio.h>

#include"choose.h"
#include"init.h"
#include"another.h"

/*选择 战斗 - 逃跑 界面*/
void choose_fight_excape(int* choose_Fight_Excape, int* leave)
{
	init_in_out_scanf_state = scanf_s("%d", choose_Fight_Excape);
	if (*choose_Fight_Excape == 1) {
		;
	}
	if (*choose_Fight_Excape == 0) {
		printf("逃跑成功!\n");
		return;
	}
	if (*choose_Fight_Excape == 0x10) {
		printf("已经脱离战斗程序!\n");
		*leave = 0;
		return;
	}
	if (*choose_Fight_Excape == 3) {
		printf("已经进入属性增加页面!\n");
	}
	/*用户输入非正确指令--数字*/
	while (*choose_Fight_Excape != 0x01 && *choose_Fight_Excape != 0x03) {
		printf("请输入准确的信息指令! Err:1 \n");
		printf("您的选择是什么:");
		rubbish_();
		init_in_out_scanf_state = scanf_s("%d", choose_Fight_Excape);
	}
		/*用户输入非正确数字指令--字符*/
	while (!init_in_out_scanf_state) {
		printf("请输入准确的信息指令!\n");
		printf("您的选择是什么:");
		rubbish_();
		init_in_out_scanf_state = scanf_s("%d", choose_Fight_Excape);
	}
}