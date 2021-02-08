// ClassTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
//class ArrayDouble
//{
//private:
//    int m_length;
//    double* m_data;
//public:
//    ArrayDouble()
//    {
//        m_length = 0;
//        m_data = nullptr;
//    }
//    ArrayDouble(int length)
//    {
//        assert(length > 0);
//        m_data = new double[length];
//        m_length = length;
//    }
//    ~ArrayDouble()
//    {
//        delete[] m_data;
//    }
//    void Erase()
//    {
//        delete[] m_data;
//        m_data = nullptr;
//        m_length = 0;
//    }
//    double& operator[] (int index)
//    {
//        assert(index >= 0 && index < m_length);
//        return m_data[index];
//    }
//    int getLength() { return m_length; }
//};

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
        assert(length > 0);
        m_data = new T[length];
        m_length = length;
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
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    int getLength();
};

template <typename T>
int Array<T>::getLength() { return m_length; }

int main()
{
    Array<int> intArr(10);
    Array<double> doubleArr(10);
    for (size_t i = 0; i < intArr.getLength(); i++)
    {
        intArr[i] = i;
        doubleArr[i] = i + 0.25;
    }
    for (size_t i = 0; i < intArr.getLength(); i++)
    {
        std::cout << intArr[i] << '\t' << doubleArr[i] << std::endl;
    }
}

