#include "ParkingLots.h"
#include "Vehicles.h"
class Registrations : public ParkingLots, public Vehicles
{
	protected:
		string RegistrationID;
		short TicketType;
		int TicketPrice;
		string StartTime;
		string EndTime;
		string OwnerID;
		string LicensePlate;
		string LotID;
		vector<Registrations> listregis;
	public:
		Registrations(string,string,string,string,short,int,string,string);
		void ReadFromFile();
};
