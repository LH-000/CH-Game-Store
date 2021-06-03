#pragma once

#define CHARTER_STATE 1		//人物编号 默认 1
#define MONSTER_STATE 2		//怪物编号 默认 2
#define MONSTER_ADD_ATT 0.25	//怪物每回合更新属性
#define CHARTER_MAX_ATT 25	//人物初始胡属性生成最大限度 25
#define MONSTER_MAX_ATT	10	//怪物初始化属性最大限度 10

void Build_Charter_Att();	//人物属性初始化
void Build_Monster_Att(int*);	//怪物属性初始化
void Build_Charter_Monster_Test(int, int*);	//人物-怪物 初始化属性检测

/* - - - - - - 暂 时 不 被 启 用 - - - - - -*/
void Build_Charter_Monster_Question(int);	//人物-怪物 初始化属性重新生成

/*人物属性面板*/
struct Charter
{
	int Aggressivity;	//攻击力
	int Defensive_Power;//防御力
	int Health;			//生命值
	int Speed;			//速  度
	int Exp;			//经验值(3 -> 1)
	int Grade;			//人物等级 
	int Att;			//属性点
}charter;

/*怪物属性面板*/
struct Monster
{
	int Aggressivity;	//攻击力
	int Defensive_Power;//防御力
	int Health;			//生命值
	int Speed;			//速  度
	int Grade;			//怪物等级(暂时不可见)
	int Frequency;		//怪物生成次数(判断是否需要进行下一次怪物属性更新)
}monster;

/*最大属性存储面板*/
struct _Charter_Max
{
	int Charter_Max_Health;	//最大生命值存放处
}_Charter;