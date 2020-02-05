#include "pch.h"
#include "Game.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <ctime>
#include "GameOver.h"


using namespace std;


Game::Game()
{
	RandomizeTurns();
}


Game::~Game()
{
}

void Game::update()
{
	
	// CHeck the possibility of collision.
	CheckCollision(uniqueArray[characterNumberTurn]);

	// Clear screen and update once here.
	if (updatePrintOnce < 1)
	{
		system("cls");
		render = true;
		Render();
		updatePrintOnce++;
	}
	

	switch (uniqueArray[characterNumberTurn])
	{

		case 0:

			if (gameBattlefield.team1.GetAhealth() > 1)
			{

				// 1 - get user input
				if (_kbhit())
				{
					char ch = _getch();

					// Down arrow key pressed.
					if (ch == 80)
					{
						if (crash.down == false)
						{
							
							gameBattlefield.team1.SetAyPos(gameBattlefield.team1.GetAyPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.A_attack_w == true || attack.A_attack_a == true || attack.A_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();
						}


					}

					// Up arrow pressed.
					if (ch == 72)
					{
						if (crash.up == false)
						{
							
							gameBattlefield.team1.SetAyPos(gameBattlefield.team1.GetAyPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.A_attack_w == true || attack.A_attack_a == true || attack.A_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Left arrow key.
					if (ch == 75)
					{
						if (crash.left == false)
						{
							
							gameBattlefield.team1.SetAxPos(gameBattlefield.team1.GetAxPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.A_attack_w == true || attack.A_attack_a == true || attack.A_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}

					}

					// Right arrow key.
					if (ch == 77)
					{
						if (crash.right == false)
						{
							
							gameBattlefield.team1.SetAxPos(gameBattlefield.team1.GetAxPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.A_attack_w == true || attack.A_attack_a == true || attack.A_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}

					}

				}

				break;
			}
			else
			{
				SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
				Sleep(30);
				render = true;
				Render();
			}


		case 1:

			if (gameBattlefield.team2.GetaHealth() > 1)
			{

				// 1 - get user input
				if (_kbhit())
				{
					char ch = _getch();

					// Down arrow key pressed.
					if (ch == 80)
					{
						if (crash.down == false)
						{
							
							gameBattlefield.team2.SetaYPos(gameBattlefield.team2.GetaYPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.a_attack_W == true || attack.a_attack_A == true || attack.a_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}

					}

					// Up arrow pressed.
					if (ch == 72)
					{
						if (crash.up == false)
						{
							
							gameBattlefield.team2.SetaYPos(gameBattlefield.team2.GetaYPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.a_attack_W == true || attack.a_attack_A == true || attack.a_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Left arrow key.
					if (ch == 75)
					{
						if (crash.left == false)
						{
							
							gameBattlefield.team2.SetaXPos(gameBattlefield.team2.GetaXPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.a_attack_W == true || attack.a_attack_A == true || attack.a_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Right arrow key.
					if (ch == 77)
					{
						if (crash.right == false)
						{
							
							gameBattlefield.team2.SetaXPos(gameBattlefield.team2.GetaXPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.a_attack_W == true || attack.a_attack_A == true || attack.a_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}
				}

				break;
			}
			else
			{
				SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
				Sleep(30);
				render = true;
				Render();
			}

		case 2:

			if (gameBattlefield.team1.GetShealth() > 1)
			{

				// 1 - get user input
				if (_kbhit())
				{
					char ch = _getch();

					// Down arrow key pressed.
					if (ch == 80)
					{
						if (crash.down == false)
						{
							
							gameBattlefield.team1.SetSyPos(gameBattlefield.team1.GetSyPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.S_attack_w == true || attack.S_attack_a == true || attack.S_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Up arrow pressed.
					if (ch == 72)
					{
						if (crash.up == false)
						{
							
							gameBattlefield.team1.SetSyPos(gameBattlefield.team1.GetSyPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.S_attack_w == true || attack.S_attack_a == true || attack.S_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}

					}

					// Left arrow key.
					if (ch == 75)
					{
						if (crash.left == false)
						{
							
							gameBattlefield.team1.SetSxPos(gameBattlefield.team1.GetSxPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.S_attack_w == true || attack.S_attack_a == true || attack.S_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Right arrow key.
					if (ch == 77)
					{
						if (crash.right == false)
						{
							
							gameBattlefield.team1.SetSxPos(gameBattlefield.team1.GetSxPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.S_attack_w == true || attack.S_attack_a == true || attack.S_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}
				}

				break;
			}
			else
			{
				SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
				Sleep(30);
				render = true;
				Render();
			}

		case 3:

			if (gameBattlefield.team2.GetsHealth() > 1)
			{

				// 1 - get user input
				if (_kbhit())
				{
					char ch = _getch();

					// Down arrow key pressed.
					if (ch == 80)
					{
						if (crash.down == false)
						{
							
							gameBattlefield.team2.SetsYPos(gameBattlefield.team2.GetsYPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.s_attack_W == true || attack.s_attack_A == true || attack.s_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Up arrow pressed.
					if (ch == 72)
					{
						if (crash.up == false)
						{
							
							gameBattlefield.team2.SetsYPos(gameBattlefield.team2.GetsYPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.s_attack_W == true || attack.s_attack_A == true || attack.s_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Left arrow key.
					if (ch == 75)
					{
						if (crash.left == false)
						{
							
							gameBattlefield.team2.SetsXPos(gameBattlefield.team2.GetsXPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.s_attack_W == true || attack.s_attack_A == true || attack.s_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Right arrow key.
					if (ch == 77)
					{
						if (crash.right == false)
						{
							
							gameBattlefield.team2.SetsXPos(gameBattlefield.team2.GetsXPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.s_attack_W == true || attack.s_attack_A == true || attack.s_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}
				}

				break;
			}
			else
			{
				SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
				Sleep(30);
				render = true;
				Render();
			}

		case 4:

			if (gameBattlefield.team1.GetWhealth() > 1)
			{

				// 1 - get user input
				if (_kbhit())
				{
					char ch = _getch();

					// Down arrow key pressed.
					if (ch == 80)
					{
						if (crash.down == false)
						{
							
							gameBattlefield.team1.SetWyPos(gameBattlefield.team1.GetWyPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.W_attack_w == true || attack.W_attack_a == true || attack.W_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Up arrow pressed.
					if (ch == 72)
					{
						if (crash.up == false)
						{
							
							gameBattlefield.team1.SetWyPos(gameBattlefield.team1.GetWyPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.W_attack_w == true || attack.W_attack_a == true || attack.W_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Left arrow key.
					if (ch == 75)
					{
						if (crash.left == false)
						{
							
							gameBattlefield.team1.SetWxPos(gameBattlefield.team1.GetWxPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.W_attack_w == true || attack.W_attack_a == true || attack.W_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Right arrow key.
					if (ch == 77)
					{
						if (crash.right == false)
						{
							
							gameBattlefield.team1.SetWxPos(gameBattlefield.team1.GetWxPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.W_attack_w == true || attack.W_attack_a == true || attack.W_attack_s == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}
				}

				break;
			}
			else
			{
				SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
				Sleep(30);
				render = true;
				Render();
			}


		case 5:

			if (gameBattlefield.team2.GetwHealth() > 1)
			{

				// 1 - get user input
				if (_kbhit())
				{
					char ch = _getch();

					// Down arrow key pressed.
					if (ch == 80)
					{
						if (crash.down == false)
						{
							
							gameBattlefield.team2.SetwYPos(gameBattlefield.team2.GetwYPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.w_attack_W == true || attack.w_attack_A == true || attack.w_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Up arrow pressed.
					if (ch == 72)
					{
						if (crash.up == false)
						{
							
							gameBattlefield.team2.SetwYPos(gameBattlefield.team2.GetwYPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.w_attack_W == true || attack.w_attack_A == true || attack.w_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Left arrow key.
					if (ch == 75)
					{
						if (crash.left == false)
						{
							
							gameBattlefield.team2.SetwXPos(gameBattlefield.team2.GetwXPos() - 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.w_attack_W == true || attack.w_attack_A == true || attack.w_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}

					// Right arrow key.
					if (ch == 77)
					{
						if (crash.right == false)
						{
							
							gameBattlefield.team2.SetwXPos(gameBattlefield.team2.GetwXPos() + 1);

							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.w_attack_W == true || attack.w_attack_A == true || attack.w_attack_S == true)
							{
								render = true;
								WantToMove = false;
								Render();

								AttackOption();
								CheckIfGameIsOver();
							}
							SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
							Sleep(30);
							render = true;
							WantToMove = false;
							Update = false;
							RealTimeUpdates();

						}


					}
				}

				break;
			}
			else
			{
				SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
				Sleep(30);
				render = true;
				Render();
			}
	}
	
	
}

void Game::Render()
{
	system("cls");

	if (render == true)
	{
		// Reference a game battlefield to use.
		gameBattlefield.Field();

		// Hide the cursor.
		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(out, &cursorInfo);

		// Set the current position for team one's archer.
		cursorPosition = { (short)gameBattlefield.team1.GetAxPos(), (short)gameBattlefield.team1.GetAyPos() };
		SetConsoleCursorPosition(out, cursorPosition);


		/////////////Team 1.

		// Print out team one's archer.
		cout << gameBattlefield.team1.GetA();

		//Set the current position for team one's warrior.
		cursorPosition.X = gameBattlefield.team1.GetWxPos();
		cursorPosition.Y = gameBattlefield.team1.GetWyPos();
		SetConsoleCursorPosition(out, cursorPosition);


		// Print out team one's warrior.
		cout << gameBattlefield.team1.GetW();

		// Set the current position for team one's sorcerer.
		cursorPosition.X = gameBattlefield.team1.GetSxPos();
		cursorPosition.Y = gameBattlefield.team1.GetSyPos();
		SetConsoleCursorPosition(out, cursorPosition);

		// Print out team one's sorcerer.
		cout << gameBattlefield.team1.GetS();



		// Re-instate games's next current's position.
		cursorPosition.X = gameBattlefield.GetMidFieldXpos();
		cursorPosition.Y = gameBattlefield.GetMidFieldYpos();
		SetConsoleCursorPosition(out, cursorPosition);



		//////////Team 2.

		// Set team two's archer position.
		cursorPosition.X = gameBattlefield.team2.GetsXPos();
		cursorPosition.Y = gameBattlefield.team2.GetsYPos();
		SetConsoleCursorPosition(out, cursorPosition);

		// Print out team two's archer.
		cout << gameBattlefield.team2.Gets();

		//Set the current position for team two's warrior.
		cursorPosition.X = gameBattlefield.team2.GetwXPos();
		cursorPosition.Y = gameBattlefield.team2.GetwYPos();
		SetConsoleCursorPosition(out, cursorPosition);


		// Print out team two's warrior.
		cout << gameBattlefield.team2.Getw();

		// Set the current position for team two's sorcerer.
		cursorPosition.X = gameBattlefield.team2.GetaXPos();
		cursorPosition.Y = gameBattlefield.team2.GetaYPos();
		SetConsoleCursorPosition(out, cursorPosition);

		// Print out team two's sorcerer.
		cout << gameBattlefield.team2.Geta();



		// Re-instate games's next current's position.
		cursorPosition.X = gameBattlefield.GetEndOfFieldXpos();
		cursorPosition.Y = gameBattlefield.GetEndoOfFieldYpos();
		SetConsoleCursorPosition(out, cursorPosition);




		// Print out the players health stats.
		cout << endl;
		cout << "P1:  A:" << gameBattlefield.team1.GetAhealth() << ",  W:" << gameBattlefield.team1.GetWhealth() << ",  S:" << gameBattlefield.team1.GetShealth() << endl;
		cout << "P2:  a:" << gameBattlefield.team2.GetaHealth() << ",  w:" << gameBattlefield.team2.GetwHealth() << ",  s:" << gameBattlefield.team2.GetsHealth() << endl;


		// Re-instate games's next current's position.
		cursorPosition.X = 0;
		cursorPosition.Y = 11;
		SetConsoleCursorPosition(out, cursorPosition);

		// Set cursor to the side of field and print out turn order.
		cursorPosition.X = 18;
		cursorPosition.Y = 0;
		SetConsoleCursorPosition(out, cursorPosition);

		// Print out Turn order list.
		cout << "Turn Order" << endl;
		for (unsigned int index = 0; index < 6; index++)
		{
			cursorPosition.Y++;
			SetConsoleCursorPosition(out, cursorPosition);

			switch (uniqueArray[index])
			{
			case 0:
				if (gameBattlefield.team1.GetAhealth() >= 1)
				{
					cout << 'A' << endl;
				}
				break;
			case 1:
				if (gameBattlefield.team2.GetaHealth() >= 1)
				{
					cout << 'a' << endl;
				}
				break;
			case 2:
				if (gameBattlefield.team1.GetShealth() >= 1)
				{
					cout << 'S' << endl;
				}
				break;
			case 3:
				if (gameBattlefield.team2.GetsHealth() >= 1)
				{
					cout << 's' << endl;
				}
				break;
			case 4:
				if (gameBattlefield.team1.GetWhealth() >= 1)
				{
					cout << 'W' << endl;
				}
				break;
			case 5:
				if (gameBattlefield.team2.GetwHealth() >= 1)
				{
					cout << 'w' << endl;
				}
				break;
			}


		}

		// Re-instate games's next current's position.
		cursorPosition.X = 0;
		cursorPosition.Y = 11;
		SetConsoleCursorPosition(out, cursorPosition);


		// Print out directions for user when they choose to move.
		if (WantToMove == true)
		{
			CheckCollision(uniqueArray[characterNumberTurn]);

			cout << "\tCurrent Moving Options:" << endl;
			cout << "\tChoose One." << endl;
			cout << endl;

			if (crash.up == false)
			{
				cout << " UP arrow key to move up." << endl;
				cout << endl;
			}
			if (crash.down == false)
			{
				cout << " DOWN arrow key to move down." << endl;
				cout << endl;
			}
			if (crash.left == false)
			{
				cout << " LEFT arrow key to move left." << endl;
				cout << endl;
			}
			if (crash.right == false)
			{
				cout << " RIGHT arrow key to move right." << endl;
				cout << endl;
			}
		}

		// Sleep the system for some time to avoid flickering.
		Sleep(110);
	}

	render = false;
}
	

void Game::RealTimeUpdates()
{

	// Run game while play equals true.
	while (play == true)
	{

		if (Update == true)
		{
			while (true)
			{
				update();
			}
			
		}
		if (render == true)
		{
			Render();

		}
		WouldYouLikeToMove();

		CheckIfGameIsOver();
		
	}
}

void Game::RandomizeTurns()
{
	// Seed the random number.
	srand((unsigned int)time(0));

	// Create a variable for random number being generated.
	int roundTurnOrder;


	// Create an array of numbers that have already been visited.
	int visitedNumbers[6];

	// Create a counter to count the number of unique numbers being saved.
	int count = 0;

	// Assign all the numbers in the visited number array to 0.
	for (unsigned int index = 0; index < 6; ++index)
	{
		visitedNumbers[index] = 0;

	}

	// Loop through and exit once your unique array has all different values.
	while (count < 6)
	{
		// Give the random number a range.
		roundTurnOrder = rand() % 6;

		// If the current position is still 0, go ahead and assign the new generated random number.
		if (visitedNumbers[roundTurnOrder] == 0)
		{
			visitedNumbers[roundTurnOrder] = 1;

			uniqueArray[count] = roundTurnOrder;
			count++;
		}
	}


}

int Game::GetCharacterNumberTurn()
{
	// Return the character index who's turn it is to move.
	return characterNumberTurn;
}

void Game::SetCharacterNumberTurn(int nextCharacter)
{
	// Set boundaries for the number of different character turns.
	if (nextCharacter > 5 || nextCharacter < 0)
	{
		characterNumberTurn = 0;
	}
	else
	{
		characterNumberTurn = nextCharacter;
	}
}

void Game::CheckCollision(int character)
{
	ResetCollision();

	switch(character)
	{
		case 0:

			// Check team 1 character A for right possible crash.
			if (gameBattlefield.team1.GetAxPos() == 5)
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetAxPos() + 1 == gameBattlefield.team1.GetSxPos()) && (gameBattlefield.team1.GetAyPos() == gameBattlefield.team1.GetSyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetAxPos() + 1 == gameBattlefield.team1.GetWxPos()) && (gameBattlefield.team1.GetAyPos() == gameBattlefield.team1.GetWyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetAxPos() + 1 == gameBattlefield.team2.GetaXPos()) && (gameBattlefield.team1.GetAyPos() == gameBattlefield.team2.GetaYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetAxPos() + 1 == gameBattlefield.team2.GetsXPos()) && (gameBattlefield.team1.GetAyPos() == gameBattlefield.team2.GetsYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetAxPos() + 1 == gameBattlefield.team2.GetwXPos()) && (gameBattlefield.team1.GetAyPos() == gameBattlefield.team2.GetwYPos()))
			{
				crash.right = true;
			}


			// Check team 1's A for left possible crash.
			if (gameBattlefield.team1.GetAxPos() == 0)
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetAxPos() - 1 == gameBattlefield.team1.GetSxPos()) && (gameBattlefield.team1.GetAyPos() == gameBattlefield.team1.GetSyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetAxPos() - 1 == gameBattlefield.team1.GetWxPos()) && (gameBattlefield.team1.GetAyPos() == gameBattlefield.team1.GetWyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetAxPos() - 1 == gameBattlefield.team2.GetaXPos()) && (gameBattlefield.team1.GetAyPos() == gameBattlefield.team2.GetaYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetAxPos() - 1 == gameBattlefield.team2.GetsXPos()) && (gameBattlefield.team1.GetAyPos() == gameBattlefield.team2.GetsYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetAxPos() - 1 == gameBattlefield.team2.GetwXPos()) && (gameBattlefield.team1.GetAyPos() == gameBattlefield.team2.GetwYPos()))
			{
				crash.left= true;
			}


			// Check team 1's A for up possible crash.
			if (gameBattlefield.team1.GetAyPos() == 0)
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetAyPos() - 1 == gameBattlefield.team1.GetSyPos()) && (gameBattlefield.team1.GetAxPos() == gameBattlefield.team1.GetSxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetAyPos() - 1 == gameBattlefield.team1.GetWyPos()) && (gameBattlefield.team1.GetAxPos() == gameBattlefield.team1.GetWxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetAyPos() - 1 == gameBattlefield.team2.GetaYPos()) && (gameBattlefield.team1.GetAxPos() == gameBattlefield.team2.GetaXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetAyPos() - 1 == gameBattlefield.team2.GetsYPos()) && (gameBattlefield.team1.GetAxPos() == gameBattlefield.team2.GetsXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetAyPos() - 1 == gameBattlefield.team2.GetwYPos()) && (gameBattlefield.team1.GetAxPos() == gameBattlefield.team2.GetwXPos()))
			{
				crash.up = true;
			}


			// Check team 1's A for down possible crash.
			if (gameBattlefield.team1.GetAyPos() == 5)
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetAyPos() + 1 == gameBattlefield.team1.GetSyPos()) && (gameBattlefield.team1.GetAxPos() == gameBattlefield.team1.GetSxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetAyPos() + 1 == gameBattlefield.team1.GetWyPos()) && (gameBattlefield.team1.GetAxPos() == gameBattlefield.team1.GetWxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetAyPos() + 1 == gameBattlefield.team2.GetaYPos()) && (gameBattlefield.team1.GetAxPos() == gameBattlefield.team2.GetaXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetAyPos() + 1 == gameBattlefield.team2.GetsYPos()) && (gameBattlefield.team1.GetAxPos() == gameBattlefield.team2.GetsXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetAyPos() + 1 == gameBattlefield.team2.GetwYPos()) && (gameBattlefield.team1.GetAxPos() == gameBattlefield.team2.GetwXPos()))
			{
				crash.down = true;
			}
			break;

		case 1:

			// Check team 2 character a for right possible crash.
			if (gameBattlefield.team2.GetaXPos() == 5)
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetaXPos() + 1 == gameBattlefield.team1.GetSxPos()) && (gameBattlefield.team2.GetaYPos() == gameBattlefield.team1.GetSyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetaXPos() + 1 == gameBattlefield.team1.GetWxPos()) && (gameBattlefield.team2.GetaYPos() == gameBattlefield.team1.GetWyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetaXPos() + 1 == gameBattlefield.team1.GetAxPos()) && (gameBattlefield.team2.GetaYPos() == gameBattlefield.team1.GetAyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetaXPos() + 1 == gameBattlefield.team2.GetsXPos()) && (gameBattlefield.team2.GetaYPos() == gameBattlefield.team2.GetsYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetaXPos() + 1 == gameBattlefield.team2.GetwXPos()) && (gameBattlefield.team2.GetaYPos() == gameBattlefield.team2.GetwYPos()))
			{
				crash.right = true;
			}


			// Check team 2's a for left possible crash.
			if (gameBattlefield.team2.GetaXPos() == 0)
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetaXPos() - 1 == gameBattlefield.team1.GetSxPos()) && (gameBattlefield.team2.GetaYPos() == gameBattlefield.team1.GetSyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetaXPos() - 1 == gameBattlefield.team1.GetWxPos()) && (gameBattlefield.team2.GetaYPos() == gameBattlefield.team1.GetWyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetaXPos() - 1 == gameBattlefield.team1.GetAxPos()) && (gameBattlefield.team2.GetaYPos() == gameBattlefield.team1.GetAyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetaXPos() - 1 == gameBattlefield.team2.GetsXPos()) && (gameBattlefield.team2.GetaYPos() == gameBattlefield.team2.GetsYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetaXPos() - 1 == gameBattlefield.team2.GetwXPos()) && (gameBattlefield.team2.GetaYPos() == gameBattlefield.team2.GetwYPos()))
			{
				crash.left = true;
			}


			// Check team 2's a for up possible crash.
			if (gameBattlefield.team2.GetaYPos() == 0)
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetaYPos() - 1 == gameBattlefield.team1.GetSyPos()) && (gameBattlefield.team2.GetaXPos() == gameBattlefield.team1.GetSxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetaYPos() - 1 == gameBattlefield.team1.GetWyPos()) && (gameBattlefield.team2.GetaXPos() == gameBattlefield.team1.GetWxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetaYPos() - 1 == gameBattlefield.team1.GetAyPos()) && (gameBattlefield.team2.GetaXPos() == gameBattlefield.team1.GetAxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetaYPos() - 1 == gameBattlefield.team2.GetsYPos()) && (gameBattlefield.team2.GetaXPos() == gameBattlefield.team2.GetsXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetaYPos() - 1 == gameBattlefield.team2.GetwYPos()) && (gameBattlefield.team2.GetaXPos() == gameBattlefield.team2.GetwXPos()))
			{
				crash.up = true;
			}


			// Check team 2's a for down possible crash.
			if (gameBattlefield.team2.GetaYPos() == 5)
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetaYPos() + 1 == gameBattlefield.team1.GetSyPos()) && (gameBattlefield.team2.GetaXPos() == gameBattlefield.team1.GetSxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetaYPos() + 1 == gameBattlefield.team1.GetWyPos()) && (gameBattlefield.team2.GetaXPos() == gameBattlefield.team1.GetWxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetaYPos() + 1 == gameBattlefield.team1.GetAyPos()) && (gameBattlefield.team2.GetaXPos() == gameBattlefield.team1.GetAxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetaYPos() + 1 == gameBattlefield.team2.GetsYPos()) && (gameBattlefield.team2.GetaXPos() == gameBattlefield.team2.GetsXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetaYPos() + 1 == gameBattlefield.team2.GetwYPos()) && (gameBattlefield.team2.GetaXPos() == gameBattlefield.team2.GetwXPos()))
			{
				crash.down = true;
			}
			break;

		case 2:

			// Check team 1 character S for right possible crash.
			if (gameBattlefield.team1.GetSxPos() == 5)
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetSxPos() + 1 == gameBattlefield.team2.GetsXPos()) && (gameBattlefield.team1.GetSyPos() == gameBattlefield.team2.GetsYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetSxPos() + 1 == gameBattlefield.team1.GetWxPos()) && (gameBattlefield.team1.GetSyPos() == gameBattlefield.team1.GetWyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetSxPos() + 1 == gameBattlefield.team2.GetaXPos()) && (gameBattlefield.team1.GetSyPos() == gameBattlefield.team2.GetaYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetSxPos() + 1 == gameBattlefield.team1.GetAxPos()) && (gameBattlefield.team1.GetSyPos() == gameBattlefield.team1.GetAyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetSxPos() + 1 == gameBattlefield.team2.GetwXPos()) && (gameBattlefield.team1.GetSyPos() == gameBattlefield.team2.GetwYPos()))
			{
				crash.right = true;
			}


			// Check team 1's S for left possible crash.
			if (gameBattlefield.team1.GetSxPos() == 0)
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetSxPos() - 1 == gameBattlefield.team2.GetsXPos()) && (gameBattlefield.team1.GetSyPos() == gameBattlefield.team2.GetsYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetSxPos() - 1 == gameBattlefield.team1.GetWxPos()) && (gameBattlefield.team1.GetSyPos() == gameBattlefield.team1.GetWyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetSxPos() - 1 == gameBattlefield.team2.GetaXPos()) && (gameBattlefield.team1.GetSyPos() == gameBattlefield.team2.GetaYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetSxPos() - 1 == gameBattlefield.team1.GetAxPos()) && (gameBattlefield.team1.GetSyPos() == gameBattlefield.team1.GetAyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetSxPos() - 1 == gameBattlefield.team2.GetwXPos()) && (gameBattlefield.team1.GetSyPos() == gameBattlefield.team2.GetwYPos()))
			{
				crash.left = true;
			}


			// Check team 1's S for up possible crash.
			if (gameBattlefield.team1.GetSyPos() == 0)
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetSyPos() - 1 == gameBattlefield.team2.GetsYPos()) && (gameBattlefield.team1.GetSxPos() == gameBattlefield.team2.GetsXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetSyPos() - 1 == gameBattlefield.team1.GetWyPos()) && (gameBattlefield.team1.GetSxPos() == gameBattlefield.team1.GetWxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetSyPos() - 1 == gameBattlefield.team2.GetaYPos()) && (gameBattlefield.team1.GetSxPos() == gameBattlefield.team2.GetaXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetSyPos() - 1 == gameBattlefield.team1.GetAyPos()) && (gameBattlefield.team1.GetSxPos() == gameBattlefield.team1.GetAxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetSyPos() - 1 == gameBattlefield.team2.GetwYPos()) && (gameBattlefield.team1.GetSxPos() == gameBattlefield.team2.GetwXPos()))
			{
				crash.up = true;
			}


			// Check team 1's S for down possible crash.
			if (gameBattlefield.team1.GetSyPos() == 5)
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetSyPos() + 1 == gameBattlefield.team2.GetsYPos()) && (gameBattlefield.team1.GetSxPos() == gameBattlefield.team2.GetsXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetSyPos() + 1 == gameBattlefield.team1.GetWyPos()) && (gameBattlefield.team1.GetSxPos() == gameBattlefield.team1.GetWxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetSyPos() + 1 == gameBattlefield.team2.GetaYPos()) && (gameBattlefield.team1.GetSxPos() == gameBattlefield.team2.GetaXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetSyPos() + 1 == gameBattlefield.team1.GetAyPos()) && (gameBattlefield.team1.GetSxPos() == gameBattlefield.team1.GetAxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetSyPos() + 1 == gameBattlefield.team2.GetwYPos()) && (gameBattlefield.team1.GetSxPos() == gameBattlefield.team2.GetwXPos()))
			{
				crash.down = true;
			}
			break;
		case 3:

			// Check team 2 character s for right possible crash.
			if (gameBattlefield.team2.GetsXPos() == 5)
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetsXPos() + 1 == gameBattlefield.team1.GetSxPos()) && (gameBattlefield.team2.GetsYPos() == gameBattlefield.team1.GetSyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetsXPos() + 1 == gameBattlefield.team1.GetWxPos()) && (gameBattlefield.team2.GetsYPos() == gameBattlefield.team1.GetWyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetsXPos() + 1 == gameBattlefield.team2.GetaXPos()) && (gameBattlefield.team2.GetsYPos() == gameBattlefield.team2.GetaYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetsXPos() + 1 == gameBattlefield.team1.GetAxPos()) && (gameBattlefield.team2.GetsYPos() == gameBattlefield.team1.GetAyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetsXPos() + 1 == gameBattlefield.team2.GetwXPos()) && (gameBattlefield.team2.GetsYPos() == gameBattlefield.team2.GetwYPos()))
			{
				crash.right = true;
			}


			// Check team 2's s for left possible crash.
			if (gameBattlefield.team2.GetsXPos() == 0)
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetsXPos() - 1 == gameBattlefield.team1.GetSxPos()) && (gameBattlefield.team2.GetsYPos() == gameBattlefield.team1.GetSyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetsXPos() - 1 == gameBattlefield.team1.GetWxPos()) && (gameBattlefield.team2.GetsYPos() == gameBattlefield.team1.GetWyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetsXPos() - 1 == gameBattlefield.team2.GetaXPos()) && (gameBattlefield.team2.GetsYPos() == gameBattlefield.team2.GetaYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetsXPos() - 1 == gameBattlefield.team1.GetAxPos()) && (gameBattlefield.team2.GetsYPos() == gameBattlefield.team1.GetAyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetsXPos() - 1 == gameBattlefield.team2.GetwXPos()) && (gameBattlefield.team2.GetsYPos() == gameBattlefield.team2.GetwYPos()))
			{
				crash.left = true;
			}


			// Check team 2's s for up possible crash.
			if (gameBattlefield.team2.GetsYPos() == 0)
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetsYPos() - 1 == gameBattlefield.team1.GetSyPos()) && (gameBattlefield.team2.GetsXPos() == gameBattlefield.team1.GetSxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetsYPos() - 1 == gameBattlefield.team1.GetWyPos()) && (gameBattlefield.team2.GetsXPos() == gameBattlefield.team1.GetWxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetsYPos() - 1 == gameBattlefield.team2.GetaYPos()) && (gameBattlefield.team2.GetsXPos() == gameBattlefield.team2.GetaXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetsYPos() - 1 == gameBattlefield.team1.GetAyPos()) && (gameBattlefield.team2.GetsXPos() == gameBattlefield.team1.GetAxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetsYPos() - 1 == gameBattlefield.team2.GetwYPos()) && (gameBattlefield.team2.GetsXPos() == gameBattlefield.team2.GetwXPos()))
			{
				crash.up = true;
			}


			// Check team 2's s for down possible crash.
			if (gameBattlefield.team2.GetsYPos() == 5)
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetsYPos() + 1 == gameBattlefield.team1.GetSyPos()) && (gameBattlefield.team2.GetsXPos() == gameBattlefield.team1.GetSxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetsYPos() + 1 == gameBattlefield.team1.GetWyPos()) && (gameBattlefield.team2.GetsXPos() == gameBattlefield.team1.GetWxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetsYPos() + 1 == gameBattlefield.team2.GetaYPos()) && (gameBattlefield.team2.GetsXPos() == gameBattlefield.team2.GetaXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetsYPos() + 1 == gameBattlefield.team1.GetAyPos()) && (gameBattlefield.team2.GetsXPos() == gameBattlefield.team1.GetAxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetsYPos() + 1 == gameBattlefield.team2.GetwYPos()) && (gameBattlefield.team2.GetsXPos() == gameBattlefield.team2.GetwXPos()))
			{
				crash.down = true;
			}
			break;

		case 4:

			// Check team 1 character W for right possible crash.
			if (gameBattlefield.team1.GetWxPos() == 5)
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetWxPos() + 1 == gameBattlefield.team1.GetSxPos()) && (gameBattlefield.team1.GetWyPos() == gameBattlefield.team1.GetSyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetWxPos() + 1 == gameBattlefield.team2.GetwXPos()) && (gameBattlefield.team1.GetWyPos() == gameBattlefield.team2.GetwYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetWxPos() + 1 == gameBattlefield.team2.GetaXPos()) && (gameBattlefield.team1.GetWyPos() == gameBattlefield.team2.GetaYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetWxPos() + 1 == gameBattlefield.team2.GetsXPos()) && (gameBattlefield.team1.GetWyPos() == gameBattlefield.team2.GetsYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team1.GetWxPos() + 1 == gameBattlefield.team1.GetAxPos()) && (gameBattlefield.team1.GetWyPos() == gameBattlefield.team1.GetAyPos()))
			{
				crash.right = true;
			}


			// Check team 1's W for left possible crash.
			if (gameBattlefield.team1.GetWxPos() == 0)
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetWxPos() - 1 == gameBattlefield.team1.GetSxPos()) && (gameBattlefield.team1.GetWyPos() == gameBattlefield.team1.GetSyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetWxPos() - 1 == gameBattlefield.team2.GetwXPos()) && (gameBattlefield.team1.GetWyPos() == gameBattlefield.team2.GetwYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetWxPos() - 1 == gameBattlefield.team2.GetaXPos()) && (gameBattlefield.team1.GetWyPos() == gameBattlefield.team2.GetaYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetWxPos() - 1 == gameBattlefield.team2.GetsXPos()) && (gameBattlefield.team1.GetWyPos() == gameBattlefield.team2.GetsYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team1.GetWxPos() - 1 == gameBattlefield.team1.GetAxPos()) && (gameBattlefield.team1.GetWyPos() == gameBattlefield.team1.GetAyPos()))
			{
				crash.left = true;
			}


			// Check team 1's W for up possible crash.
			if (gameBattlefield.team1.GetWyPos() == 0)
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetWyPos() - 1 == gameBattlefield.team1.GetSyPos()) && (gameBattlefield.team1.GetWxPos() == gameBattlefield.team1.GetSxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetWyPos() - 1 == gameBattlefield.team2.GetwYPos()) && (gameBattlefield.team1.GetWxPos() == gameBattlefield.team2.GetwXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetWyPos() - 1 == gameBattlefield.team2.GetaYPos()) && (gameBattlefield.team1.GetWxPos() == gameBattlefield.team2.GetaXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetWyPos() - 1 == gameBattlefield.team2.GetsYPos()) && (gameBattlefield.team1.GetWxPos() == gameBattlefield.team2.GetsXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team1.GetWyPos() - 1 == gameBattlefield.team1.GetAyPos()) && (gameBattlefield.team1.GetWxPos() == gameBattlefield.team1.GetAxPos()))
			{
				crash.up = true;
			}


			// Check team 1's W for down possible crash.
			if (gameBattlefield.team1.GetWyPos() == 5)
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetWyPos() + 1 == gameBattlefield.team1.GetSyPos()) && (gameBattlefield.team1.GetWxPos() == gameBattlefield.team1.GetSxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetWyPos() + 1 == gameBattlefield.team2.GetwYPos()) && (gameBattlefield.team1.GetWxPos() == gameBattlefield.team2.GetwXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetWyPos() + 1 == gameBattlefield.team2.GetaYPos()) && (gameBattlefield.team1.GetWxPos() == gameBattlefield.team2.GetaXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetWyPos() + 1 == gameBattlefield.team2.GetsYPos()) && (gameBattlefield.team1.GetWxPos() == gameBattlefield.team2.GetsXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team1.GetWyPos() + 1 == gameBattlefield.team1.GetAyPos()) && (gameBattlefield.team1.GetWxPos() == gameBattlefield.team1.GetAxPos()))
			{
				crash.down = true;
			}
			break;
		case 5:

			// Check team 2 character w for right possible crash.
			if (gameBattlefield.team2.GetwXPos() == 5)
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetwXPos() + 1 == gameBattlefield.team1.GetSxPos()) && (gameBattlefield.team2.GetwYPos() == gameBattlefield.team1.GetSyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetwXPos() + 1 == gameBattlefield.team1.GetWxPos()) && (gameBattlefield.team2.GetwYPos() == gameBattlefield.team1.GetWyPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetwXPos() + 1 == gameBattlefield.team2.GetaXPos()) && (gameBattlefield.team2.GetwYPos() == gameBattlefield.team2.GetaYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetwXPos() + 1 == gameBattlefield.team2.GetsXPos()) && (gameBattlefield.team2.GetwYPos() == gameBattlefield.team2.GetsYPos()))
			{
				crash.right = true;
			}
			if ((gameBattlefield.team2.GetwXPos() + 1 == gameBattlefield.team1.GetAxPos()) && (gameBattlefield.team2.GetwYPos() == gameBattlefield.team1.GetAyPos()))
			{
				crash.right = true;
			}


			// Check team 2's w for left possible crash.
			if (gameBattlefield.team2.GetwXPos() == 0)
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetwXPos() - 1 == gameBattlefield.team1.GetSxPos()) && (gameBattlefield.team2.GetwYPos() == gameBattlefield.team1.GetSyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetwXPos() - 1 == gameBattlefield.team1.GetWxPos()) && (gameBattlefield.team2.GetwYPos() == gameBattlefield.team1.GetWyPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetwXPos() - 1 == gameBattlefield.team2.GetaXPos()) && (gameBattlefield.team2.GetwYPos() == gameBattlefield.team2.GetaYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetwXPos() - 1 == gameBattlefield.team2.GetsXPos()) && (gameBattlefield.team2.GetwYPos() == gameBattlefield.team2.GetsYPos()))
			{
				crash.left = true;
			}
			if ((gameBattlefield.team2.GetwXPos() - 1 == gameBattlefield.team1.GetAxPos()) && (gameBattlefield.team2.GetwYPos() == gameBattlefield.team1.GetAyPos()))
			{
				crash.left = true;
			}


			// Check team 2's w for up possible crash.
			if (gameBattlefield.team2.GetwYPos() == 0)
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetwYPos() - 1 == gameBattlefield.team1.GetSyPos()) && (gameBattlefield.team2.GetwXPos() == gameBattlefield.team1.GetSxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetwYPos() - 1 == gameBattlefield.team1.GetWyPos()) && (gameBattlefield.team2.GetwXPos() == gameBattlefield.team1.GetWxPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetwYPos() - 1 == gameBattlefield.team2.GetaYPos()) && (gameBattlefield.team2.GetwXPos() == gameBattlefield.team2.GetaXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetwYPos() - 1 == gameBattlefield.team2.GetsYPos()) && (gameBattlefield.team2.GetwXPos() == gameBattlefield.team2.GetsXPos()))
			{
				crash.up = true;
			}
			if ((gameBattlefield.team2.GetwYPos() - 1 == gameBattlefield.team1.GetAyPos()) && (gameBattlefield.team2.GetwXPos() == gameBattlefield.team1.GetAxPos()))
			{
				crash.up = true;
			}


			// Check team 2's w for down possible crash.
			if (gameBattlefield.team2.GetwYPos() == 5)
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetwYPos() + 1 == gameBattlefield.team1.GetSyPos()) && (gameBattlefield.team2.GetwXPos() == gameBattlefield.team1.GetSxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetwYPos() + 1 == gameBattlefield.team1.GetWyPos()) && (gameBattlefield.team2.GetwXPos() == gameBattlefield.team1.GetWxPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetwYPos() + 1 == gameBattlefield.team2.GetaYPos()) && (gameBattlefield.team2.GetwXPos() == gameBattlefield.team2.GetaXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetwYPos() + 1 == gameBattlefield.team2.GetsYPos()) && (gameBattlefield.team2.GetwXPos() == gameBattlefield.team2.GetsXPos()))
			{
				crash.down = true;
			}
			if ((gameBattlefield.team2.GetwYPos() + 1 == gameBattlefield.team1.GetAyPos()) && (gameBattlefield.team2.GetwXPos() == gameBattlefield.team1.GetAxPos()))
			{
				crash.down = true;
			}
			break;
	}

}

void Game::ResetCollision()
{
	crash.up = false;
	crash.down = false;
	crash.left = false;
	crash.right = false;

}


// Only give them this option if they can even attack.
void Game::AttackOption()
{
	// Create a varaible to hold the user's resposne.
	int attackOrNot;

	while (true)
	{
		render = true;
		Render();

		cout << endl;
		switch (uniqueArray[characterNumberTurn])
		{
		case 0:

			// Display characters avilable to attack.
			cout << "Available characters for A to attack: " << endl;
			if (attack.A_attack_a == true)
			{
				cout << "a" << endl;
			}
			if (attack.A_attack_w == true)
			{
				cout << "w" << endl;
			}
			if (attack.A_attack_s == true)
			{
				cout << "s" << endl;
			}
			break;
		case 1:

			// Display characters avilable to attack.
			cout << "Available characters for a to attack: " << endl;
			if (attack.a_attack_A == true)
			{
				cout << "A" << endl;
			}
			if (attack.a_attack_W == true)
			{
				cout << "W" << endl;
			}
			if (attack.a_attack_S == true)
			{
				cout << "S" << endl;
			}
			break;
		case 2:

			// Display characters avilable to attack.
			cout << "Available characters for S to attack: " << endl;
			if (attack.S_attack_a == true)
			{
				cout << "a" << endl;
			}
			if (attack.S_attack_w == true)
			{
				cout << "w" << endl;
			}
			if (attack.S_attack_s == true)
			{
				cout << "s" << endl;
			}
			break;
		case 3:

			// Display characters avilable to attack.
			cout << "Available characters for s to attack: " << endl;
			if (attack.s_attack_A == true)
			{
				cout << "A" << endl;
			}
			if (attack.s_attack_W == true)
			{
				cout << "W" << endl;
			}
			if (attack.s_attack_S == true)
			{
				cout << "S" << endl;
			}
			break;
		case 4:

			// Display characters avilable to attack.
			cout << "Available characters for W to attack: " << endl;
			if (attack.W_attack_a == true)
			{
				cout << "a" << endl;
			}
			if (attack.W_attack_w == true)
			{
				cout << "w" << endl;
			}
			if (attack.W_attack_s == true)
			{
				cout << "s" << endl;
			}
			break;
		case 5:

			// Display characters avilable to attack.
			cout << "Available characters for w to attack: " << endl;
			if (attack.w_attack_A == true)// && gameBattlefield.team1.GetAhealth() > 1)
			{
				cout << "A" << endl;
			}
			if (attack.w_attack_W == true)// && gameBattlefield.team1.GetWhealth() > 1)
			{
				cout << "W" << endl;
			}
			if (attack.w_attack_S == true)// && gameBattlefield.team1.GetShealth() > 1)
			{
				cout << "S" << endl;
			}
			break;
		}	

		// Ask the user if they would like to attack.
		cout << endl;
		cout << "Would you like to attack? " << endl;
		cout << "1) Yes or 2) No" << endl;
		cout << "Choice? ";
		cin >> attackOrNot;
		cout << endl;

		if (cin.good())
		{
			if (attackOrNot < 1 || attackOrNot > 2)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');

				cout << "Please only enter 1 or 2." << endl;
				cout << endl;
				system("pause");
				continue;

			}
			break;
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << "Please only enter 1 or 2." << endl;
		cout << endl;
		system("pause");
	}
	
	if (attackOrNot == 2)
	{
		// Resume the game not attacking.
		// No action needed here.
	}
	else if (attackOrNot == 1)
	{
		cout << endl;

		// Create a counter to list the number of available enemies to attack.
		int listNumber = 1;

		// Create an integer for users response.
		int choice;

		// Set varaibles for a random attack number.
		int WarriorRandomAttack = RandomizeWarriorAttackSeverity();
		int ArcherRandomAttack = RandomizeArcherAttackSeverity();
		int SorcererRandomAttack = RandomizeSorcererAttackSeverity();
		
		// Resume the game attacking.
		switch (uniqueArray[characterNumberTurn])
		{
			case 0:

				while (true)
				{
					render = true;
					Render();

					listNumber = 1;

					cout << "Attack" << endl;
					if (attack.A_attack_a == true)
					{
						cout << listNumber << ") a " << endl;
						listNumber++;
					}
					if (attack.A_attack_w == true)
					{
						cout << listNumber << ") w " << endl;
						listNumber++;
					}
					if (attack.A_attack_s == true)
					{
						cout << listNumber << ") s " << endl;
						listNumber++;
					}
					cout << listNumber << ") Nevermind do not attack." << endl;
					cout << endl;
					cout << "Choice? ";
					cin >> choice;
					cout << endl;

					if (cin.good())
					{
						if (choice < 1 || choice > listNumber)
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');

							cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
							cout << endl;
							system("pause");
							continue;

						}
						break;
					}

					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
					cout << endl;
					system("pause");
				}

				if (choice == 3)
				{
					if (attack.A_attack_a == true && attack.A_attack_w == true && attack.A_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - ArcherRandomAttack);
					}
				}
				else if (choice == 2)
				{
					if (attack.A_attack_a == true && attack.A_attack_w == true && attack.A_attack_s == true)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - ArcherRandomAttack);
					}
					else if (attack.A_attack_a == true && attack.A_attack_w == true && attack.A_attack_s == false)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - ArcherRandomAttack);
					}
					else if (attack.A_attack_a == true && attack.A_attack_w == false && attack.A_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - ArcherRandomAttack);
					}
					else if (attack.A_attack_a == false && attack.A_attack_w == true && attack.A_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - ArcherRandomAttack);
					}
				}
				else if (choice == 1)
				{
					if (attack.A_attack_a == true && attack.A_attack_w == true && attack.A_attack_s == true)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - ArcherRandomAttack);
					}
					else if (attack.A_attack_a == true && attack.A_attack_w == true && attack.A_attack_s == false)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - ArcherRandomAttack);
					}
					else if (attack.A_attack_a == true && attack.A_attack_w == false && attack.A_attack_s == true)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - ArcherRandomAttack);
					}
					else if (attack.A_attack_a == false && attack.A_attack_w == true && attack.A_attack_s == true)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - ArcherRandomAttack);
					}
					else if (attack.A_attack_a == false && attack.A_attack_w == false && attack.A_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - ArcherRandomAttack);
					}
					else if (attack.A_attack_a == false && attack.A_attack_w == true && attack.A_attack_s == false)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - ArcherRandomAttack);
					}
					else if (attack.A_attack_a == true && attack.A_attack_w == false && attack.A_attack_s == false)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - ArcherRandomAttack);
					}
				}
				

				break;
			case 1:

				while (true)
				{
					render = true;
					Render();

					listNumber = 1;

					cout << "Attack" << endl;
					if (attack.a_attack_A == true)
					{
						cout << listNumber << ") A " << endl;
						listNumber++;
					}
					if (attack.a_attack_W == true)
					{
						cout << listNumber << ") W " << endl;
						listNumber++;
					}
					if (attack.a_attack_S == true)
					{
						cout << listNumber << ") S " << endl;
						listNumber++;
					}
					cout << listNumber << ") Nevermind do not attack." << endl;
					cout << endl;
					cout << "Choice? ";
					cin >> choice;
					cout << endl;

					if (cin.good())
					{
						if (choice < 1 || choice > listNumber)
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');

							cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
							cout << endl;
							system("pause");
							continue;

						}
						break;
					}

					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
					cout << endl;
					system("pause");
				}
				
				if (choice == listNumber)
				{
					// The user choose to cancel attack.
					// Do nothing here.
					break;
				}

				if (choice == 3)
				{
					if (attack.a_attack_A == true && attack.a_attack_W == true && attack.a_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - ArcherRandomAttack);
					}
				}
				else if (choice == 2)
				{
					if (attack.a_attack_A == true && attack.a_attack_W == true && attack.a_attack_S == true)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - ArcherRandomAttack);
					}
					else if (attack.a_attack_A == true && attack.a_attack_W == true && attack.a_attack_S == false)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - ArcherRandomAttack);
					}
					else if (attack.a_attack_A == true && attack.a_attack_W == false && attack.a_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - ArcherRandomAttack);
					}
					else if (attack.a_attack_A == false && attack.a_attack_W == true && attack.a_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - ArcherRandomAttack);
					}
				}
				else if (choice == 1)
				{
					if (attack.a_attack_A == true && attack.a_attack_W == true && attack.a_attack_S == true)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - ArcherRandomAttack);
					}
					else if (attack.a_attack_A == true && attack.a_attack_W == true && attack.a_attack_S == false)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - ArcherRandomAttack);
					}
					else if (attack.a_attack_A == true && attack.a_attack_W == false && attack.a_attack_S == true)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - ArcherRandomAttack);
					}
					else if (attack.a_attack_A == false && attack.a_attack_W == true && attack.a_attack_S == true)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - ArcherRandomAttack);
					}
					else if (attack.a_attack_A == false && attack.a_attack_W == false && attack.a_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - ArcherRandomAttack);
					}
					else if (attack.a_attack_A == false && attack.a_attack_W == true && attack.a_attack_S == false)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - ArcherRandomAttack);
					}
					else if (attack.a_attack_A == true && attack.a_attack_W == false && attack.a_attack_S == false)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - ArcherRandomAttack);
					}
				}

				break;
			case 2:

				while (true)
				{
					render = true;
					Render();

					listNumber = 1;

					cout << "Attack" << endl;
					if (attack.S_attack_a == true)
					{
						cout << listNumber << ") a " << endl;
						listNumber++;
					}
					if (attack.S_attack_w == true)
					{
						cout << listNumber << ") w " << endl;
						listNumber++;
					}
					if (attack.S_attack_s == true)
					{
						cout << listNumber << ") s " << endl;
						listNumber++;
					}
					cout << listNumber << ") Nevermind do not attack." << endl;
					cout << endl;
					cout << "Choice? ";
					cin >> choice;
					cout << endl;

					if (cin.good())
					{
						if (choice < 1 || choice > listNumber)
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');

							cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
							cout << endl;
							system("pause");
							continue;

						}
						break;
					}

					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
					cout << endl;
					system("pause");
				}
				
				if (choice == listNumber)
				{
					// The user choose to cancel attack.
					// Do nothing here.
					break;
				}
				if (choice == 3)
				{
					if (attack.S_attack_a == true && attack.S_attack_w == true && attack.S_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - SorcererRandomAttack);
					}
				}
				else if (choice == 2)
				{
					if (attack.S_attack_a == true && attack.S_attack_w == true && attack.S_attack_s == true)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - SorcererRandomAttack);
					}
					else if (attack.S_attack_a == true && attack.S_attack_w == true && attack.S_attack_s == false)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - SorcererRandomAttack);
					}
					else if (attack.S_attack_a == true && attack.S_attack_w == false && attack.S_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - SorcererRandomAttack);
					}
					else if (attack.S_attack_a == false && attack.S_attack_w == true && attack.S_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - SorcererRandomAttack);
					}
				}
				else if (choice == 1)
				{
					if (attack.S_attack_a == true && attack.S_attack_w == true && attack.S_attack_s == true)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - SorcererRandomAttack);
					}
					else if (attack.S_attack_a == true && attack.S_attack_w == true && attack.S_attack_s == false)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - SorcererRandomAttack);
					}
					else if (attack.S_attack_a == true && attack.S_attack_w == false && attack.S_attack_s == true)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - SorcererRandomAttack);
					}
					else if (attack.S_attack_a == false && attack.S_attack_w == true && attack.S_attack_s == true)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - SorcererRandomAttack);
					}
					else if (attack.S_attack_a == false && attack.S_attack_w == false && attack.S_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - SorcererRandomAttack);
					}
					else if (attack.S_attack_a == false && attack.S_attack_w == true && attack.S_attack_s == false)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - SorcererRandomAttack);
					}
					else if (attack.S_attack_a == true && attack.S_attack_w == false && attack.S_attack_s == false)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - SorcererRandomAttack);
					}
				}

				break;
			case 3:

				while (true)
				{
					render = true;
					Render();

					listNumber = 1;

					cout << "Attack" << endl;
					if (attack.s_attack_A == true)
					{
						cout << listNumber << ") A " << endl;
						listNumber++;
					}
					if (attack.s_attack_W == true)
					{
						cout << listNumber << ") W " << endl;
						listNumber++;
					}
					if (attack.s_attack_S == true)
					{
						cout << listNumber << ") S " << endl;
						listNumber++;
					}
					cout << listNumber << ") Nevermind do not attack." << endl;
					cout << endl;
					cout << "Choice? ";
					cin >> choice;
					cout << endl;

					if (cin.good())
					{
						if (choice < 1 || choice > listNumber)
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');

							cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
							cout << endl;
							system("pause");
							continue;

						}
						break;
					}

					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
					cout << endl;
					system("pause");
				}
				
				if (choice == listNumber)
				{
					// The user choose to cancel attack.
					// Do nothing here.
					break;
				}
				if (choice == 3)
				{
					if (attack.s_attack_A == true && attack.s_attack_W == true && attack.s_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - SorcererRandomAttack);
					}
				}
				else if (choice == 2)
				{
					if (attack.s_attack_A == true && attack.s_attack_W == true && attack.s_attack_S == true)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - SorcererRandomAttack);
					}
					else if (attack.s_attack_A == true && attack.s_attack_W == true && attack.s_attack_S == false)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - SorcererRandomAttack);
					}
					else if (attack.s_attack_A == true && attack.s_attack_W == false && attack.s_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - SorcererRandomAttack);
					}
					else if (attack.s_attack_A == false && attack.s_attack_W == true && attack.s_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - SorcererRandomAttack);
					}
				}
				else if (choice == 1)
				{
					if (attack.s_attack_A == true && attack.s_attack_W == true && attack.s_attack_S == true)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - SorcererRandomAttack);
					}
					else if (attack.s_attack_A == true && attack.s_attack_W == true && attack.s_attack_S == false)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - SorcererRandomAttack);
					}
					else if (attack.s_attack_A == true && attack.s_attack_W == false && attack.s_attack_S == true)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - SorcererRandomAttack);
					}
					else if (attack.s_attack_A == false && attack.s_attack_W == true && attack.s_attack_S == true)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - SorcererRandomAttack);
					}
					else if (attack.s_attack_A == false && attack.s_attack_W == false && attack.s_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - SorcererRandomAttack);
					}
					else if (attack.s_attack_A == false && attack.s_attack_W == true && attack.s_attack_S == false)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - SorcererRandomAttack);
					}
					else if (attack.s_attack_A == true && attack.s_attack_W == false && attack.s_attack_S == false)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - SorcererRandomAttack);
					}
				}

				break;
			case 4:

				while (true)
				{
					render = true;
					Render();

					listNumber = 1;

					cout << "Attack" << endl;
					if (attack.W_attack_a == true)
					{
						cout << listNumber << ") a " << endl;
						listNumber++;
					}
					if (attack.W_attack_w == true)
					{
						cout << listNumber << ") w " << endl;
						listNumber++;
					}
					if (attack.W_attack_s == true)
					{
						cout << listNumber << ") s " << endl;
						listNumber++;
					}
					cout << listNumber << ") Nevermind do not attack." << endl;
					cout << endl;
					cout << "Choice? ";
					cin >> choice;
					cout << endl;

					if (cin.good())
					{
						if (choice < 1 || choice > listNumber)
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');

							cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
							cout << endl;
							system("pause");
							continue;

						}
						break;
					}

					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
					cout << endl;
					system("pause");
				}

				if (choice == listNumber)
				{
					// The user choose to cancel attack.
					// Do nothing here.
					break;
				}
				if (choice == 3)
				{
					if (attack.W_attack_a == true && attack.W_attack_w == true && attack.W_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - WarriorRandomAttack);
					}
				}
				else if (choice == 2)
				{
					if (attack.W_attack_a == true && attack.W_attack_w == true && attack.W_attack_s == true)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - WarriorRandomAttack);
					}
					else if (attack.W_attack_a == true && attack.W_attack_w == true && attack.W_attack_s == false)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - WarriorRandomAttack);
					}
					else if (attack.W_attack_a == true && attack.W_attack_w == false && attack.W_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - WarriorRandomAttack);
					}
					else if (attack.W_attack_a == false && attack.W_attack_w == true && attack.W_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - WarriorRandomAttack);
					}
				}
				else if (choice == 1)
				{
					if (attack.W_attack_a == true && attack.W_attack_w == true && attack.W_attack_s == true)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - WarriorRandomAttack);
					}
					else if (attack.W_attack_a == true && attack.W_attack_w == true && attack.W_attack_s == false)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - WarriorRandomAttack);
					}
					else if (attack.W_attack_a == true && attack.W_attack_w == false && attack.W_attack_s == true)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - WarriorRandomAttack);
					}
					else if (attack.W_attack_a == false && attack.W_attack_w == true && attack.W_attack_s == true)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - WarriorRandomAttack);
					}
					else if (attack.W_attack_a == false && attack.W_attack_w == false && attack.W_attack_s == true)
					{
						gameBattlefield.team2.SetsHealth(gameBattlefield.team2.GetsHealth() - WarriorRandomAttack);
					}
					else if (attack.W_attack_a == false && attack.W_attack_w == true && attack.W_attack_s == false)
					{
						gameBattlefield.team2.SetwHealth(gameBattlefield.team2.GetwHealth() - WarriorRandomAttack);
					}
					else if (attack.W_attack_a == true && attack.W_attack_w == false && attack.W_attack_s == false)
					{
						gameBattlefield.team2.SetaHealth(gameBattlefield.team2.GetaHealth() - WarriorRandomAttack);
					}
				}


				break;

			case 5:

				while (true)
				{
					render = true;
					Render();


					listNumber = 1;

					cout << "Attack" << endl;
					if (attack.w_attack_A == true)
					{
						cout << listNumber << ") A " << endl;
						listNumber++;
					}
					if (attack.w_attack_W == true)
					{
						cout << listNumber << ") W " << endl;
						listNumber++;
					}
					if (attack.w_attack_S == true)
					{
						cout << listNumber << ") S " << endl;
						listNumber++;
					}
					cout << listNumber << ") Nevermind do not attack." << endl;
					cout << endl;
					cout << "Choice? ";
					cin >> choice;
					cout << endl;

					if (cin.good())
					{
						if (choice < 1 || choice > listNumber)
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');

							cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
							cout << endl;
							system("pause");
							continue;

						}
						break;
					}

					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Please only enter 1-" << listNumber << ", inclusive." << endl;
					cout << endl;
					system("pause");
				}

				if (choice == listNumber)
				{
					// The user choose to cancel attack.
					// Do nothing here.
					break;
				}
				if (choice == 3)
				{
					if (attack.w_attack_A == true && attack.w_attack_W == true && attack.w_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - WarriorRandomAttack);
					}
				}
				else if (choice == 2)
				{
					if (attack.w_attack_A == true && attack.w_attack_W == true && attack.w_attack_S == true)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - WarriorRandomAttack);
					}
					else if (attack.w_attack_A == true && attack.w_attack_W == true && attack.w_attack_S == false)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - WarriorRandomAttack);
					}
					else if (attack.w_attack_A == true && attack.w_attack_W == false && attack.w_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - WarriorRandomAttack);
					}
					else if (attack.w_attack_A == false && attack.w_attack_W == true && attack.w_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - WarriorRandomAttack);
					}
				}
				else if (choice == 1)
				{
					if (attack.w_attack_A == true && attack.w_attack_W == true && attack.w_attack_S == true)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - WarriorRandomAttack);
					}
					else if (attack.w_attack_A == true && attack.w_attack_W == true && attack.w_attack_S == false)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - WarriorRandomAttack);
					}
					else if (attack.w_attack_A == true && attack.w_attack_W == false && attack.w_attack_S == true)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - WarriorRandomAttack);
					}
					else if (attack.w_attack_A == false && attack.w_attack_W == true && attack.w_attack_S == true)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - WarriorRandomAttack);
					}
					else if (attack.w_attack_A == false && attack.w_attack_W == false && attack.w_attack_S == true)
					{
						gameBattlefield.team1.SetShealth(gameBattlefield.team1.GetShealth() - WarriorRandomAttack);
					}
					else if (attack.w_attack_A == false && attack.w_attack_W == true && attack.w_attack_S == false)
					{
						gameBattlefield.team1.SetWhealth(gameBattlefield.team1.GetWhealth() - WarriorRandomAttack);
					}
					else if (attack.w_attack_A == true && attack.w_attack_W == false && attack.w_attack_S == false)
					{
						gameBattlefield.team1.SetAhealth(gameBattlefield.team1.GetAhealth() - WarriorRandomAttack);
					}
				}

				break;
		
		}
	}

}

