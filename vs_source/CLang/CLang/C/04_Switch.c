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
	// 0 = ¹¬
	// 1 = Âî
	// 2 = ºü

	int a;
	printf("0. ¹¬  1. Âî  2. ºü\n");
	scanf_s("%d", &a);

	srand(time(NULL));
	int computer = rand() % 3;

	switch (a)
	{
		case ROCK:
		{
			if (computer == ROCK) printf("ºñ°å½À´Ï´Ù\n");
			else if (computer == SCISSORS) printf("ÀÌ°å½À´Ï´Ù\n");
			else if (computer == PAPER) printf("Á³½À´Ï´Ù\n");
			break;
		}
		case SCISSORS:
		{
			if (computer == ROCK) printf("Á³\n");
			else if (computer == SCISSORS) printf("ºñ\n");
			else if (computer == PAPER) printf("ÀÌ\n");
			break;
		}
		case PAPER:
		{
			if (computer == ROCK) printf("ÀÌ\n");
			else if (computer == SCISSORS) printf("Á³\n");
			else if (computer == PAPER) printf("ºñ\n");
			break;
		}
		default:
		{
			printf("Àß¸øµÈ °ª ÀÔ·ÂµÊ\n");
			break;
		}
	}
}