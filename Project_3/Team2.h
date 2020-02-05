#pragma once
class Team2
{
public:
	Team2();
	~Team2();

	char Getw();
	void Setw(char w);

	char Geta();
	void Seta(char a);

	char Gets();
	void Sets(char s);

	unsigned int GetaHealth();
	void SetaHealth(int aHealth);

	unsigned int GetwHealth();
	void SetwHealth(int wHealth);

	unsigned int GetsHealth();
	void SetsHealth(int sHealth);

	int GetaXPos();
	void SetaXPos(int aNewXPos);

	int GetwXPos();
	void SetwXPos(int wNewXPos);

	int GetsXPos();
	void SetsXPos(int sNewXPos);

	int GetaYPos();
	void SetaYPos(int aNewYPos);

	int GetwYPos();
	void SetwYPos(int wNewYPos);

	int GetsYPos();
	void SetsYPos(int sNewYPos);


private:

	char w;
	char a;
	char s;

	unsigned int aHealth;
	unsigned int sHealth;
	unsigned int wHealth;

	int aXPos;
	int wXPos;
	int sXPos;

	int aYPos;
	int wYPos;
	int sYPos;
};

