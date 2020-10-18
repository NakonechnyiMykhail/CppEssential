#pragma once
#include <cmath>
#include <vector>

namespace Math
{
	class Arithmetic
	{
	public:
		// returns a + b
		static double Add(double number1, double number2);
		
		// returns a - b
		static double Subtract(double number1, double number2);

		// returns a * b
		static double Multiply(double number1, double number2);

		// returns a / b
		static double Divide(double number1, double number2);

		// returns a / b
		static bool isEqual(double a, double b, double epsilon = 0.000001);

		// lesson11_ex1  
		static char* decToBin(char* s, int n); 



		static void printSumElementsOfVec(const std::vector<auto>& myVector);


		static auto sumElements2(const std::vector<auto>& myVector);

		static int max(int a, int b);


		static int fibonacci(int number);


		static void countOut(int count);

		static int sumCount(int value);

		static int recnum(int n, int i);
	};
}

/*
#include <fstream>
		int Fib(int i)
		{
			unsigned long f1 = 0;
			unsigned long f2 = 1;
			unsigned long fn;
			ofstream file("fib.txt");
			if (file.is_open())
			{
				if (i < 1)
				{
					return 0;
				}
				if (i == 1)
				{
					file << "0" << endl;
					file << "1" << endl;
					cout << "0" << endl;
					cout << "1" << endl;
				}
				if (i > 1)
				{
					file << "0" << endl;
					file << "1" << endl;
					cout << "0" << endl;
					cout << "1" << endl;
					for (int j = 1; j < i; j++)
					{
						fn = f1 + f2;
						file << fn << endl;
						cout << fn << endl;
						f1 = f2;
						f2 = fn;
					}

				}
				file.close();
			}
			else cout << "Something went wrong";

			return 0;
		}
*/

/*
int getValueFromUser()
{
	cout << "Enter an Integer: ";
	int x = 0;
	cin >> x;
	return x;
}

void print()
{
	std::cout << 2 * 2 << std::endl;
}

char getSymbol()
{
	char symbol = '0';
	cin >> symbol;
	return symbol;
}

#include <string>
int getNameLength(std::string name)
{
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Hello, " << name << std::endl; //1
	std::cout << "Length: " << name.length() << std::endl; //2
	return name.length();
}


#include <ctime>
// in main start with: 
//		srand(time(0));
long int random()
{
	return 1 + rand() % 50; // от 1 до 50
}

long int random(int, int)
{
	return 1 + rand() % 50; // от 1 до 50
}


std::string func(std::string name)
{
	return ("Hello, " + name);
}


#include <array> // c++11
#include <algorithm> // std::sort
void printLength(const std::array<auto, 5>& myArray)
{
	std::cout << "Array length = " << myArray.size() << std::endl;
}





void printLength(const std::vector<auto>& myVector)
{
	std::cout << "Array length = " << myVector.size() << std::endl;
}
void addElementToVector(std::vector<auto>& myVector)
{
	auto tmp = 0;
	std::cout << "Enter number to add at vector: ";
	std::cin >> tmp;
	myVector.push_back(tmp);
}

void printSize(int* array)
{
	cout << sizeof(array) << endl; // *(*array)
	cout << array[3] << endl;
	cout << array[7] << endl;
}

void printSize2(int array[])
{
	cout << sizeof(array) << endl; // *(*array)

}


#include <cstdint> // std::int16_t
#include <limits>

double getValue(std::string str) // ("Enter a length: ")
{
	while (true)
	{
		std::cout << str;
		double value;
		std::cin >> value;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return value;
		}
	}

}

char getOperator()
{
	while (true)
	{
		std::cout << "Enter one of the following: +, -, * or /: ";
		char op;
		std::cin >> op;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (op == '+' || op == '-' || op == '*' || op == '/')
			return op;
		else
			std::cout << "Oops, that input is invalid. Please try again.\n";
	}

}

void printResult(double value1, char op, double value2)
{
	if (op == '+')
		std::cout << value1 << " + " << value2 << " is " << value1 + value2 << '\n';
	else if (op == '-')
		std::cout << value1 << " - " << value2 << " is " << value1 - value2 << '\n';
	else if (op == '*')
		std::cout << value1 << " * " << value2 << " is " << value1 * value2 << '\n';
	else if (op == '/')
		std::cout << value1 << " / " << value2 << " is " << value1 / value2 << '\n';
	else
		std::cout << "Something went wrong: func got an invalid operator.";
}


void printStack(const std::vector<auto>& stack)
{
	for (auto const& element : stack)
		std::cout << element << ' ';
	std::cout << "(cap: " << stack.capacity() << '\t' << "len: " << stack.size() << ")\n";

}











//https://github.com/NakonechnyiMykhail/cpp1901/blob/master/lesson31/date.cpp

*/
