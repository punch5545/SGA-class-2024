#include <stdio.h>

int main()
{
	//if (3 + 5 == 10)
	//{
	//	printf("��\n");
	//	printf("������\n");
	//}
	//else if (3 + 5 == 8)
	//	printf("�±� ��\n");
	//else
	//	printf("����\n");

	printf("�ҹ��� �Է� : ");
	char word;
	scanf_s("%c", &word);

	// a == 97 / z == 122
	if (word <= 'z' && word >= 'a')
		printf("�빮�� : %c\n", word - 32);
	else if (word == ' ')
		printf("���� ���� �ȵ�\n");
	else if (word == '3')
		printf("���� �Էµ�\n");
	else
		printf("�߸��� ���� �Է�\n");

	/*
	* ���� �Է� ���α׷�
	* ���� �Է����ּ��� :  <- �Է� �ޱ�
	* 100 ~ 91 == A+
	* 90 ~ 81 == A
	* 80 ~ 71 == B
	* 70 ~ 61 == C
	* ������ == F
	* ��� ��µǵ��� ����� ���α׷��� �ۼ�
	*/

	printf("���α׷� ����\n");
}