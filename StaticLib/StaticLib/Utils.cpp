#include "pch.h"
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

	m_args = argc;
	for (size_t i = 0; i < m_args; i++)
	{
		m_argv.push_back(argv[i]); // .c_str()
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

Utils::CommandArgs::~CommandArgs()
{

}

void Utils::CommandArgs::PrintArgs()
{
	for (const auto& str : m_argv)
	{
		std::cout << str << std::endl;
	}
}

void Utils::CommandArgs::PrintArgCount()
{
	std::cout << "Count of args: " << m_args << std::endl;
}


Utils::File::File(const std::string& filename, bool isRead, std::vector<std::string>& vec) :
	m_filename(filename)
{
	if (isRead)
	{
		m_ifile.open(m_filename, std::ios::out);
		if (!m_ifile)
		{
			std::cerr << "\n\n" << m_filename << " could not be opened for reading!" << std::endl;
			exit(1);
		}
		if (m_ifile.is_open()) // read
		{
			std::string line;
			while (std::getline(m_ifile, line))
			{
				vec.push_back(line);
			}
		}
	}
	else
	{
		m_ofile.open(m_filename, std::ios::in);
		if (!m_ofile)
		{
			std::cerr << "\n\n" << m_filename << " could not be opened for writing!" << std::endl;
			exit(1);
		}
		if (m_ofile.is_open()) // write
		{
			for (auto& str : vec)
			{
				m_ofile << str << std::endl;
			}
		}

	}
}

Utils::File::~File()
{
	m_ifile.close();
	m_ofile.close();
}
