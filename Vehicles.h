#include "Owners.h"
class Vehicles : public Owners
{
	protected:
		string LicensePlate;
		string Brand;
		string Model;
		string Color;
		vector<Vehicles>listveh;
	public:
		Vehicles(string,string,string,string);
		string GetOwnerID();
		string GetLicensePlate();
		void ReadFromFile();
};
