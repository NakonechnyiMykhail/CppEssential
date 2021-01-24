// TestStaticLib.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Calc.h"
#include "Utils.h"
#include <cstdlib> // atof()
#include <fstream>
#include <string>



class User
{
public:
    User();
    ~User();
    std::string GetString(std::string str);
    void GetString(std::string str, std::string& s);
    bool GetBool(std::string str);
    void GetBool(std::string str, bool& b);
    char GetChar(std::string str);
    int GetInt(std::string str);
    long GetLong(std::string str);
    float GetFloat(std::string str);
    double GetDouble(std::string str);

private:
    std::string m_str;
    char m_char;
    bool m_bool;
    int m_int;
    long m_long;
    float m_float;
    double m_double;
};

User::User()
{
}

User::~User()
{
}

std::string User::GetString(std::string str)
{
    std::cout << str;
    std::cin >> m_str;
    return m_str;
}

void User::GetString(std::string str, std::string& s)
{
}

bool User::GetBool(std::string str)
{
    return false;
}

char User::GetChar(std::string str)
{
    std::cout << str;
    std::cin >> m_char;
    return m_char;
}

int main(int argc, char* argv[])
{
    Utils::CommandArgs cmd(argc, argv, 3);
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    //std::cout << Math::Arithmetic::Add(a, b);

    std::vector<std::string> lines;
    std::string filename = "SomeText.txt";

    Utils::File file(filename, true, lines);
    for (auto& i : lines)
    {
        std::cout << i << std::endl;
    }

    User u;
    std::string str;
    u.GetString("Enter your name: ", str);
    str = u.GetString("Enter your name: ");

    return 0;
}
