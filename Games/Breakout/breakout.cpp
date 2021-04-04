#include <QPainter>
#include <QApplication>
#include "breakout.hpp"
//#include "breakout.h"

Breakout::Breakout(QWidget *parent)
    : QWidget(parent)

{
    m_x             = 0;
    m_gameOver      = false;
    m_gameWon       = false;
    m_paused        = false;
    m_gameStarted   = false;
    m_ball          = new Ball();
    m_paddle        = new Paddle();

    int k = 0;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            m_bricks[k] = new Brick(j * 40 + 30, i * 10 + 50);
            k++;
        }
    }
}

Breakout::~Breakout()
{
    delete m_ball;
    delete m_paddle;

    for (int i = 0; i < N_OF_BRICKS; ++i)
    {
        delete m_bricks[i];
    }
}

void        Breakout::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);

    if (m_gameOver)
    {
        finishGame(&painter, "Game lost");
    }
    else if (m_gameWon)
    {
        finishGame(&painter, "Victory");
    }
    else
    {
        drawObjects(&painter);
    }

}

void        Breakout::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    moveObjects();
    checkCollision();
    repaint();
}

void        Breakout::keyPressEvent(QKeyEvent *e)
{
    int dx = 0;

    switch (e->key())
    {
    case Qt::Key_Left:
        dx = -1;
        m_paddle->setDx(dx);
        break;
    case Qt::Key_Right:
        dx = 1;
        m_paddle->setDx(dx);
        break;
    case Qt::Key_Pause:
        pauseGame();
        break;
    case Qt::Key_P:
        pauseGame();
        break;
    case Qt::Key_Space:
        startGame();
        break;
    case Qt::Key_Escape:
        qApp->exit();
        break;
    default:
        QWidget::keyPressEvent(e);
    }
}

void        Breakout::keyReleaseEvent(QKeyEvent *e)
{
    int dx = 0;
    switch (e->key())
    {
        case Qt::Key_Left:
            dx = 0;
            m_paddle->setDx(dx);
            break;

        case Qt::Key_Right:
            dx = 0;
            m_paddle->setDx(dx);
            break;
    }
}

void        Breakout::drawObjects(QPainter * painter)
{
    painter->drawImage(m_ball->getRect(), m_ball->getImage());
    painter->drawImage(m_paddle->getRect(), m_paddle->getImage());

    for (int i = 0; i < N_OF_BRICKS; ++i)
    {
        if (!m_bricks[i]->isDestroyed())
        {
            painter->drawImage(m_bricks[i]->getRect(), m_bricks[i]->getImage());
        }
    }
}

void
Breakout::finishGame(QPainter * painter, QString message)
{
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    // for Qt6
    // QSize textWidth2 = fm.size(Qt::TextSingleLine, message);

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w / 2, h / 2));
    painter->drawText(-textWidth / 2, 0, message);

    // for qt6 ???
    // painter->drawText(-textWidth2 / 2, 0, message);
}

void        Breakout::moveObjects()
{
    m_ball->autoMove();
    m_paddle->move();
}

void        Breakout::startGame()
{
    if (!m_gameStarted)
    {
        m_ball->resetState();
        m_paddle->resetState();

        for (int i = 0; i < N_OF_BRICKS; ++i)
        {
            m_bricks[i]->setDestroyed(false);
        }

        m_gameOver      = false;
        m_gameWon       = false;
        m_gameStarted   = true;
        m_timerId       = startTimer(DELAY);
    }
}

void        Breakout::pauseGame()
{
    if (m_paused)
    {
        m_timerId = startTimer(DELAY);
        m_paused = false;
    }
    else
    {
        m_paused = true;
        killTimer(m_timerId);
    }
}

void        Breakout::stopGame()
{
    killTimer(m_timerId);
    m_gameOver = true;
    m_gameStarted = false;
}

void        Breakout::victory()
{
    killTimer(m_timerId);
    m_gameWon = true;
    m_gameStarted = false;
}

void        Breakout::checkCollision()
{
    if (m_ball->getRect().bottom() > BOTTOM_EDGE)
    {
        stopGame();
    }

    for (int i = 0, j = 0; i < N_OF_BRICKS; ++i)
    {
        if (m_bricks[i]->isDestroyed())
        {
            j++;
        }

        if (j == N_OF_BRICKS)
        {
            victory();
        }
    }

    if (m_ball->getRect().intersects(m_paddle->getRect()))
    {
        int paddleLPos = m_paddle->getRect().left();
        int ballLPos = m_ball->getRect().left();

        int first   = paddleLPos + 8;
        int second  = paddleLPos + 16;
        int third   = paddleLPos + 24;
        int fourth  = paddleLPos + 32;

        if (ballLPos < first)
        {
            m_ball->setXDir(-1);
            m_ball->setYDir(-1);
        }

        if (ballLPos >= first && ballLPos < second)
        {
            m_ball->setXDir(-1);
            m_ball->setYDir(-1 * m_ball->getYDir());
        }

        if (ballLPos >= second && ballLPos < third)
        {
            m_ball->setXDir(0);
            m_ball->setYDir(-1);
        }

        if (ballLPos >= third && ballLPos < fourth)
        {
            m_ball->setXDir(1);
            m_ball->setYDir(-1 * m_ball->getYDir());
        }

        if (ballLPos > fourth)
        {
            m_ball->setXDir(1);
            m_ball->setYDir(-1);
        }
    }

    for (int i = 0; i < N_OF_BRICKS; ++i)
    {
        if (m_ball->getRect().intersects(m_bricks[i]->getRect()))
        {
            int ballLeft = m_ball->getRect().left();
            int ballHeight = m_ball->getRect().height();
            int ballWidth = m_ball->getRect().width();
            int ballTop = m_ball->getRect().top();


            QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
            QPoint pointLeft(ballLeft - 1, ballTop);
            QPoint pointTop(ballLeft, ballTop - 1);
            QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);

            if (!m_bricks[i]->isDestroyed())
            {
                if (m_bricks[i]->getRect().contains(pointRight))
                {
                    m_ball->setXDir(-1);
                }
                else if (m_bricks[i]->getRect().contains(pointLeft))
                {
                    m_ball->setXDir(1);
                }

                if (m_bricks[i]->getRect().contains(pointTop))
                {
                    m_ball->setYDir(1);
                }
                else if (m_bricks[i]->getRect().contains(pointBottom))
                {
                    m_ball->setYDir(-1);
                }

                m_bricks[i]->setDestroyed(true);
            }
        }
    }
}
