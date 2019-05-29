#include"cricx.h"
void cricx::scoreboard()
{
	outtextxy(800, 360, "SCORE");
	outtextxy(1020, 360, "OVERS");
	bar(800, 400, 1000, 450);
	bar(1020, 400, 1180, 450);
	bar(800, 470, 1000, 520);
	bar(1020, 470, 1180, 520);
}
void cricx::input()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\tSELECT TEAM1 NAME: ");
	scanf("%s", team1);
	//gets(team1);
	printf("\t\tSELECT TEAM2 NAME: ");
	scanf("%s", team2);
	//gets(team2);
	printf("\t\tSELECT OVERS TO PLAY(Minimum 1 ; Maximum 10):");
	scanf("%d", &overs);
	while (overs < 1 || overs>10)
	{
		printf("INVALID CHOICE, SELECT AGAIN OVERS TO PLAY (Minimum 1 ; Maximum 10)");
		scanf("%d", &overs);
	}
}
void gameselectcircle()
{
	char score[100][100];
	setcolor(WHITE);

	for (int i = 0; i <= 250; i++)
	{
		circle(300, 300, i);
	}


	setcolor(BLACK);
	line(300, 300, 550, 300);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 + 80, 365 - 130, "SQUARE");
	outtextxy(350 + 100, 365 - 108, "LEG");

	setcolor(BLACK);
	line(300, 300, 300 + 216.5, 300 - 125);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 + 45, 365 - 210, "LONG");
	outtextxy(350 + 53, 365 - 188, "LEG");

	setcolor(BLACK);
	line(300, 300, 300 + 125, 300 - 216.5);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 40, 365 - 245, "FINE");
	outtextxy(350 - 33, 365 - 225, "LEG");

	setcolor(BLACK);
	line(300, 300, 300, 50);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 135, 365 - 245, "THIRD");
	outtextxy(350 - 118, 365 - 225, "MAN");


	setcolor(BLACK);
	line(300, 300, 300 - 125, 300 - 216.5);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 255, 365 - 210, "BACKWARD");
	outtextxy(350 - 220, 365 - 188, "POINT");

	setcolor(BLACK);
	line(300, 300, 300 - 216.5, 300 - 125);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 238, 365 - 125, "DEEP");
	outtextxy(350 - 245, 365 - 105, "POINT");


	setcolor(BLACK);
	line(300, 300, 50, 300);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 235, 365 - 50, "DEEP");
	outtextxy(350 - 245, 365 - 27, "COVER");


	setcolor(BLACK);
	line(300, 300, 300 - 216.5, 300 + 125);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 210, 365 + 30, "EXTRA");
	outtextxy(350 - 210, 365 + 50, "COVER");


	setcolor(BLACK);
	line(300, 300, 300 - 125, 300 + 216.5);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 120, 365 + 95, "LONG");
	outtextxy(350 - 110, 365 + 115, "OFF");


	setcolor(BLACK);
	line(300, 300, 300, 550);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 40, 365 + 95, "LONG");
	outtextxy(350 - 25, 365 + 115, "ON");


	setcolor(BLACK);
	line(300, 300, 300 + 125, 300 + 216.5);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 + 55, 365 + 30, "COW");
	outtextxy(350 + 35, 365 + 50, "CORNER");

	setcolor(BLACK);
	line(300, 300, 300 + 216.5, 300 + 125);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 + 50, 365 - 40, "MIDWICKET");

}

int score_per_ball(float mx, float my, int rotation)
{
	float cx = 300, cy = 300;
	float l1 = (my - cy), l2 = (mx - cx);
	float slope = l1 / l2;
	float angle = atan(slope);
	int position1 = 0, position = angle * 180 / (30 * 3.1416);
	//printf("%lf\n",angle*180/(3.142));
	if (position == 0 && mx > cx && my < cy)
		position1 = 1;
	else if (position == -1 && mx > cx && my < cy)
		position1 = 2;
	else if (position == -2 && mx > cx && my < cy)
		position1 = 3;
	else if (position == 1 && mx < cx && my < cy)
		position1 = 4;
	else if (position == 2 && mx < cx && my < cy)
		position1 = 5;
	else if (position == 0 && mx < cx && my < cy)
		position1 = 6;
	else if (position == 0 && mx<cx && my>cy)
		position1 = 7;
	else if (position == -1 && mx<cx && my>cy)
		position1 = 8;
	else if (position == -2 && mx<cx && my>cy)
		position1 = 9;
	else if (position == 2 && mx > cx && my > cy)
		position1 = 10;

	else if (position == 1 && mx > cx && my > cy)
		position1 = 11;

	else if (position == 0 && mx > cx && my > cy)
		position1 = 12;

	position1 = (position1 + rotation) % 12;

	if (position1 == 1)
		return -1;
	else if (position1 == 2)
		return 6;
	else if (position1 == 3)
		return -1;
	else if (position1 == 4)
		return 2;
	else if (position1 == 5)
		return 1;
	else if (position1 == 6)
		return -1;
	else if (position1 == 7)
		return -1;
	else if (position1 == 8)
		return 4;
	else if (position1 == 9)
		return 2;
	else if (position1 == 10)
		return 0;
	else if (position1 == 11)
		return 4;
	else if (position1 == 0)
		return 3;
}

