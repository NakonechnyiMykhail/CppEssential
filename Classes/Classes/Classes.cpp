// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Box.h"

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
