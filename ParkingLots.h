#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class ParkingLots
{
	protected:
		string LotID;
		char Area;
		bool Status; // 0 = empty
		vector<ParkingLots>listpark;
	public:
		ParkingLots(string,char,bool);
		void readFromFile();
		string GetLotID();	
};