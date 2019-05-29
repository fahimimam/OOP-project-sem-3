#include"dotdot.h"
void gameboard()
{
	int vertic = screenHeight * 0.8 / colum, horizon = screenWidth * 0.6 / roww;
	int radx = 50, rady = 50;
	for (int k = 0; k < colum; k++)
	{
		for (int j = 0; j < roww; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				circle(radx, rady, i);
			}
			radx = radx + horizon;
		}
		rady = rady + vertic;
		radx = 50;
	}
}
void dotdot::input()
{
	printf("\n");
	printf("\n");
	printf("\n");
	int l = 20;
	while (true)
	{
		printf("Enter the size of Rows:(x\n\t\t\tx\n\t\t\tx)[MINIMUM 10][MAXIMUM:20]:");
		scanf("%d", &row);
		if (row >= 5 && row <= 20)
			break;
	}
	roww = row;
	printf("\n");
	while (true)
	{
		printf("Enter the size of Columns(xxx)[MINIMUM 10][MAXIMUM:20]:");
		scanf("%d", &column);
		if (column >= 5 && row <= 20)
			break;
	}
	colum = column;
	printf("\n");
	while (true)
	{
		printf("Enter Number of Players[MAXIMUM 10]:");
		scanf("%d", &player);
		if (player >= 2 && player <= 10)
			break;
	}
	printf("\n");
	for (int i = 0; i < player; i++)
	{
		printf("Enter name of Player%d:", i + 1);
		scanf("%s", playerName[i]);
		scorecount[i] = 0;
		printf("\n");
	}
}

void dotdot::setvalue()
{
	vertic = screenHeight * 0.8 / column, horizon = screenWidth * 0.6 / row;
}

void dotdot::showresults()
{
	for (int d = 0; d < player; d++)
	{
		//sprintf;
		float ycor = screenHeight * 0.07*(d + 2) + 50;
		settextstyle(10, HORIZ_DIR, 6);
		outtextxy(screenWidth / 2 - 50, screenHeight*0.05, "SCORES");
		settextstyle(10, HORIZ_DIR, 4);
		sprintf(printer, "%s \t %d", playerName[d], scorecount[d]);
		outtextxy(screenWidth * 0.45, ycor, printer);
	}
}


void dotdot::playernameshow()
{
	setcolor(BLACK);
	settextstyle(10, HORIZ_DIR, 4);
	outtextxy(screenWidth * 0.7, screenHeight *0.07*playerturn, playerName[playerturn - 1]);
	playerturn = playerturn % player;
	setcolor(WHITE);
	settextstyle(10, HORIZ_DIR, 4);
	outtextxy(screenWidth * 0.7, screenHeight *0.07*(playerturn + 1), playerName[playerturn]);
}

void dotdot::upkey()
{
	if (line_check[xstart][ystart][xend][yend] == 1)
	{
		setcolor(YELLOW);
		if (ystart == yend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
			}
		}
		else if (xstart == xend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
			}
		}
	}
	else
	{
		setcolor(BLACK);
		if (ystart == yend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
			}
		}
		else if (xstart == xend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
			}
		}

	}
	if (ystart == yend)
	{
		yend--;
		ystart--;
	}
	else if (xstart == xend)
	{
		xend = xstart + 1;
		yend = ystart;

	}
	if (ystart < 0)
	{
		ystart = column - 1;
		yend = column - 1;
	}
	if (xend == row)
	{
		xstart = 0;
		xend = xstart + 1;
		yend = ystart;
	}
	if (line_check[xstart][ystart][xend][yend] == 1)
	{
		setcolor(RED);
		for (int m = -1; m < 2; m++)
		{
			line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
		}
	}
	else
	{
		setcolor(WHITE);
		for (int m = -1; m < 2; m++)
		{
			line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
		}
	}
}

void dotdot::downkey()
{
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (line_check[xstart][ystart][xend][yend] == 1)
		{
			setcolor(YELLOW);
			if (ystart == yend)
			{
				for (int m = -1; m < 2; m++)
				{
					line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
				}
			}
			else if (xstart == xend)
			{
				for (int m = -1; m < 2; m++)
				{
					line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
				}
			}
		}
		else
		{
			setcolor(BLACK);
			if (ystart == yend)
			{
				for (int m = -1; m < 2; m++)
				{
					line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
				}
			}
			else if (xstart == xend)
			{
				for (int m = -1; m < 2; m++)
				{
					line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
				}
			}

		}
		if (ystart == yend)
		{
			yend = yend + 1;
			ystart = ystart + 1;
		}
		else if (xstart == xend)
		{
			xstart = xend;
			ystart = yend;
			xend++;
		}
		if (ystart == column)
		{
			ystart = 0;
			yend = 0;
		}
		if (xend == row)
		{
			xstart = 0;
			xend = xstart + 1;
			ystart = yend;
		}
		if (line_check[xstart][ystart][xend][yend] == 1)
		{
			setcolor(RED);
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
			}
		}
		else
		{
			setcolor(WHITE);
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
			}
		}
	}
}

