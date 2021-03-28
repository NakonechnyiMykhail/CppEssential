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
    static const int N_OF_BRICKS = 30;
    static const int DELAY = 10;
    static const int BOTTOM_EDGE = 400;

    Ball *m_ball;
    Paddle *m_paddle;
    Brick *m_bricks[N_OF_BRICKS];

    bool m_gameOver;
    bool m_gameWon;
    bool m_gameStarted;
    bool m_paused;

protected:
    // events
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void drawObjects(QPainter *);
    void finishGame(QPainter *, QString);
    void moveObjects();

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();

};
#endif // WIDGET_HPP
