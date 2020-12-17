#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include"../Definition.h"
#include"../Singleton.h"
#include"../Square/ShipSquare.h"
#include"../Square/SelectSquare.h"

class DataManager :public Singleton<DataManager>
{
public:
	DataManager();
	~DataManager();

	void ReceiveData(const ShipSquare& status);
	SquareState PassData();

private:
	ShipSquare ship;
	int targetPosX;
	int targetPosY;

};






#endif