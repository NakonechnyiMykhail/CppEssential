#include <iostream>
#include "paddle.hpp"

Paddle::Paddle()
{
    m_dx = 0;
    m_image.load("paddle.png");

    m_rect = m_image.rect();
    resetState();
}

Paddle::~Paddle()
{
    std::cout << ("Paddle deleted") << std::endl;
}

void        Paddle::resetState()
{
    m_rect.moveTo(INITIAL_X, INITIAL_Y);
}

void        Paddle::move()
{
    int x = m_rect.x() + m_dx;
    int y = m_rect.top();

    m_rect.moveTo(x, y);
}

void        Paddle::setDx(int x)
{
    m_dx = x;
}

QRect       Paddle::getRect()
{
    return m_rect;
}

QImage &    Paddle::getImage()
{
    return m_image;
}
