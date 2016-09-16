#include "stdafx.h"
#include "Employee.h"


Employee::Employee(const string &first, const string &last, const string &sin)
	: firstName(first), lastName(last), SIN(sin)
{

}

Employee::~Employee()
{
	
}

void Employee::setFirstName(const string &first)
{
	firstName = first;
}

string Employee::getFirstName() const
{
	return firstName;
}

void Employee::setLastName(const string &last)
{
	lastName = last;
}

string Employee::getLastName() const
{
	return lastName;
}

void Employee::setSIN(const string &sin)
{
	SIN = sin;
}

string Employee::getSIN() const
{
	return SIN;
}

void Employee::print() const
{
	cout << "Employee Added: \n\n"
		<< getFirstName() << ' ' << getLastName()
		<< "\nSIN: " << getSIN();
}