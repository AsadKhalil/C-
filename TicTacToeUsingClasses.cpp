#include<iostream>  
#include<cstdlib>
using namespace std;
class tictactoe
{
private:
	char ticarray[3][3];  // 3x3 multidimentional ticarrayay
public:
	tictactoe(char a[3][3])  //parametrized constructor
	{
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				ticarray[i][j] = a[i][j];
			}
		}
	}
	char person = 'X';
	void draw();  //member functions
	void turn();
	void changeplayer();
	bool winlose();
	void checkwin();
};
void tictactoe::draw()  // function to draw board
{
	system("cls"); //used to do change in one box rather than many
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << "   " << "_____" << ticarray[i][j] << "|";
		}
		cout << endl;
	}
}
void tictactoe::turn()  //function to play
{
	cout << endl;
loop1:  // label to re enter
	cout << endl;
loop:  //label to re enter
	int choice;
	cout << endl;
	cout << "enter your choice from the above board(1-9)=" << endl;
	cin >> choice;
	cout << endl;


	switch (choice)  //using switch to take input
	{
	case 1:
	{
		if (ticarray[0][0] == '1')  //this condition will check whether previous player has already played on that box or not
			ticarray[0][0] = person;
		else
		{

			cout << "this place is occupied =" << endl;
			goto loop1;  //used goto if user is entering number which was previously entered
		}
		break;
	}
	case 2:
	{
		if (ticarray[0][1] == '2')
			ticarray[0][1] = person;
		else
		{
			cout << "this place is occupied =" << endl;
			goto loop1;
		}
		break;
	}
	case 3:
	{
		if (ticarray[0][2] == '3')
			ticarray[0][2] = person;
		else
		{
			cout << "this place is occupied =" << endl;
			goto loop1;
		}
		break;
	}
	case 4:
	{
		if (ticarray[1][0] == '4')
			ticarray[1][0] = person;
		else
		{
			cout << "this place is occupied =" << endl;
			goto loop1;
		}
		break;
	}
	case 5:
	{
		if (ticarray[1][1] == '5')
			ticarray[1][1] = person;
		else
		{
			cout << "this place is occupied =" << endl;
			goto loop1;
		}
		break;
	}
	case 6:
	{
		if (ticarray[1][2] == '6')
			ticarray[1][2] = person;
		else
		{
			cout << "this place is occupied =" << endl;
			goto loop1;
		}
		break;
	}
	case 7:
	{
		if (ticarray[2][0] == '7')
			ticarray[2][0] = person;
		else
		{
			cout << "this place is occupied =" << endl;
			goto loop1;
		}
		break;

	}
	case 8:
	{
		if (ticarray[2][1] == '8')
			ticarray[2][1] = person;
		else
		{
			cout << "this place is occupied =" << endl;
			goto loop1;
		}
		break;
	}
	case 9:
	{
		if (ticarray[2][2] == '9')
			ticarray[2][2] = person;
		else
		{
			cout << "this place is occupied =" << endl;
			goto loop1;
		}
		break;
	}
	default: {
		cout << "sorry enter correct value=";
		goto loop;  // this goto will work if user enter except 1-9
	}
	}
}
void tictactoe::changeplayer()  //function to change player turn
{
	if (person == 'X')
	{
		person = 'Y';  //if perviously x played now y will get turn and vice versa
	}
	else
	{
		person = 'X';
	}
}
bool tictactoe::winlose()
{
	//conditions for first player
	if (ticarray[0][0] == 'X' && ticarray[0][1] == 'X' && ticarray[0][2] == 'X')  //row
		return true;
	if (ticarray[1][0] == 'X' && ticarray[1][1] == 'X' && ticarray[1][2] == 'X')
		return true;
	if (ticarray[2][0] == 'X' && ticarray[2][1] == 'X' && ticarray[2][2] == 'X')
		return true;

	if (ticarray[0][0] == 'X' && ticarray[1][0] == 'X' && ticarray[2][0] == 'X') //col
		return true;
	if (ticarray[0][1] == 'X' && ticarray[1][1] == 'X' && ticarray[2][1] == 'X')
		return true;
	if (ticarray[0][2] == 'X' && ticarray[1][2] == 'X' && ticarray[2][2] == 'X')
		return true;

	if (ticarray[0][0] == 'X' && ticarray[1][1] == 'X' && ticarray[2][2] == 'X') //diagonal
		return true;
	if (ticarray[2][0] == 'X' && ticarray[1][1] == 'X' && ticarray[0][2] == 'X')
		return true;

	//conditions for second player
	if (ticarray[0][0] == 'Y' && ticarray[0][1] == 'Y' && ticarray[0][2] == 'Y')
		return false;
	if (ticarray[1][0] == 'Y' && ticarray[1][1] == 'Y' && ticarray[1][2] == 'Y')
		return false;
	if (ticarray[2][0] == 'Y' && ticarray[2][1] == 'Y' && ticarray[2][2] == 'Y')
		return false;

	if (ticarray[0][0] == 'Y' && ticarray[1][0] == 'Y' && ticarray[2][0] == 'Y')
		return false;
	if (ticarray[0][1] == 'Y' && ticarray[1][1] == 'Y' && ticarray[2][1] == 'Y')
		return false;
	if (ticarray[0][2] == 'Y' && ticarray[1][2] == 'Y' && ticarray[2][2] == 'Y')
		return false;

	if (ticarray[0][0] == 'Y' && ticarray[1][1] == 'Y' && ticarray[2][2] == 'Y')
		return false;
	if (ticarray[2][0] == 'Y' && ticarray[1][1] == 'Y' && ticarray[0][2] == 'Y')
		return false;

}
void tictactoe::checkwin()
{
loop3:
	int count = 0;
	while (true)
	{
		count++;
		draw();
		turn();
		if (winlose() == 1)
		{
			cout << "PLAYER ONE WINS!!!";
			break;
		}
		else if (winlose() == 0)
		{
			cout << "PLAYER TWO WINS!!!";
			break;
		}
		else if (count == 9 && winlose() != 0 && winlose() != 1)  // condition for draw
		{
			cout << "Match is drawn!!" << endl;
			int choi = 0;
		loop4:
			cout << endl;
			cout << "enter choice=  1) Play again   2)quit  ";  //logic for play again
			cout << endl;
			cin >> choi;
			switch (choi)
			{
			case 1:
			{
				ticarray[0][0] = '1';  //will reset the board
				ticarray[0][1] = '2';
				ticarray[0][2] = '3';
				ticarray[1][0] = '4';
				ticarray[1][1] = '5';
				ticarray[1][2] = '6';
				ticarray[2][0] = '7';
				ticarray[2][1] = '8';
				ticarray[2][2] = '9';
				goto loop3;  //call function again
			}
			case 2:
			{
				break; //this break will take you out of the loop
			}
			default:
			{
				cout << "enter values from above only=";
				goto loop4;
			}
			}
			break; //this break will exit program

		}
		changeplayer();

	}

}
int main()
{
	char b[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };  //3 *3 char array
	tictactoe obj(b);
	obj.checkwin();
	system("pause");

}
