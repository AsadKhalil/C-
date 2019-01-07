#include<iostream>
#include<conio.h>
#include "mygraphics.h"
#include <windows.h>
using namespace std;
void printgrid(int x)
{

	if (x == 1)
	{


		int cor[15][4] = { { 2, 2, 25, 25 },{ 25, 2, 450, 25 },{ 450, 2, 475, 25 },{ 2, 25, 25, 320 },{ 2, 295, 25, 320 },{ 25, 295, 450, 320 },{ 450, 295, 475, 320 },{ 450, 25, 475, 320 } };
		int rect[3][4] = { { 100, 73, 350, 103 },{ 100, 143, 350, 173 },{ 100, 207, 350, 237 } };


		for (int i = 0; i<14; i++)
		{

			drawRectangle(cor[i][0], cor[i][1], cor[i][2], cor[i][3], 184, 0, 225);
		}
		for (int i = 0; i<3; i++)
		{
			drawRectangle(rect[i][0], rect[i][1], rect[i][2], rect[i][3], 225, 225, 225);
		}
	}
	else
	{
		drawRectangle(0, 0, 600, 600, 0, 0, 0);
	}
}
int mainpage()
{

	int x = 1;
	while (x != 4)
	{
		system("cls");
		printgrid(1);
		gotoxy(21, 3); cout << "P A C M A N";
		gotoxy(21, 7); cout << "1=NEW GAME";
		gotoxy(19, 13); cout << "2=HOW TO PLAY";
		gotoxy(19, 18); cout << "3=About PacMan";
		gotoxy(4, 5); cout << "ENTER YOUR DESIRE OPTION OR PRESS 4 TO EXIT";
		gotoxy(4, 21); cout << "Made BY:-\n    Muhammad Asad Khalil\n\n\n\n\n";
		cin >> x;
		if (x == 1)
		{
			return 0;
		}

		if (x == 2)
		{
			printgrid(0);
			char y = 'e';

			system("cls");
			while (y != 'p')
			{
				cout << "\n*** Press 'p' to Go Back ***\n";

				cout << "\n\t 1=>Move Pac-Man using Arrow Keys on your Keyboard\n";
				cout << "\n\t 2=>Eat Food and Get 1 Point Score\n";
				cout << "\n\t 3=>Eat Bonus Food and Get 200 Points Score\n";
				cout << "\n\t 4=>Protect Pac-Man from The Enemy\n";
				cout << "\n\t 5=>You have 3 lifes and life detuted when enemy eats you \n";
				cout << "\n\t 6=>If you have eaten all the food in the maze in time you will WIN\n";

				cin >> y;
			}

		}
		if (x == 3)
		{
			printgrid(0);
			char y = 'e';

			system("cls");
			while (y != 'p')
			{
				cout << "\n*** Press 'p' to Go Back ***\n";
				cout << "\n\t Pac-Man is an arcade game developed by Namco and first released\n\t in Japan on May 22, 1980.\n\n\t It was created by Japanese video game designer Toru Iwatani.\n\n\t It was licensed for distribution in the United States by Midway\n\t and released in October 1980.\n\n\t";
				cout << "But this is made by:\n\n\t Muhammad Hamza Sohail Roll no 15L-4074.\n\n\t Muhammad Yasir Roll no 15L-4027\n\n\t Is Best Than Ever.";
				cin >> y;
			}
		}
		if (x == 4)
			return 1;
	}
}
void clearscreen() // entire screen black
{
	drawRectangle(0, 0, 800, 800, 0, 0, 0);// entire screen black
}
bool ghostCollision(int x, int y, int u, int v, int a, int b)
{
	int x1 = x - 13, x2 = x + 13, y1 = y - 13, y2 = y + 13;
	int u1 = u - 13, u2 = u + 13, v1 = v - 13, v2 = v + 13;
	int a1 = a - 13, a2 = a + 13, b1 = b - 13, b2 = b + 13;
	if ((x1 - u1 >= -5 && x1 - u1 <= 5) && (x2 - u2 >= -5 && x2 - u2 <= 5) && (y1 - v1 >= -5 && y1 - v1 <= 5) && (y2 - v2 >= -5 && y2 - y2 <= 5))
		return true;
	if (((x1 - a1 >= -5 && x1 - a1 <= 5) && (x2 - a2 >= -5 && x2 - a2 <= 5) && (y1 - b1 >= -5 && y1 - b1 <= 5) && (y2 - b2 >= -5 && y2 - b2 <= 5)))
		return true;
	return false;
}
void lives(int &pacx, int &pacy, int &ene1x, int &ene1y, int &ene2x, int &ene2y, int &lives, int &score, char &c, int &ghostcolor)
{
	gotoxy(0, 10);
	cout << "lives: " << lives;//display lives

	if (ghostCollision(pacx, pacy, ene1x, ene1y, ene2x, ene2y))
	{
		if (ghostcolor == 194)   // means powerpill not active so color of  ghost will be orignal i.e 194
			lives--;
		system("CLS");
		clearscreen();
		c = 'd';
		ghostcolor = 194;
		pacx = 316, pacy = 376;
		ene1x = 195, ene1y = 64;
		ene2x = 400, ene2y = 120;
	}
}
bool gameover(int &lives, int score) //return true if lives ends or score is full
{
	if (lives == 0)
	{
		clearscreen();
		gotoxy(10, 10);
		cout << "GAME OVER";
		gotoxy(10, 11);
		cout << "YOUR SCORE IS: " << score;
		return true;
	}
	if (score == 495)
	{
		clearscreen();
		gotoxy(10, 10);
		cout << "CONGRATULATIONS!!   YOU WON";
		gotoxy(10, 11);
		cout << "YOUR SCORE IS: " << score;
		return true;
	}
	return false;
}
void powerpills(int x, int y, int pillfood[][5], int &score, int &pacmanspeed, int &enemyspeed, int &ghostcolor, int &timeofpils)
{
	for (int i = 0; i < 4; i++)
	{
		drawEllipse(pillfood[i][0], pillfood[i][1], pillfood[i][2], pillfood[i][3], pillfood[i][4], pillfood[i][4], pillfood[i][4]); //print power pills
		if (x >= pillfood[i][0] && x <= pillfood[i][2] && y >= pillfood[i][1] && y <= pillfood[i][3])  //if cordinates of pacman equal to pwerpill cordinats
			if (pillfood[i][4] == 255)  //if pill is white then it will work
			{
				ghostcolor = 0;              //ghost color change
				score = score + 5;             //score update
				pillfood[i][4] = 0;             //pillfood will be black and unuseable
				timeofpils--;              //time of pill start decrease
			}
		if (timeofpils <= 999)
			timeofpils--;
		if (timeofpils == 0)
		{
			ghostcolor = 194;
			timeofpils = 1000;
		}
	}
}
void FoodnScore(int x, int y, int arr[][5], int &score)// print food and add score
{
	gotoxy(0, 9);
	cout << "Score: " << score;
	for (int i = 0; i < 99; i++)
	{
		drawRectangle(arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], arr[i][4], arr[i][4]);
		if (x >= arr[i][0] && x <= arr[i][2] && y >= arr[i][1] && y <= arr[i][3])//if pacman eats food
		{
			if (arr[i][4] == 255)
			{
				score = score + 5;
				arr[i][4] = 0;
			}
		}
	}
}
void grid(int rectdata[][4], int row) //print gird on screen
{
	for (int i = 0; i < 39; i++)
		drawLine(rectdata[i][0], rectdata[i][1], rectdata[i][2], rectdata[i][3], 0, 0, 255);
	for (int i = 39; i < row; i++)
		drawRectangle(rectdata[i][0], rectdata[i][1], rectdata[i][2], rectdata[i][3], 0, 0, 255);
}
void iscolide(int x, int y, int arr[][4], int row, int &right, int &left, int &up, int &down)  //collision
{
	for (int i = 0; i < row; i++)
	{
		if (x == arr[i][0] - 14)//right
			if (y > arr[i][1] - 13 && y < arr[i][3] + 13)
				right = 1;
		if (y == arr[i][1] - 14)//down
			if (x > arr[i][0] - 13 && x < arr[i][2] + 13)
				down = 1;
		if (x == arr[i][2] + 14)//left
			if (y > arr[i][1] - 13 && y < arr[i][3] + 13)
				left = 1;
		if (y == arr[i][3] + 14)//up
			if (x > arr[i][0] - 13 && x < arr[i][2] + 13)
				up = 1;
	}

}
void pacmanMovement(int &midpointx, int &midpointy, int speed, char arrow, int arr[][4], int row)
{
	int size = 13;
	int right = 0, left = 0, up = 0, down = 0;
	iscolide(midpointx, midpointy, arr, row, right, left, up, down);

	if (arrow == 'M' && right != 1)//right
	{
		drawEllipse(midpointx - size, midpointy - size, midpointx + size, midpointy + size, 0, 0, 0);
		midpointx = midpointx + speed;
		drawEllipse(midpointx - size, midpointy - size, midpointx + size, midpointy + size, 255, 255, 0);
		for (int i = 0; i < 13; i++)
		{
			drawLine(midpointx, midpointy, midpointx + 13, midpointy - i, 0, 0, 0);
			drawLine(midpointx, midpointy, midpointx + 13, midpointy + i, 0, 0, 0);
		}

	}
	if (arrow == 'H'&& up != 1)//up
	{
		drawEllipse(midpointx - size, midpointy - size, midpointx + size, midpointy + size, 0, 0, 0);
		midpointy = midpointy - speed;
		drawEllipse(midpointx - size, midpointy - size, midpointx + size, midpointy + size, 255, 255, 0);
		for (int i = 0; i < 13; i++)
		{
			drawLine(midpointx, midpointy, midpointx - i, midpointy - 13, 0, 0, 0);
			drawLine(midpointx, midpointy, midpointx + i, midpointy - 13, 0, 0, 0);
		}

	}
	if (arrow == 'P' && down != 1)//down
	{
		drawEllipse(midpointx - size, midpointy - size, midpointx + size, midpointy + size, 0, 0, 0);
		midpointy = midpointy + speed;
		drawEllipse(midpointx - size, midpointy - size, midpointx + size, midpointy + size, 255, 255, 0);
		for (int i = 0; i < 13; i++)
		{
			drawLine(midpointx, midpointy, midpointx - i, midpointy + 13, 0, 0, 0);
			drawLine(midpointx, midpointy, midpointx + i, midpointy + 13, 0, 0, 0);
		}

	}
	if (arrow == 'K' && left != 1)//left
	{
		drawEllipse(midpointx - size, midpointy - size, midpointx + size, midpointy + size, 0, 0, 0);
		midpointx = midpointx - speed;
		drawEllipse(midpointx - size, midpointy - size, midpointx + size, midpointy + size, 255, 255, 0);
		for (int i = 0; i < 13; i++)
		{
			drawLine(midpointx, midpointy, midpointx - 13, midpointy - i, 0, 0, 0);
			drawLine(midpointx, midpointy, midpointx - 13, midpointy + i, 0, 0, 0);
		}

	}
}
void enemy1(int &x, int &y, int &enemyx, int &enemyy, int speed, int arr[][4], int row, int ghostcolor)
{
	int right = 0, left = 0, up = 0, down = 0;
	iscolide(enemyx, enemyy, arr, row, right, left, up, down);
	drawEllipse(enemyx + 13, enemyy - 13, enemyx - 13, enemyy + 13, 0, 0, 0);
	if (ghostcolor == 194)
	{
		if (right == 1)//right
		{
			if (enemyy < y)
				enemyy = enemyy + speed;
			else
				enemyy = enemyy - speed;
		}
		if (up == 1)//up
		{
			if (enemyx < x)
				enemyx = enemyx + speed;
			else
				enemyx = enemyx - speed;
		}
		if (down == 1)//down
		{
			if (enemyx < x)
				enemyx = enemyx + speed;
			else
				enemyx = enemyx - speed;
		}

		if (left == 1)
		{
			if (enemyy < y)
				enemyy = enemyy + speed;
			else
				enemyy = enemyy - speed;
		}
		if (right == 0 && left == 0 && up == 0 && down == 0)
		{
			if (enemyy < y)
				enemyy = enemyy + speed;
			if (enemyy > y)
				enemyy = enemyy - speed;
			if (enemyx <= x)
				enemyx = enemyx + speed;
			else
				enemyx = enemyx - speed;
		}
	}
	else
	{
		if (right == 1)//right
		{
			if (enemyy < y)
				enemyy = enemyy - speed;
			else
				enemyy = enemyy + speed;
		}
		if (up == 1)//up
		{
			if (enemyx < x)
				enemyx = enemyx - speed;
			else
				enemyx = enemyx + speed;
		}
		if (down == 1)//down
		{
			if (enemyx < x)
				enemyx = enemyx - speed;
			else
				enemyx = enemyx + speed;
		}

		if (left == 1)
		{
			if (enemyy < y)
				enemyy = enemyy - speed;
			else
				enemyy = enemyy + speed;
		}
		if (right == 0 && left == 0 && up == 0 && down == 0)
		{
			if (enemyy < y)
				enemyy = enemyy - speed;
			if (enemyy > y)
				enemyy = enemyy + speed;
			if (enemyx <= x)
				enemyx = enemyx - speed;
			else
				enemyx = enemyx + speed;
		}
	}

	drawEllipse(enemyx + 13, enemyy - 13, enemyx - 13, enemyy + 13, ghostcolor, 0, 225);
}
void enemy2(int &x, int &y, int &enemyx, int &enemyy, int speed, int arr[][4], int row, int ghostcolor)
{
	int right = 0, left = 0, up = 0, down = 0;
	iscolide(enemyx, enemyy, arr, row, right, left, up, down);
	drawEllipse(enemyx + 13, enemyy - 13, enemyx - 13, enemyy + 13, 0, 0, 0);
	if (ghostcolor == 194)
	{
		if (right == 1)//right
		{
			if (enemyy < y)
				enemyy = enemyy + speed;
			else
				enemyy = enemyy - speed;
		}
		if (up == 1)//up
		{
			if (enemyx < x)
				enemyx = enemyx + speed;
			else
				enemyx = enemyx - speed;
		}
		if (down == 1)//down
		{
			if (enemyx < x)
				enemyx = enemyx + speed;
			else
				enemyx = enemyx - speed;
		}

		if (left == 1)
		{
			if (enemyy < y)
				enemyy = enemyy + speed;
			else
				enemyy = enemyy - speed;
		}
		if (right == 0 && left == 0 && up == 0 && down == 0)
		{
			if (enemyy < y)
				enemyy = enemyy + speed;
			if (enemyy > y)
				enemyy = enemyy - speed;
			if (enemyx <= x)
				enemyx = enemyx + speed;
			else
				enemyx = enemyx - speed;
		}
	}
	else
	{
		if (right == 1)//right
		{
			if (enemyy < y)
				enemyy = enemyy - speed;
			else
				enemyy = enemyy + speed;
		}
		if (up == 1)//up
		{
			if (enemyx < x)
				enemyx = enemyx - speed;
			else
				enemyx = enemyx + speed;
		}
		if (down == 1)//down
		{
			if (enemyx < x)
				enemyx = enemyx - speed;
			else
				enemyx = enemyx + speed;
		}

		if (left == 1)
		{
			if (enemyy < y)
				enemyy = enemyy - speed;
			else
				enemyy = enemyy + speed;
		}
		if (right == 0 && left == 0 && up == 0 && down == 0)
		{
			if (enemyy < y)
				enemyy = enemyy - speed;
			if (enemyy > y)
				enemyy = enemyy + speed;
			if (enemyx <= x)
				enemyx = enemyx - speed;
			else
				enemyx = enemyx + speed;
		}
	}
	drawEllipse(enemyx + 13, enemyy - 13, enemyx - 13, enemyy + 13, ghostcolor, 0, 225);
}
void abc()
{

	drawEllipse(25, 25, 50, 50, 196, 0, 225);
	drawEllipse(28, 32, 36, 38, 0, 0, 0);
	drawEllipse(39, 32, 47, 38, 0, 0, 0);
	drawEllipse(36, 44, 40, 52, 0, 0, 0);
	drawEllipse(28, 44, 32, 52, 0, 0, 0);
	drawEllipse(44, 44, 48, 52, 0, 0, 0);
	drawEllipse(30, 34, 34, 36, 225, 225, 225);
	drawEllipse(41, 34, 45, 36, 225, 225, 225);
}
void main()
{
	int gridcorddata[70][4] = { { 100, 20, 100, 160 },{ 93, 13, 93, 167 },{ 100, 160, 180, 160 },{ 93, 167, 173, 167 },{ 180, 160, 180, 220 },{ 173, 167, 173, 213 },{ 180, 220, 100, 220, },{ 173, 213, 100, 213 },{ 535, 20, 535, 160 },{ 542, 13, 542, 167 },
	{ 535, 160, 455, 160, },{ 542, 167, 462, 167 },{ 455, 160, 455, 220 },{ 462, 167, 462, 213 },{ 455, 220, 535, 220 },{ 462, 213, 535, 213 },{ 455, 250, 535, 250 },{ 462, 257, 535, 257 },{ 455, 250, 455, 310 },{ 462, 257, 462, 303 },{ 455, 310, 535, 310 },{ 462, 303, 542, 303 },
	{ 535, 310, 535, 480 },{ 542, 303, 542, 487 },{ 100, 250, 180, 250 },{ 100, 257, 173, 257 },{ 180, 250, 180, 310 },{ 173, 257, 173, 303 },{ 180, 310, 100, 310 },{ 173, 303, 93, 303 },{ 100, 310, 100, 480 },{ 93, 303, 93, 487 },{ 100, 480, 535, 480 },{ 93, 487, 542, 487, },
	{ 93, 13, 542, 13 },{ 100, 20, 310, 20 },{ 310, 20, 310, 80 },{ 325, 20, 535, 20 },{ 325, 20, 325, 80 },
	{ 130, 50, 180, 80 },{ 210, 50, 280, 80 },{ 355, 50, 425, 80 },{ 455, 50, 505, 80 },{ 130, 110, 180, 130 },
	{ 210, 110, 220, 220 },{ 250, 110, 385, 120 },{ 220, 150, 280, 170 },{ 355, 150, 415, 170 },{ 415, 110, 425, 220 },{ 455, 110, 505, 130 },
	{ 312, 120, 322, 170 },{ 210, 250, 220, 310 },{ 415, 250, 425, 310 },{ 250, 200, 385, 270 },{ 130, 340, 180, 360 },{ 170, 360, 180, 410 },
	{ 100, 390, 140, 410 },{ 250, 300, 385, 310 },{ 210, 340, 282, 360 },{ 312, 310, 322, 360 },{ 352, 340, 425, 360 },{ 455, 340, 505, 360 },
	{ 455, 360, 465, 410 },{ 505, 390, 535, 410 },{ 130, 440, 282, 450 },{ 352, 450, 505, 440 },{ 210, 390, 220, 440 },
	{ 415, 390, 425, 440 },{ 250, 390, 385, 410 },{ 312, 410, 322, 450 } };
	int arr[99][5] = { { 194, 34, 196, 36, 255 },{ 194, 64, 196, 66, 255 },{ 194, 94, 196, 96, 255 },{ 194, 124, 196, 126, 255 },
	{ 194, 154, 196, 156, 255 },{ 194, 184, 196, 186, 255 },{ 194, 214, 196, 216, 255 },{ 194, 244, 196, 246, 255 },{ 194, 274, 196, 276, 255 },
	{ 194, 304, 196, 306, 255 },{ 194, 334, 196, 336, 255 },{ 194, 364, 196, 366, 255 },{ 194, 394, 196, 396, 255 },{ 194, 424, 196, 426, 255 },
	{ 194, 464, 196, 466, 255 },{ 399, 34, 401, 36, 255 },{ 399, 94, 401, 96, 255 },{ 399, 124, 401, 126, 255 },{ 399, 184, 401, 186, 255 },
	{ 399, 214, 401, 216, 255 },{ 399, 244, 401, 246, 255 },{ 399, 274, 401, 276, 255 },{ 399, 304, 401, 306, 255 },{ 399, 394, 401, 396, 255 },
	{ 399, 424, 401, 426, 255 },{ 399, 464, 401, 466, 255 },{ 479, 34, 481, 36, 255 },{ 479, 94, 481, 96, 255 },{ 479, 374, 481, 376, 255 },
	{ 479, 144, 481, 146, 255 },{ 479, 400, 481, 402, 255 },{ 479, 424, 481, 426, 255 },{ 479, 464, 481, 466, 255 },{ 439, 34, 441, 36, 255 },
	{ 439, 64, 441, 66, 255 },{ 439, 94, 441, 96, 255 },{ 439, 124, 441, 126, 255 },{ 439, 154, 441, 156, 255 },{ 439, 184, 441, 186, 255 },
	{ 439, 214, 441, 216, 255 },{ 439, 244, 441, 246, 255 },{ 439, 274, 441, 276, 255 },{ 439, 304, 441, 306, 255 },{ 439, 334, 441, 336, 255 },
	{ 439, 364, 441, 366, 255 },{ 439, 394, 441, 396, 255 },{ 439, 424, 441, 426, 255 },{ 439, 464, 441, 466, 255 },{ 519, 34, 521, 36, 255 },
	{ 519, 94, 521, 96, 255 },{ 519, 124, 521, 126, 255 },{ 519, 334, 521, 336, 255 },{ 519, 364, 521, 366, 255 },{ 519, 464, 521, 466, 255 },{ 339, 34, 341, 36, 255 },{ 339, 64, 341, 66, 255 },{ 339, 94, 341, 96, 255 },{ 339, 284, 341, 286, 255 },{ 339, 154, 341, 156, 255 },
	{ 339, 184, 341, 186, 255 },
	{ 339, 334, 341, 336, 255 },
	{ 339, 364, 341, 366, 255 },
	{ 339, 424, 341, 426, 255 },
	{ 339, 464, 341, 466, 255 },
	{ 294, 34, 296, 36, 255 },
	{ 294, 64, 296, 66, 255 },
	{ 294, 94, 296, 96, 255 },
	{ 294, 284, 296, 286, 255 },
	{ 294, 154, 296, 156, 255 },
	{ 294, 184, 296, 186, 255 },
	{ 294, 334, 296, 336, 255 },
	{ 294, 364, 296, 366, 255 },
	{ 294, 424, 296, 426, 255 },
	{ 294, 464, 296, 466, 255 },
	{ 114, 34, 116, 36, 255 },
	{ 114, 94, 116, 96, 255 },
	{ 114, 124, 116, 126, 255 },
	{ 114, 334, 116, 336, 255 },
	{ 114, 364, 116, 366, 255 },
	{ 114, 464, 116, 466, 255 },
	{ 154, 34, 156, 36, 255 },
	{ 154, 94, 156, 96, 255 },
	{ 154, 144, 156, 146, 255 },
	{ 154, 324, 156, 326, 255 },
	{ 154, 374, 156, 376, 255 },
	{ 154, 404, 156, 406, 255 },
	{ 154, 424, 156, 426, 255 },
	{ 154, 464, 156, 466, 255 },
	{ 234, 34, 236, 36, 255 },
	{ 234, 94, 236, 96, 255 },
	{ 234, 124, 236, 126, 255 },
	{ 234, 184, 236, 186, 255 },
	{ 234, 214, 236, 216, 255 },
	{ 234, 244, 236, 246, 255 },
	{ 234, 274, 236, 276, 255 },
	{ 234, 304, 236, 306, 255 },
	{ 234, 394, 236, 396, 255 },
	{ 234, 424, 236, 426, 255 },
	{ 234, 464, 236, 466, 255 } };
	int pillfood[4][5] = { { 111, 61, 119, 69, 255 },{ 111, 421, 119, 429, 255 },{ 516, 61, 524, 69, 255 },{ 516, 421, 524, 429, 255 } };
	int noofgrids = 70;
	int timeofpills = 1000;
	int midpointx = 316, midpointy = 376;
	int enemy1x = 195, enemy1y = 64;
	int enemy2x = 400, enemy2y = 120;
	int pacspeed = 1;
	int enemyspeed = 1;
	int score = 0;
	char up = 'M';
	int ghostcolor = 194;
	int nooflives = 2;
	if (mainpage() == 1)
		return;
	clearscreen();
	bool pilpower = false;
	while (true)
	{
		gotoxy(0, 14);
		cout << midpointx << "," << midpointy;
		if (_kbhit())
			up = _getch();
		if (up == -32)
			up = _getch();
		grid(gridcorddata, noofgrids);
		pacmanMovement(midpointx, midpointy, pacspeed, up, gridcorddata, noofgrids);
		FoodnScore(midpointx, midpointy, arr, score);
		enemy1(midpointx, midpointy, enemy1x, enemy1y, enemyspeed, gridcorddata, noofgrids, ghostcolor);
		enemy2(midpointx, midpointy, enemy2x, enemy2y, enemyspeed, gridcorddata, noofgrids, ghostcolor);
		powerpills(midpointx, midpointy, pillfood, score, pacspeed, enemyspeed, ghostcolor, timeofpills);
		lives(midpointx, midpointy, enemy1x, enemy1y, enemy2x, enemy2y, nooflives, score, up, ghostcolor);
		abc();
		if (gameover(nooflives, score))
			break;
	}
	_getch();
}