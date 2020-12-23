#include"DataManager.h"


DataManager::DataManager()
	:target1_posX{0}
	,target1_posY{0}
	,target2_posX{0}
	,target2_posY{0}
	,target3_posX{0}
	,target3_posY{0}
	,target4_posX{0}
	,target4_posY{0}
	,target5_posX{0}
	,target5_posY{0}
	,target6_posX{0}
	,target6_posY{0}
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


void DataManager::ReceiveData3(const ShipSquare& status)
{
	target3_posX = status.GetCenterPosX();
	target3_posY = status.GetCenterPosY();
}


SquareState DataManager::PassData3()
{
	return { 0,0,target3_posX,target3_posY,SquareID::NONE,ShipID::SHIP2 };
}


void DataManager::ReceiveData4(const ShipSquare& status)
{
	target4_posX = status.GetCenterPosX();
	target4_posY = status.GetCenterPosY();
}


SquareState DataManager::PassData4()
{
	return { 0,0,target4_posX,target4_posY,SquareID::NONE,ShipID::SHIP2 };
}


void DataManager::ReceiveData5(const ShipSquare& status)
{
	target5_posX = status.GetCenterPosX();
	target5_posY = status.GetCenterPosY();
}


SquareState DataManager::PassData5()
{
	return { 0,0,target5_posX,target5_posY,SquareID::NONE,ShipID::SHIP2 };
}


void DataManager::ReceiveData6(const ShipSquare& status)
{
	target6_posX = status.GetCenterPosX();
	target6_posY = status.GetCenterPosY();
}


SquareState DataManager::PassData6()
{
	return { 0,0,target6_posX,target6_posY,SquareID::NONE,ShipID::SHIP2 };
}
