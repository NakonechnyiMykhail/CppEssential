#pragma once
/*
* Utils
*	IO
		- user(stream) IO
		- file(stream) IO
		- command args
	Math


*/
/*


int main(int argc, char* argv[]) {


	char* c = "text";
	CommandArgs cmd(argc, argv[], 5);


	File f("");
	std::vector<std::string> vec = f.Read();






	return 0;
}


//~/cpp1901/lesson30/ (master) $ ./args 12 Mike some
//There are 4 arguments:
//0 ./args
//1 12 -> int -> atoi(argv[1])
//2 Mike
//3 some
*/

#include <vector>
#include <fstream>

namespace Utils
{
	class User
	{
	public:
		User();
		~User();

	private:

	};

	class File
	{
	public:
		File();
		~File();
		static std::vector<std::string> ReadFile();
		static void WriteFile();
		/*
		//https://github.com/NakonechnyiMykhail/cpp1901/blob/master/lesson30/file_write.cpp
		//https://github.com/NakonechnyiMykhail/cpp1901/blob/master/lesson30/file_read.cpp
		//std::fstream file("SomeText.txt", std::ios::in | std::ios::out);
		//
		//
		//if (!file)
		//{
		//	std::cerr << "FileNmae.txt could not be opened for writing/reading!" << std::endl;
		//	exit(1);
		//}
		*/

	private:
		std::fstream m_file;
	};

	class CommandArgs
	{
	public:
		CommandArgs(int argc, char* argv[], int argCount);
		~CommandArgs();
		static void PrintArgs();
		static void PrintArgCount();

		// HW -> create these functions
		//	std::cout << "There are " << argc << " arguments:\n";

		//for (int count = 0; count < argc; ++count)
		//	std::cout << count << " " << argv[count] << '\n';
	private:
		std::vector<int> m_integerArgs;
		std::vector<int> m_floatArgs;
	};

}


