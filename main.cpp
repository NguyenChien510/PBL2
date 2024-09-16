#include "Accounts.h"
#include <windows.h>
int main()
{
	system("color 3");
	vector<Accounts> listacc;
	Accounts acc;
	acc.readFromFile("Accounts.txt", listacc);
	acc.Login(listacc);
	return 0;
} 
