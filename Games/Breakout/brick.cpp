#include <iostream>
#include "brick.hpp"

Brick::Brick(int x, int y)
{
    m_image.load("brick.png");
    m_destroyed = false;
    m_rect = m_image.rect();
    m_rect.translate(x, y);
}

Brick::~Brick()
{
    std::cout << ("Brick deleted") << std::endl;
}

bool        Brick::isDestroyed()
{
    return m_destroyed;
}

void        Brick::setDestroyed(bool destr)
{
    m_destroyed = destr;
}

QRect       Brick::getRect()
{
    return m_rect;
}

void        Brick::setRect(QRect rect)
{
    m_rect = rect;
}

QImage &    Brick::getImage()
{
    return m_image;
}
