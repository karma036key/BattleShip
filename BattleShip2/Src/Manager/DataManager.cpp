#include"DataManager.h"


SquareState Data::status;

Data::Data()
{



}


Data::~Data()
{



}


void Data::ReceiveData(SquareState status_array)
{
	status = status_array;



}


SquareState Data::PassData()
{
	return status;


}