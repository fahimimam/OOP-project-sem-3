#pragma once
#include"graphics.h"
#include"cricx.h"
#include<math.h>
#include<iostream>
class cricx
{
	char team1[100], team2[100], a, team1score[100], team2score[100], store[100];
	int overs, balls = 0, wicket = 0, l = 0, score = 0, run = 0, team1run, team2run;
	char ch[12][10];
	int i, j, color = 1;
	int p = 0, q = 0;
	int tosswinner=0;
public:
	void scoreboard();
	void input();
	void toss();
	void gamecricx();
	void resultboard();
};
void gameplaycircle();
void gameselectcircle();
int score_per_ball(float mx, float my, int rotation);
