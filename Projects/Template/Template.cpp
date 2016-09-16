#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include "Complex.h"

using namespace std;

template < typename Temp >
bool isEqualTo(const Temp &arg1, const Temp &arg2) {
	return arg1 == arg2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//char test
	char char1;
	char char2;

	cout << "Enter two character values: ";
	cin >> char1 >> char2;
	cout << char1 << " and " << char2 << " are "
		<< (isEqualTo(char1, char2) ? "equal" : "not equal") << '\n';

	//int test
	int int1;
	int int2;
	
	cout << "\nEnter two integer values: ";
	cin >> int1 >> int2;
	cout << int1 << " and " << int2 << " are "
		<< (isEqualTo(int1, int2) ? "equal" : "not equal") << '\n';

	//double test
	double dbl1;
	double dbl2;

	cout << "\nEnter two double values: ";
	cin >> dbl1 >> dbl2;
	cout << dbl1 << " and " << dbl2 << " are "
		<< (isEqualTo(dbl1, dbl2) ? "equal" : "not equal") << '\n';

	//complex object test
	cout << "\nEnter real and imaginary parts of the first complex number: ";
	cin >> dbl1 >> dbl2;
	Complex obj1(dbl1, dbl2);

	cout << "\nEnter real and imaginary parts of the second complex number: ";
	cin >> dbl1 >> dbl2;
	Complex obj2(dbl1, dbl2);

	cout << "\nThe class objects are "
		<< (isEqualTo(obj1, obj2) ? "equal" : "not equal") << '\n';

	system("pause");

	return 0;
}