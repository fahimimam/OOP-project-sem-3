#pragma once
#include <stdlib.h>
#include"graphics.h"
#include<string>
#include<iostream>
#include<string>
#include<algorithm>
void gameboard();
int const screenWidth = GetSystemMetrics(SM_CXSCREEN);
int const screenHeight = GetSystemMetrics(SM_CYSCREEN);
int static colum, roww;
class dotdot
{
	int column, row, player;
	int vertic = screenHeight * 0.8 / column, horizon = screenWidth * 0.6 / row;
	int scorecount[20];
	char playerName[100][100];
	int line_check[20][20][20][20];
	int count, playerturn = 0, check = 0;
	char printer[100];
	int xpoint[25], ypoint[25];
	int xstart = 0, ystart = 0, xend = 1, yend = 0;
public:
	void endgame()
	{
		sprintf(printer, "%s", "press any key to continue");
		outtextxy(screenWidth*0.5, screenHeight*0.85, printer);
		getch();
		delay(200);
	}
	void firstline()
	{
		for (int m = -1; m < 2; m++)
		{
			line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
			settextstyle(10, HORIZ_DIR, 4);
			outtextxy(screenWidth * 0.7, screenHeight *0.07, playerName[0]);
		}
	}
	void setlinecheck()
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				for (int k = 0; k < 20; k++)
				{
					for (int l = 0; l < 20; l++)
					{
						line_check[i][j][k][l] = 0;
					}
				}
			}
		}
	}
	void setcount()
	{
		count = (row - 1)*column + (column - 1)*row;
	}
	int getcount()
	{
		return count;
	}
	void putpoints()
	{
		setvalue();
		setlinecheck();
		setcount();
		int radx = 50, rady = 50;
		for (int k = 0; k < column; k++)
		{
			ypoint[k] = rady;
			rady = rady + vertic;
		}
		for (int j = 0; j < row; j++)
		{
			xpoint[j] = radx;
			radx = radx + horizon;
		}
	}
	void playernameshow();
	void upkey();
	void downkey();
	void leftkey();
	void rightkey();
	int returnkey();
	void input();
	void setvalue();
	void showresults();
	/*int playert()
	{
		return playerturn;
	}
	int getplayer()
	{
		return player;
	}
	char * getplayername(int n)
	{
		return playerName[n];
	}*/

};