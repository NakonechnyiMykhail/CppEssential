#ifndef BALL_HPP
#define BALL_HPP

#include <QImage>
#include <QRect>

class Ball
{
public:
    Ball();
    ~Ball();

private:
    int     m_xdir;
    int     m_ydir;
    QImage  m_image;
    QRect   m_rect;

    static const int INITIAL_X  = 111;
    static const int INITIAL_Y  = 111;
    static const int RIGHT_EDGE = 111;

public:
    void resetState();
    void autoMove();
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();

    QRect getRect();
    QImage & getImage();
};

#endif // BALL_HPP
