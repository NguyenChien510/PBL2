#include "Accounts.h"
#include <fstream>

Accounts::Accounts(string username,string password,bool role)
{
	this->username = username;
	this->password = password;
	this->role = role;
}

Accounts::Accounts() {}

void Accounts::ReadFromFile()
{
	ifstream filein("Accounts.txt");
	if(filein.is_open())
	{
		string user,pass;
		bool role;
		while(!filein.fail())
		{
			getline(filein,user,';');
			getline(filein,pass,';');
			filein>>role;
			Accounts acc(user,pass,role);
			listacc.push_back(acc);
		}
		filein.close();
	}
	else cout << "Cannot open file Accounts.txt" << endl;
}

void AdminInterface()
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

void UserInterface()
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

bool Accounts::Login()
{
	ReadFromFile();
	string user,pass;
	while(true)
	{
	cout << "Username : ";getline(cin,user);
	cout << "Password : ";getline(cin,pass);
	for(auto acc : listacc)
	{
		if(acc.username == user && acc.password == pass)
		{
			cout << "Login Success!!!!" << endl;
			if(acc.role)
			{
				AdminInterface();
			}
			else
			{
				UserInterface();
			}
			return true; 
		}
	}
	cout << "Invalid username or password!!!!" << endl << endl;
	}
}
