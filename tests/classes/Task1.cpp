#include <iostream>
#include <cstring>
#include <cassert>

class Fraction 
{
private:
    // Calculates the greates common divisor with
    // Euclid's algorithm
    // both arguments have to be positive
    long long gcd(long long a, long long b) 
    {
        while (a != b) 
        {
            if (a > b) 
            {
                a -= b;
            }
            else 
            {
                b -= a;
            }
        }
        return a;
    }

public:
    long long m_numerator, m_denominator;

    Fraction() 
    {
        m_numerator = 0;
        m_denominator = 1;
    }

    Fraction(long long n, long long d) 
    {
        // assert(d != 0);
        if (d == 0) 
        {
            std::cerr << "Denominator may not be 0." << std::endl;
            exit(0);
        }
        else if (n == 0) 
        {
            m_numerator = 0;
            m_denominator = 1;
        }
        else 
        {
            int sign = 1;
            if (n < 0) 
            {
                sign *= -1;
                n *= -1;
            }
            if (d < 0) 
            {
                sign *= -1;
                d *= -1;
            }

            long long tmp = gcd(n, d);
            m_numerator = n / tmp * sign;
            m_denominator = d / tmp;
        }
    }

    operator int() { return (m_numerator) / m_denominator; }
    operator float() { return ((float)m_numerator) / m_denominator; }
    operator double() { return ((double)m_numerator) / m_denominator; }

    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator+=(Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-=(Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*=(Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(int lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& rhs, int lhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);
    friend std::ostream& operator<<(std::ostream& strm, const Fraction& a);
    friend std::istream& operator>>(std::istream& in, Fraction& f);
};
// c = a   + b
// c = 1/2 + 1/3
// a += b => a = a + b
// 1/2 + 1/3 => a = 1/2 + 1/3 
Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
    Fraction tmp(lhs.m_numerator * rhs.m_denominator + rhs.m_numerator * lhs.m_denominator, lhs.m_denominator * rhs.m_denominator);
    return tmp;
}

Fraction operator+=(Fraction& lhs, const Fraction& rhs) 
{
    Fraction tmp(lhs.m_numerator * rhs.m_denominator + rhs.m_numerator * lhs.m_denominator, lhs.m_denominator * rhs.m_denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) 
{
    Fraction tmp(lhs.m_numerator * rhs.m_denominator - rhs.m_numerator * lhs.m_denominator, lhs.m_denominator * rhs.m_denominator);
    return tmp;
}

Fraction operator-=(Fraction& lhs, const Fraction& rhs) 
{
    Fraction tmp(lhs.m_numerator * rhs.m_denominator - rhs.m_numerator * lhs.m_denominator, lhs.m_denominator * rhs.m_denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) 
{
    Fraction tmp(lhs.m_numerator * rhs.m_numerator, lhs.m_denominator * rhs.m_denominator);
    return tmp;
}

Fraction operator*=(Fraction& lhs, const Fraction& rhs) 
{
    Fraction tmp(lhs.m_numerator * rhs.m_numerator, lhs.m_denominator * rhs.m_denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(int lhs, const Fraction& rhs) 
{
    Fraction tmp(lhs * rhs.m_numerator, rhs.m_denominator);
    return tmp;
}

Fraction operator*(const Fraction& rhs, int lhs) 
{
    Fraction tmp(lhs * rhs.m_numerator, rhs.m_denominator);
    return tmp;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) 
{
    Fraction tmp(lhs.m_numerator * rhs.m_denominator, lhs.m_denominator * rhs.m_numerator);
    return tmp;
}

std::ostream& operator<<(std::ostream& strm, const Fraction& a) 
{
    if (a.m_denominator == 1) 
    {
        strm << a.m_numerator;
    }
    else 
    {
        strm << a.m_numerator << "/" << a.m_denominator;
    }
    return strm;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    std::cout << "Enter elements of fraction:\n";
    while (true)
    {
        std::cout << "Enter a numerator: ";
        in >> f.m_numerator;

        if (in.fail())
        {
            in.clear();
            in.ignore(32767, '\n');
            continue;
        }

        break;
    }
    while (true)
    {
        std::cout << "Enter a denominator: ";
        in >> f.m_denominator;

        if (in.fail())
        {
            in.clear();
            in.ignore(32767, '\n');
            continue;
        }
        // our data should be Non-zero
        if (f.m_denominator == 0) { continue; }

        break;
    }
    return in;
}

int main() 
{
    Fraction a(1, 3);
    Fraction b(3, 28);
    Fraction c; // 0/1

    std::cin >> c;
    std::cout << c << std::endl;


    c = a + b;
    std::cout << c << "\t(should be 37/84)" << std::endl;

    c = a - b;
    std::cout << c << "\t(should be 19/84)" << std::endl;

    c = a * b;
    std::cout << c << "\t(should be 1/28)" << std::endl;

    c = a / b;
    std::cout << c << "\t(should be 28/9)" << std::endl;

    c = -1 * b;
    std::cout << c << "\t(should be -3/28)" << std::endl;

    c = b * (-1);
    std::cout << c << "\t(should be -3/28)" << std::endl;

    c = Fraction(-100, 3);
    std::cout << (int)c << "\t(should be -33)" << std::endl;
    std::cout << (float)c << "\t(should be -33.3...)" << std::endl;
    std::cout << (double)c << "\t(should be -33.3...)" << std::endl;

    a -= b;
    std::cout << a << "\t(should be 19/84)" << std::endl;

    return 0;
}









