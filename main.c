#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#include"init.h"
#include"build.h"
#include"another.h"
#include"game.h"

extern int escape;
extern char name[20];

int main()
{
	system("title ������Ϸ");

	/*����ʼ��ѡ����� -- ����-�˳�--*/
	init_in_out(&choose, init_in_out_scanf_state);

	/*ִ���������������*/
	srand((unsigned)time(NULL));

	/*��������*/
	who_usr(name);

	/*ִ����������Ψһ����*/
	Build_Charter_Att();

	/*ִ�й������Գ�������*/
	/*Build_Monster_Att(&escape);*/

	Game_Start();

	system("pause");
	return 0;
}