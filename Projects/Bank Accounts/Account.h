#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Account
{
private:
	double balance;

public:
	Account(const double &);
	~Account();

	void setBalance(const double &);
	double getBalance() const;

	virtual void credit(const double &);
	virtual void debit(const double &);
};

