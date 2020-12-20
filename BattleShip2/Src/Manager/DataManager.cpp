#include"DataManager.h"


DataManager::DataManager()
	:target1_posX{0}
	,target1_posY{0}
	,target2_posX{0}
	,target2_posY{0}
{



}


DataManager::~DataManager()
{



}


void DataManager::ReceiveData1(const ShipSquare& status)
{
	target1_posX=status.GetCenterPosX();
	target1_posY=status.GetCenterPosY();
}


SquareState DataManager::PassData1()
{
	return {0,0,target1_posX,target1_posY,SquareID::NONE,ShipID::SHIP2};
}

void DataManager::ReceiveData2(const ShipSquare& status)
{
	target2_posX = status.GetCenterPosX();
	target2_posY = status.GetCenterPosY();
}


SquareState DataManager::PassData2()
{
	return { 0,0,target2_posX,target2_posY,SquareID::NONE,ShipID::SHIP2 };
}
