// TestStaticLib.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Calc.h"
#include "Utils.h"
#include <cstdlib> // atof()

int main(int argc, char* argv[])
{
    Utils::CommandArgs::CommandArgs(argc, argv, 2);
    double a = atof(argv[0]);
    double b = atof(argv[1]);

    std::cout << Math::Arithmetic::Add(a, b);
}
