#include <stdio.h>

int main()
{
	//if (3 + 5 == 10)
	//{
	//	printf("참\n");
	//	printf("참참참\n");
	//}
	//else if (3 + 5 == 8)
	//	printf("맞긴 함\n");
	//else
	//	printf("거짓\n");

	printf("소문자 입력 : ");
	char word;
	scanf_s("%c", &word);

	// a == 97 / z == 122
	if (word <= 'z' && word >= 'a')
		printf("대문자 : %c\n", word - 32);
	else if (word == ' ')
		printf("문자 감지 안됨\n");
	else if (word == '3')
		printf("숫자 입력됨\n");
	else
		printf("잘못된 문자 입력\n");

	/*
	* 성적 입력 프로그램
	* 성적 입력해주세요 :  <- 입력 받기
	* 100 ~ 91 == A+
	* 90 ~ 81 == A
	* 80 ~ 71 == B
	* 70 ~ 61 == C
	* 나머지 == F
	* 라고 출력되도록 만드는 프로그램을 작성
	*/

	printf("프로그램 종료\n");
}