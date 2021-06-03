#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"build.h"

/*人物属性初始化(只进行一次)*/
void Build_Charter_Att()
{
	int charter_state = CHARTER_STATE;

	charter.Aggressivity = rand() % CHARTER_MAX_ATT;
	Build_Charter_Monster_Test(charter_state, &charter.Aggressivity);

	charter.Defensive_Power = rand() % CHARTER_MAX_ATT;
	Build_Charter_Monster_Test(charter_state, &charter.Defensive_Power);

	charter.Health = rand() % CHARTER_MAX_ATT;
	Build_Charter_Monster_Test(charter_state, &charter.Health);

	charter.Speed = rand() % CHARTER_MAX_ATT;
	Build_Charter_Monster_Test(charter_state, &charter.Speed);
}

/*怪物属性初始化--非唯一*/
void Build_Monster_Att(int* state)
{
	if (*state == 1) {
		monster.Frequency++;
	}
	int monster_state = MONSTER_STATE;

	monster.Aggressivity = rand() % MONSTER_MAX_ATT + monster.Frequency * MONSTER_ADD_ATT;
	Build_Charter_Monster_Test(monster_state, &monster.Aggressivity);

	monster.Defensive_Power = rand() % MONSTER_MAX_ATT + monster.Frequency * MONSTER_ADD_ATT;
	Build_Charter_Monster_Test(monster_state, &monster.Defensive_Power);

	monster.Health = rand() % MONSTER_MAX_ATT + monster.Frequency * MONSTER_ADD_ATT;
	Build_Charter_Monster_Test(monster_state, &monster.Health);

	monster.Speed = rand() % MONSTER_MAX_ATT + monster.Frequency * MONSTER_ADD_ATT;
	Build_Charter_Monster_Test(monster_state, &monster.Speed);
}

/*人物-怪物属性是否建立成功(即人物属性 > 15? 怪物属性 = 0 ?)*/
void Build_Charter_Monster_Test(int state, int* charter_monster_att)
{
	/*当人物属性出错*/
	while (state == CHARTER_STATE && *charter_monster_att < 15)
	{
		*charter_monster_att = rand() % CHARTER_MAX_ATT;
	}
	/*当怪物属性出错时*/
	while (state == MONSTER_STATE && *charter_monster_att <= 0)
	{
		*charter_monster_att = rand() % MONSTER_MAX_ATT;
	}	
}
/*人物-怪物属性建立失败(即人物属性建立错误 所有初始值 < 15,怪物属性值 = 0)*/
void Build_Charter_Monster_Question(int state)
{
	;
}