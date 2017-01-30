#include "MineManager.h"

//constructor sets x pos for all the mines
MineManager::MineManager()
{
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist(0, 700);
	for (int i = 0; i < nMinesMax; i++)
	{
		mine[i].SetPos(xDist(rng));
	}
}

//updates the active mines, take ship as argument since it's needed in mines update function
void MineManager::Update(Ship& ship)
{
	for (int i = 0; i < nMines; i++)
	{
		if (mine[i].isActive())
		mine[i].Update(ship);
	}

	//when mine counter reaches newMine a new mine will be drawn on screen
	//unless nMines == nMinesMax because that's the end of the array, there are no more mines to be drawn
	mineCounter++;
	if (mineCounter == newMine && nMines != nMinesMax)
	{
		nMines++;
		mineCounter = 0;
	}
}

//Draws the mines 
void MineManager::Draw(Graphics & gfx, Ship& ship)
{
	for (int i = 0; i < nMines; i++)
	{
		mine[i].Draw(gfx, ship);
	}
}