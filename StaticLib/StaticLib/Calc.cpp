#include "pch.h"

namespace Math
{
	double Arithmetic::Add(double number1, double number2)
	{
		return number1 + number2;
	}
	double Arithmetic::Subtract(double number1, double number2)
	{
		return number1 - number2;
	}
	double Arithmetic::Multiply(double number1, double number2)
	{
		return number1 * number2;
	}
	double Arithmetic::Divide(double number1, double number2)
	{
		return number1 / number2;
	}

	bool Arithmetic::isEqual(double a, double b, double epsilon)
	{
		return fabs(a - b) <= epsilon;//eps = 0.000001
	}

	char* Arithmetic::decToBin(char* s, int n) 
	{
		unsigned int u = (unsigned int)n;
		char* t = s;

		do {
			*s++ = (char)((u & 1) + '0');
		} while ((u >>= 1) != 0);
		*s-- = '\0';

		char c;
		for (char* p = t; p < s; ++p, --s) {
			c = *p;
			*p = *s;
			*s = c;
		}
		return t;
	}
}


