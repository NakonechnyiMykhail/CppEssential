#include <cassert>
#include <iostream>

class Drob
{
private:
    int m_numerator;
    int m_denominator;

public:
    Drob(int numerator = 0, int denominator = 1):
        m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }

    // safe from copy
    // Drob(const Drob &drob) = delete;
    // Drob& operator= (const Drob &drob) = delete;


    Drob(const Drob &drob) :
        m_numerator(drob.m_numerator), m_denominator(drob.m_denominator)
    {
        std::cout << "Copy constuctor worked here!\n";
    }

    Drob& operator= (const Drob &drob)
    {
        // check
        if (this == &drob)
        {
            return *this;
        }

        m_numerator = drob.m_numerator;
        m_denominator = drob.m_denominator;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Drob &d1);
};

std::ostream& operator<<(std::ostream& out, const Drob &d1)
{
    out << d1.m_numerator << "/" << d1.m_denominator;
    return out;
}

int main()
{
    Drob d1(6,7);
    Drob d2(d1);
    // d2.m_numerator = d1.m_numerator(6); 

    // Drob myNum = d1;
    Drob d3;
    d3 = d1;    
    std::cout << d3 << std::endl;

    Drob d4(1,2);
    Drob d5(2,3);
    d1 = d2 = d3;
    d1 = d1;


    return 0;
}