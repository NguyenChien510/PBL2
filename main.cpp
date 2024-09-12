#include "Accounts.h"
int main()
{
	vector<Accounts> listacc;
	Accounts acc;
	acc.readFromFile("Accounts.txt", listacc);
	if(acc.Login(listacc))
	{
		acc.Display(listacc);
	}
	return 0;
} 
