#include <stdio.h>

int main()
{
	//int a;
	//a = 100;
	//int b = a;

	//float pi = 3.141592f;

	//// 자료형 변수명;

	//printf("Hello World, %f\n", pi);

	//float asdf = 20.2f;
	//printf("%f", asdf);
	
	char input;
	scanf_s("%c", &input);

	printf("입력된 값은 %c입니다.\n", input - 32);
	
	return 0;

	/*
	* 프로그램이 시작하면 아래의 순서를 따를 것
	* 1. 소문자를 하나 입력하시오 : 
	* 2. 입력된 문자를 대문자로 바꿔서 화면에 출력
	* "A"
	* 힌트 : 아스키코드
	*/
}

/*
float형을 사용하는 변수 asdf라는걸 만들어서
20.2로 초기화 후 출력
*/

/*
* = : 대입 연산자
*  -> 변수에 어떤 값을 대입시켜주는 연산자
* 
* unsigned : -부호 제외
* 
* 정수
* short		2byte
* int		4byte
* long		4byte
* longlong	8byte
* 
* 실수
* float		4byte
* 0      0000 0000  000 0000 0000 0000 0000 0000
* 부호   지수부		가수부
* double	8byte
* 
* 문자형
* char		1byte
*/

/*
서식지정자
사용자가 출력할 데이터의 서식을 지정할 수 있다.

종류
%d == %i	: 부호있는 10진 정수
%f			: 고정 소수점으로 표현한 실수 (소수점 아래 6자리까지 표현)
%lf			: 고정 소수점으로 표현한 실수 (long double)
%c			: 하나의 문자
%o			: 부호없는 8진 정수
%u			: 부호없는 10진 정수
%x			: 부호없는 16진 정수(소문자 사용)
%X			: 부호없는 16진 정수(대문자 사용)
%e			: 부동 소수점으로 표현한 실수 (e- 표기법)
%E			: 부동 소수점으로 표현한 실수 (E- 표기법)
%g			: 값에 따라 %f나 %e를 사용함
%G			: 값에 따라 %f나 %E를 사용함
%%			: %출력
*/

/*
이스케이프 시퀀스
프로그램 결과가 화면에 출력될 때 사용하게 될 특수문자를 위해 만들어졌다.

종류
\n : 줄 바꿈
\t : 수평 탭
\\ : 백슬레시 출력

\' : 작은따옴표 출력
\" : 큰따옴표 출력
\? : 물음표 출력
\a : 경고음 발생
\b : 백스페이스
\r : 케리지 리턴
\v : 수직 탭
\f : 폼 피드

*/