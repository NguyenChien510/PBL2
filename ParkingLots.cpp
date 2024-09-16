#include "ParkingLots.h"
ParkingLots::ParkingLots(string ID,char area,bool status)
{
	this->LotID = ID;
	this->Area  = area;
	this->Status= status;
}
void ParkingLots::readFromFile()
{
	ifstream filein("ParkingLots.txt");
	if(!filein.is_open())
	{
		cout << "Cannot open ParkingLots.txt"<<endl;
	}
	else
	{
		string id;
		char area;
		bool status;
		while(!filein.fail())
		{
			getline(filein,id,';');
			filein >> area;
			filein.ignore();
			filein >> status;
			ParkingLots park(id,area,status);
			listpark.push_back(park);
		}
		filein.close();
	}
}

string ParkingLots::GetLotID()
{
	return this->LotID;
}

