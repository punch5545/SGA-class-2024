#include <stdio.h>		// ǥ�� �����
#include <stdlib.h>		// rand()
#include <time.h>		// srand() ��ų�� �õ尪 �ֱ� ���ؼ�

int main()
{
	// �õ尪 ����
	srand(time(NULL));

	// ��ǻ�� ī�� ����
	int computer;
	computer = rand() % 18; // 0 ~ 17
	computer += 4;			// �ּҰ� 4 ~ 21

	int card1 = rand() % 10;
	card1++;				// �ּҰ� �̻��� ������ �ϱ� ���ؼ� +1

	int card2 = rand() % 10;
	card2++;

	printf("�÷��̾��� ī���� �� : %d\n", card1 + card2);
	if (card1 + card2 > 21)
	{
		printf("21 �ʰ� ���ӿ���\n");
		return 0;
	}

	printf("\n�߰� ī�带 ��ο� �Ͻðڽ��ϱ�?\n");
	printf("0. NO\t1. YES\n");

	int draw;
	scanf_s("%d", &draw);

	switch (draw)
	{
		case 0:
		{
			if (card1 + card2 > computer)
				printf("�÷��̾��� �¸��Դϴ�.\n");
			else if (card1 + card2 < computer)
				printf("��ǻ���� �¸��Դϴ�.\n");
			else
				printf("���º�");

			printf("�÷��̾��� ī�� �� : %d\n��ǻ���� ī�� �� : %d\n", card1 + card2, computer);
			return 0;
		}
		case 1:
		{
			int card3 = rand() % 10;
			card3++;

			if (card1 + card2 + card3 > 21)
			{
				printf("21�ʰ��� ���ӿ��� �ƽ��ϴ�.\n");
				return 0;
			}

			if (card1 + card2 + card3 > computer)
				printf("�÷��̾��� �¸��Դϴ�\n");
			else if (card1 + card2 + card3 < computer)
				printf("��ǻ���� �¸��Դϴ�.\n");
			else
				printf("�����ϴ�\n");

			printf("�÷��̾��� ī�� �� : %d\n��ǻ���� ī�� �� : %d\n", card1 + card2 + card3, computer);
			return 0;
		}
		// 0�� 1�ܿ� �ٸ� ���ڰ� �Էµ��� ���
		default:
		{
			printf("�߸��� ���� �Է��ϼ̽��ϴ�.\n");
			return 0;
		}
	}
}