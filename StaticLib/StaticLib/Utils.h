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
#include <string>

namespace Utils
{
	class User
	{
	public:
		//User();
		//~User();

		int GetInt(std::string str);
		float GetFloat(std::string str);
		double GetDouble(std::string str);
		char GetChar(std::string str);
		std::string GetString(std::string str);
	private:

	};

	/*
	main()
	{
		int number = GetInt("Enter your best number: ");
	
	}

	
	*/

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
		void PrintArgs();
		void PrintArgCount();

	private:
		int m_args;
		std::vector<std::string> m_argv;

	};

}


