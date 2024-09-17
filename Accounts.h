#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Registrations.h"
using namespace std;
class Accounts
{
	private:
		string username;
		string password;
		bool role;
		vector<Accounts>listacc;
	public:
		Accounts();
		Accounts(string,string,bool);
		void ReadFromFile();
		bool Login();	
		int checkinput(string); 
};

