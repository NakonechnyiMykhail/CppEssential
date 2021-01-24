#include "Box.h"
//Box::Box() {}
void Box::Clean() { m_capacity.clear(); }
Box::Box(int length, int height, int width) : m_length(length), m_height(height), m_width(width) {}
bool Box::IsFree()
{
	/* 29 balls ~= 971 volume
	(1000 - [] * 33.51) > 32

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