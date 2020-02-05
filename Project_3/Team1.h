#pragma once
class Team1
{
public:
	Team1();
	~Team1();

	char GetW();
	void SetW(char W);

	char GetA();
	void SetA(char A);

	char GetS();
	void SetS(char S);

	unsigned int GetAhealth();
	void SetAhealth(int Ahealth);

	unsigned int GetWhealth();
	void SetWhealth(int Whealth);

	unsigned int GetShealth();
	void SetShealth(int Shealth);

	int GetAxPos();
	void SetAxPos(int AnewXPos);

	int GetWxPos();
	void SetWxPos(int WnewXPos);

	int GetSxPos();
	void SetSxPos(int SnewXPos);
	
	int GetAyPos();
	void SetAyPos(int AnewYPos);

	int GetWyPos();
	void SetWyPos(int WnewYPos);

	int GetSyPos();
	void SetSyPos(int SnewYPos);

private:

	char W;
	char A;
	char S;

	unsigned int Ahealth;
	unsigned int Shealth;
	unsigned int Whealth;

	int AxPos;
	int WxPos;
	int SxPos;

	int AyPos;
	int WyPos;
	int SyPos;
};