void Game::CalculateRangePossibleAttack()
{
	ResetRangePossibleAttack();

	//Determine attack range with this formula, distance = abs (x2 – x1) + abs (y2 – y1).

	// List characters variables of attack ranges.
	int ArcherAttackRange = 4;
	int WarriorAttackRange = 1;
	int SorcererAttackRange = 2;
	
	switch(uniqueArray[characterNumberTurn])
	{
		case 0:
			
			if (abs(gameBattlefield.team2.GetwXPos() - gameBattlefield.team1.GetAxPos()) + abs(gameBattlefield.team2.GetwYPos() - gameBattlefield.team1.GetAyPos()) < ArcherAttackRange + 1)
			{
				if (gameBattlefield.team2.GetwHealth() >= 1)
				{
					attack.A_attack_w = true;
				}
				
			}
			if (abs(gameBattlefield.team2.GetaXPos() - gameBattlefield.team1.GetAxPos()) + abs(gameBattlefield.team2.GetaYPos() - gameBattlefield.team1.GetAyPos()) < ArcherAttackRange + 1)
			{
				if (gameBattlefield.team2.GetaHealth() >= 1)
				{
					attack.A_attack_a = true;
				}
				
			}
			if (abs(gameBattlefield.team2.GetsXPos() - gameBattlefield.team1.GetAxPos()) + abs(gameBattlefield.team2.GetsYPos() - gameBattlefield.team1.GetAyPos()) < ArcherAttackRange + 1)
			{
				if (gameBattlefield.team2.GetsHealth() >= 1)
				{
					attack.A_attack_s = true;
				}
				
			}
			break;
		case 1:

			if (abs(gameBattlefield.team1.GetWxPos() - gameBattlefield.team2.GetaXPos()) + abs(gameBattlefield.team1.GetWyPos() - gameBattlefield.team2.GetaYPos()) < ArcherAttackRange + 1)
			{
				if (gameBattlefield.team1.GetWhealth() >= 1)
				{
					attack.a_attack_W = true;
				}
				
			}
			if (abs(gameBattlefield.team1.GetAxPos() - gameBattlefield.team2.GetaXPos()) + abs(gameBattlefield.team1.GetAyPos() - gameBattlefield.team2.GetaYPos()) < ArcherAttackRange + 1)
			{
				if (gameBattlefield.team1.GetAhealth() >= 1)
				{
					attack.a_attack_A = true;
				}
				
			}
			if (abs(gameBattlefield.team1.GetSxPos() - gameBattlefield.team2.GetaXPos()) + abs(gameBattlefield.team1.GetSyPos() - gameBattlefield.team2.GetaYPos()) < ArcherAttackRange + 1)
			{
				if (gameBattlefield.team1.GetShealth() >= 1)
				{
					attack.a_attack_S = true;
				}
				
			}
			break;
		case 2:

			if (abs(gameBattlefield.team2.GetwXPos() - gameBattlefield.team1.GetSxPos()) + abs(gameBattlefield.team2.GetwYPos() - gameBattlefield.team1.GetSyPos()) < SorcererAttackRange + 1)
			{
				if (gameBattlefield.team2.GetwHealth() >= 1)
				{
					attack.S_attack_w = true;
				}
				
			}
			if (abs(gameBattlefield.team2.GetaXPos() - gameBattlefield.team1.GetSxPos()) + abs(gameBattlefield.team2.GetaYPos() - gameBattlefield.team1.GetSyPos()) < SorcererAttackRange + 1)
			{
				if (gameBattlefield.team2.GetaHealth() >= 1)
				{
					attack.S_attack_a = true;
				}
				
			}
			if (abs(gameBattlefield.team2.GetsXPos() - gameBattlefield.team1.GetSxPos()) + abs(gameBattlefield.team2.GetsYPos() - gameBattlefield.team1.GetSyPos()) < SorcererAttackRange + 1)
			{
				if (gameBattlefield.team2.GetsHealth() >= 1)
				{
					attack.S_attack_s = true;
				}
				
			}
			break;
		case 3:

			if (abs(gameBattlefield.team1.GetWxPos() - gameBattlefield.team2.GetsXPos()) + abs(gameBattlefield.team1.GetWyPos() - gameBattlefield.team2.GetsYPos()) < SorcererAttackRange + 1)
			{
				if (gameBattlefield.team1.GetWhealth() >= 1)
				{
					attack.s_attack_W = true;
				}
				
			}
			if (abs(gameBattlefield.team1.GetAxPos() - gameBattlefield.team2.GetsXPos()) + abs(gameBattlefield.team1.GetAyPos() - gameBattlefield.team2.GetsYPos()) < SorcererAttackRange + 1)
			{
				if (gameBattlefield.team1.GetAhealth() >= 1)
				{
					attack.s_attack_A = true;
				}
				
			}
			if (abs(gameBattlefield.team1.GetSxPos() - gameBattlefield.team2.GetsXPos()) + abs(gameBattlefield.team1.GetSyPos() - gameBattlefield.team2.GetsYPos()) < SorcererAttackRange + 1)
			{
				if (gameBattlefield.team1.GetShealth() >= 1)
				{
					attack.s_attack_S = true;
				}
				
			}
			break;
		case 4:
			
			if (abs(gameBattlefield.team2.GetwXPos() - gameBattlefield.team1.GetWxPos()) + abs(gameBattlefield.team2.GetwYPos() - gameBattlefield.team1.GetWyPos()) < WarriorAttackRange + 1)
			{
				if (gameBattlefield.team2.GetwHealth() >= 1)
				{
					attack.W_attack_w = true;
				}
				
			}
			if (abs(gameBattlefield.team2.GetaXPos() - gameBattlefield.team1.GetWxPos()) + abs(gameBattlefield.team2.GetaYPos() - gameBattlefield.team1.GetWyPos()) < WarriorAttackRange + 1)
			{
				if (gameBattlefield.team2.GetaHealth() >= 1)
				{
					attack.W_attack_a = true;
				}
				
			}
			if (abs(gameBattlefield.team2.GetsXPos() - gameBattlefield.team1.GetWxPos()) + abs(gameBattlefield.team2.GetsYPos() - gameBattlefield.team1.GetWyPos()) < WarriorAttackRange + 1)
			{
				if (gameBattlefield.team2.GetsHealth() >= 1)
				{
					attack.W_attack_s = true;
				}
				
			}
			break;
		case 5:

			if (abs(gameBattlefield.team1.GetWxPos() - gameBattlefield.team2.GetwXPos()) + abs(gameBattlefield.team1.GetWyPos() - gameBattlefield.team2.GetwYPos()) < WarriorAttackRange + 1)
			{
				if (gameBattlefield.team1.GetWhealth() >= 1)
				{
					attack.w_attack_W = true;
				}
				
			}
			if (abs(gameBattlefield.team1.GetAxPos() - gameBattlefield.team2.GetwXPos()) + abs(gameBattlefield.team1.GetAyPos() - gameBattlefield.team2.GetwYPos()) < WarriorAttackRange + 1)
			{
				if (gameBattlefield.team1.GetAhealth() >= 1)
				{
					attack.w_attack_A = true;
				}
				
			}
			if (abs(gameBattlefield.team1.GetSxPos() - gameBattlefield.team2.GetwXPos()) + abs(gameBattlefield.team1.GetSyPos() - gameBattlefield.team2.GetwYPos()) < WarriorAttackRange + 1)
			{
				if (gameBattlefield.team1.GetShealth() >= 1)
				{
					attack.w_attack_S = true;
				}
				
			}
			break;
	}

}


