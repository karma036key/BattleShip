#include"DataManager.h"


DataManager::DataManager()
{



}


DataManager::~DataManager()
{



}


void DataManager::ReceiveData(const ShipSquare& status)
{
	targetPosX=status.GetReleasePosXForDraw();
	targetPosY=status.GetReleasePosYForDraw();


}


SquareState DataManager::PassData()
{
	return {0,0,targetPosX,targetPosY,SquareID::NONE,ShipID::SHIP2};


}