void dotdot::leftkey()
{
	if (line_check[xstart][ystart][xend][yend] == 1)
	{
		setcolor(YELLOW);
		if (ystart == yend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
			}
		}
		else if (xstart == xend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
			}
		}
	}
	else
	{
		setcolor(BLACK);
		if (ystart == yend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
			}
		}
		else if (xstart == xend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
			}
		}
	}
	if (ystart == yend)
	{
		xend = xstart;
		yend++;
	}
	else if (xstart == xend)
	{
		xend--;
		xstart--;
	}
	if (xstart < 0)
	{
		xstart = row - 1;
		xend = row - 1;
	}
	if (yend == column)
	{
		ystart = 0;
		yend = ystart + 1;
		xend = xstart;
	}
	if (line_check[xstart][ystart][xend][yend] == 1)
	{
		setcolor(RED);
		for (int m = -1; m < 2; m++)
		{
			line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
		}
	}
	else
	{
		setcolor(WHITE);
		for (int m = -1; m < 2; m++)
		{
			line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
		}
	}
}

void dotdot::rightkey()
{
	if (line_check[xstart][ystart][xend][yend] == 1)
	{
		setcolor(YELLOW);
		if (ystart == yend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
			}
		}
		else if (xstart == xend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
			}
		}
	}
	else
	{
		setcolor(BLACK);
		if (ystart == yend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
			}
		}
		else if (xstart == xend)
		{
			for (int m = -1; m < 2; m++)
			{
				line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
			}
		}
	}
	if (ystart == yend)
	{
		xstart = xend;
		ystart = yend;
		yend++;
	}
	else if (xstart == xend)
	{
		xend++;
		xstart++;

	}
	if (xstart == row)
	{
		xstart = 0;
		xend = 0;
	}
	if (yend == column)
	{
		ystart = 0;
		yend = ystart + 1;
		xstart = xend;
	}
	if (line_check[xstart][ystart][xend][yend] == 1)
	{
		setcolor(RED);
		for (int m = -1; m < 2; m++)
		{
			line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
		}
	}
	else
	{
		setcolor(WHITE);
		for (int m = -1; m < 2; m++)
		{
			line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
		}
	}
}

int dotdot::returnkey()
{
	int returncheck = 0;
	setcolor(LIGHTGREEN);
	if (ystart == yend)
	{
		for (int m = -1; m < 2; m++)
		{
			line(xpoint[xstart] + 2, ypoint[ystart] + m, xpoint[xend] - 3, ypoint[yend] + m);
		}
	}
	else if (xstart == xend)
	{
		for (int m = -1; m < 2; m++)
		{
			line(xpoint[xstart] + m, ypoint[ystart] + 2, xpoint[xend] + m, ypoint[yend] - 3);
		}
	}
	if (line_check[xstart][ystart][xend][yend] == 0)
	{
		int xcor, ycor;
		line_check[xstart][ystart][xend][yend] = 1;
		line_check[xend][yend][xstart][ystart] = 1;
		returncheck = 1;
		if (ystart == yend)
		{
			if (line_check[xstart][ystart - 1][xstart][ystart] == 1 && line_check[xstart][ystart - 1][xend][yend - 1] == 1 && line_check[xend][yend - 1][xend][yend] == 1)
			{
				scorecount[playerturn%player]++;
				setcolor(WHITE);
				settextstyle(10, HORIZ_DIR, 3);
				xcor = xpoint[xstart] + xpoint[xend] - 15;
				ycor = ypoint[ystart] + ypoint[ystart - 1] - 30;
				sprintf(printer, "%c", playerName[playerturn%player][0]);
				outtextxy(xcor / 2, ycor / 2, printer);
				if (!check)
					check = 1;
			}
			if (line_check[xstart][ystart][xstart][ystart + 1] == 1 && line_check[xstart][ystart + 1][xend][yend + 1] == 1 && line_check[xend][yend][xend][yend + 1] == 1)
			{
				scorecount[playerturn%player]++;
				setcolor(WHITE);
				settextstyle(10, HORIZ_DIR, 3);
				xcor = xpoint[xstart] + xpoint[xend] - 15;
				ycor = ypoint[ystart] + ypoint[ystart + 1] - 30;
				sprintf(printer, "%c", playerName[playerturn%player][0]);
				outtextxy(xcor / 2, ycor / 2, printer);
				if (!check)
					check = 1;
			}
		}
		else if (xstart == xend)
		{
			if (xstart > 0)
			{
				if (line_check[xstart - 1][ystart][xend - 1][yend] == 1 && line_check[xstart - 1][ystart][xstart][ystart] == 1 && line_check[xend - 1][yend][xend][yend] == 1)
				{
					scorecount[playerturn%player]++;
					setcolor(WHITE);
					settextstyle(10, HORIZ_DIR, 3);
					xcor = xpoint[xstart - 1] + xpoint[xstart] - 15;
					ycor = ypoint[ystart] + ypoint[yend] - 30;
					sprintf(printer, "%c", playerName[playerturn%player][0]);
					outtextxy(xcor / 2, ycor / 2, printer);
					if (!check)
						check = 1;
				}
			}
			if (xstart < row - 1)
			{
				if (line_check[xstart][ystart][xstart + 1][ystart] == 1 && line_check[xstart + 1][ystart][xend + 1][yend] == 1 && line_check[xend][yend][xend + 1][yend] == 1)
				{
					scorecount[playerturn%player]++;
					setcolor(WHITE);
					settextstyle(10, HORIZ_DIR, 3);
					xcor = xpoint[xstart] + xpoint[xstart + 1] - 15;
					ycor = ypoint[ystart] + ypoint[yend] - 30;
					sprintf(printer, "%c", playerName[playerturn%player][0]);
					outtextxy(xcor / 2, ycor / 2, printer);
					if (!check)
						check = 1;

				}
			}
		}
		playerturn++;
		printf("%d", playerturn);
		if (check)
		{
			check = 0;
			playerturn--;
			printf("%d", playerturn);
		}
	}
	return returncheck;
}

