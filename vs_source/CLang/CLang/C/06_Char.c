#include <stdio.h>

int main()
{
	//printf("%c\n", 'S');
	//printf("%s\n", "asdf");
	//
	//printf("%d", sizeof("asdf"));

	char begin, end;

	printf("Input Begin : ");
	scanf_s("%c", &begin, 1);
	rewind(stdin);

	printf("Input End : ");
	scanf_s("%c", &end, 1);
	rewind(stdin);

	printf("Check : begin(%c) ~ end(%c)\n", begin, end);

	printf("\u0398");
}

/*
* char
*	- ��ǻ�ʹ� ��� �����͸� ���������� �����ϴµ� ���ڴ� ��� �����ϴ°�?
*	 -> �ƽ�Ű �ڵ� : 7��Ʈ ���ڵ� / ��ǻ�Ϳ��� ����ϴ� ǥ���� �������鼭
*					 �����ڵ�� �Ѿ��
*	- char�� ������ printf("%d")�� ����ϸ� ������ �����°� Ȯ���� �� �ִ�
*	- char�� �������� "�� ����"�� ����
*	- ' ' = ����   %c
*	- " " = ���ڿ� %s	(null���ڸ� ���� �� ���� ���)
* 
* �����ڵ�
*	- �� ������ ��� ���ڸ� ��ǻ�Ϳ��� �ϰ��ǰ� ǥ���ϰ� �ٷ� �� �ֵ��� �����
*     ��� ǥ��
*	- https://unicode-table.com/kr/
*/