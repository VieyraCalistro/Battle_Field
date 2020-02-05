#include "pch.h"
#include "Team1.h"
#include <iostream>

using namespace std;


Team1::Team1()
{
	// Initiate player characters, character's position, alive status, and health.
	SetA('A');
	SetS('S');
	SetW('W');
	SetAhealth(20);
	SetShealth(20);
	SetWhealth(20);
	AxPos = 0;
	WxPos = 1;
	SxPos = 0;
	AyPos = 0;
	WyPos = 0;
	SyPos = 1;
}


Team1::~Team1()
{
}


char Team1::GetW()
{
	// Return the character as requested.
	return W;
}

void Team1::SetW(char W)
{
	// Prevent the user from changine the players character.
	if (W != 'W' && W != 'D')
	{
		cout << "This must be set to W only, or D if dead." << endl;
		cout << endl;
		system("pause");
	}
	else
	{
		this->W = W;
	}
}

char Team1::GetA()
{
	// Return the character as requested.
	return A;
}

void Team1::SetA(char A)
{
	// Prevent the user from changine the players character.
	if (A != 'A' && A != 'D')
	{
		cout << "This must be set to A only, or D if dead." << endl;
		cout << endl;
		system("pause");
	}
	else
	{
		this->A = A;
	}
}

char Team1::GetS()
{
	// Return the character as requested.
	return S;
}

void Team1::SetS(char S)
{
	// Prevent the user from changine the players character.
	if (S != 'S' && S != 'D')
	{
		cout << "This must be set to S only, or D if dead." << endl;
		cout << endl;
		system("pause");
	}
	else
	{
		this->S = S;
	}
}

unsigned int Team1::GetAhealth()
{
	// Return the health of the archer.
	return Ahealth;
}

void Team1::SetAhealth(int Ahealth)
{
	// Assign a variable of the max possible health.
	int MaxHealthPossible = 20;

	//Assign a variable of minimum possible health value.
	int MinHealthValue = 1;

	if (Ahealth < MinHealthValue)// Prevent from printing out anything lower than a 0 for health.
	{
		this->Ahealth = 0;
		SetA('D');
	}
	else if (Ahealth <= MaxHealthPossible)// Prevent the user from setting a health higher than the max health possible.
	{
		this->Ahealth = Ahealth;
	}
	else
	{
		cout << "Max health possible is 20" << endl;
		cout << endl;
		system("pause");
	}
	
}

unsigned int Team1::GetWhealth()
{
	// Return the health of the warrior.
	return Whealth;
}

void Team1::SetWhealth(int Whealth)
{
	// Assign a variable of the max possible health.
	int MaxHealthPossible = 20;

	//Assign a variable of minimum possible health value.
	int MinHealthValue = 1;

	if (Whealth < MinHealthValue)// Prevent from printing out anything lower than a 0 for health.
	{
		this->Whealth = 0;
		SetW('D');
	}
	else if (Whealth <= MaxHealthPossible)// Prevent the user from setting a health higher than the max health possible.
	{
		this->Whealth = Whealth;
	}
	else
	{
		cout << "Max health possible is 20" << endl;
		cout << endl;
		system("pause");
	}
}

unsigned int Team1::GetShealth()
{
	// Return the health of the sourcerer.
	return Shealth;
}

void Team1::SetShealth(int Shealth)
{
	// Assign a variable of the max possible health.
	int MaxHealthPossible = 20;

	//Assign a variable of minimum possible health value.
	int MinHealthValue = 1;

	if (Shealth < MinHealthValue)// Prevent from printing out anything lower than a 0 for health.
	{
		this->Shealth = 0;
		SetS('D');
	}
	else if (Shealth <= MaxHealthPossible)// Prevent the user from setting a health higher than the max health possible.
	{
		this->Shealth = Shealth;
	}
	else
	{
		cout << "Max health possible is 20" << endl;
		cout << endl;
		system("pause");
	}
}

int Team1::GetAxPos()
{
	// Return archer x position.
	return AxPos;
}

void Team1::SetAxPos(int AnewXPos)
{
	// Set x position boundries for archer.
	if (AnewXPos > 5)
	{
		AnewXPos = 5;
	}
	else if (AnewXPos < 0)
	{
		AnewXPos = 0;
	}
	else
	{
		AxPos = AnewXPos;
	}

	
}

int Team1::GetWxPos()
{
	// Return warrior x position.
	return WxPos;
}

void Team1::SetWxPos(int WnewXPos)
{
	// Set x position boundries for warrior.
	if (WnewXPos > 5)
	{
		WnewXPos = 5;
	}
	else if (WnewXPos < 0)
	{
		WnewXPos = 0;
	}
	else
	{
		WxPos = WnewXPos;
	}

	
}

int Team1::GetSxPos()
{
	// Return sorcerer x position.
	return SxPos;
}

void Team1::SetSxPos(int SnewXPos)
{
	// Set x position boundries for sorcerer.
	if (SnewXPos > 5)
	{
		SnewXPos = 5;
	}
	else if (SnewXPos < 0)
	{
		SnewXPos = 0;
	}
	else
	{
		SxPos = SnewXPos;
	}

	
}

int Team1::GetAyPos()
{
	// Return archer y position.
	return AyPos;
}

void Team1::SetAyPos(int AnewYPos)
{
	// Set y position boundries for archer.
	if (AnewYPos > 5)
	{
		AnewYPos = 5;
	}
	else if (AnewYPos < 0)
	{
		AnewYPos = 0;
	}
	else
	{
		AyPos = AnewYPos;
	}

	
}

int Team1::GetWyPos()
{
	// Return warrior y position.
	return WyPos;
}

void Team1::SetWyPos(int WnewYPos)
{
	// Set y position boundries for warrior
	if (WnewYPos > 5)
	{
		WnewYPos = 5;
	}
	else if (WnewYPos < 0)
	{
		WnewYPos = 0;
	}
	else
	{
		WyPos = WnewYPos;
	}

	
}

int Team1::GetSyPos()
{
	// Return sorcerer y position.
	return SyPos;
}

void Team1::SetSyPos(int SnewYPos)
{
	// Set y position boundries for sorcerer.
	if (SnewYPos > 5)
	{
		SnewYPos = 5;
	}
	else if (SnewYPos < 0)
	{
		SnewYPos = 0;
	}
	else
	{
		SyPos = SnewYPos;
	}

	
}

