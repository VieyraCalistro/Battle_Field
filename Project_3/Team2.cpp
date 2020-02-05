#include "pch.h"
#include "Team2.h"
#include <iostream>

using namespace std;


Team2::Team2()
{
	// Initiate player characters, character's position, alive status, and health.
	Seta('a');
	Sets('s');
	Setw('w');
	SetaHealth(20);
	SetsHealth(20);
	SetwHealth(20);
	aXPos = 5;
	wXPos = 4;
	sXPos = 5;
	aYPos = 5;
	wYPos = 5;
	sYPos = 4;
}


Team2::~Team2()
{
}

char Team2::Getw()
{
	// Return the character as requested.
	return w;
}

void Team2::Setw(char w)
{
	// Prevent the user from changine the players character.
	if (w != 'w' && w != 'd')
	{
		cout << "This must be set to w only, or d if dead." << endl;
		cout << endl;
		system("pause");
	}
	else
	{
		this->w = w;
	}

}

char Team2::Geta()
{
	// Return the character as requested.
	return a;
}

void Team2::Seta(char a)
{
	// Prevent the user from changine the players character.
	if (a != 'a' && a != 'd')
	{
		cout << "This must be set to a only, or d if dead." << endl;
		cout << endl;
		system("pause");
	}
	else
	{
		this->a = a;
	}
}

char Team2::Gets()
{
	// Return the character as requested.
	return s;
}

void Team2::Sets(char s)
{
	// Prevent the user from changine the players character.
	if (s != 's' && s != 'd')
	{
		cout << "This must be set to s only, or d if dead." << endl;
		cout << endl;
		system("pause");
	}
	else
	{
		this->s = s;
	}
}

unsigned int Team2::GetaHealth()
{
	// Return the health of the archer.
	return aHealth;
}

void Team2::SetaHealth(int aHealth)
{
	// Assign a variable of the max possible health.
	int MaxHealthPossible = 20;

	//Assign a variable of minimum possible health value.
	int MinHealthValue = 1;

	if (aHealth < MinHealthValue)// Prevent from printing out anything lower than a 0 for health.
	{
		this->aHealth = 0;
		Seta('d');
	}
	else if (aHealth <= MaxHealthPossible)// Prevent the user from setting a health higher than the max health possible.
	{
		this->aHealth = aHealth;
	}
	else
	{
		cout << "Max health possible is 20" << endl;
		cout << endl;
		system("pause");
	}
}

unsigned int Team2::GetwHealth()
{
	// Return the health of the warrior.
	return wHealth;
}

void Team2::SetwHealth(int wHealth)
{
	// Assign a variable of the max possible health.
	int MaxHealthPossible = 20;

	//Assign a variable of minimum possible health value.
	int MinHealthValue = 1;

	if (wHealth < MinHealthValue)// Prevent from printing out anything lower than a 0 for health.
	{
		this->wHealth = 0;
		Setw('d');
	}
	else if (wHealth <= MaxHealthPossible)// Prevent the user from setting a health higher than the max health possible.
	{
		this->wHealth = wHealth;
	}
	else
	{
		cout << "Max health possible is 20" << endl;
		cout << endl;
		system("pause");
	}
}

unsigned int Team2::GetsHealth()
{
	// Return the health of the sorcerer.
	return sHealth;
}

void Team2::SetsHealth(int sHealth)
{
	// Assign a variable of the max possible health.
	int MaxHealthPossible = 20;

	//Assign a variable of minimum possible health value.
	int MinHealthValue = 1;

	if (sHealth < MinHealthValue)// Prevent from printing out anything lower than a 0 for health.
	{
		this->sHealth = 0;
		Sets('d');
	}
	else if (sHealth <= MaxHealthPossible)// Prevent the user from setting a health higher than the max health possible.
	{
		this->sHealth = sHealth;
	}
	else
	{
		cout << "Max health possible is 20" << endl;
		cout << endl;
		system("pause");
	}
}

int Team2::GetaXPos()
{
	// Return archer x position.
	return aXPos;
}

void Team2::SetaXPos(int aNewXPos)
{
	// Set x position boundries for archer.
	if (aNewXPos > 5)
	{
		aNewXPos = 5;
	}
	else if (aNewXPos < 0)
	{
		aNewXPos = 0;
	}
	else
	{
		aXPos = aNewXPos;
	}

	
}

int Team2::GetwXPos()
{
	// Return warrior x position.
	return wXPos;
}

void Team2::SetwXPos(int wNewXPos)
{
	// Set x position boundries for warrior.
	if (wNewXPos > 5)
	{
		wNewXPos = 5;
	}
	else if (wNewXPos < 0)
	{
		wXPos = 0;
	}
	else
	{
		wXPos = wNewXPos;
	}
	
}

int Team2::GetsXPos()
{
	// Return sorcerer x position.
	return sXPos;
}

void Team2::SetsXPos(int sNewXPos)
{
	// Set x position boundries for sorcerer.
	if (sNewXPos > 5)
	{
		sNewXPos = 5;
	}
	else if (sNewXPos < 0)
	{
		sNewXPos = 0;
	}
	else
	{
		sXPos = sNewXPos;
	}
	
}

int Team2::GetaYPos()
{
	// Return archer y position.
	return aYPos;
}

void Team2::SetaYPos(int aNewYPos)
{
	// Set y position boundries for archer.
	if (aNewYPos > 5)
	{
		aNewYPos = 5;
	}
	else if (aNewYPos < 0)
	{
		aNewYPos = 0;
	}
	else
	{
		aYPos = aNewYPos;
	}
	
}

int Team2::GetwYPos()
{
	// Return warrior y position.
	return wYPos;
}

void Team2::SetwYPos(int wNewYPos)
{
	// Set y position boundries for warrior.
	if (wNewYPos > 5)
	{
		wNewYPos = 5;
	}
	else if (wNewYPos < 0)
	{
		wNewYPos = 0;
	}
	else
	{
		wYPos = wNewYPos;
	}
	
}

int Team2::GetsYPos()
{
	// Return sorcerer y position.
	return sYPos;
}

void Team2::SetsYPos(int sNewYPos)
{
	// Set y position boundries for sorcerer.
	if (sNewYPos > 5)
	{
		sNewYPos = 5;
	}
	else if (sNewYPos < 0)
	{
		sNewYPos = 0;
	}
	else
	{
		sYPos = sNewYPos;
	}
	
}
