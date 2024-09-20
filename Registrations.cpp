#include "Registrations.h"
Registrations::Registrations(string regisid,string ownid,string lp,string lotid,short tickettype,int ticketprice,string stime,string etime)
	:ParkingLots("",'A',0),Vehicles("","","","")
{	
	this->RegistrationID = regisid;
	this->TicketType = tickettype;
	this->TicketPrice = ticketprice;
	this->StartTime = stime;
	this->EndTime = etime;
	this->OwnerID = ownid;
	this->LicensePlate = lp;
	this->LotID = lotid;
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
		string regisid,lp,lotid,stime,etime,ownid;
		short type;int price;
		while(!filein.fail())
		{
			getline(filein,regisid,';');
			getline(filein,lp,';');
			getline(filein,lotid,';');
			filein>>type;filein.ignore();
			getline(filein,stime,';');
			getline(filein,etime,';');
			for(auto &veh:listveh)
			{
				if(veh.GetLicensePlate()==lp)
				{
					ownid = veh.GetOwnerID();
				}
			}
			if(type == 0) price = 50000;
			else if (type == 1) price = 300000;
			else if (type == 2) price = 1000000;
 			Registrations regis(regisid,ownid,lp,lotid,type,price,stime,etime);
			listregis.push_back(regis);
		}
		filein.close();
	}
}
