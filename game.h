#pragma once

#define SISTY_PERCENT 0.6	//攻击力的 60%
#define OK 1


int who;
int Defensive_Power_Hight_Low;
int fight_who;
int Add_Any_Att;	//增加 任何 属性
//int add_Aggressivity;	//增加的攻击力
//int add_Health;			//增加生命值
//int add_Defensive_Power;//	  防御力
//int add_Speed;			//	  速  度
int Att_;				//检测是否还有剩余属性
int Att_State;

void Game_Start();	//游戏开始运行处
void Gudgement_Speed(int*);		//速度判定模块
void Fight_charter_monster(int*, int*);
void Charter_Att_(int*, int**);

void Charter_Upgrade();	//人物升级判定
void Att_Add(int*, int*);			//增加人物属性

/*暂 停 使 用*/
void Defensive_Power(int*, int*);		//防御力 -> 攻击力 判定	
void charter_health_full();		//判断是否为最大生命值
