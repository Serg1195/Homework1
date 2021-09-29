#include <iostream> 
#include <random> 
#include <stdlib.h> 
#include <chrono> 
#include "windows.h"


using namespace std;

enum Cell : char
{
	CROSS = 'X',
	ZERO = '0',
	EMTRY = '-'
};

enum Progress : uint8_t
{
	IN_PROGRESS,
	WON_AI,
	WON_HUMAN,
	DRAW
};

struct Coord 
{
	size_t y{ 0 };
	size_t x{ 0 };
};

#pragma pack(push,1)
struct Game
{
	Cell** ppField = nullptr;
	size_t SIZE = 3;
	size_t turn = 0;
	Cell human;
	Cell ai;
	Progress progress = IN_PROGRESS;
};
#pragma pack(pop)

inline void clearScr() 
{
	system("cls");
	
}

int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

Progress getWon(const Game& g)
{
	for (size_t y = 0; y < g.SIZE; y++)
	{
		if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][1] == g.ppField[y][2])
		{
			if (g.ppField[y][0] == g.human)
				return WON_HUMAN;
			if (g.ppField[y][0] == g.ai)
				return WON_AI;
		}
	}

	for (size_t x = 0; x < g.SIZE; x++)
	{
		if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[1][x] == g.ppField[2][x])
		{
			if (g.ppField[0][x] == g.human)
				return WON_HUMAN;
			if (g.ppField[0][x] == g.ai)
				return WON_AI;
		}
	}

	if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[1][1] == g.ppField[2][2])
	{
		if (g.ppField[1][1] == g.human)
			return WON_HUMAN;
		if (g.ppField[1][1] == g.ai)
			return WON_AI;
	}

	if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[1][1] == g.ppField[0][2])
	{
		if (g.ppField[1][1] == g.human)
			return WON_HUMAN;
		if (g.ppField[1][1] == g.ai)
			return WON_AI;
	}
	//=====================
	bool draw = true;
	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			if (g.ppField[y][x] == EMTRY)
			{
				draw = false;
				break;
			}
			if (!draw)
				break;
		}
		if (draw)
			return DRAW;
	}

	return IN_PROGRESS;
}


void __fastcall initGame(Game& g)
{
	g.ppField = new Cell * [g.SIZE];
	for (size_t i = 0; i < g.SIZE; i++)
	{
		g.ppField[i] = new Cell [g.SIZE];
	}
	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			g.ppField[y][x] = EMTRY;
		}
	}
	if (getRandomNum(0, 1) > 0)
	{
		g.human = CROSS;
		g.ai = ZERO;
		g.turn = 0;
	}
	else
	{
		g.human = ZERO;
		g.ai = CROSS;
		g.turn = 1;
	}
}

void __fastcall deinitGame(Game& g)
{
	for (size_t i = 0; i < g.SIZE; i++)
	{
		delete[] g.ppField[i];
	}
	delete[] g.ppField;
	g.ppField = nullptr;
}

void __fastcall printGame(Game& g)
{
	cout << "    " ;
	for (size_t x = 0; x < g.SIZE; x++)
		cout << x + 1<<"   ";
	cout << endl;
	for (size_t y = 0; y < g.SIZE; y++)
	{
		cout << y + 1<< " | ";
		for (size_t x = 0; x < g.SIZE; x++)
		{
			cout <<g.ppField[y][x]<<" | ";
		}
		cout << endl;
	}
	cout << endl << "Humen: " << g.human << endl << "AI: " << g.ai << endl;
}

void __fastcall congrats(Game& g)
{
	if (g.progress == WON_HUMAN)
		cout << "Human won!" << endl;
	if (g.progress == WON_AI)
		cout << "Ai won!" << endl;
	if (g.progress == DRAW)
		cout << "Draw!" << endl;
}

Coord getHumanCoord(const Game& g)
{
	Coord c;
	do
	{
		cout << "Enter X: ";
		cin >> c.x;
		cout << "Enter Y: ";
		cin >> c.y;
	} while (c.x == 0 || c.x >3 || c.y == 0 || c.y > 3|| g.ppField[c.y-1][c.x-1]!=EMTRY);
	c.x--;
	c.y--;
	return { c.x, c.y };
}

Coord getAiCoord(Game& g)
{
	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			if (g.ppField[y][x] == EMTRY)
			{
				g.ppField[y][x] = g.ai;
				if (getWon(g)==WON_AI)
				{
					g.ppField[y][x] = EMTRY;
					return { y,x };
				}
				g.ppField[y][x] = EMTRY;
			}
		}

	}

	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			if (g.ppField[y][x] == EMTRY)
			{
				g.ppField[y][x] = g.human;
				if (getWon(g) == WON_HUMAN)
				{
					g.ppField[y][x] = EMTRY;
					return { y,x };
				}
				g.ppField[y][x] = EMTRY;
			}
		}

	}



	if(g.ppField[1][1]==EMTRY)
		return {1,1};

	Coord arr[4];
	size_t num = 0;
	if (g.ppField[0][0] == EMTRY)
	{
		arr[num] = { 0,0 };
		num++;
	}
	if (g.ppField[2][2] == EMTRY)
	{
		arr[num] = { 2,2 };
		num++;
	}
	if (g.ppField[2][0] == EMTRY)
	{
		arr[num] = { 2,0 };
		num++;
	}
	if (g.ppField[0][2] == EMTRY)
	{
		arr[num] = { 0,2 };
		num++;
	}
	if (num > 0)
	{
		const size_t index = getRandomNum(0, 1000) % num;
		return arr[index];		
	}
	num = 0;
	//===============================
	if (g.ppField[1][0] == EMTRY)
	{
		arr[num] = { 1,0 };
		num++;
	}
	if (g.ppField[0][1] == EMTRY)
	{
		arr[num] = { 0,1 };
		num++;
	}
	if (g.ppField[2][1] == EMTRY)
	{
		arr[num] = { 2,1 };
		num++;
	}
	if (g.ppField[1][2] == EMTRY)
	{
		arr[num] = { 1,2 };
		num++;
	}
	if (num > 0)
	{
		const size_t index = getRandomNum(0, 1000) % num;
		return arr[index];
		num = 0;
	}
	return{};
}



	int main() 
	{
		Game g;
		initGame(g);
		clearScr();
		printGame(g);
		do
		{
			if (g.turn%2==0)
			{
				Coord c = getHumanCoord(g);
				g.ppField[c.y][c.x] = g.human;
			}
			else
			{
				Coord c = getAiCoord(g);
				g.ppField[c.y][c.x] = g.ai;
				Sleep(1000);
			}
			clearScr();
			printGame(g);
			g.progress = getWon(g);
			g.turn++;
		} while (g.progress ==IN_PROGRESS);
		congrats(g);//54.06
		deinitGame(g);
		return 0;
	}
