#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include"../Definition.h"

class DataManager
{
public:
	DataManager();
	~DataManager();

	static void ReceiveData(SquareState* status_array);
	static SquareState* PassData();

private:
	static SquareState* status;// [count_height] [count_width] ;


};






#endif