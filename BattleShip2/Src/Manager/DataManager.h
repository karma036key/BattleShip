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

	void ReceiveData1(const ShipSquare& status);
	SquareState PassData1();

	void ReceiveData2(const ShipSquare& status);
	SquareState PassData2();
private:
	ShipSquare ship;
	int target1_posX;
	int target1_posY;
	int target2_posX;
	int target2_posY;

};






#endif