void Game::ResetRangePossibleAttack()
{
	
	attack.A_attack_w = false;
	attack.A_attack_a = false;
	attack.A_attack_s = false;

	attack.a_attack_W = false;
	attack.a_attack_S = false;
	attack.a_attack_A = false;

	attack.S_attack_w = false;
	attack.S_attack_s = false;
	attack.S_attack_a = false;

	attack.s_attack_W = false;
	attack.s_attack_S = false;
	attack.s_attack_A = false;

	attack.W_attack_a = false;
	attack.W_attack_w = false;
	attack.W_attack_s = false;

	attack.w_attack_W = false;
	attack.w_attack_S = false;
	attack.w_attack_A = false;
}

int Game::RandomizeWarriorAttackSeverity()
{
	srand((unsigned int)time(0));

	int randomForWarrior =  7 + (rand() % 8);

	return randomForWarrior;
}

int Game::RandomizeArcherAttackSeverity()
{
	srand((unsigned int)time(0));

	int randomForArcher =  2 + (rand() % 6);

	return randomForArcher;
}

int Game::RandomizeSorcererAttackSeverity()
{
	srand((unsigned int)time(0));

	int randomForSorcerer = 1 + (rand() % 10);

	return randomForSorcerer;
}

void Game::WouldYouLikeToMove()
{
	// Create a varaible that holds the user's choice.
	int choice;

	bool askToMove = false;
	bool Dead = false;

	bool Wturn = false;
	bool Aturn = false;
	bool Sturn = false;
	bool wTurn = false;
	bool aTurn = false;
	bool sTurn = false;

	// CHeck the possibility of collision.
	CheckCollision(uniqueArray[characterNumberTurn]);

	switch (uniqueArray[characterNumberTurn])
	{
		case 0:
			if ((crash.down == false || crash.up == false || crash.left == false || crash.right == false) && (gameBattlefield.team1.GetAhealth() >= 1))
			{
				askToMove = true;
			}

			if (gameBattlefield.team1.GetAhealth() < 1)
			{
				Dead = true;
			}
			Aturn = true;
			break;
		case 1:
			if ((crash.down == false || crash.up == false || crash.left == false || crash.right == false) && (gameBattlefield.team2.GetaHealth() >= 1))
			{
				askToMove = true;
			}

			if (gameBattlefield.team2.GetaHealth() < 1)
			{
				Dead = true;
			}
			aTurn = true;
			break;
		case 2:
			if ((crash.down == false || crash.up == false || crash.left == false || crash.right == false) && (gameBattlefield.team1.GetShealth() >= 1))
			{
				askToMove = true;
			}

			if (gameBattlefield.team1.GetShealth() < 1)
			{
				Dead = true;
			}
			Sturn = true;
			break;
		case 3:
			if ((crash.down == false || crash.up == false || crash.left == false || crash.right == false) && (gameBattlefield.team2.GetsHealth() >= 1))
			{
				askToMove = true;
			}

			if (gameBattlefield.team2.GetsHealth() < 1)
			{
				Dead = true;
			}
			sTurn = true;
			break;
		case 4:
			if ((crash.down == false || crash.up == false || crash.left == false || crash.right == false) && (gameBattlefield.team1.GetWhealth() >= 1))
			{
				askToMove = true;
			}

			if (gameBattlefield.team1.GetWhealth() < 1)
			{
				Dead = true;
			}
			Wturn = true;
			break;
		case 5:
			if ((crash.down == false || crash.up == false || crash.left == false || crash.right == false) && (gameBattlefield.team2.GetwHealth() >= 1))
			{
				askToMove = true;

			}

			if (gameBattlefield.team2.GetwHealth() < 1)
			{
				Dead = true;
			}
			wTurn = true;
			break;
	}

	//If a player got skipped let them know here.
	switch (uniqueArray[characterNumberTurn])
	{
		case 0:
			if (crash.down == true && crash.up == true && crash.left == true && crash.right == true && Dead == false)
			{
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.A_attack_w == true || attack.A_attack_a == true || attack.A_attack_s == true)
				{
					render = true;
					Render();
					cout << " A you are skipped from the moving phase only(due to being blocked) of this cycle." << endl;
					cout << endl;
					system("pause");
				}
				else
				{
					render = true;
					Render();
					cout << " A you are skipped from the moving phase(due to being blocked), and the attack phase(due to no enemies in range) of this cycle." << endl;
					cout << endl;
					system("pause");
				}

			}
			break;
		case 1:

			if (crash.down == true && crash.up == true && crash.left == true && crash.right == true && Dead == false)
			{
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.a_attack_W == true || attack.a_attack_A == true || attack.a_attack_S == true)
				{
					render = true;
					Render();
					cout << " a you are skipped from the moving phase only(due to being blocked) of this cycle." << endl;
					cout << endl;
					system("pause");
				}
				else
				{
					render = true;
					Render();
					cout << " a you are skipped from the moving phase(due to being blocked), and the attack phase(due to no enemies in range) of this cycle." << endl;
					cout << endl;
					system("pause");
				}

			}
			break;
		case 2:

			if (crash.down == true && crash.up == true && crash.left == true && crash.right == true && Dead == false)
			{
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.S_attack_w == true || attack.S_attack_a == true || attack.S_attack_s == true)
				{
					render = true;
					Render();
					cout << " S you are skipped from the moving phase only(due to being blocked) of this cycle." << endl;
					cout << endl;
					system("pause");
				}
				else
				{
					render = true;
					Render();
					cout << " S you are skipped from the moving phase(due to being blocked), and the attack phase(due to no enemies in range) of this cycle." << endl;
					cout << endl;
					system("pause");
				}

			}
			break;
		case 3:

			if (crash.down == true && crash.up == true && crash.left == true && crash.right == true && Dead == false)
			{
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.s_attack_W == true || attack.s_attack_A == true || attack.s_attack_S == true)
				{
					render = true;
					Render();
					cout << " s you are skipped from the moving phase only(due to being blocked) of this cycle." << endl;
					cout << endl;
					system("pause");
				}
				else
				{
					render = true;
					Render();
					cout << " s you are skipped from the moving phase(due to being blocked), and the attack phase(due to no enemies in range) of this cycle." << endl;
					cout << endl;
					system("pause");
				}

			}
			break;
		case 4:

			if (crash.down == true && crash.up == true && crash.left == true && crash.right == true && Dead == false)
			{
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.W_attack_w == true || attack.W_attack_a == true || attack.W_attack_s == true)
				{
					render = true;
					Render();
					cout << " W you are skipped from the moving phase only(due to being blocked) of this cycle." << endl;
					cout << endl;
					system("pause");
				}
				else
				{
					render = true;
					Render();
					cout << " W you are skipped from the moving phase(due to being blocked), and the attack phase(due to no enemies in range) of this cycle." << endl;
					cout << endl;
					system("pause");
				}

			}
			break;
		case 5:

			if (crash.down == true && crash.up == true && crash.left == true && crash.right == true && Dead == false)
			{
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.w_attack_W == true || attack.w_attack_A == true || attack.w_attack_S == true)
				{
					render = true;
					Render();
					cout << " w you are skipped from the moving phase only(due to being blocked) of this cycle." << endl;
					cout << endl;
					system("pause");
				}
				else
				{
					render = true;
					Render();
					cout << " w you are skipped from the moving phase(due to being blocked), and the attack phase(due to no enemies in range) of this cycle." << endl;
					cout << endl;
					system("pause");
				}

			}
			break;
	}
	

	if (askToMove == true && Dead == false)
	{
		askToMove = false;

		while (true)
		{
			system("cls");
			render = true;
			Render();

			if (Aturn == true)
			{
				cout << " A would You like to move? " << endl;
			}
			else if (aTurn == true)
			{
				cout << " a would You like to move? " << endl;
			}
			else if (Sturn == true)
			{
				cout << " S would You like to move? " << endl;
			}
			else if (sTurn == true)
			{
				cout << " s would You like to move? " << endl;
			}
			else if (Wturn == true)
			{
				cout << " W would You like to move? " << endl;
			}
			else if (wTurn == true)
			{
				cout << " w would You like to move? " << endl;
			}
			
			cout << endl;
			cout << "1) Yes 2) No" << endl;
			cout << endl;
			cout << "Choice? ";
			cin >> choice;
			cout << endl;

			if (cin.good())
			{
				if (choice < 1 || choice > 2)
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Please only enter 1 or 2." << endl;
					cout << endl;
					system("pause");
					continue;

				}
				if (choice == 2)
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					
					Sleep(30);
					render = true;
					WantToMove = false;

					// Add Attack Option If they have it available.
					switch (uniqueArray[characterNumberTurn])
					{
						case 0:
							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.A_attack_w == true || attack.A_attack_a == true || attack.A_attack_s == true)
							{
								Render();

								AttackOption();
							}
							break;
						case 1:
							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.a_attack_W == true || attack.a_attack_A == true || attack.a_attack_S == true)
							{
								Render();

								AttackOption();
							}
							break;
						case 2:
							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.S_attack_w == true || attack.S_attack_a == true || attack.S_attack_s == true)
							{
								Render();

								AttackOption();
							}
							break;
						case 3:
							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.s_attack_W == true || attack.s_attack_A == true || attack.s_attack_S == true)
							{
								Render();

								AttackOption();
							}
							break;
						case 4:
							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.W_attack_w == true || attack.W_attack_a == true || attack.W_attack_s == true)
							{
								Render();

								AttackOption();
							}
							break;
						case 5:
							// Calculate the possible range of attack.
							CalculateRangePossibleAttack();

							if (attack.w_attack_W == true || attack.w_attack_A == true || attack.w_attack_S == true)
							{
								Render();

								AttackOption();
							}
							break;
					}

					SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
					Render();
					RealTimeUpdates();
				}
				if (choice == 1)
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					updatePrintOnce = 0;
					Update = true;
					WantToMove = true;
					RealTimeUpdates();
				}
				break;
			}

			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cout << "Please only enter 1 or 2." << endl;
			cout << endl;
			system("pause");
		}
	}

	if (askToMove == false && Dead == false)
	{
		// If the player can not move let's check to see if they have an option to attack.
		// Add Attack Option If they have it available.
		switch (uniqueArray[characterNumberTurn])
		{
			case 0:
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.A_attack_w == true || attack.A_attack_a == true || attack.A_attack_s == true)
				{
					render = true;
					Render();

					AttackOption();
				}
				break;
			case 1:
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.a_attack_W == true || attack.a_attack_A == true || attack.a_attack_S == true)
				{
					render = true;
					Render();

					AttackOption();
				}
				break;
			case 2:
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.S_attack_w == true || attack.S_attack_a == true || attack.S_attack_s == true)
				{
					render = true;
					Render();

					AttackOption();
				}
				break;
			case 3:
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.s_attack_W == true || attack.s_attack_A == true || attack.s_attack_S == true)
				{
					render = true;
					Render();

					AttackOption();
				}
				break;
			case 4:
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.W_attack_w == true || attack.W_attack_a == true || attack.W_attack_s == true)
				{
					render = true;
					Render();

					AttackOption();
				}
				break;
			case 5:
				// Calculate the possible range of attack.
				CalculateRangePossibleAttack();

				if (attack.w_attack_W == true || attack.w_attack_A == true || attack.w_attack_S == true)
				{
					render = true;
					Render();

					AttackOption();
				}
				break;
		}
	}

	SetCharacterNumberTurn(GetCharacterNumberTurn() + 1);
	Sleep(30);
	render = true;
	Render();
}

void Game::CheckIfGameIsOver()
{
	if (gameBattlefield.team1.GetAhealth() < 1 && gameBattlefield.team1.GetWhealth() < 1 && gameBattlefield.team1.GetShealth() < 1)
	{
		render = true;

		Render();

		cout << "Sorry Player 1, you lost." << endl;
		cout << endl;
		system("pause");

		GameOver over;

		over.PlayAgainOption();
	}

	if (gameBattlefield.team2.GetaHealth() < 1 && gameBattlefield.team2.GetwHealth() < 1 && gameBattlefield.team2.GetsHealth() < 1)
	{
		render = true;

		Render();

		cout << "Sorry Player 2, you lost." << endl;
		cout << endl;
		system("pause");

		GameOver over;

		over.PlayAgainOption();
	}
}

