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

void adminInterface()
{
	cout << "-------------- QUAN LI BAI DO XE ---------------"<<endl;
	cout << "*               1.Them ve moi                  *"<<endl;
	cout << "*               2.Xem danh sach bai do         *"<<endl;
	cout << "*               3.Chinh sua ve                 *"<<endl;
	cout << "*               4.Xoa ve                       *"<<endl;
	cout << "*               5.Thong ke                     *"<<endl;
	cout << "*               6.Dang xuat                    *"<<endl;
	cout << "*               7.Thoat                        *"<<endl;
	cout << "------------------------------------------------"<<endl;
	cout << "Nhap lua chon : ";
}

void userInterface()
{
	cout << "-------------- CHUC NANG ----------------------"<<endl;
	cout << "*               1.Dat ve                      *"<<endl;
	cout << "*               2.Xem ve                      *"<<endl;
	cout << "*               3.Chinh sua                   *"<<endl;
	cout << "*               4.Dang xuat                   *"<<endl;
	cout << "*               5.Thoat                       *"<<endl;
	cout << "LUU Y : Moi user chi dang ki toi da 3 ve!!!!!!!"<<endl;
	cout << "-----------------------------------------------"<<endl;
	cout <<"Nhap lua chon : ";
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
			if(listacc[i].role = 1)
			{
				adminInterface();
			}
			else
			{
				userInterface();
			}
			return true; 
		}
	}
	cout << "Invalid username or password!!!!" << endl << endl << endl;
	}
}
