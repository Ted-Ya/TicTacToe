#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void manu()
{
	printf("**********************\n");
	printf("***** 1.play 0.exit ***\n");
	printf("**********************\n");
}

void play() 
{
	char ret = 0;
	char board[ROW][ROL] = {0};
	initalboard(board,ROW,ROL);
	displayboard(board,ROW,ROL);

	while (1)
	{
		user_play(board, ROW, ROL);
		displayboard(board, ROW, ROL);
		ret = is_win(board, ROW, ROL);
		if (ret != 'C')
		{
			break;
		}

		computer_play(board, ROW, ROL);
		displayboard(board, ROW, ROL);
		ret = is_win(board, ROW, ROL);
		if (ret != 'C')
		{
			break;
		}

	}

	if (ret == '*')
	{
		printf("���Ӯ\n");
	}else if (ret == '#')
	{
		printf("����Ӯ\n");
	}else
	{
		printf("ƽ��\n");
	}


}

void play_tic_tac_toe()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do {
		manu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			play();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("������ѡ��");
			break;
		}

	} while (input);
}

int main()
{
	play_tic_tac_toe();
	return 0;
}