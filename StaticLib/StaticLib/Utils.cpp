#include "Utils.h"
#include <iostream>
#include <cstdlib> // exit()

Utils::CommandArgs::CommandArgs(int argc, char* argv[], int argCount)
{
	if (argc < argCount)
	{
		if (argv[1])
			std::cerr << "Usage: " << argv[0] << " <" << argCount << "> " << '\n';
		else
			std::cerr << "Usage: <program name> <number of args>" << '\n';

		exit(1);
	}
	/*
	* getListDataOfIntegers -> {1, 4, 7}
	* getListDataOfFloats -> {2, 3, 5}
	* 
	* C-style
	* ints-> {1, 4, 7} -> for-each (index = 1, 4, 7)-> atoi(argv[index])
	* floats-> {2, 3, 5} -> for-each (index = 2, 3, 5)-> atof(argv[index])
	* 
	* C++ style
	* 	#include <sstream> // std::stringstream
	std::stringstream convert(argv[1]);
	int number;
	if (!(convert >> number))
		number = 0;

	std::cout << "Got integer: " << number << '\n';
	*/
	
}
