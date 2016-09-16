#include "stdafx.h"
#include "FacultyMember.h"


FacultyMember::FacultyMember(const string &first, const string &last, const string &sin, const string &office, const vector<string> &courses)
	: Employee(first, last, sin)
{
	setOffice(office);
	setCourses(courses);
}

FacultyMember::~FacultyMember()
{

}

void FacultyMember::setCourses(const vector<string> &courses)
{
	courseCodes = courses;
}

vector<string> FacultyMember::getCourses() const
{
	return courseCodes;
}

void FacultyMember::setOffice(const string &office)
{
	officeNum = office;
}

string FacultyMember::getOffice() const
{
	return officeNum;
}

void FacultyMember::print()
{
	//invoke employee's print function
	Employee::print();

	cout << "\nOffice: " << getOffice()
		<< "\nCourses: ";

	for (i = 0; i < courseCodes.size(); i++)
	{
		cout << courseCodes[i]
			<< "\n";
	}
		
	cout << "\n\n\n";
}
