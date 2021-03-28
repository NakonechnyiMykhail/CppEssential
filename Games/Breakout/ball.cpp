#include "ball.hpp"

Ball::Ball()
{

}

Ball::~Ball()
{

}


void Ball::resetState()
{

}

void Ball::autoMove()
{
    /*
     |--------------|
     |              |
     |              |
     |              |
     |              |
     xxxxxxxxxxxxxxxx
     */

    m_rect.translate(m_xdir, m_ydir);

    if (m_rect.left() == 0)
    {
        m_xdir = 1;
    }

    if (m_rect.right() == RIGHT_EDGE)
    {
        m_xdir = -1;
    }

    if (m_rect.top() == 0)
    {
        m_ydir = 1;
    }
}

void Ball::setXDir(int)
{

}

void Ball::setYDir(int)
{

}

int Ball::getXDir()
{

}

int Ball::getYDir()
{

}

QRect Ball::getRect()
{

}

QImage & Ball::getImage()
{

}
