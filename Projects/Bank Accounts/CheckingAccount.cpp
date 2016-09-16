#include "stdafx.h"
#include "CheckingAccount.h"


CheckingAccount::CheckingAccount(const double &bal, const double &fees)
	:Account(bal)
{
	setFee(fees);
}

CheckingAccount::~CheckingAccount()
{

}

void CheckingAccount::setFee(const double &fees)
{
	fee = fees;
}

double CheckingAccount::getFee() const
{
	return fee;
}

void CheckingAccount::credit(const double &amnt)
{
	Account::credit(amnt);
	Account::debit(fee);
}

void CheckingAccount::debit(const double &amnt)
{
	Account::debit(amnt);
	Account::debit(fee);
}