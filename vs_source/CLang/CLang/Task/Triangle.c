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
		// ���κ�
		if (i <= MiddleLine)
		{
			for (int j = 0; j < input / 2 - i; j++)
				printf(" ");
			for (int j = 0; j < i * 2 + 1; j++)
				printf("*");
		}
		// �Ʒ��κ�
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