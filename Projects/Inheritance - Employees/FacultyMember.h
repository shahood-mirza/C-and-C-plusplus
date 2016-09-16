#pragma once
#include "Employee.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class FacultyMember : public Employee
{
private:
	int i = 0; //iterator for courses
	string officeNum;
	vector<string> courseCodes;

public:
	FacultyMember(const string &, const string &, const string &, const string &, const vector<string> &);
	~FacultyMember(); //destructor

	void setCourses(const vector<string> &); //set courses
	vector<string> getCourses() const; //return courses

	void setOffice(const string &); //set office number
	string getOffice() const; //return office number

	void print();	//print faculty member object
};

