#include "stdafx.h"
#include "FacultyMember.h"
#include <vector>


int _tmain(int argc, _TCHAR* argv[])
{
	int i,j,k,l; //generic iterators
	string fname, lname, sin, office;

	cout << "How many employees will you be adding? ";
	cin >> i;

	for (j = 0; j < i; j++)
	{
		cout << "First Name: ";
		cin >> fname;
		
		cout << "Last Name: ";
		cin >> lname;

		cout << "SIN: ";
		cin >> sin;

		cout << "Office: ";
		cin >> office;

		cout << "How many courses will you be adding? ";
		cin >> k;

		vector<string> courses(k);

		for (l = 0; l < k; l++)
		{
			cout << "Enter Course Code: ";
			cin >> courses[l];
		}

		FacultyMember employee(fname, lname, sin, office, courses);

		system("cls");
		employee.print();
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}