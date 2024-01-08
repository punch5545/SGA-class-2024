#include <stdio.h>

int main()
{
	//char word = 200;			// 오버
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
	* 산술 연산에 대한 결과값의 타입은 피연산자의 타입과 언제나 일치하기 때문
	* 즉 int형 데이터끼리의 산술 연산에 대한 결과값은 언제나 int형으로 나옴
	* 따라서 두 번째 연산처럼 하나의 피연산자를 double형으로 지정해야만
	* 정확한 값을 얻을 수 있음
	*/
}

/*
* 형 변환
* 1. 암묵적 형변환
*	- 대입 연산이나 산술 연산에서 c 컴파일러가 자동으로 형변환을 시켜주는 것
*	- 대입 연산시 연산자의 오른쪽에 존재하는 데이터의 타입이 왼쪽에 위치한
*	  데이터의 타입으로 암시적으로 바뀜
*		ex) float f = 3; -> float f = 3.0f;
*	- 산술 연산자에서는 데이터의 손실이 최소화되는 방향으로 암묵적 형 변환이 발생
*	- 아래와 같은 순서대로 자동 타입 변환을 수행
*		char -> short -> int -> long -> float -> double -> long double
* 
* 2. 명시적 형변환
*	- 타입 캐스트 연산자를 사용하여 강제적으로 수행하는 타입 변환
*	- 변환하고자 하는 데이터 앞에 ()를 추가하고, 그 안에 변환할 타입을 삽입
*	() = 타입 캐스트 연산자
*/