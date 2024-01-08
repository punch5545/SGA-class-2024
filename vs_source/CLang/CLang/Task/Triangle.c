#include <stdio.h>

int main()
{
	int input;
	scanf_s("%d", &input);

	for (int i = 0; i < input; i++)
	{
		int StarCount = i * 2 + 1;
		int EmptySpace = input - i - 1;

		for (int j = 0; j < EmptySpace; j++)
			printf(" ");

		for (int j = 0; j < StarCount; j++)
			printf("*");

		printf("\n");
	}

	printf("\n\n");

	input = input % 2 == 1 ? input : ++input;
	int MiddleLine = input / 2;

	int EmptySpace = 1;
	for (int i = 0; i < input; i++)
	{
		// 윗부분
		if (i <= MiddleLine)
		{
			for (int j = 0; j < input / 2 - i; j++)
				printf(" ");
			for (int j = 0; j < i * 2 + 1; j++)
				printf("*");
		}
		// 아래부분
		else
		{
			for (int j = 0; j < EmptySpace; j++)
				printf(" ");
			for (int j = 0; j < input - (EmptySpace * 2); j++)
				printf("*");

			EmptySpace++;
		}

		printf("\n");
	}
	
}