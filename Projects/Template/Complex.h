#pragma once

class Complex
{
private:
	double real;
	double imaginary;

public:
	Complex(double arg1, double arg2);
	~Complex();

	bool operator==(const Complex &number) const;
};

