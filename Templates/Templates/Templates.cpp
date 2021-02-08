// Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//int max(int a, int b)
//{
//    return (a > b) ? a : b;
//}
//double max(double a, double b)
//{
//    return (a > b) ? a : b;
//}

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
T1 max(T1 a, T2 b)
{
    // a = number1
    // b = number2
    return (a > b) ? a : b;
}
//max(number1, number2)

// for classes and objects
//template <typename T>
//const T& max(const T& a, const T& b)
//{
//    return (a > b) ? a : b;
//}

int main()
{
    std::cout << max(4, 8) << std::endl;
    std::cout << max(4.1, 8.2) << std::endl;
    std::cout << max(4, 8.2) << std::endl;
    std::cout << max(4.6, 8) << std::endl;
}
