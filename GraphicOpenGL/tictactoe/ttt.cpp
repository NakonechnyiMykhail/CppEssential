//
//  main.cpp
//  OpenGl_test_settings
//
//  Created by Mikhail on 06.04.2021.
//
// tic-tac-toe
// cmake
// make
// qmake


//#if __APPLE_OS
#include <GLUT/glut.h>
//#if __WIN_32__
//#include <GL/glut.h>

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

int board[3][3];    // board for gameplay
int turn;           // current move
int result;         // result of the game
bool over;          // game over ?

void Initialize();
void Reshape(int x, int y);
void Display();
void OnKeyPress(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);

void DrawString(void *font, const char s[], float x, float y);
void DrawLines();
void DrawXO();
bool CheckWinner();
bool CheckIfDraw();
void DrawCircle(float cx, float cy, float r, int num_segments);

int main(int argc, char **argv)
{
    Initialize();
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(550, 200);
    glutInitWindowSize(300, 350);
    glutCreateWindow("Tic Tac Toe");
    glutReshapeFunc(Reshape); // int, int
    glutDisplayFunc(Display); // void
    glutKeyboardFunc(OnKeyPress); // uchar, int, int
    glutMouseFunc(OnMouseClick); // int, int, int, int
    glutIdleFunc(Display); // void
    glutMainLoop();
    
    return 0;
}

void Initialize()
{
    turn = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = 0;
        }
    }
}

void OnKeyPress(unsigned char key, int x, int y)
{
    switch (key) {
        case 'y':
            if (over == true) {
                over = false;
                Initialize();
            }
            break;
        case 'n':
            if (over == true) {
                exit(0);
            }
            break;
        default:
            exit(0);
    }
}

void OnMouseClick(int button, int state, int x, int y)
{
    if (over == false && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (turn == 1) {
            if (board[(y - 50) / 100][x / 100] == 0) {
                board[(y - 50) / 100][x / 100] = 1;
                turn = 2;
            }
        }
        else if (turn == 2)
        {
            if (board[(y - 50) / 100][x / 100] == 0) {
                board[(y - 50) / 100][x / 100] = 2;
                turn = 1;
            }
        }
    }
}

void Reshape(int x, int y) {
    glViewport(0, 0, x, y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, x, y, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
}

void DrawString(void *font, const char s[], float x, float y) {
    unsigned int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen(s); ++i) {
        glutBitmapCharacter(font, s[i]);
    }
}

bool CheckIfDraw() {
    /*
     check if there is draw X/O
     */
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void DrawLines() {
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    
    glVertex2f(100, 50);
    glVertex2f(100, 340);
    glVertex2f(200, 340);
    glVertex2f(200, 50);
    
    glVertex2f(0, 150);
    glVertex2f(300, 150);
    glVertex2f(0, 250);
    glVertex2f(300, 250);
    
    glEnd();
}

void DrawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; ++i) {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void DrawXO() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 1) {
                glBegin(GL_LINES);
                glVertex2f(50 + j * 100 - 25, 100 + i * 100 - 25);
                glVertex2f(50 + j * 100 + 25, 100 + i * 100 + 25);
                glVertex2f(50 + j * 100 - 25, 100 + i * 100 + 25);
                glVertex2f(50 + j * 100 + 25, 100 + i * 100 - 25);
                glEnd();
            } else if (board[i][j] == 2) {
                 DrawCircle(50 + j * 100, 100 + i * 100, 25, 15);
            }
        }
    }
}

bool CheckWinner() {
    int i, j;
    // horizontal
    for (i = 0; i < 3; ++i) {
        for (j = 1; j < 3; ++j) {
            /*
             00 01 02
             10 11 12
             20 21 22
             */
            
            if (board[i][0] != 0 && board[i][0] == board[i][j]) {
                if (j == 2) {
                    return true;
                }
            }
            else {
                break;
            }
        }
    }
    // vertical
    for (i = 0; i < 3; ++i) {
        for (j = 1; j < 3; ++j) {
            /*
             00 01 02
             10 11 12
             20 21 22
             */
            if (board[0][i] != 0 && board[0][i] == board[j][i]) {
                if (j == 2) {
                    return true;
                }
            }
            else {
                break;
            }
            
        }
    }
    // diagonal check
    /*
     00 01 02
     10 11 12
     20 21 22
     */
    if (
        (board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[2][0] != 0 && board[2][0] == board[1][1] && board[2][0] == board[0][2])
        ) {
        return true;
    }
    
    return false;
}


void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 0);
    
    // turns
    if (turn == 1) {
        DrawString(GLUT_BITMAP_HELVETICA_18, "Player1's turn", 100, 30);
    }
    else {
        DrawString(GLUT_BITMAP_HELVETICA_18, "Player2's turn", 100, 30);
    }
        
    
    DrawLines();
    DrawXO();
    
    // check winner
    if (CheckWinner() == true) {
        if (turn == 1) {
            over = true;
            result = 2;
        }
        else {
            over = true;
            result = 1;
        }
    }
    else if (CheckIfDraw() == true) {
        over = true;
        result = 0;
    }
    
    // check over ?
    if (over == true) {
        DrawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 100, 160);
        if (result == 0) {
            DrawString(GLUT_BITMAP_HELVETICA_18, "It's tie", 110, 185);
        }
        if (result == 1) {
            DrawString(GLUT_BITMAP_HELVETICA_18, "Player1 wins", 95, 185);
        }
        if (result == 2) {
            DrawString(GLUT_BITMAP_HELVETICA_18, "Player2 wins", 95, 185);
        }
        DrawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play again (y/n)", 40, 210);
    }
    
    glutSwapBuffers();
}
