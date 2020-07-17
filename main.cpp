#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>
#include <gtest/gtest.h>
#include <thread>

#include "game.hpp"

#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;
bool sGameOver = false;

void timer_callback(int);
void display_callback();
void reshapeCallback(int, int);
void keyboard_callback(int, int, int);


void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    drawGrid();
    initGrid(COLUMNS, ROWS);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("SNAKE");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshapeCallback);
    glutSpecialFunc(keyboard_callback);
    glutTimerFunc(0, timer_callback, 0);
    init();
    glutMainLoop();
    return 0;    
}


void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers();
    if (sGameOver)
    {
        //MessageBox(NULL, "Your Score : ", "GAME OVER", 0);
        exit(0);
    }
}

void reshapeCallback(int a_w, int a_h)
{
    glViewport(0, 0, (GLsizei) a_w, (GLsizei) a_h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, COLUMNS, 0.0f, ROWS, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer_callback, 0);
}

void keyboard_callback(int key, int, int)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            if(sDirection != DOWN)
                sDirection = UP;
            break;
        case GLUT_KEY_DOWN:
            if (sDirection != UP)
                sDirection = DOWN;
            break;
        case GLUT_KEY_RIGHT:
            if (sDirection != LEFT)
                sDirection = RIGHT;
            break;
        case GLUT_KEY_LEFT:
            if (sDirection != RIGHT)
                sDirection = LEFT;
            break;
    }
}
