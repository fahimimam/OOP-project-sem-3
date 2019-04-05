#include <stdio.h>
#include <stdlib.h>
#include"graphics.h"
#include<string>
#include<iostream>
#include"cricx.h"
int main()
{
	char team1[100], team2[100], a, team1score[100], team2score[100], store[100];
	int overs, balls = 0, wicket = 0, l = 0, score = 0, run = 0, team1run, team2run;
	printf("SELECT TEAM1 NAME: ");
	scanf("%s", team1);
	//gets(team1);
	printf("SELECT TEAM2 NAME: ");
	scanf("%s", team1);
	//gets(team2);
	printf("SELECT OVERS TO PLAY(Minimum 1 ; Maximum 10):");
	scanf("%d", &overs);
	while (overs < 1 || overs>10)
	{
		printf("INVALID CHOICE, SELECT AGAIN OVERS TO PLAY (Minimum 1 ; Maximum 10)");
		scanf("%d", &overs);
	}

	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth, screenHeight, "", 2, 2);
	char ch[12][10];
	int i, j, color = 1;

	int p = 0, q = 0;
	int tosswinner = toss(team1, team2);

	outtextxy(800, 360, "SCORE");
	outtextxy(1020, 360, "OVERS");
	bar(800, 400, 1000, 450);
	bar(1020, 400, 1180, 450);
	bar(800, 470, 1000, 520);
	bar(1020, 470, 1180, 520);
	for (i = 0; i < 1; i++)
	{
		if (tosswinner % 2)
		{
			outtextxy(600, 400, team1);
			outtextxy(600, 470, team2);

		}
		else
		{
			outtextxy(600, 400, team2);
			outtextxy(600, 470, team1);
		}
		while (balls != overs * 6)
		{
			l = 0;
			gameplaycircle();
			delay(500);
			gameselectcircle();
			while (!GetAsyncKeyState(VK_LBUTTON));
			{
				if (GetAsyncKeyState(VK_LEFT))
				{
					l--;
				}
				else if (GetAsyncKeyState(VK_RIGHT))
				{
					l++;
				}
				else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
				{
					l = l + 6;
				}
				getmouseclick(WM_LBUTTONDOWN, p, q);
			}
			score = score_per_ball(p, q, l);
			if (score == -1)
				wicket++;
			else
				run = run + score;
			balls++;
			sprintf(team1score, "%d-%d", run, wicket);
			outtextxy(880, 418, team1score);
			sprintf(team1score, "%d.%d", balls / 6, balls % 6);
			outtextxy(1080, 418, team1score);
			l = 0;
			if (wicket == 10)
				break;
		}
		team1run = run;
		balls = 0;
		run = 0;
		wicket = 0;
		while (balls != overs * 6)
		{

			gameplaycircle();
			delay(2000);
			gameselectcircle();
			while (!GetAsyncKeyState(VK_LBUTTON));
			{
				if (GetAsyncKeyState(VK_LEFT))
				{
					l--;
				}
				else if (GetAsyncKeyState(VK_RIGHT))
				{
					l++;
				}
				else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
				{
					l = l + 6;
				}
				getmouseclick(WM_LBUTTONUP, p, q);
			}
			score = score_per_ball(p, q, l);
			if (score == -1)
				wicket++;
			else
				run = run + score;
			balls++;
			sprintf(team1score, "%d-%d", run, wicket);
			outtextxy(880, 498, team1score);
			sprintf(team1score, "%d.%d", balls / 6, balls % 6);
			outtextxy(1080, 498, team1score);
			l = 0;
			if (wicket == 10)
				break;
			if (team1run < run)
				break;
		}
	}
	team2run = run;


	cleardevice();
	if (team1run > team2run)
	{
		if (tosswinner % 2)
			sprintf(store, "%s WINS", team1);
		else
			sprintf(store, "%s WINS", team2);
	}
	else if (team1run < team2run)
	{
		if (tosswinner % 2)
			sprintf(store, "%s WINS", team2);
		else
			sprintf(store, "%s WINS", team1);
	}
	else
		sprintf(store, "MATCH DRAWN");
	settextstyle(8, HORIZ_DIR, 8);
	outtextxy(550, 420, store);
	delay(3000);
	getch();
	closegraph();
	return 0;
}
