#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct CharacterInfo
{
	char Name[20];
	float HP;
	float MP;
	float Damage;
	int LV;
	float EXP;
};

typedef struct CharacterInfo CharacterInfo;

void Print(CharacterInfo data);

int main()
{
	//CharacterInfo Player = {"Player", 30.0f, 30.0f, 10.0f, 3, 0.0f};
	//
	//printf("Player HP : %f\n", Player.HP);
	//printf("Player MP : %f\n", Player.MP);
	//printf("Player Damage : %f\n", Player.Damage);
	//printf("Player LV : %d\n", Player.LV);
	//printf("Player EXP : %f\n\n", Player.EXP);
	//
	//CharacterInfo Enemy;
	//strcpy_s(Enemy.Name, 20, "Enemy");
	//
	//printf("Enemy Name : %s\n", Enemy.Name);
	//
	//CharacterInfo Enemys[30];

	srand(time(NULL));

	CharacterInfo Player;
	CharacterInfo Enemy = {"Enemy", 100.0f, 100.0f, 10, 1, 0.0f};

	strcpy_s(Player.Name, 20, "Player");
	Player.HP = rand() % 100 + 50;
	Player.MP = rand() % 100 + 50;
	Player.Damage = rand() % 25 + 1;
	Player.EXP = 0.0f;
	Player.LV = 1;

	printf("Player HP : %d\n", (int)Player.HP);
	printf("Player MP : %d\n", (int)Player.MP);
	printf("Player Damage : %d\n", (int)Player.Damage);

	printf("\n");

	printf("GAME START\n");

	int turn = 1;
	int action = 0;

	while (1)
	{
		if (Player.HP <= 0)
		{
			printf("Player Lose\n");
			break;
		}
		else if (Enemy.HP <= 0)
		{
			printf("Player Win\n");
			break;
		}

		// Player
		if (turn % 2 == 1)
		{
			printf("액션 선택\n");
			printf("0. 공격\n");
			scanf_s("%d", &action);

			switch(action)
			{
				case 0:
				{
					printf("공격 개시\n");
					printf("Enemy HP : %d (%d - %d)\n", (int)Enemy.HP - (int)Player.Damage, (int)Enemy.HP, (int)Player.Damage);
					Enemy.HP -= Player.Damage;
					break;
				}
				default:
				{
					printf("잘못된 입력\n");
					continue;
				}
			}

			turn++;
		}
		// Enemy
		else
		{
			printf("Enemy의 턴\n");
			printf("Player HP : %d (%d - %d)\n", (int)Player.HP - (int)Enemy.Damage, (int)Player.HP, (int)Enemy.Damage);
			Player.HP -= Enemy.Damage;
			turn++;
		}
	}

	printf("GAME OVER\n");
}

/*
구조체
- 사용자가 c언어의 기본 타입을 가지고 새롭게 정의할 수 있는 사용자 정의 타입
- 기본 타입만으로는 나타낼 수 없는 복잡한 데이터를 표현할 수 있다.
- 배열이 같은 구조의 집합이라고 한다면, 구조체는 다양한 타입의 변수 집합을 하나의 타입으로 나타낸 것
- 이때 구조체를 구성하는 변수를 구조체의 멤버 또는 멤버 변수라고 한다.

typedef
- 이미 존재하는 타입에 새로운 이름을 붙일 때 사용
- 구조체 변수를 선언하거나 사용할 때, 매번 struct 키워드를 사용하여 구조체임을 명시해야 한다.
- 하지만 typedef 키워드를 사용하여 구조체에 새로운 이름을 선언하면 매번 struct 키워드를 사용하지 않아도 된다.*/