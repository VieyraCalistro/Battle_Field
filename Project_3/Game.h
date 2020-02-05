#pragma once
#include "BattleField.h"
#include <Windows.h>


class Game
{
public:

	struct Collision
	{
		bool up = false;
		bool down = false;
		bool left = false;
		bool right = false;

	};

	struct Attack
	{
		// List booleans to tell you who you can attack if in fact you can attack.
		bool A_attack_w = false;
		bool A_attack_a = false;
		bool A_attack_s = false;

		bool a_attack_W = false;
		bool a_attack_S = false;
		bool a_attack_A = false;

		bool S_attack_w = false;
		bool S_attack_s = false;
		bool S_attack_a = false;

		bool s_attack_S = false;
		bool s_attack_A = false;
		bool s_attack_W = false;

		bool W_attack_a = false;
		bool W_attack_w = false;
		bool W_attack_s = false;

		bool w_attack_W = false;
		bool w_attack_S = false;
		bool w_attack_A = false;

	};

	Game();
	~Game();

	void update();

	void Render();

	// Set and create a HANDLE for cursor.
	CONSOLE_CURSOR_INFO cursorInfo;
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	// Give the X and Y position for the cursor.
	COORD cursorPosition;

	void RealTimeUpdates();

	void RandomizeTurns();

	int GetCharacterNumberTurn();
	void SetCharacterNumberTurn(int nextCharacter);

	void CheckCollision(int character);

	void ResetCollision();

	void AttackOption();

	void CalculateRangePossibleAttack();

	void ResetRangePossibleAttack();

	int RandomizeWarriorAttackSeverity();

	int RandomizeArcherAttackSeverity();

	int RandomizeSorcererAttackSeverity();

	void WouldYouLikeToMove();

	void CheckIfGameIsOver();

	
	

private:

	BattleField gameBattlefield;

	Collision crash;

	Attack attack;

	bool play = true;

	int uniqueArray[6];

	int characterNumberTurn = 0;

	bool render = true;

	bool Update = false;

	int updatePrintOnce = 0;

	bool WantToMove = false;
};

