#include <stdio.h>

int main()
{
	printf("��� ������\n");
	printf("%d + %d = %d\n", 10, 3, 10 + 3);
	printf("%d - %d = %d\n", 10, 3, 10 - 3);
	printf("%d * %d = %d\n", 10, 3, 10 * 3);
	printf("%d / %d = %d\n", 10, 3, 10 / 3);
	printf("%d %% %d = %d\n", 10, 3, 10 % 3);

	printf("\n\n");

	printf("���� ������\n");
	int a = 5;
	printf("a++ = %d\n", a++);	// 5
	printf("++a = %d\n", ++a);	// 7
	printf("a-- = %d\n", a--);	// 7
	printf("--a = %d\n", --a);	// 5

	printf("\n\n");

	printf("�� ������\n");
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

	printf("�� ������\n");
	printf("b == 3 && c == 10 is %d\n", b == 3 && c == 10);			// 1
	printf("b == 5 || c == 10 is %d\n", b == 5 || c == 10);			// 1
	printf("!(b == 3 && c == 10) is %d\n", !(b == 3 && c == 10));	// 0

	int value;
	value = b == 3 ? 5 : 10;
	//value = ���� ? �� : ����;

	//if (b == 3)
	//	value = 5;
	//else
	//	value = 10;
}

/*
* ������
* 1. ���� ������ = += -= *= /=
* 2. ��� ������ + - * / %
* 3. ���� ������ ++ --
* 4. �� ������ == != > >= < <=
* 5. �� ������ ! && ||
* 6. ��Ʈ ������ << >> & | ^ ~
* 7. ���� ������ ? :
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