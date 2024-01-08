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
*	- 컴퓨터는 모든 데이터를 이진법으로 저장하는데 문자는 어떻게 저장하는가?
*	 -> 아스키 코드 : 7비트 인코딩 / 컴퓨터에서 사용하는 표현이 많아지면서
*					 유니코드로 넘어갔다
*	- char형 변수를 printf("%d")로 출력하면 정수가 나오는걸 확인할 수 있다
*	- char형 변수에는 "한 글자"만 들어간다
*	- ' ' = 문자   %c
*	- " " = 문자열 %s	(null문자를 만날 때 까지 출력)
* 
* 유니코드
*	- 전 세계의 모든 문자를 컴퓨터에서 일관되게 표현하고 다룰 수 있도록 설계된
*     산업 표준
*	- https://unicode-table.com/kr/
*/