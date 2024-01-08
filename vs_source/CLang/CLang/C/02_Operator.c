#include <stdio.h>

int main()
{
	printf("산술 연산자\n");
	printf("%d + %d = %d\n", 10, 3, 10 + 3);
	printf("%d - %d = %d\n", 10, 3, 10 - 3);
	printf("%d * %d = %d\n", 10, 3, 10 * 3);
	printf("%d / %d = %d\n", 10, 3, 10 / 3);
	printf("%d %% %d = %d\n", 10, 3, 10 % 3);

	printf("\n\n");

	printf("증감 연산자\n");
	int a = 5;
	printf("a++ = %d\n", a++);	// 5
	printf("++a = %d\n", ++a);	// 7
	printf("a-- = %d\n", a--);	// 7
	printf("--a = %d\n", --a);	// 5

	printf("\n\n");

	printf("비교 연산자\n");
	int b = 3;
	int c = 10;
	printf("b = 3 / c = 10\n");
	printf("b == c is %d\n", b == c);
	printf("b != c is %d\n", b != c);
	printf("b >= c is %d\n", b >= c);
	printf("b >  c is %d\n", b > c);
	printf("b <= c is %d\n", b <= c);
	printf("b <  c is %d\n", b < c);

	printf("\n\n");

	printf("논리 연산자\n");
	printf("b == 3 && c == 10 is %d\n", b == 3 && c == 10);			// 1
	printf("b == 5 || c == 10 is %d\n", b == 5 || c == 10);			// 1
	printf("!(b == 3 && c == 10) is %d\n", !(b == 3 && c == 10));	// 0

	int value;
	value = b == 3 ? 5 : 10;
	//value = 조건 ? 참 : 거짓;

	//if (b == 3)
	//	value = 5;
	//else
	//	value = 10;
}

/*
* 연산자
* 1. 대입 연산자 = += -= *= /=
* 2. 산술 연산자 + - * / %
* 3. 증감 연산자 ++ --
* 4. 비교 연산자 == != > >= < <=
* 5. 논리 연산자 ! && ||
* 6. 비트 연산자 << >> & | ^ ~
* 7. 삼항 연산자 ? :
*/

/*
char 1byte
	 << 0000 0110
        0000 1100

	 >>	0000 0110
        0000 0011

		0000 0110
	 &  0000 1100
	    0000 0100

		0000 0110
	 |  0000 1100
		0000 1110

		0000 0110
	 ^  0000 1100
		0000 1010

	 ~  0000 0110
	    1111 1001
*/