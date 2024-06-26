#include <Windows.h>
#include"help.h";
#include<math.h>
#include<conio.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<thread>
int a = 0;
int c = 0;
bool flap = 0;
int score = 0;
int q1 = 165, w1 = 70, q2 = 225, w2 = 130, R = 255, G = 255, B = 255, whichKey = 0;
int si = 0, sj = 0;
using namespace std;
void printshapes(int b[][8]);
void printshapess(int b[][8]);
void samevaluecuts(int b[][8], int k, int l);

void previousrows(int b[][8], int i, int j)
{
	for (int k = i; k >= 0; k--)
	{
		b[k][j] = b[k - 1][j];
		if (k == 0)
		{
			b[k][j] = rand() % 5;
		}
	}
}
void helpssleep(int b[][8], int r, int c, bool flag)
{
	myRects(160, 70, 680, 550, 0, 0, 0);    // so that the screen dont blink and also all the system screen cls can hurt the timer.
	int x1, y1, x2, y2, R, G, B;

	x1 = 180, x2 = 205, y1 = 80, y2 = 105, R = 255, G = 0, B = 0;
	for (int i = 0; i < 8; i++)
	{
		x1 = 180;
		x2 = 205;

		for (int j = 0; j < 8; j++)
		{
			if (i == r && j == c)
			{
				myRect(x1 + 5, y1, x2 + 3, y2, 0, 0, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (i == r && j == c + 1)
			{
				myRect(x1 + 5, y1, x2 + 3, y2, 0, 0, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (i == r && j == c + 2)
			{
				myRect(x1 + 5, y1, x2 + 3, y2, 0, 0, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (i == r && j == c + 3 && flag == 0)
			{
				myRect(x1 + 5, y1, x2 + 3, y2, 0, 0, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 0)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 128, 128);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 128, 128);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 128, 128);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 1)
			{
				myLine(x1, y1 + 10, x1 + 5, y1, 0, 80, 200);
				myLine(x2 - 10, y1 + 33, x2 + 5, y1 + 8, 0, 80, 200);
				myLine(x1, y1 + 8, x1 + 15, y1 + 33, 0, 80, 200);
				myLine(x2, y1, x2 + 5, y1 + 10, 0, 80, 200);
				myLine(x1 + 5, y1 + 1, x1 + 25, y1 + 1, 0, 80, 200);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 2)
			{
				myLine(x1 - 7, y1 + 16, x1 + 11, y2 - 20 - 7, 155, 28, 49);
				myLine(x1 + 12, y2 - 25, x2 + 5, y1 + 13, 155, 28, 49);
				myLine(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49);
				myLine(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49);
				myLine(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 3)
			{
				myLine(x1 + 3, y1 - 2, x1 + 24, y1 - 2, 255, 0, 255);
				myLine(x1 + 25, y1 - 2, x1 + 32, y1 + 12, 255, 0, 255);
				myLine(x1 + 31, y1 + 14, x1 + 25, y1 + 28, 255, 0, 255);
				myLine(x1 - 3, y1 + 14, x1 + 3, y1 + 28, 255, 0, 255);
				myLine(x1 + 3, y2 + 4, x1 + 24, y2 + 4, 255, 0, 255);
				myLine(x1 - 4, y1 + 12, x1 + 4, y1 - 3, 255, 0, 255);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 4)
			{
				myEllipse(x1 - 2, y1 - 5, x2 + 6, y2 + 5, 0, 255, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 10)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 128, 128);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 128, 128);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 128, 128);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 128, 128);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 128, 128);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 128, 128);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 11)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 80, 200);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 80, 200);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 80, 200);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 80, 200);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 80, 200);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 80, 200);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 12)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 155, 28, 49);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 155, 28, 49);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 155, 28, 49);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 155, 28, 49);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 155, 28, 49);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 155, 28, 49);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 13)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 255, 0, 255);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 255, 0, 255);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 255, 0, 255);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 255, 0, 255);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 255, 0, 255);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 255, 0, 255);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 14)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 255, 0);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 255, 0);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 255, 0);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 255, 0);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 255, 0);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 255, 0);
				x1 += 60;
				x2 += 60;
			}

		}
		y1 += 60;
		y2 += 60;
	}
	Sleep(1000);
}
void helpssleepcol(int b[][8], int q, int r, bool flag)
{
	myRects(160, 70, 680, 550, 0, 0, 0);                     // so that the screen dont blink and also all the system screen cls can hurt the timer.
	int x1, y1, x2, y2, R, G, B;
	x1 = 180, x2 = 205, y1 = 80, y2 = 105, R = 255, G = 0, B = 0;
	for (int i = 0; i < 8; i++)
	{
		x1 = 180;
		x2 = 205;

		for (int j = 0; j < 8; j++)
		{
			if (i == r && j == q)
			{
				myRect(x1 + 5, y1, x2 + 3, y2, 0, 0, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (i == r + 1 && j == q)
			{
				myRect(x1 + 5, y1, x2 + 3, y2, 0, 0, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (i == r + 2 && j == q)
			{
				myRect(x1 + 5, y1, x2 + 3, y2, 0, 0, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (i == r + 3 && j == q && flag == 0)
			{
				myRect(x1 + 5, y1, x2 + 3, y2, 0, 0, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 0)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 128, 128);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 128, 128);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 128, 128);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 1)
			{
				myLine(x1, y1 + 10, x1 + 5, y1, 0, 80, 200);
				myLine(x2 - 10, y1 + 33, x2 + 5, y1 + 8, 0, 80, 200);
				myLine(x1, y1 + 8, x1 + 15, y1 + 33, 0, 80, 200);
				myLine(x2, y1, x2 + 5, y1 + 10, 0, 80, 200);
				myLine(x1 + 5, y1 + 1, x1 + 25, y1 + 1, 0, 80, 200);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 2)
			{
				myLine(x1 - 7, y1 + 16, x1 + 11, y2 - 20 - 7, 155, 28, 49);
				myLine(x1 + 12, y2 - 25, x2 + 5, y1 + 13, 155, 28, 49);
				myLine(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49);
				myLine(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49);
				myLine(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 3)
			{
				myLine(x1 + 3, y1 - 2, x1 + 24, y1 - 2, 255, 0, 255);
				myLine(x1 + 25, y1 - 2, x1 + 32, y1 + 12, 255, 0, 255);
				myLine(x1 + 31, y1 + 14, x1 + 25, y1 + 28, 255, 0, 255);
				myLine(x1 - 3, y1 + 14, x1 + 3, y1 + 28, 255, 0, 255);
				myLine(x1 + 3, y2 + 4, x1 + 24, y2 + 4, 255, 0, 255);
				myLine(x1 - 4, y1 + 12, x1 + 4, y1 - 3, 255, 0, 255);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 4)
			{
				myEllipse(x1 - 2, y1 - 5, x2 + 6, y2 + 5, 0, 255, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 10)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 128, 128);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 128, 128);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 128, 128);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 128, 128);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 128, 128);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 128, 128);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 11)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 80, 200);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 80, 200);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 80, 200);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 80, 200);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 80, 200);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 80, 200);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 12)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 155, 28, 49);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 155, 28, 49);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 155, 28, 49);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 155, 28, 49);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 155, 28, 49);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 155, 28, 49);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 13)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 255, 0, 255);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 255, 0, 255);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 255, 0, 255);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 255, 0, 255);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 255, 0, 255);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 255, 0, 255);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 14)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 255, 0);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 255, 0);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 255, 0);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 255, 0);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 255, 0);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 255, 0);
				x1 += 60;
				x2 += 60;
			}

		}
		y1 += 60;
		y2 += 60;
	}
	Sleep(1000);
}
void helpsleepelbow(int b[][8], int u, int v)
{
	myRects(160, 70, 680, 550, 0, 0, 0);
	int x1, y1, x2, y2, R, G, B;
	x1 = 180, x2 = 205, y1 = 80, y2 = 105, R = 255, G = 0, B = 0;
	for (int i = 0; i < 8; i++)
	{
		x1 = 180;
		x2 = 205;
		for (int j = 0; j < 8; j++)
		{
			if (i == u || j == v)
			{
				myEllipse(x1 + 5, y1, x2 + 3, y2, 0, 0, 0);
				x1 += 35;
				x2 += 35;
			}

			else if (b[i][j] == 0)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 128, 128);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 128, 128);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 128, 128);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 1)
			{
				myLine(x1, y1 + 10, x1 + 5, y1, 0, 80, 200);
				myLine(x2 - 10, y1 + 33, x2 + 5, y1 + 8, 0, 80, 200);
				myLine(x1, y1 + 8, x1 + 15, y1 + 33, 0, 80, 200);
				myLine(x2, y1, x2 + 5, y1 + 10, 0, 80, 200);
				myLine(x1 + 5, y1 + 1, x1 + 25, y1 + 1, 0, 80, 200);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 2)
			{
				myLine(x1 - 7, y1 + 16, x1 + 11, y2 - 20 - 7, 155, 28, 49);
				myLine(x1 + 12, y2 - 25, x2 + 5, y1 + 13, 155, 28, 49);
				myLine(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49);
				myLine(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49);
				myLine(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 3)
			{
				myLine(x1 + 3, y1 - 2, x1 + 24, y1 - 2, 255, 0, 255);
				myLine(x1 + 25, y1 - 2, x1 + 32, y1 + 12, 255, 0, 255);
				myLine(x1 + 31, y1 + 14, x1 + 25, y1 + 28, 255, 0, 255);
				myLine(x1 - 3, y1 + 14, x1 + 3, y1 + 28, 255, 0, 255);
				myLine(x1 + 3, y2 + 4, x1 + 24, y2 + 4, 255, 0, 255);
				myLine(x1 - 4, y1 + 12, x1 + 4, y1 - 3, 255, 0, 255);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 4)
			{
				myEllipse(x1 - 2, y1 - 5, x2 + 6, y2 + 5, 0, 255, 0);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 10)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 128, 128);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 128, 128);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 128, 128);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 128, 128);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 128, 128);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 128, 128);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 11)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 80, 200);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 80, 200);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 80, 200);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 80, 200);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 80, 200);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 80, 200);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 12)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 155, 28, 49);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 155, 28, 49);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 155, 28, 49);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 155, 28, 49);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 155, 28, 49);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 155, 28, 49);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 13)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 255, 0, 255);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 255, 0, 255);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 255, 0, 255);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 255, 0, 255);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 255, 0, 255);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 255, 0, 255);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 14)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 255, 0);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 255, 0);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 255, 0);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 255, 0);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 255, 0);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 255, 0);
				x1 += 60;
				x2 += 60;
			}

		}
		y1 += 60;
		y2 += 60;
	}
	Sleep(2000);
}
void copypreviouscolvalues(int b[][8], int k, int l, bool flag)        //it gives the previous values of particular coloumn having same shapes 
{                                                                      // there previous coloumn elements       
	int i = 0;
	for (i = l; i >= 0; i--)
	{
		if (flag == 0)
		{
			i -= 4;                                                //starting from previous set of coloums
		}
		else if (flag == 1)
		{
			i -= 3;
		}
		if (i == 0 && flag == 0)
		{
			b[i][k] = rand() % 5;
			b[i + 1][k] = rand() % 5;
			b[i + 2][k] = rand() % 5;
			b[i + 3][k] = rand() % 5;
		}
		else if (i == 0 && flag == 1)
		{
			b[i][k] = rand() % 5;
			b[i + 1][k] = rand() % 5;
			b[i + 2][k] = rand() % 5;
		}
		if (i == 1)
		{
			if (flag == 0)
			{
				b[i][k] = rand() % 5;
				b[i + 1][k] = rand() % 5;
				b[i + 2][k] = rand() % 5;
				b[i + 3][k] = b[i + 3 - 4][k];

			}
			else if (flag == 1)
			{
				b[i][k] = rand() % 5;
				b[i + 1][k] = rand() % 5;
				b[i + 2][k] = b[i + 2 - 3][k];
			}
		}
		if (i == 2)
		{
			if (flag == 0)
			{
				b[i][k] = rand() % 5;
				b[i + 1][k] = rand() % 5;
				b[i + 2][k] = b[i + 2 - 4][k];
				b[i + 3][k] = b[i + 3 - 4][k];

			}
			else if (flag == 1)
			{
				b[i][k] = rand() % 5;
				b[i + 1][k] = b[i + 1 - 3][k];
				b[i + 2][k] = b[i + 2 - 3][k];

			}
		}

	}
	if (l == 1)
	{
		b[0][k] = rand() % 5;
	}
	else if (l == 4)
	{
		b[0][k] = rand() % 5;
	}
	else if (l == 2)
	{
		b[0][k] = rand() % 5;
		b[1][k] = rand() % 5;
	}
	else if (l == 5)
	{
		b[0][k] = rand() % 5;
		b[1][k] = rand() % 5;
	}
	else if (l == 3 && flag == 0)
	{
		b[0][k] = rand() % 5;
		b[1][k] = rand() % 5;
		b[2][k] = rand() % 5;
	}
}
void copypreviousrowsvalues(int b[][8], int k, int l, bool flag)      //it gives the previous values of particular row having same shapes 
{                                                                     //there previous values.
	int i = k - 1;                                          // starting from the previous row.
	if (i > 0)
	{
		for (i = k - 1; i > 0; i--)
		{
			if (flag == 1)
			{
				b[i][l] = b[i - 1][l];
				b[i][l + 1] = b[i - 1][l + 1];
				b[i][l + 2] = b[i - 1][l + 2];
			}
			else if (flag == 0)
			{
				b[i][l] = b[i - 1][l];
				b[i][l + 1] = b[i - 1][l + 1];
				b[i][l + 2] = b[i - 1][l + 2];
				b[i][l + 3] = b[i - 1][l + 3];
			}
		}
	}
	if (i == 0)
	{
		if (flag == 0)
		{
			b[i][l] = rand() % 5;
			b[i][l + 1] = rand() % 5;
			b[i][l + 2] = rand() % 5;
			b[i][l + 3] = rand() % 5;
		}
		else if (flag == 1)
		{
			b[i][l] = rand() % 5;
			b[i][l + 1] = rand() % 5;
			b[i][l + 2] = rand() % 5;
		}
	}
}
void callpreviousvalues(int b[][8], int q, int v)     //it gives 
{
	int i = q - 2;
	v = v - 1;
	if (q == 7)
	{
		for (i = q - 2; i >= 0; i--)
		{
			for (int j = v; j < v + 3; j++)
			{
				if (i >= 2)
				{
					b[i][j] = b[i - 2][j];
				}
				else
				{
					b[i][j] = rand() % 5;
				}
			}
		}

	}
	else
	{
		for (int i = q - 2; i >= 0; i--)
		{
			for (int j = v; j < v + 3; j++)
			{

				if (i <= 2)
				{
					b[i][j] = rand() % 5;
				}
				else if (i == 3)
				{
					if (i == 3)
					{
						b[i][j] = b[i - 3][j];
					}
				}
				else if (i == 4)
				{
					if (i == 4)
					{
						b[i][j] = b[i - 3][j];
					}
				}
			}
		}
	}


}
void samevaluecuts(int b[][8], int k, int l)  // cuts all the same values of row and coloumn abd also the special gem
{
	srand(time(0));
	for (int k = 0; k < 8; k++)
	{
		for (int l = 0; l < 6; l++)
		{
			bool flag = 1;
			if (k == 0)
			{
				if (l >= 0 && l <= 4)
				{
					if (b[k][l] == b[k][l + 1] && b[k][l + 1] == b[k][l + 2] && b[k][l + 2] == b[k][l + 3])
					{
						b[k][l] = rand() % 5;
						b[k][l + 1] = rand() % 5;
						b[k][l + 2] = rand() % 5;
						b[k][l + 3] = rand() % 5;
						flag = 0;
						helpssleep(b, k, l, flag);
						copypreviousrowsvalues(b, k, l, flag);
						score += 200;
					}
					else if (b[k][l] == b[k][l + 1] && b[k][l + 1] == b[k][l + 2])
					{
						b[k][l] = rand() % 5;
						b[k][l + 1] = rand() % 5;
						b[k][l + 2] = rand() % 5;
						flag = 1;
						helpssleep(b, k, l, flag);
						copypreviousrowsvalues(b, k, l, flag);
						score += 200;
					}
				}
				else if (l == 5)
				{
					if (b[k][l] == b[k][l + 1] && b[k][l + 1] == b[k][l + 2])
					{
						b[k][l] = rand() % 5;
						b[k][l + 1] = rand() % 5;
						b[k][l + 2] = rand() % 5;
						flag = 1;
						helpssleep(b, k, l, flag);
						copypreviousrowsvalues(b, k, l, flag);
						score += 200;
					}
				}
			}
			if (k > 0)
			{
				if (l >= 0 && l <= 4)
				{
					if (b[k][l] == b[k][l + 1] && b[k][l + 1] == b[k][l + 2] && b[k][l + 2] == b[k][l + 3])
					{
						b[k][l] = b[k - 1][l];
						b[k][l + 1] = b[k - 1][l + 1];
						b[k][l + 2] = b[k - 1][l + 2];
						b[k][l + 3] = b[k - 1][l + 3];
						flag = 0;
						helpssleep(b, k, l, flag);
						copypreviousrowsvalues(b, k, l, flag);
						score += 200;
					}
					else if (b[k][l] == b[k][l + 1] && b[k][l + 1] == b[k][l + 2])
					{
						b[k][l] = b[k - 1][l];
						b[k][l + 1] = b[k - 1][l + 1];
						b[k][l + 2] = b[k - 1][l + 2];
						flag = 1;
						helpssleep(b, k, l, flag);
						copypreviousrowsvalues(b, k, l, flag);
						score += 200;
					}
				}
				else if (l == 5)
				{
					if (b[k][l] == b[k][l + 1] && b[k][l + 1] == b[k][l + 2])
					{
						b[k][l] = b[k - 1][l];
						b[k][l + 1] = b[k - 1][l + 1];
						b[k][l + 2] = b[k - 1][l + 2];
						flag = 1;
						helpssleep(b, k, l, flag);
						copypreviousrowsvalues(b, k, l, flag);
						score += 200;
					}
				}
			}
			if (k == 0)
			{
				if (b[k][l] - 10 == b[k][l + 1] && b[k][l + 1] == b[k][l + 2])
				{
				//	b[k + 1][l] = rand() % 5;
					b[k][l - 1] = rand() % 5;
					b[k][l ] = rand() % 5;
					b[k ][l + 1] = rand() % 5;
					b[k ][l + 2] = rand() % 5;
					b[k+1][l-1] = rand() % 5;
					b[k+1][l ] = rand() % 5;
					b[k+1][l + 1] = rand() % 5;
					score += 1500;
				}
				else if (b[k][l] == b[k][l + 1] - 10 && b[k][l + 1] - 10 == b[k][l + 2])
				{
					b[k ][l-1] = rand() % 5;
					b[k ][l ] = rand() % 5;
					b[k ][l + 1] = rand() % 5;
					b[k+1][l-1] = rand() % 5;
					b[k+1][l] = rand() % 5;
					b[k+1][l + 1] = rand() % 5;
					score += 1500;
				}
				else if (b[k][l] == b[k][l + 1] && b[k][l + 1] == b[k][l + 2] - 10)
				{
					b[k + 1][l] = rand() % 5;
					b[k + 1][l + 1] = rand() % 5;
					b[k + 1][l - 1] = rand() % 5;
					b[k + 1][l - 2] = rand() % 5;
					b[k][l] = rand() % 5;
					b[k][l - 1] = rand() % 5;
					b[k][l + 1] = rand() % 5;
					score += 1500;
				}
			}
			else if (k >= 1)
			{
				if (b[k][l] - 10 == b[k][l + 1] && b[k][l + 1] == b[k][l + 2])      // special gem cases
				{
					if (k == 1)
					{
						b[k - 1][l] = rand() % 5;
						b[k - 1][l + 1] = rand() % 5;
						b[k - 1][l - 1] = rand() % 5;
						b[k][l] = rand() % 5;
						b[k][l + 1] = rand() % 5;
						b[k][l - 1] = rand() % 5;
						b[k + 1][l] = rand() % 5;
						b[k + 1][l - 1] = rand() % 5;
						b[k + 1][l + 1] = rand() % 5;
						previousrows(b, k, l + 2);
					}
					else	if (k == 2)
					{
						b[k + 1][l] = b[k + 1 - 3][l];
						b[k + 1][l - 1] = b[k + 1 - 3][l -1];
						b[k + 1][l + 1] = b[k + 1 - 3][l +1];
						b[k][l] = rand() % 5;
						b[k][l + 1] = rand() % 5;
						b[k][l - 1] = rand() % 5;
						b[k - 1][l] = rand() % 5;
						b[k - 1][l + 1] = rand() % 5;
						b[k - 1][l - 1] = rand() % 5;
						previousrows(b, k, l + 2);
						callpreviousvalues(b, k, l);

					}
					else	if (k == 3)
					{
						b[k + 1][l] = b[k + 1 - 3][l];
						b[k + 1][l + 1] = b[k + 1 - 3][l + 1];
						b[k + 1][l - 1] = b[k + 1 - 3][l - 1];
						b[k][l] = b[k - 3][l];
						b[k][l + 1] = b[k - 3][l + 1];
						b[k][l - 1] = b[k - 3][l - 1];
						b[k - 1][l] = rand() % 5;
						b[k - 1][l + 1] = rand() % 5;
						b[k - 1][l - 1] = rand() % 5;
						previousrows(b, k, l + 2);
						callpreviousvalues(b, k, l);
					}
					else if (k == 7)
					{
						b[k][l] = b[k - 2][l];
						b[k][l + 1] = b[k - 2][l + 1];
						b[k][l - 1] = b[k - 2][l - 1];
						b[k - 1][l] = b[k - 3][l];
						b[k - 1][l + 1] = b[k - 3][l + 1];
						b[k - 1][l - 1] = b[k - 3][l - 1];
						previousrows(b, k, l + 2);
						callpreviousvalues(b, k, l);
					}
					else
					{
						b[k + 1][l] = b[k + 1 - 3][l];
						b[k + 1][l + 1] = b[k + 1 - 3][l + 1];
						b[k + 1][l - 1] = b[k + 1 - 3][l - 1];
						b[k][l] = b[k - 3][l];
						b[k][l + 1] = b[k - 3][l + 1];
						b[k][l - 1] = b[k - 3][l - 1];
						b[k - 1][l] = b[k - 4][l];
						b[k - 1][l + 1] = b[k - 4][l + 1];
						b[k - 1][l - 1] = b[k - 4][l - 1];
						previousrows(b, k, l + 2);
						callpreviousvalues(b, k, l);
					}
					score += 1500;
				}

				else if (b[k][l] == b[k][l + 1] - 10 && b[k][l + 1] - 10 == b[k][l + 2])      // special gem cases
				{
					if (k == 1)
					{
						b[k + 1][l] = rand() % 5;
						b[k + 1][l + 1] = rand() % 5;
						b[k + 1][l - 1] = rand() % 5;
						b[k][l] = rand() % 5;
						b[k][l + 1] = rand() % 5;
						b[k][l - 1] = rand() % 5;
						b[k - 1][l] = rand() % 5;
						b[k - 1][l + 1] = rand() % 5;
						b[k - 1][l - 1] = rand() % 5;
					}
					else	if (k == 2)
					{
						b[k + 1][l] = b[k + 1 - 3][l];
						b[k + 1][l + 1] = b[k + 1 - 3][l + 1];
						b[k + 1][l - 1] = b[k + 1 - 3][l - 1];
						b[k][l] = rand() % 5;
						b[k][l + 1] = rand() % 5;
						b[k][l - 1] = rand() % 5;
						b[k - 1][l] = rand() % 5;
						b[k - 1][l + 1] = rand() % 5;
						b[k - 1][l - 1] = rand() % 5;
						callpreviousvalues(b, k, l + 1);
					}
					else	if (k == 3)
					{
						b[k + 1][l] = b[k + 1 - 3][l];
						b[k + 1][l + 1] = b[k + 1 - 3][l + 1];
						b[k + 1][l - 1] = b[k + 1 - 3][l - 1];
						b[k][l] = b[k - 3][l];
						b[k][l + 1] = b[k - 3][l + 1];
						b[k][l - 1] = b[k - 3][l - 1];
						b[k - 1][l] = rand() % 5;
						b[k - 1][l + 1] = rand() % 5;
						b[k - 1][l - 1] = rand() % 5;
						callpreviousvalues(b, k, l + 1);
					}
					else if (k == 7)
					{
						b[k][l] = b[k - 2][l];
						b[k][l + 1] = b[k - 2][l + 1];
						b[k][l - 1] = b[k - 2][l - 1];
						b[k - 1][l] = b[k - 3][l];
						b[k - 1][l + 1] = b[k - 3][l + 1];
						b[k - 1][l + 2] = b[k - 3][l - 1];
						callpreviousvalues(b, k, l + 1);
					}
					else
					{
						b[k + 1][l] = b[k + 1 - 3][l];
						b[k + 1][l + 1] = b[k + 1 - 3][l + 1];
						b[k + 1][l - 1] = b[k + 1 - 3][l - 1];
						b[k][l] = b[k - 3][l];
						b[k][l + 1] = b[k - 3][l + 1];
						b[k][l - 1] = b[k - 3][l - 1];
						b[k - 1][l] = b[k - 4][l];
						b[k - 1][l + 1] = b[k - 4][l + 1];
						b[k - 1][l - 1] = b[k - 4][l - 1];
						callpreviousvalues(b, k, l + 1);
					}
					score += 1500;
				}
				else if (b[k][l] == b[k][l + 1] && b[k][l + 1] == b[k][l + 2] - 10)      // special gem cases
				{
					if (k == 1)
					{
						b[k + 1][l + 1] = rand() % 5;
						b[k + 1][l + 2] = rand() % 5;
						b[k + 1][l + 3] = rand() % 5;
						b[k][l+1] = rand() % 5;
						b[k][l + 2] = rand() % 5;
						b[k][l + 3] = rand() % 5;
						b[k - 1][l+1] = rand() % 5;
						b[k - 1][l + 2] = rand() % 5;
						b[k - 1][l + 3] = rand() % 5;
						previousrows(b, k, l);
					}

					else	if (k == 2)
					{
						b[k + 1][l+1] = b[k + 1 - 4][l+1];
						b[k + 1][l +2] = b[k + 1 - 4][l +2];
						b[k + 1][l + 3] = b[k + 1 - 4][l + 3];
						b[k][l+1] = rand() % 5;
						b[k][l + 2] = rand() % 5;
						b[k][l + 3] = rand() % 5;
						b[k - 1][l+1] = rand() % 5;
						b[k - 1][l + 2] = rand() % 5;
						b[k - 1][l + 3] = rand() % 5;
						previousrows(b, k, l);
						callpreviousvalues(b, k, l + 2);
					}
					else	if (k == 3)
					{
						b[k + 1][l+1] = b[k + 1 - 3][l+1];
						b[k + 1][l + 2] = b[k + 1 - 3][l + 2];
						b[k + 1][l + 3] = b[k + 1 - 3][l + 3];
						b[k][l] = b[k - 3][l+1];
						b[k][l + 1] = b[k - 3][l + 2];
						b[k][l + 2] = b[k - 3][l + 3];
						b[k - 1][l+1] = rand() % 5;
						b[k - 1][l + 2] = rand() % 5;
						b[k - 1][l + 3] = rand() % 5;
						previousrows(b, k, l);
						callpreviousvalues(b, k, l + 2);
					}
					else if (k == 7)
					{
						b[k][l+1] = b[k - 2][l+1];
						b[k][l + 2] = b[k - 2][l + 2];
						b[k][l + 3] = b[k - 2][l + 3];
						b[k - 1][l+1] = b[k - 3][l+1];
						b[k - 1][l + 2] = b[k - 3][l +2];
						b[k - 1][l + 3] = b[k - 3][l + 3];
						previousrows(b, k, l);
						callpreviousvalues(b, k, l + 2);
					}
					else
					{
						b[k + 1][l+1] = b[k + 1 - 3][l+1];
						b[k + 1][l + 2] = b[k + 1 - 3][l + 2];
						b[k + 1][l + 3] = b[k + 1 - 3][l + 3];
						b[k][l+1] = b[k - 3][l+1];
						b[k][l + 2] = b[k - 3][l +2];
						b[k][l + 3] = b[k - 3][l + 3];
						b[k - 1][l+1] = b[k - 4][l+1];
						b[k - 1][l + 2] = b[k - 4][l + 2];
						b[k - 1][l + 3] = b[k - 4][l + 3];
						previousrows(b, k, l);
						callpreviousvalues(b, k, l + 2);
					}
					score += 1500;
				}
			}
		}
	}

	for (int k = 0; k < 8; k++)
	{
		for (int l = 0; l < 6; l++)
		{
			bool flag = 1;
			if (l < 3)
			{
				if (l == 0)
				{
					if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k] && b[l + 2][k] == b[l + 3][k])
					{
						b[l][k] = rand() % 5;
						b[l + 1][k] = rand() % 5;
						b[l + 2][k] = rand() % 5;
						b[l + 3][k] = rand() % 5;
						flag = 0;
						helpssleepcol(b, k, l, flag);
						copypreviouscolvalues(b, k, l, flag);
						score += 200;
					}
					else if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k])
					{
						b[l][k] = rand() % 5;
						b[l + 1][k] = rand() % 5;
						b[l + 2][k] = rand() % 5;
						flag = 1;
						helpssleepcol(b, k, l, flag);
						copypreviouscolvalues(b, k, l, flag);
						score += 200;
					}
				}
				if (l == 1)
				{
					if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k] && b[l + 2][k] == b[l + 3][k])
					{
						b[l][k] = rand() % 5;
						b[l + 1][k] = rand() % 5;
						b[l + 2][k] = rand() % 5;
						b[l + 3][k] = b[l + 3 - 4][k];
						flag = 0;
						helpssleepcol(b, k, l, flag);
						copypreviouscolvalues(b, k, l, flag);
						score += 200;
					}
					else if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k])
					{
						b[l][k] = rand() % 5;
						b[l + 1][k] = rand() % 5;
						b[l + 2][k] = b[l + 2 - 3][k];
						flag = 1;
						helpssleepcol(b, k, l, flag);
						copypreviouscolvalues(b, k, l, flag);
						score += 200;
					}
				}
				if (l == 2)
				{
					if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k] && b[l + 2][k] == b[l + 3][k])
					{
						b[l][k] = rand() % 5;
						b[l + 1][k] = rand() % 5;
						b[l + 2][k] = b[l + 2 - 4][k];
						b[l + 3][k] = b[l + 3 - 4][k];
						flag = 0;
						helpssleepcol(b, k, l, flag);
						copypreviouscolvalues(b, k, l, flag);
						score += 200;
					}
					else if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k])
					{
						b[l][k] = rand() % 5;
						b[l + 1][k] = b[l + 1 - 3][k];
						b[l + 2][k] = b[l + 2 - 3][k];
						flag = 1;
						helpssleepcol(b, k, l, flag);
						copypreviouscolvalues(b, k, l, flag);
						score += 200;
					}

				}

			}
			if (l == 3)
			{
				if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k] && b[l + 2][k] == b[l + 3][k])
				{
					b[l][k] = rand() % 5;
					b[l + 1][k] = b[l + 1 - 4][k];
					b[l + 2][k] = b[l + 2 - 4][k];
					b[l + 3][k] = b[l + 3 - 4][k];
					flag = 0;
					helpssleepcol(b, k, l, flag);
					copypreviouscolvalues(b, k, l, flag);
					score += 200;
				}
				else if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k])
				{
					b[l][k] = b[l - 3][k];
					b[l + 1][k] = b[l + 1 - 3][k];
					b[l + 2][k] = b[l + 2 - 3][k];
					flag = 1;
					helpssleepcol(b, k, l, flag);
					copypreviouscolvalues(b, k, l, flag);
					score += 200;
				}

			}
			if (l == 4)
			{
				if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k] && b[l + 2][k] == b[l + 3][k])
				{
					b[l][k] = b[l - 4][k];
					b[l + 1][k] = b[l + 1 - 4][k];
					b[l + 2][k] = b[l + 2 - 4][k];
					b[l + 3][k] = b[l + 3 - 4][k];
					flag = 0;
					helpssleepcol(b, k, l, flag);
					copypreviouscolvalues(b, k, l, flag);
					score += 200;
				}
				else if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k])
				{
					b[l][k] = b[l - 3][k];
					b[l + 1][k] = b[l + 1 - 3][k];
					b[l + 2][k] = b[l + 2 - 3][k];
					flag = 1;
					helpssleepcol(b, k, l, flag);
					copypreviouscolvalues(b, k, l, flag);
					score += 200;
				}
			}
			else
			{
				if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k])
				{
					b[l][k] = b[l - 3][k];
					b[l + 1][k] = b[l + 1 - 3][k];
					b[l + 2][k] = b[l + 2 - 3][k];
					flag = 1;
					helpssleepcol(b, k, l, flag);
					copypreviouscolvalues(b, k, l, flag);
					score += 200;
				}

			}

			if (b[l][k] - 10 == b[l + 1][k] && b[l + 1][k] == b[l + 2][k])
			{
				for (int z = 0; z < 3; ++z)
				{
					previousrows(b, l + 1, k - 1);
					previousrows(b, l + 1, k);
					previousrows(b, l + 1, k + 1);
				}
				previousrows(b, l + 2, k);
				score += 1500;
			}
			else if (b[l][k] == b[l + 1][k] - 10 && b[l + 1][k] - 10 == b[l + 2][k])
			{
				for (int z = 0; z < 3; ++z)
				{
					previousrows(b, l + 2, k - 1);
					previousrows(b, l + 2, k);
					previousrows(b, l + 2, k + 1);

				}
				score += 1500;
			}
			else if (b[l][k] == b[l + 1][k] && b[l + 1][k] == b[l + 2][k] - 10)
			{
				previousrows(b, l - 2, k);

				for (int z = 0; z < 3; ++z)
				{
					previousrows(b, l + 3, k - 1);
					previousrows(b, l + 3, k);
					previousrows(b, l + 3, k + 1);
				}
				score += 1500;
			}
		}

	}
}

