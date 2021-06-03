#include<stdio.h>
#include<stdlib.h>

#include"init.h"
#include"another.h"

/*程序开始的界面*/
void init_in_out(int* choose, int init_in_out_scanf_state)
{
	printf("\t\t\t\t\t --------------------------------------\n");
	printf("\t\t\t\t\t|--------------------------------------|\n");
	printf("\t\t\t\t\t|      文      字      游      戏      |\n");
	printf("\t\t\t\t\t --------------------------------------\n");
	printf("\t\t\t\t\t|    1.开 始    |        |   0.退 出   |\n");
	printf("\t\t\t\t\t --------------------------------------\n");
	printf("您的选择是什么:");
	init_in_out_scanf_state = scanf_s("%d", choose);	
	//printf("init_in_out_state = %d\n", init_in_out_scanf_state);	//输入检测	(默认关闭)

	/*输入为开始*/
	if (*choose == 1)
	{
		;
	}
	/*用户输入非正确数字指令--字符*/
	while (!init_in_out_scanf_state)
	{
		printf("请输入正确的指令命令!\n");
		printf("您的选择是什么:");
		rubbish_();	//处理垃圾数据
		init_in_out_scanf_state = scanf_s("%d", choose);
	}
	/*用户选择退出选择*/
	if (*choose == 0) {
		printf("期待您的下次试玩!\n");
		exit(EXIT_SUCCESS);
	}
	/*用户输入非正确指令--数字*/
	while (*choose != 1)
	{
		printf("请输入正确的指令命令!!\n");
		printf("您的选择是什么:");
		rubbish_();	//处理垃圾数据
		init_in_out_scanf_state = scanf_s("%d", choose);
	}
}
/*战斗 - 逃跑 界面*/
void init_fight_excape()
{
	printf(" ----------------------------------------------\n");
	printf("|1.战斗| |16.紧急脱离程序| |3.添加属性| |0.逃跑|\n");
	printf(" ----------------------------------------------\n");
	printf("你的选择是:");
}