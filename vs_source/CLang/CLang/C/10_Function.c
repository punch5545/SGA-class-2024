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
	//printf("둘 중 큰 값은 %d 입니다\n", MAX(a,b));

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
	printf("호출됨\n");
	return;
}

/*
* 함수
*	- 하나의 특별한 목적의 작업을 수행하기 위해 독립적으로 설계된 프로그램
*	  코드의 집합
*	- 반복적인 프로그래밍을 피할 수 있다
*	- 특정 작업을 여러번 반복해야 할 때는 해당 작업을 수행하는 함수를 작성
*	  하면 된다
*	- 프로그램이 필요할 때마다 작성한 함수를 호출해주면 된다
*	- 프로그램을 여러개의 함수로 나눠서 작성하면, 모듈화로 인해서 가독성이
*	  올라간다
*	- 문제가 발생하거나 기능의 변경이 필요할 때도 유지보수가 수월하다
* 
* 함수의 정의
*	
*	반환형 함수이름(매개변수 목록)
*	{
*		함수 몸체
*		
*		반환 값
*	}
* 
*	반환형 : 함수가 모든 작업을 마치고 반환하는 데이터 타입
*	함수 이름 : 함수를 호출하기 위한 이름
*	매개 변수 목록 (파라미터) : 함수 호출 시에 전달되는 인수의 값을
*							  지정할 변수들을 명시
*	함수 몸체 : 함수 고유의 기능을 수행하는 명령문의 집합
*	반환 값 : 함수를 끝내고 값을 반환
*/