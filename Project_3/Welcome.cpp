#include "pch.h"
#include "Welcome.h"
#include <iostream>

using namespace std;


Welcome::Welcome()
{
}


Welcome::~Welcome()
{
}

void Welcome::Greetings()
{
	cout << "Welcome to the Battle Field!" << endl;

	cout << endl;
	system("pause");

	StartGame();

}

void Welcome::StartGame()
{
	system("cls");

	cout << "Two player game." << endl;
	cout << "Each player will have a Warrior, Archer, and a Sorcerer." << endl;
	cout << "On a 6x6 grid the characters can attack the opponent when in range." << endl;
	cout << "Warrior attack range is 1" << endl;
	cout << "Archer attack range is 4" << endl;
	cout << "Sorcerer attack range is 2" << endl;
	cout << endl;

	cout << "Warrior has a random attack from 7 to 14" << endl;
	cout << "Archer has a random attack from 2 to 7" << endl;
	cout << "Sorcerer has a random attack from 1 to 10" << endl;

	cout << endl;
	cout << "Players character turn will always begin in random order." << endl;
	cout << "Use the arrow keys to move player character." << endl;
	cout << "If you are able to move(character not blocked in), you also have the option to not move if you wish." << endl;
	cout << "If your character is not allowed to move or attack, that turn will be forfeited." << endl;
	cout << "Player with his three characters dead first loses." << endl;

	cout << endl;
	system("pause");

	Game game;

	game.RealTimeUpdates();
}
