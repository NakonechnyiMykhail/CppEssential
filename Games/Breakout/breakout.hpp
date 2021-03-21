#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>
#include <QKeyEvent>
#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"


class Breakout : public QWidget
{
    Q_OBJECT

public:
    Breakout(QWidget *parent = nullptr);
    ~Breakout();

private:
    int m_x;
    int m_timerId;
    static const int N_OF_BRICKS = 20;
    static const int DELAY = 20;
    static const int BOTTOM_EDGE = 20;

    Ball *m_ball;
    Paddle *m_paddle;
    Brick *m_bricks[N_OF_BRICKS];

    bool m_gameOver;
    bool m_gameWon;
    bool m_gameStarted;
    bool m_paused;

protected:
    // events

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();

};
#endif // WIDGET_HPP
