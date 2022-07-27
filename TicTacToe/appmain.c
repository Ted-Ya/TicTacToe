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
		printf("玩家赢\n");
	}else if (ret == '#')
	{
		printf("电脑赢\n");
	}else
	{
		printf("平局\n");
	}


}

void play_tic_tac_toe()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do {
		manu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			play();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("请重新选择");
			break;
		}

	} while (input);
}

int main()
{
	play_tic_tac_toe();
	return 0;
}