#include<stdio.h>

#include"watch.h"
#include"build.h"
#include"another.h"


/*�鿴��������*/
void Watch_Charter_Monster_Att(char* name)
{
	printf("----------------------------------------------\n");
	printf("  %10s ��������\n", name);
	printf("|����ֵ| | %4d  |	| ����ֵ |  |  %3d  |\n", charter.Health, monster.Health);
	printf("|������| | %4d  |	| ������ |  |  %3d  |\n", charter.Aggressivity, monster.Aggressivity);
	printf("|������| | %4d  |	| ������ |  |  %3d  |\n", charter.Defensive_Power, monster.Defensive_Power);
	printf("|��  ��| | %4d  |	| ��  �� |  |  %3d  |\n", charter.Speed, monster.Speed);
	printf("|����ֵ| | %4d  |	| ��  �� |  |  %3d  |\n", charter.Exp, monster.Frequency);
	printf("|���Ե�| | %4d  |                        \n", charter.Att);
	printf("---------------------------------------------\n");
}

/*�����������Ӳ鿴ҳ��*/
void Charter_Att_Add()
{
	printf(" ----------------\n");
	printf("| 1.������ | | + |\n");
	printf("| 2.����ֵ | | + |\n");
	printf("| 3.������ | | + |\n");
	printf("| 4.��  �� | | + |\n");
	printf(" ----------------\n");
}

/*�鿴��������*/	/*ͣ ֹ ʹ ��*/
//void Watch_Monster_Att()
//{
//	;
//}