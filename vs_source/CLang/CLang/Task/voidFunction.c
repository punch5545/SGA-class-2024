#include <stdio.h>

struct EX
{
	int a;
	int b;
	float c;
};

typedef struct EX EX;

void print(EX* data);

int main()
{
	struct EX ex = { 3, 5, 10.0f };
	while (1)
	{
		int num;
		scanf_s("%d", &num);

		if (num == 0)
			return;
		else
			print(&ex);
	}
}

void print(EX* data)
{
	printf("a : %d\nb : %d\nc : %f\n", data->a, data->b, --data->c);
}