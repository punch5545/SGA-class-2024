#include <stdio.h>

int MAX(int a, int b);

int SUM(int a, int b);
int SUB(int a, int b);
int MUL(int a, int b);
int DEV(int a, int b);

void PRINT();

int main()
{
	//int a, b, max;
	//scanf_s("%d %d", &a, &b);
	//
	//printf("�� �� ū ���� %d �Դϴ�\n", MAX(a,b));

	int a, b;
	char o;

	while (1)
	{
		scanf_s("%d %c %d", &a, &o, 1, &b);
		rewind(stdin);

		switch (o)
		{
			case '+':
				printf("= %d\n", SUM(a, b));
				break;

			case '-':
				printf("= %d\n", SUB(a, b));
				break;

			case '*':
				printf("= %d\n", MUL(a, b));
				break;

			case '/':
				printf("= %d\n", DEV(a, b));
				break;

			default : 
				PRINT();
				return 0;
		}
	}
	
}

int MAX(int a, int b)
{
	if (a > b)
		return a;
	else if (b > a)
		return b;
	else
		return 10;
}

int SUM(int a, int b)
{
	return a + b;
}

int SUB(int a, int b)
{
	return a - b;
}

int MUL(int a, int b)
{
	return a * b;
}

int DEV(int a, int b)
{
	return a / b;
}

void PRINT()
{
	printf("ȣ���\n");
	return;
}

/*
* �Լ�
*	- �ϳ��� Ư���� ������ �۾��� �����ϱ� ���� ���������� ����� ���α׷�
*	  �ڵ��� ����
*	- �ݺ����� ���α׷����� ���� �� �ִ�
*	- Ư�� �۾��� ������ �ݺ��ؾ� �� ���� �ش� �۾��� �����ϴ� �Լ��� �ۼ�
*	  �ϸ� �ȴ�
*	- ���α׷��� �ʿ��� ������ �ۼ��� �Լ��� ȣ�����ָ� �ȴ�
*	- ���α׷��� �������� �Լ��� ������ �ۼ��ϸ�, ���ȭ�� ���ؼ� ��������
*	  �ö󰣴�
*	- ������ �߻��ϰų� ����� ������ �ʿ��� ���� ���������� �����ϴ�
* 
* �Լ��� ����
*	
*	��ȯ�� �Լ��̸�(�Ű����� ���)
*	{
*		�Լ� ��ü
*		
*		��ȯ ��
*	}
* 
*	��ȯ�� : �Լ��� ��� �۾��� ��ġ�� ��ȯ�ϴ� ������ Ÿ��
*	�Լ� �̸� : �Լ��� ȣ���ϱ� ���� �̸�
*	�Ű� ���� ��� (�Ķ����) : �Լ� ȣ�� �ÿ� ���޵Ǵ� �μ��� ����
*							  ������ �������� ���
*	�Լ� ��ü : �Լ� ������ ����� �����ϴ� ��ɹ��� ����
*	��ȯ �� : �Լ��� ������ ���� ��ȯ
*/