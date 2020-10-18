#include "pch.h"
#include <iostream>

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

	void printSumElementsOfVec(const std::vector<auto>& myVector)
	{
		auto summ = 0;
		for (auto const& element : myVector)
			summ += element;
		std::cout << "Summ of vector = " << summ << std::endl;
	}

	auto sumElements2(const std::vector<auto>& myVector)
	{
		auto summ = 0;
		for (auto const& element : myVector)
			summ += element;
		return summ;
	}

	int max(int a, int b)
	{
		return a < b ? b : a;
	}

	int sumCount(int value)
	{
		if (value <= 0)
			return 0;
		else if (value == 1)
			return 1;
		else
			return sumCount(value - 1) + value; // 4 + .. + 3 + .. + 2 + .. + 1 = 10

	}

	int fibonacci(int number)
	{
		if (number == 0)
			return 0;
		if (number == 1)
			return 1;
		return fibonacci(number - 1) + fibonacci(number - 2);
	}
	void countOut(int count)
	{
		std::cout << "push: " << count << '\n';

		if (count > 1)
			countOut(count - 1);

		std::cout << "pop: " << count << '\n';
	}

	int recnum(int n, int i) 
	{
		return (n == 0) ? i : recnum(n / 10, i * 10 + n % 10);
	}
}


