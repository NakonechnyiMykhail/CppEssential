#include <iostream>
#include <cstring>
#include <cassert>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_full_numerator{ 0 }; // value of (m_integer * m_denominator) + m_numerator == m_full_numerator
    int m_denominator{ 0 };
    int m_integer{ 0 };
    
public:
    Fraction();
    Fraction(float number);                                 // 0.8 1.2
    Fraction(int numerator, int denominator);               // 1/2 9/2
    Fraction(int integer, int numerator, int denominator);  // 4 1/2 -> 9/2
    void shortFraction(); // 36/12 -> 12/4 -> 3/1
    friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); // assert(frac1.isFraction() && frac2.isFraction())
    friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator/(const Fraction& frac1, const Fraction& frac2);

    bool isFraction(); // check numerator and denominator > 0 

    int getInteger();
    int getNumerator();
    int getFullNumerator();
    int getDenominator();

    void setInteger(int integer);
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);

};
Fraction::Fraction()
{
    m_denominator = setDenominator(get_positive_int(""));
}
Fraction::Fraction(float number)
{
    assert((typeid(float) || typeid(double)) && number >= 0.0000000001);
    // get integer and get fraction 
}
Fraction::Fraction(int numerator, int denominator) :
    m_numerator(numerator), m_denominator(denominator)
{
    m_full_numerator = numerator;
}
Fraction::Fraction(int integer, int numerator, int denominator) :
    m_numerator(numerator), m_denominator(denominator), m_integer(integer)
{
    m_full_numerator = integer * denominator + numerator;
}
void Fraction::shortFraction()
{
    assert(m_full_numerator > m_denominator && m_numerator > m_denominator);
    // m_full_numerator % m_denominator 
}
int Fraction::getInteger()
{
    return m_integer;
}
int Fraction::getNumerator()
{
    return m_numerator;
}
int Fraction::getFullNumerator()
{
    return m_full_numerator;
}
int Fraction::getDenominator()
{
    return m_denominator;
}
void Fraction::setInteger(int integer)
{
    assert(integer > 0);
    m_integer = integer;
}
void Fraction::setNumerator(int numerator)
{
    assert(numerator > 0);
    m_numerator = numerator;
}
void Fraction::setDenominator(int denominator)
{
    assert(denominator > 0);
    m_denominator = denominator;
}
std::ostream& Fraction::operator<<(std::ostream& out, const Fraction& frac)
{
    assert(frac.getDenominator() > 0 && (frac.getNumerator() >= 0 || (frac.getInteger() > 0 && frac.getNumerator() > 0)));
    if (frac.getInteger() != 0)
    {
        out << frac.getFullNumerator() << " / " << frac.getDenominator() << "\n";
        return out;
    }
    else if (frac.getInteger() == 0)
    {
        out << frac.getNumerator() << " / " << frac.getDenominator() << "\n";
        return out;
    }
}

inline uint16_t get_positive_int(std::string category)
{
    /*
    Funtion:    print category and check inputting varieble for correct data
    Get:        integer varieble from user 
    Return:     int
    */
    uint16_t number{0};
    while (true)
    {
        std::cout << "Enter your " << category << ": ";
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            continue;
        }
        // our data shoul be Non-zero
        if (number <= 0) { continue; }

        break;
    }
    return number;
}

int main()
{
    Fraction f;
    f.setNumerator(2);
    f.setDenominator(get_positive_int("Enter a denominator: "));

    //std::cout << f.getFullNumerator() << "/" << f.getDenominator();
    std::cout << f;
}