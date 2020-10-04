// lesson3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "pch.h"
#include "ReadFile.h"


int main()
{
    bool b = true; // false
    char c = 'a'; // '\n'
    std::string s = "my name is mike";
    short sh = 0;
    int i = 0;
    long l = 0l;
    float f = 0.0;
    double d = 0.1e12;

    std::cout << Add(20, 23) << std::endl;
    //ReadFile();

    /* condition
    > < >= <= == != & && (and) | || (or) ^ (xor) !(not)
    a > b (4>3) -> true
    a == b (5 == 5) -> true
    true && true          (true and true) (4 > 3 and a == b)
    || (or)
    (a != b and c != b and a == c) or (a == b and b == c)
    !true -> false
    !false -> true
     */

     // if (!true)
     // {
     //     std::cerr << "Error!!!" << std::endl;
     //     return -1;
     // }

     // if (/* condition */)
     // {
     //     /* code */
     // }
     // else
     // {
     //     /* code */
     // }

     // if (/* condition */)
     // {
     //     /* code */
     // }
     // else if (/* condition */)
     // {
     //     /* code */
     // }
     // else
     // {
     //     /* code */
     // }
    int a = 1;
    switch (a)
    {
    case 1:
        std::cout << "Monday" << std::endl;
        break;
    case 2:
        std::cout << "Tuesday" << std::endl;
        break;
    case 5:
        std::cout << "Friday" << std::endl;
        break;
    default:
        break;
    }


    // for (size_t i = 0; i < count; i++)
    // {
    //     /* code */
    // }
    // for(;;)
    // {

    // }
    // for (auto &&i : v)
    // {

    // }
    // while (a>0) // a <10
    // {
    //     /* code */
    //     --a; // ++a;
    // }
    // do
    // {
    //     /* code */
    // } while (a<0);

    const int count = 10;

    int arr[count];
    int arr2[count] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arr3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // arr2[0] = 0;
    // arr2[1] = 0;
    // arr2[2] = 0;
    // arr2[3] = 0;
    // arr2[4] = 0;
    for (size_t i = 0; i < count; i++)
    {
        arr[i] = 0;
    }
    for (size_t i = 0; i < count; i++)
    {
        arr[i] = i * i;
        std::cout << arr[i] << ' ';
    }


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
