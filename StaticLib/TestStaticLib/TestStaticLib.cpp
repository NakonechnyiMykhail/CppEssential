// TestStaticLib.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Calc.h"
#include "Utils.h"
#include <cstdlib> // atof()

int main(int argc, char* argv[])
{
    Utils::CommandArgs cmd(argc, argv, 3);
    double a = atof(argv[1]);
    double b = atof(argv[2]);

    std::cout << Math::Arithmetic::Add(a, b);
}
