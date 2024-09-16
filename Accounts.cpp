#include "Accounts.h"
#include <fstream>

Accounts::Accounts(string username,string password,bool role)
{
	this->username = username;
	this->password = password;
	this->role = role;
}

Accounts::Accounts() {}

void Accounts::readFromFile(string filename,vector<Accounts>& listacc)
{
	ifstream filein(filename);
	if(filein.is_open())
	{
		string user,pass;
		bool role;
		while(!filein.fail())
		{
			getline(filein,user,';');
			getline(filein,pass,';');
			filein>>role;
			filein.ignore();
			Accounts acc(user,pass,role);
			listacc.push_back(acc);
		}
		filein.close();
	}
	else cout << "Cannot open file" << filename << endl;
}

void Accounts::Display(vector<Accounts>& listacc)
{
	for (int i = 0; i < listacc.size(); ++i)
	{
		cout << "Account " << i + 1 << ":" << endl;
		cout << "Username : " << listacc[i].username << endl;
		cout << "Password : " << listacc[i].password << endl;
		cout << "Role     : " << (listacc[i].role ? "Admin" : "User") << endl;
		cout << "-------------------" << endl;
	}
}



bool Accounts::Login(vector<Accounts>& listacc)
{
	string user,pass;
	while(true)
	{
	cout << "Username : ";getline(cin,user);
	cout << "Password : ";getline(cin,pass);
	for(int i = 0 ; i < listacc.size();++i)
	{
		if(listacc[i].username == user && listacc[i].password == pass)
		{
			cout << "Login Success!!!!" << endl;
			if(listacc[i].role = 0)
			{
				
			}
			else
			{
				
			}
			return true; 
		}
	}
	cout << "Invalid username or password!!!!" << endl << endl << endl;
	}
}
