// BankAccounts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>


int _tmain(int argc, _TCHAR* argv[])
{
	double amount;

	vector <Account *> accounts(4);
	accounts[0] = new CheckingAccount(4000, 5);
	accounts[1] = new SavingsAccount (5000, 0.1);
	accounts[2] = new CheckingAccount(10000, 10);
	accounts[3] = new SavingsAccount(2000, 0.05);

	for (int i = 0; i < accounts.size(); i++)
	{		
		SavingsAccount *derivedPtr = dynamic_cast <SavingsAccount *> (accounts[i]);

		cout << "Account is: " << typeid(*accounts[i]).name() << "\n";
		cout << "Balance: $" << accounts[i]->getBalance() << "\n";

		if (derivedPtr != 0)
		{
			cout << "Interest Rate: " << (derivedPtr->getInterestRate())*100 << "%\n";
			cout << "Interest Added: $" << derivedPtr->calculateInterest() << "\n";
			derivedPtr->credit(derivedPtr->calculateInterest());
			cout << "New Balance: $" << derivedPtr->getBalance() << "\n";
		}

		cout << "\n\nHow much will you be depositing? ";
		cin >> amount;
		accounts[i]->credit(amount);

		cout << "\nNew Balance: $" << accounts[i]->getBalance() << "\n";


		cout << "\nHow much will you be withdrawing? ";
		cin >> amount;
		accounts[i]->debit(amount);

		cout << "\nNew Balance: $" << accounts[i]->getBalance() << "\n";
		
		system("Pause");
		system("cls");
	}

	system("Pause");

	return 0;
}

