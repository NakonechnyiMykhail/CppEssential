#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <QWidget>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Snake; }
QT_END_NAMESPACE

class Snake : public QWidget
{
    Q_OBJECT

public:
    Snake(QWidget *parent = nullptr);
    ~Snake();

protected:
    //
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
private:
    //Ui::Snake *ui;
    QImage dot;
    QImage head;
    QImage apple;

    static const int B_WIDTH    = 300;  // background width
    static const int B_HEIGHT   = 300;
    static const int DOT_SIZE   = 10;
    static const int ALL_DOTS   = 900;
    static const int RAND_POS   = 29;
    static const int DELAY      = 140;

    int timerId;
    int dots;
    int apple_x;
    int apple_y;

    int x[ALL_DOTS];
    int y[ALL_DOTS];

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;

    void loadImages();
    void initGame();
    void locateApple();
    void checkApple();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter &);

};
#endif // SNAKE_HPP
