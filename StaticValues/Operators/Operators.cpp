// Operators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Dollars
{
public:
    Dollars(double dollars) 
    { 
        m_dollars = dollars;
        m_dolls = (int) dollars;
        m_cents = dollars - m_dolls;
    }
    int getDollars() const { return m_dollars; }
    friend Dollars operator+(const Dollars& d1, const Dollars& d2)
    {
        return Dollars(d1.getDollars() + d2.getDollars());
    }
    friend Dollars operator+(const Dollars& d1, int value)
    {
        return Dollars(d1.getDollars() + value);
    }
    friend Dollars operator+(int value, const Dollars& d1)
    {
        return Dollars(d1.getDollars() + value);
    }
    friend Dollars operator-(const Dollars& d1, const Dollars& d2)
    {
        return Dollars(d1.getDollars() - d2.getDollars());
    }
    void print()
    {
        std::cout << m_dollars << " dollars";
    }

    friend std::ostream& operator<< (std::ostream& out, const Dollars &dol)
    {
        out << "Dollars: " << dol.m_dollars << '.' << dol.m_cents << std::endl;
        return out;
    }
private:
    double m_dollars;
    // 7.76 -> m_dolls => 7 / m_cents = 76

    int m_dolls;
    int m_cents;
};


int main()
{
    Dollars dollars1(7);
    Dollars dollars2(5);

    //int dol1 = 7;
    //int dol2 = 5;
    //int sum = dol1 + dol2;

    Dollars all_dollars = 7 + Dollars(5);
    std::cout << all_dollars;
}
