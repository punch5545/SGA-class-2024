#include <stdio.h>

int main()
{
	//char word = 200;			// ����
	//int integer = 3.15;		// int -> double
	//double realNumber = 5;	// double -> int
	//
	//printf("word : %d\n", word);
	//printf("integer : %d\n", integer);
	//printf("realNumber : %f\n", realNumber);

	//double result0 = 3 + 3.14;		// int + double
	//double result1 = 3.0f + 3.14;	// float + double
	//
	//printf("result0 : %f\n", result0);
	//printf("result1 : %f\n", result1);

	int num0 = 1;
	int num1 = 2;

	double result0 = num0 / num1;				// int / int
	double result1 = (double)num0 / num1;		// double / int

	printf("result0 : %f\n", result0);
	printf("result1 : %f\n", result1);

	/*
	* ��� ���꿡 ���� ������� Ÿ���� �ǿ������� Ÿ�԰� ������ ��ġ�ϱ� ����
	* �� int�� �����ͳ����� ��� ���꿡 ���� ������� ������ int������ ����
	* ���� �� ��° ����ó�� �ϳ��� �ǿ����ڸ� double������ �����ؾ߸�
	* ��Ȯ�� ���� ���� �� ����
	*/
}

/*
* �� ��ȯ
* 1. �Ϲ��� ����ȯ
*	- ���� �����̳� ��� ���꿡�� c �����Ϸ��� �ڵ����� ����ȯ�� �����ִ� ��
*	- ���� ����� �������� �����ʿ� �����ϴ� �������� Ÿ���� ���ʿ� ��ġ��
*	  �������� Ÿ������ �Ͻ������� �ٲ�
*		ex) float f = 3; -> float f = 3.0f;
*	- ��� �����ڿ����� �������� �ս��� �ּ�ȭ�Ǵ� �������� �Ϲ��� �� ��ȯ�� �߻�
*	- �Ʒ��� ���� ������� �ڵ� Ÿ�� ��ȯ�� ����
*		char -> short -> int -> long -> float -> double -> long double
* 
* 2. ����� ����ȯ
*	- Ÿ�� ĳ��Ʈ �����ڸ� ����Ͽ� ���������� �����ϴ� Ÿ�� ��ȯ
*	- ��ȯ�ϰ��� �ϴ� ������ �տ� ()�� �߰��ϰ�, �� �ȿ� ��ȯ�� Ÿ���� ����
*	() = Ÿ�� ĳ��Ʈ ������
*/