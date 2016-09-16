#pragma once
#include <string>
#include <iostream>

using namespace std;

class Employee
{
private:
	string firstName;
	string lastName;
	string SIN;

public:
	Employee(const string &, const string &, const string &);
	~Employee(); //destructor

	void setFirstName(const string &); //set first name
	string getFirstName() const; //return first name

	void setLastName(const string &); //set last name
	string getLastName() const; //return last name

	void setSIN(const string &); //set SIN
	string getSIN() const; //return SIN

	void print() const;	//print employee object
};

