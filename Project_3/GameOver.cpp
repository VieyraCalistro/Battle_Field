#include "pch.h"
#include "GameOver.h"
#include <iostream>
#include "Welcome.h"

using namespace std;

GameOver::GameOver()
{
}


GameOver::~GameOver()
{
}

void GameOver::PlayAgainOption()
{
	int playAgainOrNot;

	while (true)
	{
		cout << "Would you like to play again? " << endl;
		cout << endl;
		cout << "1) Yes" << endl;
		cout << "2) No" << endl;
		cout << endl;
		cout << "Choice? ";
		cin >> playAgainOrNot;
		cout << endl;

		if (cin.good())
		{
			if (playAgainOrNot < 1 || playAgainOrNot > 2)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');

				cout << "Only numbers 1 or 2 are valid." << endl;
				cout << endl;
				system("pause");
				continue;
			}

			if (playAgainOrNot == 2)
			{
				cout << "Thank you for playing, Goodbye." << endl;
				cout << endl;
				system("pause");
				exit(0);
			}
			else if (playAgainOrNot == 1)
			{
				system("cls");

				Welcome StartOver;

				StartOver.Greetings();
			}
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << "Only numbers 1 or 2 are valid." << endl;
		cout << endl;
		system("pause");

	}
	


}
