#include "stdafx.h"
#include "Complex.h"


Complex::Complex(double arg1, double arg2)
{
	real = arg1;
	imaginary = arg2;
}


Complex::~Complex()
{
}

bool Complex::operator==(const Complex &number) const
{
	return real == number.real && imaginary == number.imaginary;
}