void gameplaycircle()
{

	char score[100][100], cpy[100];
	strcpy(score[1], "CAUGHT");
	strcpy(score[2], "SIX");
	strcpy(score[3], "LBW");
	strcpy(score[4], "TWO");
	strcpy(score[5], "ONE");
	strcpy(score[6], "BOWLED");
	strcpy(score[7], "RUNOUT");
	strcpy(score[8], "FOUR");
	strcpy(score[9], "TWO");
	strcpy(score[10], "DOT");
	strcpy(score[11], "FOUR");
	strcpy(score[12], "THREE");
	setcolor(WHITE);

	for (int i = 0; i <= 250; i++)
	{
		circle(300, 300, i);
	}
	settextstyle(3, HORIZ_DIR, 3);
	outtextxy(550, 40, "INSTRUCTIONS:");
	outtextxy(580, 60, "FOR BOWLER");
	outtextxy(620, 80, "USE RIGHT ARROW TO ROTATE CLOCKWISE BY ONE SCORING ZONE");
	outtextxy(620, 100, "USE LEFT ARROW TO ROTATE COUNTER-CLOCKWISE BY ONE SCORING ZONE");
	outtextxy(620, 120, "USE UP/DOWN ARROW TO ROTATE BY SIX SCORING ZONE");
	outtextxy(580, 140, "FOR BATSMAN");
	outtextxy(620, 160, "USE LEFT MOUSECLICK AT THE SCORING AREA YOU WANT TO SELECT");
	outtextxy(620, 180, "THEN PRESS ANY KEY TO CONTINUE");


	setcolor(BLACK);
	line(300, 300, 550, 300);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 + 80, 365 - 110, score[1]);

	setcolor(BLACK);
	line(300, 300, 300 + 216.5, 300 - 125);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 + 45, 365 - 190, score[2]);

	setcolor(BLACK);
	line(300, 300, 300 + 125, 300 - 216.5);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 40, 365 - 225, score[3]);

	setcolor(BLACK);
	line(300, 300, 300, 50);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 110, 365 - 225, score[4]);


	setcolor(BLACK);
	line(300, 300, 300 - 125, 300 - 216.5);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 180, 365 - 180, score[5]);

	setcolor(BLACK);
	line(300, 300, 300 - 216.5, 300 - 125);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 245, 365 - 105, score[6]);

	setcolor(BLACK);
	line(300, 300, 50, 300);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 245, 365 - 45, score[7]);

	setcolor(BLACK);
	line(300, 300, 300 - 216.5, 300 + 125);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 185, 365 + 20, score[8]);

	setcolor(BLACK);
	line(300, 300, 300 - 125, 300 + 216.5);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 110, 365 + 60, score[9]);

	setcolor(BLACK);
	line(300, 300, 300, 550);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 - 30, 370 + 60, score[10]);

	setcolor(BLACK);
	line(300, 300, 300 + 125, 300 + 216.5);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 + 30, 365 + 20, score[11]);

	setcolor(BLACK);
	line(300, 300, 300 + 216.5, 300 + 125);
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(350 + 80, 365 - 40, score[12]);

}

void cricx:: toss()
{
	char a;
	int i, j;
	int team11 = 0;
	int team12 = 0;
	char cpy[100];
	settextstyle(8, HORIZ_DIR, 6);
	outtextxy(650, 40, "TOSS");
	settextstyle(8, HORIZ_DIR, 4);
	outtextxy(100, 140, "PRESS SHIFT TO LOCK YOUR SCORE");
	outtextxy(100, 180, "[TEAM WITH GREATER SCORE WILL WIN THE TOSS AND BAT FIRST]");
	delay(800);
	settextstyle(3, HORIZ_DIR, 5);
	while (team11 == team12)
	{
		for (i = 0; i < 10; i++)
		{
			outtextxy(400, 380, team1);
			sprintf(cpy, " %d ", i);
			outtextxy(400, 420, cpy);
			delay(50);
			if (i == 9)
				i = 0;
			if (GetAsyncKeyState(VK_SHIFT))
				break;
		}
		delay(200);
		team11 = i;
		for (i = 0; i < 10; i++)
		{
			outtextxy(800, 380, team2);
			sprintf(cpy, " %d ", i);
			outtextxy(800, 420, cpy);
			delay(50);
			if (i == 9)
				i = 0;
			if (GetAsyncKeyState(VK_SHIFT))
				break;
		}
		team12 = i;
	}
	if (team11 > team12)
	{
		sprintf(cpy, "%s WINS THE TOSS", team1);
		outtextxy(500, 600, cpy);
		tosswinner = 1;
	}
	else
	{
		sprintf(cpy, "%s WINS THE TOSS", team2);
		outtextxy(500, 600, cpy);
		tosswinner = 2;
	}
	delay(1800);
	cleardevice();
	outtextxy(600, 420, "LETS GO");
	delay(1200);
	cleardevice();
}

void cricx::gamecricx()
{
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

}

void cricx::resultboard()
{
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
}
