#include "game.h"

void initalboard(char board[ROW][ROL],int row, int rol)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < rol; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void displayboard(char board[ROW][ROL], int row, int rol)
{
	int i = 0;
	int j = 0;
	int n = 0;

	for (i = 0; i < row; i++)
	{
		
		for (j = 0; j < rol; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != rol - 1) 
			{
				printf("|");
			}
			else
			{
				printf("\n");

			
				for (n = 0; n < rol; n++)
				{
					if (n != rol - 1) {
						if (i != row - 1)
						{
							printf("---|");

						}
					}
					else
					{
						if (i != row - 1) 
						{
							printf("---");
						}
					
					}
				}
				printf("\n");
			}
			
		}

	}
}

void user_play(char board[ROW][ROL], int row, int rol)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("�����������ִ�������:>");
		scanf("%d%d", &i, &j);
		if (i >= 1 && i <= row &&  j>=1 && j <= rol)
		{
			if (board[i-1][j-1] == ' ')
			{
				board[i-1][j-1] = '*';
				break;
			}
			else
			{
				printf("��λ���ѱ�ѡ��");
			}
		}
		else
		{
			printf("����λ�ò��ں���Χ");
		}
	}
}
void computer_play(char board[ROW][ROL], int row, int rol)
{
	int i = 0;
	int j = 0;
	printf("���Կ�ʼ\n");
	while (1)
	{
		i = rand() % row;
		j = rand() % rol;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}

// '*' ��ʾ�û�Ӯ
// '#' ��ʾ����Ӯ
// 'Q' ��ʾƽ��
// 'C' ��ʾ����
char is_win(char board[ROW][ROL], int row, int rol)
{
	int i = 0;
	for (i = 0; i < row; i++) 
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	int j = 0;
	for (j = 0; j < rol; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}

	if (1 == is_full) 
	{
		return 'Q';
	
	}
	return 'C';
}

int is_full(char board[ROW][ROL],int row,int rol)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < rol; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}