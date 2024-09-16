#include "Registrations.h"
Registrations::Registrations(string regisid,short tickettype,int ticketprice,string stime,string etime)
	:ParkingLots("",'A',0),Vehicles("","","","")
{	
	this->RegistrationID = regisid;
	this->TicketType = tickettype;
	this->TicketPrice = ticketprice;
	this->StartTime = stime;
	this->EndTime = etime;
}

void Registrations::ReadFromFile()
{
	ifstream filein("Registrations.txt");
	if(!filein.is_open())
	{
		cout << "Cannot open Registrations.txt"<<endl;
	}
	else
	{
		string regisid,pl,lotid,stime,etime;
		short type;int price;
		while(!filein.fail())
		{
			getline(filein,regisid,';');
			getline(filein,pl,';');
			getline(filein,lotid,';');
			filein>>type;filein.ignore();
			getline(filein,stime,';');
			getline(filein,etime,';');
			if(type == 0) price = 50000;
			else if (type == 1) price = 300000;
			else if (type == 2) price = 1000000;
 			Registrations regis(regisid,type,price,stime,etime);
			listregis.push_back(regis);
		}
		filein.close();
	}
}
