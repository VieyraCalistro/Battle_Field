#include "pch.h"
#include "BattleField.h"
#include <iostream>


using namespace std;


BattleField::BattleField()
{
	// Assign the midfield x and y positions.
	midFieldXpos = 2;
	midFieldYpos = 2;


}


BattleField::~BattleField()
{
}

void BattleField::Field()
{

	// Char to represent an empty space.
	char emptySpace = '*';

	// Create an integer for battlefield width.
	int battlefieldWidth = 6;

	// Create an integer for battelfield height.
	int battlefieldHeight = 6;


	// Create the empty spaces between the teams.
	for (int index = 0; index < battlefieldHeight; ++index)
	{
		cout.width(battlefieldWidth);
		cout.fill(emptySpace);
		cout << "" << endl;
	}

}


int BattleField::GetEndOfFieldXpos()
{
	// Return the end of field on the x position.
	return endOfFieldXpos;
}


int BattleField::GetEndoOfFieldYpos()
{
	// Return the end of field on the y position.
	return endOfFieldYpos;
}



int BattleField::GetMidFieldXpos()
{
	// Return the current x position of the mid field.
	return midFieldXpos;
}

int BattleField::GetMidFieldYpos()
{
	// Return the current y position of the mid field.
	return midFieldYpos;
}
