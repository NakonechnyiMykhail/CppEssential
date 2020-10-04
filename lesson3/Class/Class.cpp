// Class.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Person
{
public:
	Person();
	Person(std::string name, int age);
	~Person();
	void SayName();
	//void SayPassword();
	int GetAge();
	std::string GetName();
	void SetAge(int age);
	void SetName(std::string name);


private:
	std::string m_name;
	int m_age{ 0 };
};
Person::Person()
{
}

Person::Person(std::string name, int age) :
	m_name(name), m_age(age)
{
}

Person::~Person()
{
}

void Person::SayName()
{
	std::cout << m_name << std::endl;
}

int Person::GetAge()
{
	return m_age;
}

std::string Person::GetName()
{
	return m_name;
}

void Person::SetAge(int age)
{
	m_age = age;
}

void Person::SetName(std::string name)
{
	m_name = name;
}

int main()
{
    std::cout << "Hello World!\n";

	Person p;
	Person p1("Mike", 20);
	p.SayName();
	p1.SayName();

	int a = p1.GetAge();


	return 0;
}
//class foo;
//get_int()


