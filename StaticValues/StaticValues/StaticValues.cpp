// StaticValues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int generateID()
{
    static int s_id = 0;
    return ++s_id;
}

class Anything
{
public:
    static int s_value;
    static const int s_value2 = 0;
    static constexpr float exp = 2.7;
    //int arr[5];
    //std::array<int, 4>
    //std::vector<int>
 
    static int getVal() { return s_val; }
private:
    static int s_val;
};

int Anything::s_value = 3;
int Anything::s_val = 1;


class Hero
{
public:
    Hero() { m_id = s_idGenerator++; }
    int getID() const { return m_id; }

private:
    static int s_idGenerator;
    int m_id;
};
int Hero::s_idGenerator = 1;

class IDGenerator
{
private:
    static int s_nextID;
public:
    static int getNextID();
};
int IDGenerator::s_nextID = 1;
int IDGenerator::getNextID() { return s_nextID++; }


int main()
{
    //std::cout << generateID() << std::endl;
    //std::cout << generateID() << std::endl;
    //std::cout << generateID() << std::endl;
    // --------------------------------------------------------
    //Anything first;
    //Anything second;
    //first.s_value = 4;
    //std::cout << first.s_value << std::endl;
    //std::cout << second.s_value << std::endl;
    // --------------------------------------------------------
    //Anything::s_value = 4;
    //std::cout << Anything::s_value << std::endl;
    //std::cout << Anything::getVal() << std::endl;
    // --------------------------------------------------------
    //Hero bull;
    //Hero djoker;
    //Hero mage;
    //std::cout << bull.getID() << std::endl;
    //std::cout << mage.getID() << std::endl;
    //std::cout << djoker.getID() << std::endl;
    // --------------------------------------------------------

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "The next ID is: " << IDGenerator::getNextID() << std::endl;
    }
}

