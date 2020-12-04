#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include"../Definition.h"

class Data
{
public:
	Data();
	~Data();

	static void ReceiveData(SquareState status_array);
	static SquareState PassData();

private:
	static SquareState status;


};






#endif