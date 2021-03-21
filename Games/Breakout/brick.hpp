#ifndef BRICK_HPP
#define BRICK_HPP

#include <QImage>
#include <QRect>

class Brick
{
public:
    Brick();
    ~Brick();

private:
    QImage  m_image;
    QRect   m_rect;
    bool    m_destroyed;

public:
    bool        isDestroyed();
    void        setDestroyed(bool);
    QRect       getRect();
    void        setRect(QRect);
    QImage &    getImage();
};

#endif // BRICK_HPP
