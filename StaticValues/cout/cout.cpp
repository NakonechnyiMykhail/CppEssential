#include <iostream>
#include <iomanip> 
int main()
{
    // manipulators / flags


    // std::boolalpha   - on  (true/false)
    // std::noboolalpha - off (1/0)
    // bool logic = true; 
    // std::cout << std::boolalpha << logic << std::endl;

    // basefield
    // oct/ dec/ hex
    //std::cout.unsetf(std::ios::dec);
    // std::cout.setf(std::ios::hex);
    // std::cout << std::hex << 30 << std::endl;

    // showpos
    // noshowpos
    // std::cout.setf(std::ios::showpos);
    // std::cout << std::dec << 30 << std::endl;

    // fixed        = 140000
    // scientific   = 1.4e+5 (1.4 * 10^5) 
    // showpoint    = 140000.0
    // std::fixed
    // setprecision(2)

    // std::cout << std::fixed;
    // std::cout << std::setprecision(2) << (double) 12 << std::endl;

    // ==========================================
    // internal     - знак слева, значение справа
    // left         - знак и значение слева
    // right        - знак и значение справа

    // setfill(char) - задаем заполнитель
    // setw(int)     - задаем ширину поля

    // width()   - возвращает текущую ширину
    // width(10) - задает ширину

    // std::cout << -1234 << std::endl;
    // std::cout << std::setw(10) << -1234 << std::endl;
    // std::cout << std::setw(10) << std::left << -1234 << std::endl;
    // std::cout << std::setw(10) << std::right << -1234 << std::endl;
    // std::cout << std::setw(10) << std::internal << -1234 << std::endl;

    // std::cout.fill('*');
    // std::cout << -1234 << std::endl;
    // std::cout << std::setw(10) << -1234 << std::endl;
    // std::cout << std::setw(10) << std::left << -1234 << std::endl;
    // std::cout << std::setw(10) << std::right << -1234 << std::endl;
    // std::cout << std::setw(10) << std::internal << 1234 << std::endl;


    // text
    // uppercase
    // nouppercase
    // std::cout.setf(std::ios::uppercase);
    // std::cout << std::uppercase << "rest api" << std::endl;
    // std::cout << std::nouppercase << "Rest API" << std::endl;
    // tolower()
    // toupper()


    return 0;
}