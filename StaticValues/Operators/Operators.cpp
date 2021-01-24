// Operators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cassert> // assert
class Dollars
{
public:
    Dollars()
    {

    }
    Dollars(double dollars) 
    { 
        // https://www.baeldung.com/java-separate-double-into-integer-decimal-parts
        m_dollars = dollars;
        m_dolls = static_cast<int>(dollars);
        m_cents = static_cast<int>((dollars - m_dolls) * 100);
        m_doll[0] = m_dolls;
        m_doll[1] = m_cents;
    }
    // 0.00000001
    double getDollars() const { return m_dollars; }
    int getDolls() const { return m_dolls; }
    int getCents() const { return m_cents; }

    int& operator[] (const int index)
    {
        // Dollars d(8.76);
        // d[0] -> m_dolls -> 8
        // d[1] -> m_cents -> 76
        assert(index == 0 || index == 1); // index >=0 && index <= 10 (int m_doll[10];)

        return m_doll[index];
    } 
    double& operator() (int dollars, int cents)
    {
        // d1( 0,  2)
        // d1(-1, 23)
        // d1( 0,-22)

        // !! only for positive values
        assert(dollars >= 0 && cents >=0);
        m_dollars = static_cast<double>(dollars + (cents * 0.01));
        return m_dollars;
    }

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
    Dollars operator- () const
    {
        return Dollars(-m_dollars);
    }
    bool operator!() const 
    {
        return (m_dolls >= 0 && m_cents >= 0);
    } 
    
