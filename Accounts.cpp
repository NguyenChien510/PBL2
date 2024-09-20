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
			filein.ignore();
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

int	Accounts::checkinput(string s){
	for(char c:s){
		if(!isdigit(c)) return -1;
	}
	if(s=="") return -1;
	else
	return stoi(s);
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
		if(acc.username == user && acc.password == pass && acc.role == 1)
		{
			cout << "Login Success!!!!" << endl;
				string option;
				while(1)
				{
					AdminInterface();
					getline(cin,option);
					int check = checkinput(option);
					system("cls");
					switch(check)
					{
						case 1:
							cout << "------ TAO VE MOI ------"<<endl;
							
							break;
						case 2:
							cout << "------ DANH SANH ------"<<endl;
							ParkingLots pl;
							pl.Show(4);
							cout <<endl<<endl<<"BAM PHIM BAT KI DE QUAY TRO LAI....."<<endl;
                    		_getch();
                    		system("cls");
							break;
						
					}
				}
			}
			else if(acc.username == user && acc.password == pass && acc.role == 0)
			{
				cout << "Login Success!!!!" << endl;
				string option;
				while(1)
				{
					UserInterface();
					getline(cin,option);
					int check = checkinput(option);
					system("cls");
					switch(check)
					{
						case 1:{
							string option;
							cout << "-------- DAT VE ------------"<<endl;
							cout << "Chon loai ve:"<<endl;
							cout << "1.Ngay"<<endl;
							cout << "2.Tuan"<<endl;
							cout << "3.Thang"<<endl;
							cout << "Chon loai ve: "<<endl;
							getline(cin,option);
							int check = checkinput(option);
							ParkingLots pl;
							switch(check)
							{
								case 1:{
									pl.Show(1);
									break;
								}
								case 2:{
									pl.Show(2);
									break;
								}
								case 3:{
									pl.Show(3);
									break;
								}
							}
						}		
					}
				}
				
			}
		}
		cout << "Invalid username or password!!!"<<endl;
	}
}
