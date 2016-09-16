#include "stdafx.h"
#include "Account.h"


Account::Account(const double &bal)
	: balance(bal)
{

}

Account::~Account()
{

}

void Account::setBalance(const double &bal)
{
	balance = bal;
}

double Account::getBalance() const
{
	return balance;
}

void Account::credit(const double &amnt)
{
	balance += amnt;
}

void Account::debit(const double &amnt)
{
	if ((balance - amnt) >= 0)
	{
		balance -= amnt;
	}
	else
		cout << "Debit amount exceeded account balance.\n";
}