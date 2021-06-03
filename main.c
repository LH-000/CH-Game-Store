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
	system("title 文字游戏");

	/*程序开始的选择界面 -- 进入-退出--*/
	init_in_out(&choose, init_in_out_scanf_state);

	/*执行生成随机数种子*/
	srand((unsigned)time(NULL));

	/*姓名输入*/
	who_usr(name);

	/*执行人物属性唯一生成*/
	Build_Charter_Att();

	/*执行怪物属性初次生成*/
	/*Build_Monster_Att(&escape);*/

	Game_Start();

	system("pause");
	return 0;
}