void elbowcase(int b[][8], int u, int v)                      //elbow case
{
	if (b[u][v] == b[u - 1][v] && b[u - 1][v] == b[u - 2][v] && b[u][v] == b[u][v + 1] && b[u][v + 1] == b[u][v + 2])
	{
		for (int w = 0; w < 8; w++)
		{
			b[w][v] = rand() % 5;                 //gives rand value to the colomn of special gem
			b[u][w] = b[u - 1][w];                //copy previous values of the elbow row.
		}
		for (int l = u - 1; l >= 0; l--)
		{
			for (int p = 0; p < 8; p++)
			{
				b[l][p] = b[l - 1][p];

				if (l == 0)
				{
					b[l][p] = rand() % 5;
				}
			}
		}
		helpsleepelbow(b, u, v);
		score += 1000;
	}
	else if (b[u][v] == b[u][v - 1] && b[u][v - 1] == b[u][v - 2] && b[u][v] == b[u + 1][v] && b[u + 1][v] == b[u + 2][v])
	{
		for (int w = 0; w < 8; w++)
		{
			b[w][v] = rand() % 5;                            //gives rand value to the colomn of special gem
			b[u][w] = b[u - 1][w];                             //copy previous values of the elbow row.
		}
		for (int l = u - 1; l >= 0; l--)
		{
			for (int p = 0; p < 8; p++)
			{
				b[l][p] = b[l - 1][p];

				if (l == 0)
				{
					b[l][p] = rand() % 5;
				}
			}
		}
		helpsleepelbow(b, u, v);
		score += 1000;
	}
	else if (b[u][v] == b[u][v - 1] && b[u][v - 1] == b[u][v - 2] && b[u][v] == b[u - 1][v] && b[u - 1][v] == b[u - 2][v])
	{
		for (int w = 0; w < 8; w++)
		{
			b[w][v] = rand() % 5;                                      //gives rand value to the colomn of special gem
			b[u][w] = b[u - 1][w];                                      //copy previous values of the elbow row.
		}
		for (int l = u - 1; l >= 0; l--)
		{
			for (int p = 0; p < 8; p++)
			{
				b[l][p] = b[l - 1][p];

				if (l == 0)
				{
					b[l][p] = rand() % 5;
				}
			}
		}
		helpsleepelbow(b, u, v);
		score += 1000;
	}
	else if (b[u][v] == b[u][v + 1] && b[u][v + 1] == b[u][v + 2] && b[u][v] == b[u + 1][v] && b[u + 1][v] == b[u + 2][v])
	{
		for (int w = 0; w < 8; w++)
		{
			b[w][v] = rand() % 5;                                 //gives rand value to the colomn of special gem
			b[u][w] = b[u - 1][w];                                  //copy previous values of the elbow row.
		}
		for (int l = u - 1; l >= 0; l--)
		{
			for (int p = 0; p < 8; p++)
			{
				b[l][p] = b[l - 1][p];

				if (l == 0)
				{
					b[l][p] = rand() % 5;
				}
			}
		}
		helpsleepelbow(b, u, v);
		score += 1000;
	}
}

