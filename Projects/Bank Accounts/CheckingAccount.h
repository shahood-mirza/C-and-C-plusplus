#pragma once
#include "Account.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class CheckingAccount : public Account
{
private:
	double fee;

public:
	CheckingAccount(const double &, const double &);
	~CheckingAccount();

	void setFee(const double &);
	double getFee() const;

	void credit(const double &);
	void debit(const double &);
};

