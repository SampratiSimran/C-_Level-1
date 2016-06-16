// ----------------------------------------------------------------------------
//
// ----------------------------- Let's Make A Deal ----------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose  : To analyze Let's Make A Deal show using this program and find if the player should change his choice of door or not.
//
//  Author   : Chetan Kumar Parakh
//  Date     : 1/18/2016
//
// ----------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

void setupDoors(char &door1, char &door2, char &door3);
void pickDoorChoices(char door1, char door2, char door3, int&doorPlayer, int &doorMonty);
void checkstrategy(char door1, char door2, char door3, int&doorPlayer, int&strategy2, int&strategy1);

int main()
{	
	int seed = static_cast<int>(time(0));
	srand(seed);
	char door1, door2, door3;
	int doorPlayer, doorMonty;
	int strategy1 = 0, strategy2 = 0, total=10000;
	float strategy1_percent, strategy2_percent;

	for (int i = 0; i < total; i++)
	{
		setupDoors(door1, door2, door3);
		pickDoorChoices(door1, door2, door3, doorPlayer, doorMonty);
		checkstrategy(door1, door2, door3, doorPlayer, strategy2, strategy1);
	}

	strategy1_percent = ((float) strategy1 / (float) total)*100;
	strategy2_percent = ((float) strategy2 / (float)total) * 100;

	cout << fixed << setprecision(2);
	cout << "Number of wins if the player changes his choice: " << strategy1 << endl;
	cout << "Number of wins if the player does not change his choice: " << strategy2 << endl;
	cout << "Percentage of win if the player changes his choice: " << strategy1_percent << "%" << endl;
	cout << "Percentage of win if the player does not changes his choice: " << strategy2_percent << "%" << endl;

	if (strategy1 > strategy2)
	{
		cout << "Player should change the door" << endl;
	}
	else
	{
		cout << "Player should not change the door" << endl;
	}
	return(0);
}


// To assign which door should have car behind it and which 2 doors should have goat behind it.
void setupDoors(char &door1, char &door2, char &door3)
{
	int a;
	a = rand() % 3;
	a = a + 1;

	switch (a)
	{
	case 1: door1 = 'C';
		door2 = 'G';
		door3 = 'G';
		break;
	case 2: door1 = 'G';
		door2 = 'C';
		door3 = 'G';
		break;
	case 3: door1 = 'G';
		door2 = 'G';
		door3 = 'C';
		break;
	default:
		break;
	}
}

// To assign which door the player chooses and which door the Monty should show first.
void pickDoorChoices(char door1, char door2, char door3, int &doorPlayer, int &doorMonty)
{
	int a;
	a = rand() % 3;

	doorPlayer = a+1;


	if (doorPlayer == 1)
	{
		doorMonty = 2;
		if (door2 == 'C')
		{
			doorMonty = 3;
		}
	}
	else if (doorPlayer == 2)
	{
		doorMonty = 1;
		if (door1 == 'C')
		{
			doorMonty = 3;
		}
	}
	else
	{
		doorMonty = 1;
		if (door1 == 'C')
		{
			doorMonty = 2;
		}
	}
}

// To check if the player wins when he/ she changes his/ her choice or when he/ she does not change his/ her choice.
void checkstrategy(char door1, char door2, char door3, int&doorPlayer, int&strategy2, int&strategy1)
{

	if (doorPlayer == 1)
	{
		if (door1 == 'C')
		{
			strategy2++;
		}
		else
		{
			strategy1++;
		}
	}
	else if (doorPlayer == 2)
	{
		if (door2 == 'C')
		{
			strategy2++;
		}
		else
		{
			strategy1++;
		}
	}
	else if (doorPlayer == 3)
	{
		if (door3 == 'C')
		{
			strategy2++;
		}
		else
		{
			strategy1++;
		}
	}
}