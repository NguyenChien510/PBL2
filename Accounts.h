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
	public:
		Accounts();
		Accounts(string,string,bool);
		void readFromFile(string,vector<Accounts>&);
		void Display(vector<Accounts>&);
		bool Login(vector<Accounts>&);	
};

