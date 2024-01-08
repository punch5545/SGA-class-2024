#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum State
{
	NORMAL,
	RUN,
	WALK,
	STUN,
	SPRINT,
	ERROR,
};

int a;

int main()
{
	//int a = 0;
	//while (/*조건식*/a < 100)
	//{
	//	/*명령문*/
	//	a++;	// 조건식의 결과를 변경하는 명령문
	//}
	srand(time(NULL));

	//int i = 0;
	//int a = 0;
	//while (1)
	//{
	//	i = rand() % 6;
	//
	//	printf("i = %d\n", i);
	//
	//	if (i == ERROR)
	//		continue;
	//
	//	printf("정상 작동됨\n");
	//
	//	if (a++ > 100)
	//		break;
	//}

	//int i = 0;
	//do
	//{
	//	printf("%d\n", ++i);
	//} while (i < 100);

	//자체적으로 초기식, 조건식, 증감식을 모두 포함
	//for (int i = 0; i < 100; i++)
	//{
	//	for (int j = 0; j < 100; j++)
	//		printf("%d\t%d\n", i, j);
	//}

	int input;
	printf("몇 층의 삼격형을 만들까요? : ");
	scanf_s("%d", &input);

	for (int i = 0; i <= input; i++)
	{
		printf("%d", i);
		for (int j = 0; j < i; j++)
			printf("*");

		printf("\n");
	}
}

/*
* 1. while
*	- 특정 조건을 만족하면 무한반복
*	- 순서
*		1) 조건식 검사
*		2) 명령문 실행
*		3) 조건식의 결과를 변경하는 명령문
*		4) 조건식 검사
*		5) 반복
* 
* 2. do while
*	- 특정 조건을 만족하면 무한반복
*	- 순서
*		1) 명령문 실행
*		2) 조건식의 결과를 변경하는 명령문
*		3) 조건식 검사
*		4) 반복
* 
* 3. for
*	- 자체적으로 초기식, 조건식, 증감식을 모두 포함하는 반복문
*	- while문 보다는 더 간결하게 반복문을 표현할 수 있음
*	- for문 안에 for문 안에 for문 안에 .....
*	- 되도록이면 2개 초과는 사용하지 말자...
*	- 아무리 많아도 5개 이하로만 쓰자...
* 
* 루프 제어문
* 1. break
*	- 루프를 중단시킨다
* 2. continue
*	- 해당 순번을 넘기고 계속 진행
* 
* 변수의 유효 범위
* 1. 지역 변수	(Local Variable)
 	- 블록 내에서 선언된 변수
	- 블록 내에서만 유효
	- 블록이 종료되면 메모리에서 사라짐

* 2. 전역 변수	(Global Variable)
 	- 함수 외부에서 선언된 변수
	- 프로그램의 어디에서나 접근할 수 있다.
	- 프로그램이 종료되어야 메모리에서 사라진다.
	- 직접 초기화하지 않아도 0으로 초기화된다.

* 3. 정적 변수	(Static Variable)
 	- 지역 변수와 전역 변수의 특성을 모두 가지게 된다
	- 함수 내에서 선언된 정적 변수는 전역 변수처럼 단 한 번만 초기화된다
	- 프로그램이 종료되어야 메모리상에서 사라진다.
	- 이렇게 선언된 정적 변수는 지역 변수처럼 해당 함수 내에서만 접근할 수 있다.
	- 해당 예제는 함수를 배울 때 다시 설명
* 
* 메모리의 구조
* 1. 코드 영역
*	- 실행할 프로그램의 코드
* 
* 2. 데이터 영역
*	- 전역 변수 / 정적 변수
* 
* 3. 힙 영역
*	- 사용자의 동적 할당 (추후 배울 예정)
*	- 프로그램이 시작될 때 크기가 결정
* 
* 4. 스택 영역
*	- 지역 변수 / 매개 변수 (나중에 배울 예정)
*	- 컴파일 타임에 크기가 결정
* 
* 컴파일
*	- 사용하고 있는 프로그램인 Visual Studio는 컴파일러라고 부른다 (컴파일 시켜주는 놈)
*	- 컴파일러는 고급언어를 저급언어로 변경해주는 통역 역할을 한다.
*	(고급 언어 : 사람이 사용하는 언어체계와 비슷한것 (JAVA, C, C++, C#, Ruby 등))
*	(저급 언어 : 컴퓨터가 사용하는 언어 (이진법, 어셈블리어 등))
*/