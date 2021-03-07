// Exception.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <exception>

double divide(int a, int b, bool& success)
{
    //assert(b != 0);
    if (b == 0)
    {
        success = false;
        return 0.0;
    }

    success = true;
    //return (double) a / b;
    return static_cast<double>(a) / b;
}

int get_int(std::string str)
{
    /*
    Funtion:    print category and check inputting varieble for correct data
    Get:        integer varieble from user
    Return:     int
    */
    int number{ 0 };
    while (true)
    {
        std::cout << "\nEnter your " << str << ": ";
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            continue;
        }
        // our data shoul be Non-zero
        // if (number <= 0) { continue; }

        break;
    }
    return number;
}

void last()
{
    std::cout << "Start last\n";
    std::cout << "last throwing int exception\n";
    throw -1.0;
    std::cout << "End last\n";
}

void three()
{
    std::cout << "Start three\n";
    last();
    std::cout << "End three\n";
}

void two()
{
    std::cout << "Start two\n";
    try
    {
        three();
    }
    catch (double)
    {
        std::cerr << "two caught double exception\n";
    }
    //catch (...) // catch-all
    //{
    //    std::cerr << "two catch-all exception\n";
    //}
    std::cout << "End two\n";
}
void one()
{
    std::cout << "Start one\n";
    try
    {
        two();
    }
    catch (int)
    {
        std::cerr << "one caught int exception\n";
    }
    catch (double)
    {
        std::cerr << "one caught double exception\n";
    }
    std::cout << "End one\n";
}

class ArrayException : public std::exception
{
private:
    std::string m_error;
public:
    ArrayException(std::string error)
        : m_error(error)
    {}

    //const char* getError() { return m_error.c_str(); }
    const char* what() const noexcept { return m_error.c_str(); }
};

template <class T>
class Array
{
private:
    int m_length;
    T* m_data;
public:
    Array()
    {
        m_length = 0;
        m_data = nullptr;
    }
    Array(int length)
    {
        try
        {
            //assert(length > 0);
            if (length < 0)
            {
                throw "negative alloc";
            }

            m_data = new T[length];
            //if (length > 10000000)
            //{
            //    
            //}
            m_length = length;
            throw std::runtime_error("Bad things happend");
        }
        catch (std::bad_alloc& ex) // index >= m_length)
        {
            std::cerr << "You ran out of memory!\n";
        }
        catch (const std::exception& ex)
        {
            std::cerr << "Standart exception " << ex.what() << "\n";
        }

    }
    ~Array()
    {
        delete[] m_data;
    }
    void Erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    T& operator[] (int index)
    {
        // assert(index >= 0 && index < m_length);
        if (index < 0 || index >= m_length) { throw ArrayException("Invalid index"); }
        return m_data[index];
    }
    int getLength();
};

template <typename T>
int Array<T>::getLength() { return m_length; }

int main()
{
    //bool success;
    //double result = divide(2, 0, success);

    //if (!success)
    //{
    //    std::cerr << "An error occurred!" << std::endl;
    //}
    //else
    //{
    //    std::cout << "The answer is " << result << std::endl;
    //}

    // ==============================================================
    //double n = static_cast<double>(get_int("Enter a number"));
    //try
    //{
    //    if (n < 0.0)
    //    {
    //        //throw -1;
    //        throw "Can not take sqrt of negative number";
    //    }
    //    std::cout << "The sqrt of " << n << " is " << sqrt(n) << std::endl;
    //}
    //catch (const char* ex)
    //{
    //    std::cerr << "Error: " << ex << std::endl;
    //}
    //catch (int ex)
    //{
    //    std::cerr << "Error: " << ex << std::endl;
    //}
    //catch (const std::exception& ex)
    //{
    //    std::cerr << "Error: " << &ex << std::endl;
    //}
    // ==============================================================

    //std::cout << "Start main\n";
    //try
    //{
    //    one();
    //}
    //catch (int)
    //{
    //    std::cerr << "main caught int exception\n";
    //}
    //std::cout << "End main\n";
        // FIRST OUTPUT
        //Start main
        //Start one
        //Start two
        //Start three
        //Start last
        //last throwing int exception
        //one caught int exception
        //End one
        //End main

    // ==============================================================

    Array<int> intArr(100000000000);
    Array<double> doubleArr(10);
    
    try
    {
        for (size_t i = 0; i < intArr.getLength(); i++)
        {

            intArr[i] = i;
            doubleArr[i] = i + 0.25;
        }
        //for (size_t i = 0; i < intArr.getLength(); i++)
        //{
        //    std::cout << intArr[i] << '\t' << doubleArr[i] << std::endl;
        //}
        
        // exception
        //std::cout << intArr[-4] << std::endl;
    }
    catch (ArrayException& ex)
    {
        std::cerr << "An array exception occurred (" << ex.what() << ")\n";
    }
    catch (std::exception& ex)
    {
        std::cerr << "Some other std::exception occurred (" << ex.what() << ")\n";
    }
    catch (const char* ex)
    {
        std::cerr << "const char*\n";
    }
    catch (int)
    {
        std::cerr << "int \n";
    }
    catch (...) // catch-all
    {
        std::cerr << "Some other exception occurred\n";
    }
    // ==============================================================

}

//throw -1;
//throw "error ...";

//try
//{
//
//}
//catch (const std::exception&)
//{
//
//}