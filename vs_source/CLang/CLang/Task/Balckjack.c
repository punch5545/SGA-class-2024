#include <stdio.h>		// 표준 입출력
#include <stdlib.h>		// rand()
#include <time.h>		// srand() 시킬때 시드값 넣기 위해서

int main()
{
	// 시드값 변경
	srand(time(NULL));

	// 컴퓨터 카드 설정
	int computer;
	computer = rand() % 18; // 0 ~ 17
	computer += 4;			// 최소값 4 ~ 21

	int card1 = rand() % 10;
	card1++;				// 최소값 이상이 나오게 하기 위해서 +1

	int card2 = rand() % 10;
	card2++;

	printf("플레이어의 카드의 합 : %d\n", card1 + card2);
	if (card1 + card2 > 21)
	{
		printf("21 초과 게임오버\n");
		return 0;
	}

	printf("\n추가 카드를 드로우 하시겠습니까?\n");
	printf("0. NO\t1. YES\n");

	int draw;
	scanf_s("%d", &draw);

	switch (draw)
	{
		case 0:
		{
			if (card1 + card2 > computer)
				printf("플레이어의 승리입니다.\n");
			else if (card1 + card2 < computer)
				printf("컴퓨터의 승리입니다.\n");
			else
				printf("무승부");

			printf("플레이어의 카드 합 : %d\n컴퓨터의 카드 합 : %d\n", card1 + card2, computer);
			return 0;
		}
		case 1:
		{
			int card3 = rand() % 10;
			card3++;

			if (card1 + card2 + card3 > 21)
			{
				printf("21초과로 게임오버 됐습니다.\n");
				return 0;
			}

			if (card1 + card2 + card3 > computer)
				printf("플레이어의 승리입니다\n");
			else if (card1 + card2 + card3 < computer)
				printf("컴퓨터의 승리입니다.\n");
			else
				printf("비겼습니다\n");

			printf("플레이어의 카드 합 : %d\n컴퓨터의 카드 합 : %d\n", card1 + card2 + card3, computer);
			return 0;
		}
		// 0과 1외에 다른 숫자가 입력됐을 경우
		default:
		{
			printf("잘못된 값을 입력하셨습니다.\n");
			return 0;
		}
	}
}