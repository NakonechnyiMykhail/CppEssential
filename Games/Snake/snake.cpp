#include <QPainter>
#include <QTime>
#include "snake.hpp"
#include "ui_snake.h"

Snake::Snake(QWidget *parent)
    : QWidget(parent)
    //, ui(new Ui::Snake)
{
    //ui->setupUi(this);
    setStyleSheet("background-color:black;");

    rightDirection  = true;
    leftDirection   = false;
    upDirection     = false;
    downDirection   = false;

    inGame = true;

    resize(B_WIDTH, B_HEIGHT);
    loadImages();
    initGame();
}

Snake::~Snake()
{
    //delete ui;
}

void Snake::loadImages()
{
    dot.load("../Snake/dot.png");
    head.load("../Snake/head.png");
    apple.load("../Snake/apple.png");
}

void Snake::initGame()
{
    dots = 3;
    for (int var = 0; var < dots; ++var)
    {
        x[var] = 50 - var * 10;
        y[var] = 50;
    }
    locateApple();
    timerId = startTimer(DELAY);
}

void Snake::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    doDrawing();
}

void Snake::doDrawing()
{
    QPainter qp(this);
    if (inGame)
    {
        qp.drawImage(apple_x, apple_y, apple);

        for (int var = 0; var < dots; ++var)
        {
            if (var == 0)
            {
                qp.drawImage(x[var], y[var], head);
            }
            else
            {
                qp.drawImage(x[var], y[var], dot);
            }
        }
    }
    else
    {
        gameOver(qp);
    }
}

void Snake::locateApple()
{
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());

    int r = qrand() % RAND_POS;
    apple_x = (r * DOT_SIZE);

    r = qrand() % RAND_POS;
    apple_y = (r * DOT_SIZE);
}

void Snake::gameOver(QPainter &qp)
{
    QString message = "Game over";
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    qp.setPen(QColor(Qt::white));
    qp.setFont(font);

    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
}

void Snake::checkApple()
{
    if ((x[0] == apple_x) && (y[0] == apple_y))
    {
        dots++;
        locateApple();
    }
}

void Snake::checkCollision()
{
    for (int var = dots; var > 0; --var) { if ( ( var > 4) && (x[0] == x[var]) && (y[0] == y[var])) { inGame = false; } }

    if (y[0] >= B_HEIGHT)   { inGame = false; }
    if (y[0] < 0)           { inGame = false; }
    if (x[0] >= B_WIDTH)    { inGame = false; }
    if (x[0] < 0)           { inGame = false; }
    if (!inGame)            { killTimer(timerId); }
}


/*
  (0, 0)   ->
  |
 \ /

 -   |+   +
 - (0,0) ->
     |-

 -   |-   +
 - (0,0) ->
     |+
*/


void Snake::move()
{
    for (int var = dots; var > 0; --var)
    {
        x[var] = x[(var - 1)];
        y[var] = y[(var - 1)];
    }
    if (leftDirection)  { x[0] -= DOT_SIZE; }
    if (rightDirection) { x[0] += DOT_SIZE; }
    if (upDirection)    { y[0] -= DOT_SIZE; }
    if (downDirection)  { y[0] += DOT_SIZE; }

}

void Snake::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    if (inGame)
    {
        checkApple();
        checkCollision();
        move();
    }
    repaint();
}

void Snake::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    if ((key == Qt::Key_Left) && (!rightDirection))
    {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Right) && (!leftDirection))
    {
        rightDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Up) && (!downDirection))
    {
        upDirection = true;
        rightDirection = false;
        leftDirection = false;

    }

    if ((key == Qt::Key_Down) && (!upDirection))
    {
        downDirection = true;
        leftDirection = false;
        rightDirection = false;

    }
    QWidget::keyPressEvent(e);
}
