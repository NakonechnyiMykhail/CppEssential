// Operators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
class Dollars
{
public:
    Dollars()
    {

    }
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
    friend Dollars operator-(const Dollars& d1, int value)
    {
        return Dollars(d1.getDollars() - value);
    }
    friend Dollars operator-(int value, const Dollars& d1)
    {
        return Dollars(value - d1.getDollars());
    }
    void print()
    {
        std::cout << m_dollars << " dollars";
    }

    friend std::ostream& operator<< (std::ostream& out, const Dollars &dol)
    {
        //out << std::fixed;
        //out << "Dollars: (" << std::setprecision(2) << dol.m_dollars << ")" << dol.m_dolls << '.' << dol.m_cents << std::endl;
        out << "Dollars: " << dol.m_dolls << '.' << dol.m_cents << std::endl;
        return out;
    }
    friend std::istream& operator>> (std::istream& in, Dollars& dol)
    { 
        // in: 7.76 7 76                         => XXXXXXXX 
        // in: 7.76 visa 4444-4444-44444--4444   => OK
        in >> dol.m_dollars;
        //in >> dol.m_dolls;
        //in >> dol.m_cents;
        dol.m_dolls = static_cast<int>(dol.m_dollars);
        // static_cast<DATA_TYPE>(value)
        // reinterpret_cast<DATA_TYPE>(value)
        // (DATA_TYPE) value                        C-Style
        dol.m_cents = static_cast<int>((dol.m_dollars - dol.m_dolls) * 100);
        // person
        // student
        //static_cast<student>(person)

        return in;
    }
private:
    double m_dollars;
    // 7.76 -> m_dolls => 7 / m_cents = 76

    int m_dolls; // целая
    int m_cents; // дробная
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
    
    Dollars in_dol;
    std::cout << "Enter a few dollars: ";
    std::cin >> in_dol;
    std::cout << in_dol;


}
