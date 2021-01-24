#include <cstring>
#include <cassert>
#include <iostream>
// ['h', 'e', 'l', 'l', 'o']                                        // 5
// "hello" == ['h', 'e', 'l', 'l', 'o', '\0']                       // 6

class SomeString
{
private:
    char *m_data;
    int m_length;

public:
    SomeString(const char *source="")
    {
        assert(source);

        m_length = strlen(source) + 1;
        m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
        {
            m_data[i] = source[i];
        }
        m_data[m_length-1] = '\0';
    }
    SomeString(const SomeString &source) //:m_length(source.m_length), m_data(source.m_data)
    {
        m_length = source.m_length;

        if (source.m_data)
        {
            m_data = new char[m_length];
            for (int i = 0; i < m_length; ++i)
            {
                m_data[i] = source.m_data[i];
            }
        }
        else
        {
            m_data = 0;
        }
        
    }
    SomeString& operator= (const SomeString &source) 
    {
        if (this == &source) { return *this; }

        delete[] m_data;
        m_length = source.m_length;
        if (source.m_data)
        {
            m_data = new char[m_length];
            for (int i = 0; i < m_length; ++i)
            {
                m_data[i] = source.m_data[i];
            }
        }
        else
        {
            m_data = 0;
        }
        return *this;
    }
    ~SomeString()
    {
        delete[] m_data;
    }
    char* getString() { return m_data; }
    int getLength() { return m_length; }

};

int main()
{
    SomeString hello("Hello, world!");
    {
        SomeString copy = hello;
    }
    std::cout << hello.getString() << std::endl;
    return 0;
}