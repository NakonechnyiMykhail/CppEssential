// fuctions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>

struct Person
{

};
//bool b = true; // false
//char c = 'a'; // '\n'
//std::string s = "my name is mike";
//short sh = 0;
//int i = 0;
//long l = 0l;
//float f = 0.0;
//double d = 0.1e12;
void print();
Person getPerson();
std::string get_str();
std::vector<int> get_vec();
std::list<int> get_list();
std::set<int> get_set();
std::map<int, int> get_map();
unsigned int get_positive_int(std::string str);

// stack
// heap
int main()
{
    //print();
    int length = get_positive_int("Enter a positiv number: ");

    std::vector<int> data;
    for (size_t i = 0; i < length; i++)
    {
        data.push_back(i*i);
    }
    //for (size_t i = 0; i < data.size(); i++)
    //{
    //    std::cout << data[i] << std::endl;
    //}
    for (const auto& element : data)
    {
        std::cout << element << std::endl;
    }


    return 0;
}

void print()
{
    std::cout << "Hello World!\n";
}
unsigned int get_positive_int(std::string str)
{
    int number = 0;
    //uint32_t number2 = 0;
    do
    {
        std::cout << str;
        std::cin >> number;
    } while (number <= 0);
    return number;
}
