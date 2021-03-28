#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <QImage>
#include <QRect>

class Paddle
{
public:
    Paddle();
    ~Paddle();

private:
    QImage m_image;
    QRect m_rect;
    int m_dx;
    static const int INITIAL_X = 200;
    static const int INITIAL_Y = 360;

public:
    void        resetState();
    void        move();
    void        setDx(int);
    QRect       getRect();
    QImage &    getImage();

};

#endif // PADDLE_HPP
