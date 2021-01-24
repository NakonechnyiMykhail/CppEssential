#pragma once

#include <vector>
#include "Ball.h"


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
	int m_width{ 10 };
	int m_volume = m_length * m_height * m_width;
	std::vector<Ball> m_capacity;
};
