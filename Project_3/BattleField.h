#pragma once
#include "Team1.h"
#include "Team2.h"


class BattleField
{
public:
	BattleField();
	~BattleField();

	void Field();

	Team1 team1;

	Team2 team2;

	int GetEndOfFieldXpos();

	int GetEndoOfFieldYpos();

	int GetMidFieldXpos();

	int GetMidFieldYpos();

private:

	int midFieldXpos;
	int midFieldYpos;

	int endOfFieldXpos = 0;
	int endOfFieldYpos = 7;

};