    Dollars& operator++()
    {
        // + 1.0 dollar
        m_dollars++;
        m_dolls++;

        // += 0.01
        // m_dollars += 0.01;
        // m_cents++;
        return *this;
    }
    Dollars& operator--()
    {
        if (m_dolls > 1)
        {
            // - 1.0 dollar
            m_dollars--;
            m_dolls--;
        }
        else 
        {
            std::cerr << "ballance is minus!" << std::endl;
        }

        return *this;
    }
    Dollars operator++(int)
    {
        // + 1.0 dollar
        Dollars temp(m_dollars); // 7.23
        ++(*this);

        // += 0.01
        // m_dollars += 0.01;
        // m_cents++;
        return temp;
    }
    Dollars operator--(int)
    {
        Dollars temp(m_dollars);
        if (temp > 1)
        {
            --(*this);
        }
        else
        {
            std::cout << "Ballance is minus!" << std::endl;
        }
        return *this;
    }
    friend bool operator> (const Dollars& d1, const Dollars& d2) 
    { 
        // 4.21 > 4.17 -> +
        // 6.22 > 4.22 -> +
        // 6.22 > 4.21 -> +
        // 4.21 > 5.22 -> +
        // 4.21 > 4.22 -> +
        // 4.21 > 4.21 -> +                 
        // 4.23 > 5.22 -> +
        return (
            (d1.m_dolls > d2.m_dolls and d1.m_cents > d2.m_cents)   ||
            (d1.m_dolls == d2.m_dolls and d1.m_cents > d2.m_cents)  ||
            (d1.m_dolls > d2.m_dolls and d1.m_cents == d2.m_cents)
        );
    }
    friend bool operator< (const Dollars& d1, const Dollars& d2) 
    { 
        // 7.43 < 7.23 -> true && false => false 
        // 6.22 < 4.22 -> false && true => false
        // 6.22 < 4.21 -> false && false => false
        // 4.21 < 5.22 -> true && true => true
        // 4.21 < 4.22 -> true && true => true
        // 4.21 < 4.21 ->                   true ???
        // 4.23 < 5.22 -> true && false => false ???
        return (
            (d1.m_dolls < d2.m_dolls and d1.m_cents < d2.m_cents)   ||
            (d1.m_dolls == d2.m_dolls and d1.m_cents < d2.m_cents)  ||
            (d1.m_dolls < d2.m_dolls and d1.m_cents == d2.m_cents)
        );
    }
    friend bool operator> (const Dollars& d1, const int& d2);
    friend bool operator< (const Dollars& d1, const int& d2);
    friend bool operator>= (const Dollars& d1, const Dollars& d2) 
    {
        // 5.22 >= 4.23 
        return (
            (d1.m_dolls >= d2.m_dolls and d1.m_cents >= d2.m_cents)   ||
            (d1.m_dolls > d2.m_dolls and d1.m_cents < d2.m_cents)
        );
    }
    friend bool operator<= (const Dollars& d1, const Dollars& d2) 
    {
        // 7.23 <= 7.43 +
        // 4.22 <= 6.22 +
        // 6.22 <= 4.21 +
        // 4.21 <= 5.22 +
        // 4.21 <= 4.21 +  
        // 4.23 <= 5.22 +
        // 4.22 <= 2.22 +
        // 4.21 <= 2.24 +

        return (
            (d1.m_dolls <= d2.m_dolls and d1.m_cents <= d2.m_cents)   ||
            (d1.m_dolls < d2.m_dolls and d1.m_cents > d2.m_cents)
        );
    }
    friend bool operator== (const Dollars& d1, const Dollars& d2) 
    {
        return (d1.m_dolls == d2.m_dolls && d1.m_cents == d2.m_cents);
    }
    friend bool operator!= (const Dollars& d1, const Dollars& d2) 
    {
        return (d1.m_dolls != d2.m_dolls || d1.m_cents != d2.m_cents);
    }
    void print()
    {
        std::cout << m_dollars << " dollars";
    }
    void countCoins()
    {
        // task - write algorithm for calculate minimal count of coins
        // Cents:
        // 1   pennies
        // 5   nickels
        // 10  dimes
        // 25  quarters

        // input dollars:            9.41
        // count coins and output:   4*9 + 25+10+5+1 => 40 
        int p = 0, n = 0, d = 0, q = 0, z, count;
        q += m_dolls * 4;
        q += m_cents / 25;
        z = m_cents % 25;
        d += z / 10;
        z = z % 10;
        n += z / 5; // n = n + z/5;
        z = z % 5;
        p += z / 1; // p = z;
        count = q + d + n + p;
        std::cout << "Counts of coins: " << count << std::endl;
    }
    friend std::ostream& operator<< (std::ostream& out, const Dollars &dol)
    {
        //out << std::fixed;
        //out << "Dollars: (" << std::setprecision(2) << dol.m_dollars << ")" << dol.m_dolls << '.' << dol.m_cents << std::endl;
        if (abs(dol.m_cents) < 10) out << "\nDollars: " << dol.m_dolls << ".0" << abs(dol.m_cents);
        else out << "\nDollars: " << dol.m_dolls << '.' << abs(dol.m_cents);
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
    double m_dollars; // 0.0 == 0.0000000000013
    // 7.76 -> m_dolls => 7 / m_cents = 76
    // unsigned int m_dolls; // целая
    int m_dolls; // целая
    int m_cents; // дробная

    // array
    int m_doll[2];
};

// operator/
// 21.50 by 5:
// 21.50 / 5 => 4.30 (0000023)
// 21 / 5 = 4
// 21 % 4 = (1 != 0 ) => 1 * 100 + CENTS => 150 / 5 = 30
//                                          150 % 5 = (0x != 0 ) => 0x => 21.5 - 0.00x ... 

int main()
{
    // Dollars dollars1(7);
    // Dollars dollars2(5);

    // //int dol1 = 7;
    // //int dol2 = 5;
    // //int sum = dol1 + dol2;

    // Dollars all_dollars = 7 + Dollars(5);
    // std::cout << all_dollars;
    
    // Dollars in_dol;
    // std::cout << "Enter a few dollars: ";
    // std::cin >> in_dol;
    // std::cout << in_dol;

    //std::cout << "Enter count of money:";
    // Dollars in;
    // std::cin >> in;
    // std::cout << in;
    // std::cout << "Enter the amount spent:";
    // Dollars spent_Dollars;
    // std::cin >> spent_Dollars;
    // in = in - spent_Dollars;
    // std::cout << -spent_Dollars;

    // if (!in)
    // {
    //     std::cout << "You spent all your money" << std::endl;
    // }
    // else {
    //     std::cout << "You still have money" << std::endl;
    // }

    // !true == false

    Dollars d1(7.23), d2(23.01), d3;
    //std::cout << d1[0] << "\t" << d2[1] << std::endl;
    std::cout << d3(1,5) << std::endl;
    //d2.countCoins();

    // std::cin >> d1;
    // std::cin >> d2;
    // if (d1 > d2)
    // {
    //     std::cout << d1 << " > " << d2 << std::endl;
    // }
    // //++a - pre
    // //a++ - post
    // int a = 5;

    // std::cout << a++ << std::endl; // 5
    // std::cout << ++a << std::endl; // 7

    // std::cout << ++a << std::endl; // 8
    // std::cout << a++ << std::endl; // 8

    // std::cout << d1 << std::endl;
    // std::cout << ++d1 << std::endl;
    // std::cout << d2++ << std::endl;
    // std::cout << d2 << std::endl;
}

// for (int i = 0, count = 1; i < 10000; i++)
// {
    
//     for (size_t j = 0; j < 10; j++)
//     {
//         array[i] = 
//     }
    
    

// }


// ++, --
// [] (vector<int> vec -> push => vec[7])
// ()
// =



