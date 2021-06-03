#include<stdio.h>

#include"another.h"

/*处理垃圾数据函数*/
void rubbish_()
{
	char rubbish;
	while ((rubbish = getchar()) != '\n' && rubbish != EOF);
}

void who_usr(char* name)
{
	printf("请问勇士您的姓名是:");
	scanf_s("%s", name, NAME_MAX);
}