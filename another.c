#include<stdio.h>

#include"another.h"

/*�����������ݺ���*/
void rubbish_()
{
	char rubbish;
	while ((rubbish = getchar()) != '\n' && rubbish != EOF);
}

void who_usr(char* name)
{
	printf("������ʿ����������:");
	scanf_s("%s", name, NAME_MAX);
}