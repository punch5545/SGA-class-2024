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
			printf("�׼� ����\n");
			printf("0. ����\n");
			scanf_s("%d", &action);

			switch(action)
			{
				case 0:
				{
					printf("���� ����\n");
					printf("Enemy HP : %d (%d - %d)\n", (int)Enemy.HP - (int)Player.Damage, (int)Enemy.HP, (int)Player.Damage);
					Enemy.HP -= Player.Damage;
					break;
				}
				default:
				{
					printf("�߸��� �Է�\n");
					continue;
				}
			}

			turn++;
		}
		// Enemy
		else
		{
			printf("Enemy�� ��\n");
			printf("Player HP : %d (%d - %d)\n", (int)Player.HP - (int)Enemy.Damage, (int)Player.HP, (int)Enemy.Damage);
			Player.HP -= Enemy.Damage;
			turn++;
		}
	}

	printf("GAME OVER\n");
}

/*
����ü
- ����ڰ� c����� �⺻ Ÿ���� ������ ���Ӱ� ������ �� �ִ� ����� ���� Ÿ��
- �⺻ Ÿ�Ը����δ� ��Ÿ�� �� ���� ������ �����͸� ǥ���� �� �ִ�.
- �迭�� ���� ������ �����̶�� �Ѵٸ�, ����ü�� �پ��� Ÿ���� ���� ������ �ϳ��� Ÿ������ ��Ÿ�� ��
- �̶� ����ü�� �����ϴ� ������ ����ü�� ��� �Ǵ� ��� ������� �Ѵ�.

typedef
- �̹� �����ϴ� Ÿ�Կ� ���ο� �̸��� ���� �� ���
- ����ü ������ �����ϰų� ����� ��, �Ź� struct Ű���带 ����Ͽ� ����ü���� ����ؾ� �Ѵ�.
- ������ typedef Ű���带 ����Ͽ� ����ü�� ���ο� �̸��� �����ϸ� �Ź� struct Ű���带 ������� �ʾƵ� �ȴ�.*/