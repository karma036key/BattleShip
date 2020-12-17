#include "GameSteage.h"

GameSteage::GameSteage()
		:PoachingBoat(false)
		,SmallShip(false)
		,Ship(false)
		,LargeShip(false)
		,BigShip(false)
{
	for (int y; y < 10; y++)
	{
		for (int x; x < 10; x++)
		{
			Steage[y][x] = 0;
		}
	}
}

void GameSteage::SetShip()
{
	
	PoachingBoat;
	SmallShip;
	Ship;
	LargeShip;
	BigShip;
}

bool GameSteage::CheckClear()
{
	if (PoachingBoat||SmallShip||Ship||LargeShip||BigShip)
	{
		return true;
	}
	return false;
}