void inovativegem(int b[][8], int g, int h)            //give unique values.
{
	if (b[g][h] == 0)
	{
		b[g][h] += 10;
	}
	else if (b[g][h] == 1)
	{
		b[g][h] += 10;
	}
	else if (b[g][h] == 2)
	{
		b[g][h] += 10;
	}
	else if (b[g][h] == 3)
	{
		b[g][h] += 10;
	}
	else if (b[g][h] == 4)
	{
		b[g][h] += 10;
	}
}
void specialgem(int b[][8], int z, int x)
{
	if (b[z][x] == b[z][x - 1] && b[z][x - 1] == b[z][x - 2] && b[z][x] == b[z][x + 1] && x >= 2 && x <= 6)     //for the horizontal special gem with one at 2 at left and one at right
	{
		inovativegem(b, z, x);
		for (int l = z; l >= 0; l--)
		{
			b[l][x - 1] = b[l - 1][x - 1];
			b[l][x - 2] = b[l - 1][x - 2];
			b[l][x + 1] = b[l - 1][x + 1];
			if (l == 0)
			{
				b[l][x - 1] = rand() % 5;
				b[l][x - 2] = rand() % 5;
				b[l][x + 1] = rand() % 5;
			}
		}
		score += 750;
	}
	else if (b[z][x] == b[z][x - 1] && b[z][x] == b[z][x + 1] && b[z][x + 1] == b[z][x + 2] && x >= 1 && x <= 5)
	{
		inovativegem(b, z, x);
		for (int l = z; l >= 0; l--)
		{
			b[l][x - 1] = b[l - 1][x - 1];
			b[l][x + 2] = b[l - 1][x + 2];
			b[l][x + 1] = b[l - 1][x + 1];
			if (l == 0)
			{
				b[l][x - 1] = rand() % 5;
				b[l][x + 2] = rand() % 5;
				b[l][x + 1] = rand() % 5;
			}
		}
		score += 750;
	}
	else if (b[z][x] == b[z - 1][x] && b[z - 1][x] == b[z - 2][x] && b[z][x] == b[z + 1][x] && z >= 2 && z <= 6)      // makes special gem
	{
		inovativegem(b, z + 1, x);
		previousrows(b, z, x);
		previousrows(b, z, x);
		previousrows(b, z, x);
		score += 750;

	}
	else if (b[z][x] == b[z - 1][x] && b[z][x] == b[z + 1][x] && b[z + 1][x] == b[z + 2][x] && z >= 1 && z <= 5)
	{
		inovativegem(b, z + 2, x);
		previousrows(b, z + 1, x);
		previousrows(b, z + 1, x);
		previousrows(b, z + 1, x);
		score += 750;
		
	}
}
void callcursor(int b[][8])                ///calls the cursor and allows the swapping.
{
	R = 255, G = 0, B = 0;
	int key;
	int comdiffernce1 = 0;
	int comdiffernce2 = 0;
	comdiffernce1 = q2 - q1;
	comdiffernce2 = w2 - w1;
	int count = 0;
	while (1 && flap == 0)
	{
		myRect(q1, w1, q2, w2, R, G, 255);
		bool cursor = isCursorKeyPressed(key);
		if (cursor == 1)
		{
			if (key == 1 && flap == 0)
			{
				if (q2 > 225)
				{
					myRect(q1, w1, q2, w2, 0, 0, 0);
					q2 -= comdiffernce1;
					q1 -= comdiffernce1;
					myRect(q1, w1, q2, w2, R, G, B);
					sj--;
				}
			}
			if (key == 2)
			{
				if (w1 > 70)
				{
					myRect(q1, w1, q2, w2, 0, 0, 0);
					w1 -= comdiffernce2;
					w2 -= comdiffernce2;
					myRect(q1, w1, q2, w2, R, G, B);
					si--;
				}
			}
			if (key == 3)
			{
				if (q2 < 600)
				{
					myRect(q1, w1, q2, w2, 0, 0, 0);
					q2 += comdiffernce1;
					q1 += comdiffernce1;
					myRect(q1, w1, q2, w2, R, G, B);
					sj++;
				}
			}
			if (key == 4)
			{
				if (w2 < 550)
				{
					myRect(q1, w1, q2, w2, 0, 0, 0);
					w1 += comdiffernce2;
					w2 += comdiffernce2;
					myRect(q1, w1, q2, w2, R, G, B);
					si++;
				}
			}

			if (key == 5)             // for enter
			{

				if (count == 0)
				{
					++count;
					a = si;
					c = sj;
				}
				else if (count == 1)
				{
					count = 0;
					if (a == si + 1 || a == si - 1 || c == sj + 1 || c == sj - 1)
					{
						
						swap(b[a][c], b[si][sj]);
						if (b[si][sj] == b[si + 1][sj] && b[si + 1][sj] == b[si + 2][sj] || b[si][sj] == b[si][sj + 1] && b[si][sj + 1] == b[si][sj + 2] || b[si][sj] - 10 == b[si + 1][sj] && b[si + 1][sj] == b[si + 2][sj] || b[si][sj] - 10 == b[si][sj + 1] && b[si][sj + 1] == b[si][sj + 2] || b[si][sj] == b[si + 1][sj]-10 && b[si + 1][sj]-10 == b[si + 2][sj] || b[si][sj] == b[si + 1][sj] && b[si + 1][sj] == b[si + 2][sj]-10 || b[si][sj]  == b[si][sj + 1]-10 && b[si][sj + 1]-10 == b[si][sj + 2] || b[si][sj]  == b[si][sj + 1] && b[si][sj + 1] == b[si][sj + 2]-10)
						{
							for (int i = 0; i < 5; i++)
							{
								specialgem(b, si, sj);
								elbowcase(b, si, sj);
								samevaluecuts(b, 8, 8);
								printshapess(b);
							}
						}
						else	if (b[si][sj] == b[si-1][sj] && b[si][sj] == b[si + 1][sj] || b[si][sj]-10 == b[si][sj -1] && b[si][sj]-10 == b[si][sj + 1] || b[si][sj]-10 == b[si - 1][sj] && b[si][sj]-10 == b[si + 1][sj] || b[si][sj]  == b[si][sj - 1]-10 && b[si][sj]  == b[si][sj + 1] || b[si][sj]  == b[si][sj - 1] && b[si][sj]  == b[si][sj + 1]-10|| b[si][sj]  == b[si - 1][sj]-10 && b[si][sj] == b[si + 1][sj]|| b[si][sj]  == b[si - 1][sj] && b[si][sj]  == b[si + 1][sj]-10)
						{
							for (int i = 0; i < 5; i++)
							{
								specialgem(b, si, sj);
								elbowcase(b, si, sj);
								samevaluecuts(b, 8, 8);
								printshapess(b);
							}
							
						}
						else	if (b[si][sj] == b[si - 1][sj] && b[si -1][sj] == b[si - 2][sj] || b[si][sj] == b[si][sj -1] && b[si][sj - 1] == b[si][sj - 2] || b[si][sj]-10 == b[si - 1][sj] && b[si - 1][sj] == b[si - 2][sj]|| b[si][sj]-10 == b[si][sj - 1] && b[si][sj - 1] == b[si][sj - 2] || b[si][sj]  == b[si - 1][sj]-10 && b[si - 1][sj]-10 == b[si - 2][sj]|| b[si][sj] == b[si - 1][sj]  && b[si - 1][sj] == b[si - 2][sj]-10|| b[si][sj]  == b[si][sj - 1]-10 && b[si][sj - 1]-10 == b[si][sj - 2]|| b[si][sj]== b[si][sj - 1] && b[si][sj - 1] == b[si][sj - 2]-10)
						
						{
							for (int i = 0; i < 5; i++)
							{
								specialgem(b, si, sj);
								elbowcase(b, si, sj);
								samevaluecuts(b, 8, 8);
								printshapess(b);
							}
					
						}
						
						else
						{
							swap(b[si][sj], b[a][c]);
						}
						
					}

				}
			}
		}
	}
	system("cls");
	Sleep(1500);
}
void timer()
{
	cout << endl << endl << endl << endl;
	flap = 0;
	myLines(625, 20, 625, 40, 255, 0, 0);
	myLines(175, 20, 175, 40, 255, 0, 0);
	int x1, y1, x2, y2, R, G, B;
	x1 = 180, x2 = 205, y1 = 30, y2 = 30, R = 255, G = 0, B = 0;
	for (int i = 0; i <= 60; i++)
	{
		if (i == 60)
		{
			flap = 1;
		}
		myLines(x1, y1, x2, y2, R, G, B);
		x1 += 7;
		x2 += 7;
		Sleep(1000);
		gotoxy(0, 0);//helps not to let the score go away from its origin
		cout << "Score:" << score;
		if (score > 10000)
		{
			cout << "-------------------------------DAMN YOU ARE A REAL PLAYER";
		}
		else	if (score < 10000 && score>5000)
		{
			cout << "-------------------------------YOU NEED TO LERAN MORE";
		}
		else   if (score < 5000)
		{
			cout << "-------------------------------I GUESS YOU ARE NEW";
		}
	}

}
void printshapess(int b[][8])
{                  // this will avoid the timer line not to start from the beginning everytime the cursor is called
	//system("cls");
	myRects(160, 70, 680, 550, 0, 0, 0);
	int x1, y1, x2, y2, R, G, B;
	x1 = 180, x2 = 205, y1 = 80, y2 = 105, R = 255, G = 0, B = 0;
	for (int i = 0; i < 8; i++)
	{
		x1 = 180;
		x2 = 205;

		for (int j = 0; j < 8; j++)
		{
			if (b[i][j] == 0)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 128, 128);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 128, 128);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 128, 128);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 1)
			{
				myLine(x1, y1 + 10, x1 + 5, y1, 0, 80, 200);
				myLine(x2 - 10, y1 + 33, x2 + 5, y1 + 8, 0, 80, 200);
				myLine(x1, y1 + 8, x1 + 15, y1 + 33, 0, 80, 200);
				myLine(x2, y1, x2 + 5, y1 + 10, 0, 80, 200);
				myLine(x1 + 5, y1 + 1, x1 + 25, y1 + 1, 0, 80, 200);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 2)
			{
				myLine(x1 - 7, y1 + 16, x1 + 11, y2 - 20 - 7, 155, 28, 49);
				myLine(x1 + 12, y2 - 25, x2 + 5, y1 + 13, 155, 28, 49);
				myLine(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49);
				myLine(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49);
				myLine(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 3)
			{

				myLine(x1 + 3, y1 - 2, x1 + 24, y1 - 2, 255, 0, 255);
				myLine(x1 + 25, y1 - 2, x1 + 32, y1 + 12, 255, 0, 255);
				myLine(x1 + 31, y1 + 14, x1 + 25, y1 + 28, 255, 0, 255);
				myLine(x1 - 3, y1 + 14, x1 + 3, y1 + 28, 255, 0, 255);
				myLine(x1 + 3, y2 + 4, x1 + 24, y2 + 4, 255, 0, 255);
				myLine(x1 - 4, y1 + 12, x1 + 4, y1 - 3, 255, 0, 255);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 4)
			{
				myEllipse(x1 - 2, y1 - 5, x2 + 6, y2 + 5, 0, 255, 0);
				x1 += 60;
				x2 += 60;

			}
			else if (b[i][j] == 10)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 128, 128);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 128, 128);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 128, 128);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 128, 128);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 128, 128);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 128, 128);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 11)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 80, 200);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 80, 200);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 80, 200);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 80, 200);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 80, 200);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 80, 200);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 12)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 155, 28, 49);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 155, 28, 49);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 155, 28, 49);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 155, 28, 49);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 155, 28, 49);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 155, 28, 49);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 13)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 255, 0, 255);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 255, 0, 255);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 255, 0, 255);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 255, 0, 255);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 255, 0, 255);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 255, 0, 255);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 14)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 255, 0);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 255, 0);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 255, 0);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 255, 0);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 255, 0);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 255, 0);
				x1 += 60;
				x2 += 60;
			}

		}
		y1 += 60;
		y2 += 60;
	}

}
void printshapes(int b[][8])
{
	myRects(160, 70, 680, 550, 0, 0, 0);
	int x1, y1, x2, y2, R, G, B;
	x1 = 180, x2 = 205, y1 = 80, y2 = 105, R = 255, G = 0, B = 0;
	for (int i = 0; i < 8; i++)
	{
		x1 = 180;
		x2 = 205;

		for (int j = 0; j < 8; j++)
		{
			if (b[i][j] == 0)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 128, 128);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 128, 128);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 128, 128);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 1)
			{
				myLine(x1, y1 + 10, x1 + 5, y1, 0, 80, 200);
				myLine(x2 - 10, y1 + 33, x2 + 5, y1 + 8, 0, 80, 200);
				myLine(x1, y1 + 8, x1 + 15, y1 + 33, 0, 80, 200);
				myLine(x2, y1, x2 + 5, y1 + 10, 0, 80, 200);
				myLine(x1 + 5, y1 + 1, x1 + 25, y1 + 1, 0, 80, 200);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 2)
			{
				myLine(x1 - 7, y1 + 16, x1 + 11, y2 - 20 - 7, 155, 28, 49);
				myLine(x1 + 12, y2 - 25, x2 + 5, y1 + 13, 155, 28, 49);
				myLine(x1 - 7, y1 + 16, x1 + 1, y2 + 5, 155, 28, 49);
				myLine(x2 + 4, y1 + 16, x2 - 4, y2 + 5, 155, 28, 49);
				myLine(x1 + 3, y2 + 5, x2 - 5, y2 + 5, 155, 28, 49);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 3)
			{
				myLine(x1 + 3, y1 - 2, x1 + 24, y1 - 2, 255, 0, 255);
				myLine(x1 + 25, y1 - 2, x1 + 32, y1 + 12, 255, 0, 255);
				myLine(x1 + 31, y1 + 14, x1 + 25, y1 + 28, 255, 0, 255);
				myLine(x1 - 3, y1 + 14, x1 + 3, y1 + 28, 255, 0, 255);
				myLine(x1 + 3, y2 + 4, x1 + 24, y2 + 4, 255, 0, 255);
				myLine(x1 - 4, y1 + 12, x1 + 4, y1 - 3, 255, 0, 255);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 4)
			{
				myEllipse(x1 - 2, y1 - 5, x2 + 6, y2 + 5, 0, 255, 0);
				x1 += 60;
				x2 += 60;

			}
			else if (b[i][j] == 10)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 128, 128);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 128, 128);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 128, 128);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 128, 128);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 128, 128);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 128, 128);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 11)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 80, 200);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 80, 200);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 80, 200);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 80, 200);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 80, 200);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 80, 200);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 12)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 155, 28, 49);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 155, 28, 49);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 155, 28, 49);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 155, 28, 49);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 155, 28, 49);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 155, 28, 49);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 13)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 255, 0, 255);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 255, 0, 255);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 255, 0, 255);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 255, 0, 255);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 255, 0, 255);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 255, 0, 255);
				x1 += 60;
				x2 += 60;
			}
			else if (b[i][j] == 14)
			{
				myLine(x1 + 15, y1 - 2, x2 + 7, y2 + 1, 0, 255, 0);
				myLine(x1 + 15, y1 - 2, x1, y2 + 2, 0, 255, 0);
				myLine(x1, y2 + 2, x2 + 6, y2 + 2, 0, 255, 0);
				myLine(x1, y2 - 18, x2 + 6, y2 - 18, 0, 255, 0);
				myLine(x1, y2 - 18, x1 + 15, y2 + 10, 0, 255, 0);
				myLine(x2 + 6, y2 - 18, x2 - 9, y2 + 10, 0, 255, 0);
				x1 += 60;
				x2 += 60;
			}
		}
		y1 += 60;
		y2 += 60;
	}
	std::thread first(callcursor, b);
	std::thread second(timer);
	first.join();
	second.join();
}
int main()
{
	srand(time(0));
	int b[8][8];
	int random = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			random = rand() % 5;
			b[i][j] = random;
		}
	}
	printshapes(b);
	cout << endl;
	_getch();
}