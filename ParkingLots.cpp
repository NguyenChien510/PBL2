#include "ParkingLots.h"
ParkingLots::ParkingLots(string ID,char area,bool status)
{
	this->LotID = ID;
	this->Area  = area;
	this->Status= status;
}
void ParkingLots::ReadFromFile()
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
		while(getline(filein, id, ';'))
		{
			filein >> area;
			filein.ignore();
			filein >> status;
			filein.ignore();
			ParkingLots park(id,area,status);
			listpark.push_back(park);
		}
		filein.close();
	}
}

ParkingLots::ParkingLots() {ReadFromFile();}

string ParkingLots::GetLotID()
{
	return this->LotID;
}

void ParkingLots::Show()
{
	for(auto park:listpark)
	{
	cout << "LotID : " << park.LotID << endl;
	cout << "Area  : " << park.Area  << endl;
	cout << "Status: " << ((park.Status) ? "ORDER" : "EMPTY") << endl;
	cout << "-------------------"<<endl;
	}
	cout << "Nhap LotID can xem : ";
}

