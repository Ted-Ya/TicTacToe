#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define ROL 3

void initalboard(char board[ROW][ROL], int row, int rol);
void displayboard(char board[ROW][ROL],int row, int rol);
void user_play(char board[ROW][ROL],int row,int rol);
void computer_play(char board[ROW][ROL],int row,int rol);
char is_win(char board[ROW][ROL],int row,int rol);
int is_full(char board[ROW][ROL], int row, int rol);