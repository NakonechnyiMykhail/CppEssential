
#include "pch.h"


//// read data in file
//std::ifstream infile("FileName.txt", std::ios::binary);
//
//if (!infile)
//{
//    std::cerr << "FileNmae.txt could not be opened for reading!" << std::endl;
//    exit(1);
//}

std::vector<std::string> ReadFile(std::ifstream &infile)
{
    std::vector<std::string> vec;
    while (infile)
    {
        std::string strInput;
        // infile >> strInput; // each element throw space
        getline(infile, strInput);
        vec.push_back(strInput);
        //// console
        //std::cout << strInput << std::endl;
    }
    return vec;
}

