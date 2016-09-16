#include "stdafx.h"
#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(const double &bal, const double &intRate)
	: Account(bal)
{
	setInterestRate(intRate);
}

SavingsAccount::~SavingsAccount()
{

}

void SavingsAccount::setInterestRate(const double &intRate)
{
	interestRate = intRate;
}

double SavingsAccount::getInterestRate() const
{
	return interestRate;
}

double SavingsAccount::calculateInterest()
{
	interest = Account::getBalance() * interestRate;
	return interest;
}