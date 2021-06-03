#include<stdio.h>

#include"watch.h"
#include"build.h"
#include"another.h"


/*查看人物属性*/
void Watch_Charter_Monster_Att(char* name)
{
	printf("----------------------------------------------\n");
	printf("  %10s 您的属性\n", name);
	printf("|生命值| | %4d  |	| 生命值 |  |  %3d  |\n", charter.Health, monster.Health);
	printf("|攻击力| | %4d  |	| 攻击力 |  |  %3d  |\n", charter.Aggressivity, monster.Aggressivity);
	printf("|防御力| | %4d  |	| 防御力 |  |  %3d  |\n", charter.Defensive_Power, monster.Defensive_Power);
	printf("|速  度| | %4d  |	| 速  度 |  |  %3d  |\n", charter.Speed, monster.Speed);
	printf("|经验值| | %4d  |	| 波  数 |  |  %3d  |\n", charter.Exp, monster.Frequency);
	printf("|属性点| | %4d  |                        \n", charter.Att);
	printf("---------------------------------------------\n");
}

/*人物属性增加查看页面*/
void Charter_Att_Add()
{
	printf(" ----------------\n");
	printf("| 1.攻击力 | | + |\n");
	printf("| 2.生命值 | | + |\n");
	printf("| 3.防御力 | | + |\n");
	printf("| 4.速  度 | | + |\n");
	printf(" ----------------\n");
}

/*查看怪物属性*/	/*停 止 使 用*/
//void Watch_Monster_Att()
//{
//	;
//}