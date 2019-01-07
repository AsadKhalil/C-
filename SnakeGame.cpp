#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;



bool gameOver;
const int width = 25;
const int height = 25;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0,LEFT,RIGHT,UP,DOWN };
eDirection dir;

void setup()
{
	
	gameOver = false;
	dir = STOP;
	x = width / 2;         //snake position
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	
}
void draw()
{
	system("cls");


	for (int i = 0; i < width+1+1; i++)     //top boundary
	{
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "|";       //left boundary
			if(i==y&&j==x)
				cout << "O";           //snake
			else if(i==fruitY && j==fruitX)    //fruit
				cout << "X";

			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
				
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
					
				}
				if (!print)
					cout << " ";
			}
			if (j == width - 1)
			{
				cout << "|";                 //right boundary
			}
		

		}
		cout << endl;

	}

	for (int i = 0; i < width+1+1; i++) //bottom boundary
	{
		cout << "-";
	}
	cout << endl;
	cout << "SCORE:" << score << endl;
}
 void input()
 {
	 if (_kbhit())
	 {
		 switch (_getch())
		 {
		 case 'a':
			 dir = LEFT;
				 break;
		  case's':
			  dir = DOWN;
				 break;
		  case 'w':
			  dir = UP;
			  break;
		  case'd':
			  dir = RIGHT;
			  break;
		  case'x':
			  gameOver = true;
			  break;

		 }
	 }
 }
 void logic()
 {
	 int prevX = tailX[0];
	 int prevY = tailY[0];
	 int prev2X, prev2Y;
	 tailX[0] = x;
	 tailY[0] = y;
	 for (int i = 1; i <nTail; i++)
	 {
		 prev2X = tailX[i];
		 prev2Y = tailY[i];
		 tailX[i] = prevX;
		 tailY[i] = prevY;
		 prevX = prev2X;
		 prevY = prev2Y;
	 }
	switch (dir)
	 {
	 
	 case LEFT:
		 x--;
		 break;
	 case RIGHT:
		 x++;
		 break;
		 case UP:
			 y--;
		 break;
	 case DOWN:
		 y++;
		 break;
	 default:
		 break;
	 }

	// if (x > width || x < 0 || y > height || y < 0)          //break on Wall
		// gameOver = true;
	//system("cls");
	//cout <<endl<< " ----------GAMEOVER--------------"<<endl;
	 if (x >= width)
		 x = 0;
	 else if (x < 0)
		 x = width - 1;

	 if (y >= height)
		 y = 0;
	 else if (y < 0)
		 y = height - 1;

	 for (int i = 0; i < nTail; i++)
	 {
		 if (tailX[i] == x && tailY[i] == y)
		 {
			 gameOver = true;
			 system("cls");
			 cout <<endl <<" ----------GAMEOVER--------------"<<endl;
		 }
	 }
	 if (x == fruitX && y == fruitY)
	 {
		 score += 10;
		 fruitX = rand() % width;
		 fruitY = rand() % height;
		 nTail++;
	 }


 }
int main() 
{
	setup();

	
	while (!gameOver)
	{
		draw();
		input();
		logic();
		Sleep(250);
	}
	system("pause");
}