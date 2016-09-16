#pragma once
#include "Account.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class SavingsAccount : public Account
{
private:
	double interestRate;
	double interest;

public:
	SavingsAccount(const double &, const double &);
	~SavingsAccount();

	void setInterestRate(const double &);
	double getInterestRate() const;

	double calculateInterest();
};

