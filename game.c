#include<stdio.h>
#include<windows.h>

#include"game.h"
#include"init.h"
#include"choose.h"
#include"build.h"
#include"watch.h"
#include"another.h"

int escape = 1;

static int num = 0;

/*游戏开始进行处*/
void Game_Start()
{
	int leave = 1;	//脱离战斗程序
	int add_att = 0;
	int _charter_run_ = 0;
	_Charter.Charter_Max_Health = charter.Health;
	while (leave)
	{
		Build_Monster_Att(&escape);

		/*查看人物-怪物 属性界面*/
		Watch_Charter_Monster_Att(name);

		init_fight_excape();	//战斗 或者 逃跑 界面

		choose_fight_excape(&choose_Fight_Excape, &leave);	//选择战斗 或者 逃跑

		if (choose_Fight_Excape == 3) {
			add_att = 1;
		}
		if (choose_Fight_Excape == 0) {
			_charter_run_++;
			if (_charter_run_ == 10) {	//达到逃跑上限
				for (int i = 0; i < 10; i++) {
					printf("已经不可以了！再逃跑会受到制裁的!\n");
					Sleep(1000);
				}
			}
			if (_charter_run_ == 11) {
				charter.Health -= 10;
				printf("您已经被扣除10点生命值!\n");
				Sleep(3000);
				_charter_run_ = 0;
				printf("按任意键继续......\n");
				system("pause");
			}
			continue;
		}

		/*进入 增加属性 界面*/
		while (choose_Fight_Excape == 3 && add_att == 1)
		{
			Att_Add(&Att_,&Att_State);	//增加属性模块 -> 回传属性状态
			if (Att_State)	//回传状态正常
			{
				printf("您还有加点需要么[1][0]: ");
				scanf_s("%d", &add_att);
			}
			if (Att_ == 0) {	//出现错误 判断usr 是否 继续执行 加点任务
				printf("出现错误,是否继续执行加点任务:[1]继续执行加点任务 [2]退出加点任务 :-:");	
				scanf_s("%d", &add_att);
			}
			if (add_att == 1) {	//继续 执行 加点任务
				;
			}
		}
		/*选项为正常时起用*/
		if (choose_Fight_Excape == 1)
		{
			Gudgement_Speed(&who);	//速度判定

			/*暂 时 停 用*/
			//Defensive_Power(&who, &Defensive_Power_Hight_Low);	//防御力 -> 攻击力判定	

			while (charter.Health > 0 && monster.Health > 0)
			{
				Fight_charter_monster(&who, &fight_who);	//战斗程序
				if (charter.Health <= 0) {
					printf("Game OVER!");
					printf("您存活的波数是 %d.\n", monster.Frequency - 1);
					return;
				}
				if (monster.Health <= 0) {
					printf("怪物已阵亡! Exp+1!\n");
					charter.Exp++;
					Charter_Upgrade();	//人物升级判定
				}
			}
		}
	}
}

/*速度判定模块*/
void Gudgement_Speed(int* who)
{
	if (charter.Speed >= monster.Speed) {	//人物速度 > 怪物速度
		*who = CHARTER_STATE;
	}
	else {	//怪物先出手
		*who = MONSTER_STATE;
	}
}
/*防御力 -> 攻击力判定*/	/*暂 时 停 用*/
//void Defensive_Power(int* who, int* Defensive_Power_Hight_Low)
//{
//	if (*who == CHARTER_STATE) {
//		*Defensive_Power_Hight_Low = charter.Aggressivity * SISTY_PERCENT - monster.Defensive_Power;
//	}
//}

/*人物-怪物 开始战斗 */
void Fight_charter_monster(int* who, int* fight_who)
{
	if (*who == CHARTER_STATE && charter.Aggressivity > monster.Defensive_Power + monster.Health) {	//人物先出手 
		monster.Health = monster.Health + monster.Defensive_Power - charter.Aggressivity;
		*who = MONSTER_STATE;	//状态为 2 攻防转换
	}
	else if (*who == CHARTER_STATE && charter.Aggressivity <= monster.Health + monster.Defensive_Power) {
		monster.Health -= 3;
		*who = MONSTER_STATE;
	}

	else if (*who == MONSTER_STATE && monster.Aggressivity > charter.Aggressivity + charter.Defensive_Power) {
		charter.Health = charter.Health + charter.Defensive_Power - monster.Aggressivity;
		*who = CHARTER_STATE;
	}
	else if (*who == MONSTER_STATE && monster.Aggressivity <= charter.Health + charter.Defensive_Power) {
		charter.Health -= 3;
		*who = CHARTER_STATE;
	}
}

/*属 性 增 加 程 序*/
void Att_Add(int* Att_, int* state)
{
	int Att = 0;
	int** p_Att_ = &Att_;
	Charter_Att_Add();	//增加属性界面
	printf("您想增加哪条属性数据:");
	scanf_s("%d", &Att);
	switch (Att)
	{
	case 1:printf("您将增加 | 攻击力 |:"); scanf_s("%d", &Add_Any_Att); Charter_Att_(&Add_Any_Att, p_Att_);
		if (*Att_ == 0) {	//属性不够 退出
			return;
		}	
		charter.Aggressivity += Add_Any_Att; *state = OK;
		charter.Att -= Add_Any_Att;
		break;

	case 2:printf("您将增加 | 生命值 |:"); scanf_s("%d", &Add_Any_Att); Charter_Att_(&Add_Any_Att, p_Att_);
		if (*Att_ == 0) {	//属性不够 退出
			return;
		}	
		charter.Health += Add_Any_Att;
		_Charter.Charter_Max_Health += Add_Any_Att; *state = OK; 
		charter.Att -= Add_Any_Att;
		break;

	case 3:printf("您将增加 | 防御力 |:"); scanf_s("%d", &Add_Any_Att); Charter_Att_(&Add_Any_Att, p_Att_);
		if (*Att_ == 0) {	//属性不够 退出
			return;
		}	
		charter.Defensive_Power += Add_Any_Att; *state = OK; 
		charter.Att -= Add_Any_Att;
		break;

	case 4:printf("您将增加 | 速  度 |:"); scanf_s("%d", &Add_Any_Att); Charter_Att_(&Add_Any_Att, p_Att_);
		if (*Att_ == 0) {	//属性不够 退出
			return;
		}	
		charter.Speed += Add_Any_Att; *state = OK;
		charter.Att -= Add_Any_Att;
		break;

	default:printf("请输入正确的增加属性序号!\n"); 
	}
}

///*判断人物生命值是否是最大值*/	/* 暂 停 使 用*/
//void charter_health_full()
//{
//	//生命值 = 最大生命值
//	if (charter.Health == _Charter.Charter_Max_Health) {
//		;
//	}
//}

/*人物剩余属性判定*/
void Charter_Att_(int* Add_Att, int** Att_)
{
	if (charter.Att < *Add_Att) {	//属性点不够
		printf("对不起!您的剩余属性点不够!\n");
		**Att_ = 0;
	}
	else {	//属性点足够
		**Att_ = 1;
	}
}

/*人 物 升 级 判 定 程 序*/
void Charter_Upgrade()
{
	num++;
	if (charter.Exp % 3 == 0 && num > 1) {
		charter.Health = _Charter.Charter_Max_Health;	//恢复最大生命值
		charter.Att += 3;
		charter.Exp = 0;
	}
}