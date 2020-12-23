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

	void ReceiveData3(const ShipSquare& status);
	SquareState PassData3();

	void ReceiveData4(const ShipSquare& status);
	SquareState PassData4();

	void ReceiveData5(const ShipSquare& status);
	SquareState PassData5();

	void ReceiveData6(const ShipSquare& status);
	SquareState PassData6();
private:
	ShipSquare ship;
	int target1_posX;
	int target1_posY;
	int target2_posX;
	int target2_posY;
	int target3_posX;
	int target3_posY;
	int target4_posX;
	int target4_posY;
	int target5_posX;
	int target5_posY;
	int target6_posX;
	int target6_posY;

};






#endif