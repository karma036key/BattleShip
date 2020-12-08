#include"DataManager.h"


SquareState* DataManager::status;

DataManager::DataManager()
{



}


DataManager::~DataManager()
{



}


void DataManager::ReceiveData(SquareState* status_array)
{
	status = status_array;



}


SquareState* DataManager::PassData()
{
	return status;


}