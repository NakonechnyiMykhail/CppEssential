#pragma once
#include <cmath> // M_PI ?????
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
	double m_volume3d = 4 / 3 * M_PI * pow(m_radius, 3); // as 3D box
};
