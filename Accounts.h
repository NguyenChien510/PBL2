#include <iostream>
#include <string>
#include <vector>
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
};

