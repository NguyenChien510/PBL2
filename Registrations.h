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
		vector<Registrations> listregis;
	public:
		Registrations(string,short,int,string,string);
		void ReadFromFile();
};
