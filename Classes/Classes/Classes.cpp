// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
//#include <cmath> // M_PI ?????

#define M_PI 3.1415926

class Ball
{
public:
	//Ball();
	//~Ball();
	Ball(int radius);
	int GetVolume();
private:
	int m_radius{ 5 };
	//int m_diameter = 2 * m_radius;
	double m_volume3d = 4/3 * M_PI * pow(m_radius, 3); // as 3D box
};
Ball::Ball(int radius) : m_radius(radius) {}
int Ball::GetVolume() { return m_volume3d; }

class Box
{
public:
	//Box(); 
	//~Box(); // if !IsFree() -> delete *this;
	Box(int length, int height, int width); 
	bool IsFree();
	void AddToBox(const Ball& b);
	void Clean();

private:
	int m_length{ 10 };
	int m_height{ 10 };
	int m_width { 10 };
	int m_volume = m_length * m_height * m_width;
	std::vector<Ball> m_capacity;
};
//Box::Box() {}
void Box::Clean() { m_capacity.clear(); }
Box::Box(int length, int height, int width) : m_length(length), m_height(height), m_width(width) {}
bool Box::IsFree()
{
	/* 31 balls == 992 volume
	(1000 - [31] * 32) > 32
	
	*/
	//if ((m_volume - m_capacity.size() * m_capacity.at(0).GetVolume()) > m_capacity.at(0).GetVolume())
	if ((m_volume - m_capacity.size() * Ball(2).GetVolume()) > Ball(2).GetVolume())
	{
		return true;
	}
	return false;
}
void Box::AddToBox(const Ball& b)
{
	if (IsFree())
	{
		m_capacity.push_back(b);
	}
}

int main()
{
	std::vector<Ball> balls;// (1000);
	int length = 1000;
	for (size_t i = 0; i < length; i++)
	{
		balls.push_back(Ball(2));
	}
	std::vector<Box> boxes;
	Box* temp = new Box(10, 10, 10);


	for (auto& ball : balls)
	{
		temp->AddToBox(ball);
		if (!temp->IsFree())
		{
			boxes.push_back(*temp);
			temp->Clean();
		}
	}
    std::cout << "We need to have " << boxes.size() << " boxes.\n";
}


// Tips for Getting Started: 
//   1. description: box, ball 
//   2. calculation: 
//   3. 
//   4. 
