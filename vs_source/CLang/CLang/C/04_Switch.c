#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum RSP
{
	ROCK,
	SCISSORS,
	PAPER
};

int main()
{
	// 0 = ��
	// 1 = ��
	// 2 = ��

	int a;
	printf("0. ��  1. ��  2. ��\n");
	scanf_s("%d", &a);

	srand(time(NULL));
	int computer = rand() % 3;

	switch (a)
	{
		case ROCK:
		{
			if (computer == ROCK) printf("�����ϴ�\n");
			else if (computer == SCISSORS) printf("�̰���ϴ�\n");
			else if (computer == PAPER) printf("�����ϴ�\n");
			break;
		}
		case SCISSORS:
		{
			if (computer == ROCK) printf("��\n");
			else if (computer == SCISSORS) printf("��\n");
			else if (computer == PAPER) printf("��\n");
			break;
		}
		case PAPER:
		{
			if (computer == ROCK) printf("��\n");
			else if (computer == SCISSORS) printf("��\n");
			else if (computer == PAPER) printf("��\n");
			break;
		}
		default:
		{
			printf("�߸��� �� �Էµ�\n");
			break;
		}
	}
}